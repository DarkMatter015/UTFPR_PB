Algoritmo "TrocaValores"

Var
   a, b, aux: real


Inicio
      escreva("Informe o valor de A: ")
      leia(a)
      
      escreva("Informe o valor de B: ")
      leia(b)
      
      escreval("Antes da troca:")
      escreval("A: ", a, " e B: ", b)
      
      aux <- b

      b <- a
      
      a <- aux
      
      escreval("Depois da troca:")
      escreval("A: ", a, " e B: ", b)


Fimalgoritmo