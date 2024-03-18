Algoritmo "VerificaGenero"

Var
   genero: caractere


Inicio
      escreva("Informe o gênero (F ou M): ")
      leia(genero)
      
      se (genero = "M") ou (genero = "m") entao
         escreva("Masculino")
      senao
           se (genero = "F") ou (genero = "f") entao
              escreva("Feminino")
           senao
              escreva("Caracter inválido")
           fimse
      fimse


Fimalgoritmo