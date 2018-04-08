# Relatório
  
  - A atividade foi implementada em C++.
  
  - O exercício foi ótimo para treinar a recursiviade.
  
  - A maior dificuldade foi encontrar o padrão para criar as figuras.
  
  - Feita em grupo.
  
  
  - Dificuldade em aumentar a espessura em diferentes níveis da recursão.
  
  
## O que foi feito?

  - Os fractais emboa, triângulo, floco de neve, trigo, árvore, quadrado espiral.
  
  - O FLOCO DE NEVE consiste na chamada de 5 blocos com a recursividade, basicamente 
    foi preciso andar o valor do lado virar seu respectivo ângulo(72 graus já que eram 5 lados), 
    e retornar o valor andado para realizar a recursão novamente.
    
  - A ÁRVORE foi realializada a alteração na sua cor, as extremidade ficaram com cor 
    verde e o tronco e caules com tom de marro. Sua espessura também foi alterada, dando um aspecto "realista".
    
  - O TRIGO foi o mais complicado, precisei da ajuda de um amigo para fazer, mas consiste em um laço
    e dentro dele, ocorre a aço de andar, virar uma algulação para que possa chamar a recursão,isso desenhará 
    apenas um lado, na próxima recursão deve-se virar o dobro da angulação para desenhar o próximo lado. E por fim,
    fora do laço tem mais uma instrução onde o valor de volta(- lado) será multiplicado 
    pela condição de parada que há dentro do laço, para que a figura possa ser desenhada, se
    não existir essa parte do código, a figura irá desenhar apenas apara o lado que virar no início da função. 

  - QUADRADO ESPIRAL tive ajuda de um amigo de sala, Rendley, que me orientou na lógica da recursão, que basicamente
    fazemos um laço 'for', e desenhamos o primeiro quadrado antes de chamar a recursão, andamos um lado para dar
    espaço e desenhar outro triângulo, faremos uma elevação com a função 'up', para que o próximo quadrado não fique 
    no mesmo nível que o quadrado anterior, com um pequena inclinação, após isso, chamaremos a recusão.
