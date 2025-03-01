import csv
import sys
import re


def main(*args): # ve como usar argumentos em python

    # TODO: Verificar o uso da linha de comando
    argvs = sys.argv
    argc = len(sys.argv)

    # print(f"{argc} {argvs[0]} {argvs[1]} {argvs[2]}")
    
    if argc != 3:
        print("Use: dna.py databases/NAME.csv sequences/NAME.txt")

    # TODO: Ler arquivo de banco de dados em uma variável
    name_database = argvs[1]
    database = open(f"{name_database}")

    with database as file:
        reader = csv.DictReader(file)
        #print(reader.fieldnames)
        strs = reader.fieldnames
    strs = strs[1:]
    rows = []
    
    with open(f"{name_database}") as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
    
    #print(rows[1])

    # TODO: Ler arquivo de sequência de DNA em uma variável
    dna_arquivo = open(f"{argvs[2]}")
    dna = dna_arquivo.read()
    #print(f"{dna}")

    # TODO: Encontrar a correspondência mais longa de cada STR na sequência de DNA
    quantidade_de_str = 0
    for i in strs:
        quantidade_de_str += 1
    #print(f"{quantidade_de_str}")

    quantidade_str = [0] * quantidade_de_str 
    
    for j in range(quantidade_de_str):
        quantidade_str[j] = longest_match(dna, strs[j])

    #print(quantidade_str)
    
    # TODO: Verificar o banco de dados para perfis correspondentes
    
    contador = 0

    # Loop que itera por cada linha (rows)
    for q in range(len(rows)):
        # Transformar o rows atual em lista
        lista = list(rows[q].values())

        # Criar uma nova lista sem a primeira string - nome da pessoa
        strs_lista = []
        for x in lista[1:]:
            strs_lista.append(int(x)) #converte para int

        # Resetar contador
        contador = 0

        # Comparar cada valor de quantidade_str com os valores correspondentes de strs_lista
        for j in range(len(strs_lista)):
            if quantidade_str[j] == strs_lista[j]:
                contador += 1
            else:
                break

        # Se o contador atingir a quantidade esperada  as STRs correspondem, exibir o resultado
        if contador == quantidade_de_str:
            print(lista[0])
            break
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Retorna o comprimento da maior execução da subsequência na sequência."""

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
