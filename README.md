Implementação do segundo trabalho numéricos I


Tema1:
Um foguete espacial, ao entrar na atmosfera, sofre deslocamentos d1, d2,..., dn em suas partes dadas pela<br>
solução do sistema de equações lineares Ad = f, onde A é a matriz das propriedades, d é o vetor das incógnitas<br>
e f é o vetor dos termos independentes (vetor constante). Caso o deslocamento de umas dessas partes passe de<br>
2 cm o foguete explode, causando prejuízo gigantesco. Os deslocamentos podem ser negativos ou positivos,<br>
dependendo da direção para onde ocorrem (dentro ou fora) e, por isso, são considerados em módulo após os<br>
cálculos efetuados. Uma das soluções possíveis para esse sistema é usar uma variação do método de fatoração<br>
LU onde, se A é uma matriz não singular e A = LU, então A pode ser reescrita como A = LDP, onde L é a<br>
mesma matriz triangular inferior do método convencional de fatoração LU, D é uma matriz diagonal e P é<br>
uma matriz triangular superior com diagonal unitária. Desenvolva, então, um sistema para calcular os<br>
deslocamentos d das partes de um foguete espacial considerado com todos os requisitos apresentados abaixo:<br>
a) Implementar algoritmo para calcular valores de {d} pelo método de Fatoração LU normal.<br>
b) Implementar algoritmo para calcular valores de {d} pelo método de Fatoração LU descrito.<br>
c) Calibrar sistema desenvolvido usando como padrão a matriz [A] e vetor {f} dados abaixo.<br>
d) Fornecer um quadro resposta para cada método pedido, variando os valores de [A] e de {f}.<br>
e) Analisar o que vai acontecer com o foguete em questão para o sistema mencionado abaixo.<br>

[A] = 3 −2 1 <br>
      1 −3 4 <br>
      9 4 −5 <br>

{ f } = 8 6 11 <br>


Dados de entrada: n (número de deslocamentos), os termos de [A]nxn e os de {f}nx1.<br>
Dados de saída: valores de {d}nx1 que representam os n deslocamentos d1, d2,..., dn.<br>

Compilar no linux:<br>
<code>c++ main.cpp -o main</code><br>
para executar<br>
<code>./main</code>
