import os
import sqlite3 

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Verificacoes do simbolo e cotacao do simbolo
        symbol = request.form.get("symbol")
        if symbol != None:
            quote = lookup(symbol)
            if quote == None:
                return apology("Simbolo invalido", 403)
        else:
            return apology("Digite um simbolo", 403)
        # verificacoes do numero de acoes 
        qtd = request.form.get("shares")
        if qtd.isdigit() == False or qtd == None or qtd[0] == "-":
            return apology("Quantidade invalida", 403)
        # adicionar nova tabela no banco de dados - para armazenar as transacoes
        db.execute("""
            CREATE TABLE IF NOT EXISTS transactions (
                id_user INTEGER,
                username TEXT NOT NULL, 
                symbol TEXT NOT NULL,
                price NUMERIC NOT NULL,
                date TEXT NOT NULL);
        """)
        # variaveis necessarias para inserir no db
        username = db.execute("SELECT username FROM users WHERE users.id = ?;", session["user_id"])
        data = datetime.today().strftime("%Y-%m-%d")
        # insere os dados no db
        db.execute(
            "INSERT INTO transactions (id_user, username, symbol, price, date) VALUES (?, ?, ?, ?, ?);",
            session["user_id"], username[0]["username"], quote["symbol"], quote["price"], data 
            )
        # valor a ser debitado da conta
        valorDebitado = int(qtd) * float(quote["price"])
        # valor que usuario tem na conta
        consultaCash = db.execute("SELECT cash FROM users WHERE users.id = ?;", session["user_id"])
        valorConta = consultaCash[0]["cash"]
        if valorDebitado > valorConta:
            return apology("Saldo insuficiente", 401)

        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        sbl = request.form.get("symbol")
        if sbl != None:
            quote = lookup(sbl)
            if quote == None:
                return apology("Simbolo invalido", 403)
        else:
            return apology("Simbolo invalido", 403)
    
        return render_template("quoted.html", name=quote["name"], price=quote["price"], symbol=quote["symbol"])
    return render_template("quote.html")
    


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # verifica se username foi enviado
        if not request.form.get("username"):
                return apology("usuario invalido", 403)
        # verifica se a senha foi enviada
        if not request.form.get("password"):
            return apology("senha invalida", 403)
        elif not request.form.get("confirmation") or request.form.get("confirmation") != request.form.get("password") :
            return apology("senha invalida e/ou senha diferente", 403)
        # armazena no db
        try:
            db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?);", request.form.get("username"), 
                generate_password_hash(request.form.get("password"))
            )
        except Exception as e:  # se existir o username
            return apology(f"usuario existente", 403)
            
    return render_template("login.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    return apology("TODO")
