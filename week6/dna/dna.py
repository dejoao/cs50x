import csv
import sys


def main(*args): # ve como usar argumentos em python

    # TODO: Verificar o uso da linha de comando
    if args != 2:
        print ("Use: dna.py databases/NAME.csv sequences/NUMBER.csv")

    # TODO: Ler arquivo de banco de dados em uma variável
    database = args
    print(f"{database}")
    # TODO: Ler arquivo de sequência de DNA em uma variável
    
    # TODO: Encontrar a correspondência mais longa de cada STR na sequência de DNA

    # TODO: Verificar o banco de dados para perfis correspondentes

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Verifique cada caractere na sequência para a maioria das execuções consecutivas de subsequência
    for i in range(sequence_length):

        # Inicializar contagem de execuções consecutivas
        count = 0

        # Verifique se há uma correspondência de subsequência em uma "substring" (um subconjunto de caracteres) dentro da sequência
        # Se houver uma correspondência, mova a substring para a próxima correspondência potencial na sequência
        # Continue movendo a substring e verificando se há correspondências até que não haja correspondências consecutivas
        while True:

            # Ajustar início e fim da substring
            start = i + count * subsequence_length
            end = start + subsequence_length

            # Se houver uma correspondência na substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # Se não houver correspondência na substring
            else:
                break
        
        # Atualizar a maioria das correspondências consecutivas encontradas
        longest_run = max(longest_run, count)

    # Após verificar as execuções em cada caractere na sequência, retornar a execução mais longa encontrada
    return longest_run


main()
