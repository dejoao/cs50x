from cs50 import get_string

def CalcNumFrases(texto):
    frases = 0
    for i in texto:
        if i == '.' or i == '!' or i == '?':
            frases += 1
    return frases

def CalcNumLetras(texto):
    letras = 0
    for letra in texto:
        if letra.isalpha():
            letras += 1
    return letras

def CalcNumPalavras(texto):
    palavras = 0
    for i in texto.split():
        palavras += 1
    return palavras

texto = get_string("Text: ")
num_palavras = CalcNumPalavras(texto)
num_frases = (CalcNumFrases(texto) / num_palavras) * 100
num_letras = (CalcNumLetras(texto) /num_palavras) * 100

#Fazer o calculo "índice Coleman-Liau"
index = 0.0588 * num_letras - 0.296 * num_frases - 15.8
#Arrendondar a nota para o numero inteiro mais proximo
index1 = round(index)
#Mostrar o resutado
if index1 > 16:
    print("Grade 16+")
if index1 < 1:
    print("Before Grade 1")
if index1 > 1 and index1 < 16:
    print(f"Grade {index1}")
