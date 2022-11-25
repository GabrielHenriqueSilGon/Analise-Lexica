# Dijsktra
 
Na teoria dos grafos, o problema do caminho mínimo diz respeito a encontrar um caminho entre dois vértices (ou nós) em um grafo, de modo que a soma dos pesos (ou distancias) das arestas constituintes do caminho seja minimizada. Esse código utiliza como exemplo encontrar a menor rota entre duas cidades, dado um grafo em que cada vértice representa uma cidade, que faz fronteira com diversas outras e possui uma distância entre si, e como algoritmo para resolver o problema, é utilizado o Algoritmo de Dijsktra.

## Problema de Caminho Mínimo
O Caminho Mínimo têm multiplas variações as quais possuem seus prós e contras, assim como seus requisitos de um grafo. Para começar vamos falar sobre o básico, é necessário, acima de tudo, um grafo com vértices e tais vértices podem ser conectados por arestas. Um caminho então é formado pelas arestas que levam de um vértice à outro, logo, para um grafo simples sem peso em suas arestas, o caminho mínimo é aquele que utiliza menos arestas para chegar de um ponto a outro. Um algoritmo clássico que encontra o menor caminho em grafos sem peso é o BFS, que percorre o grafo utilizando-se movimentações em forma de ondas. O modelo de ondas se refere a forma de propagação da busca. Nela, os vértices são investigados visitando-se todos os seus adjacentes para só depois um novo vértice ser escolhido e assim repetir o processo.

Um grafo pode ser Direcionado, não direcionado ou misturado, significando que o caminho pode ser uma via de uma aresta á outra, via dupla ou independente. Cada variação pode ou não possuir um peso para as arestas. Alguns algoritmos não aceitam pesos negativos ou direcionamento que causa ciclos, uma vez que tais podem causar problemas de política e criar loops infinitos (Dijsktra aceita ciclos, mas não pesos negativos).

Existem três subtipos mais tratados do Caminho Mínimo na literatura:

- O Caminho Mínimo de Fonte Única, no qual são encontrados os menores caminhos de um vértice origem até todos os demais vértices no gráfo. 

- O Caminho Mínimo de Destino Único, no qual são encontrados os menores caminhos de todos os vértices no gráfo até um vértice de destino. 

- O Caminho Mínimo de Todos os Pares, em que são encontrados os menores caminhos entre cada par de vértices no grafo.

Comentando por cima de alguns algoritmos clássicos para Caminho mínimos, nós temos:

- Algoritmo de Bellman–Ford que resolve o problema mesmo se alguma arresta tiver peso negativo, mas pode causar um loop infinito se houver ciclos no grafo.
- Algoritimo de busca A* resolve o problema de par único por meio de heuristica, com a intenção de deixar a execução mais rápida.
- Algoritmo de Floyd-Warshall resolve o problema de caminho mínimo para todos os pares.
- Algoritmo de Johnson resolve o problema de caminho mínimo para todos os pares, e é mais rápido em grafos com poucas arestas comparadas aos vértices.

Como o problema a ser tratado é um que involve distância entre cidades, que não podem ser negativas e que podem ter ciclos em seu caminho, o Algoritmo de Dijsktra foi o utilizado, implementado com uma política de Destino Único. 

## Makefile

Como executar:

  make clean - Apaga a última compilação realizada contida na pasta build
  
  make - Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build
  
  make run - Executa o programa da pasta build após a realização da compilação
  
  e se tudo falhar, https://onlinegdb.com/u8X8WZXxO
