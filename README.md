<p align="center">
  <img src="https://github.com/dejoao/cs50x/blob/main/src/212026_1298716.png" alt="" width="900"/>
</p>

O CS50x é uma versão online do famoso curso de introdução à ciência da computação de Harvard. Ele ensina os conceitos fundamentais da programação e da ciência da computação, cobrindo temas como algoritmos, estruturas de dados, desenvolvimento web, segurança, e mais. Ao longo do curso, aprendendemos várias tecnologias, incluindo C, Python, SQL, HTML, CSS e JavaScript, por meio de projetos práticos.

## Este repositório
Este repositório foi criado para apresentar os projetos que desenvolvi ao longo do curso, destacando aqueles que considero mais importantes. Nele, compartilho as soluções que implementei e as abordagens que utilizei para resolver os desafios propostos.

---
- [credit.c](https://github.com/dejoao/cs50x/edit/main/README.md#creditc) O inicio
- [substitution.c](https://github.com/dejoao/cs50x/tree/main/Week%202%20-%20Arrays/substitution) Talvez meu favorito
- [runoff.c](https://github.com/dejoao/cs50x/tree/main/Week%203%20-%20Algorithms/runoff) Vote aqui
- [rcover.c](https://github.com/dejoao/cs50x/tree/main/Week%204%20-%20Memory/recover) Recuperando
---
## **credit.c**
### Desafio
Neste projeto, o objetivo é implementar um programa em C que verifica a validade de números de cartões de crédito. Cartões da American Express, MasterCard e Visa possuem números com formatos específicos, incluindo uma "fórmula de verificação" que ajuda a detectar erros, como transposições de dígitos. O programa deve analisar o número informado e determinar se ele é válido de acordo com essas regras.

Então qual é a fórmula secreta? Bem, a maioria dos cartões usa um algoritmo inventado por Hans Peter Luhn da IBM. De acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da seguinte forma:
1. Multiplique cada outro dígito por 2, começando pelo penúltimo dígito do número, e depois some os dígitos desses produtos.
2. Adicione a soma à soma dos dígitos que não foram multiplicados por 2.
3. Se o último dígito do total for 0 (ou, em termos mais formais, se o total módulo 10 for congruente a 0), o número é válido!

### **Implementação**
![funcionamento](https://github.com/dejoao/cs50x/blob/main/src/credit.gif)
[Codigo](https://github.com/dejoao/cs50x/blob/main/problemas/credit3.c)

