#include <stdio.h>
#include <cs50.h>
#include <string.h>

int validador (void);

string numeroCartao;

int main (void){
    //Solicita ao usuario o numero de cartao
    numeroCartao = get_string("Numero: ");
    validador ();
    printf("%s", numeroCartao);
    
}


int validador (void){
    /*inverte o numero do cartao. Preciso passar por cada caracter da string
    comecando do final, e adicionar os caraceteres em uma nova  string */
    string numeroCartaoAoContrario;
    int indiceNC = strlen(numeroCartao - 1);
    int indiceNCC = 0;
    for (int i = 0; i < strlen(numeroCartao - 1); i++)
    {
        numeroCartaoAoContrario[indiceNCC] = numeroCartao[indiceNC];
        indiceNC--;        
    }
    printf("%s", numeroCartaoAoContrario);

    //Seledcionar os digitos para multiplicar por dois cada digito e, depois somar
    
    //Somar o resultado com os numeros q nao foram multiplicados por dois


}
