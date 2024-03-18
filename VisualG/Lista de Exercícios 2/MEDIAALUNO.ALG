Algoritmo "MediaALuno"

Var
   nota1, nota2, nota3, media: real


Inicio
      escreva("Informe a primeira nota: ")
      leia(nota1)
      
      escreva("Informe a segunda nota: ")
      leia(nota2)
      
      escreva("Informe a terceira nota: ")
      leia(nota3)
      
      media <- (nota1 * 1 + nota2 * 3 + nota3 * 4) / (1 + 3 + 4)
      
      escreval("Média: ", media)
      
      se media >= 6 entao
         escreva("Aluno aprovado")
      senao
           se media < 4 entao
              escreva("Aluno reprovado")
           senao
              escreva("Aluno em recuperação")
           fimse
      fimse


Fimalgoritmo