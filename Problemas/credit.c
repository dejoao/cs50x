#include <stdio.h>
#include <cs50.h>

string numeroCartao;

int main (void){
    //Solicita ao usuario o numero de cartao
    numeroCartao = get_string("Numero: ");
    
}

int validador (string cartao[]){
    /*inverte o numero do cartao. Preciso passar por cada caracter da string
    comecando do final, e adicionar os caraceteres em uma nova  string */
    
    int caracterCartao = 0;
    for (int i = 0; i < cartao[caracterCartao]; i++)
    {
        caracterCartao++;
    }

    //Seledcionar os digitos para multiplicar por dois cada digito e, depois somar
    
    //Somar o resultado com os numeros q nao foram multiplicados por dois


}