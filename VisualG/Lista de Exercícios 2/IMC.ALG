Algoritmo "IMC"

Var
   altura, peso, imc: real


Inicio
      escreva("Informe a altura(M): ")
      leia(altura)
      
      escreva("Informe a peso(Kg): ")
      leia(peso)
      
      imc <- peso / (altura * altura)
      
      escreval("IMC: ", imc)
      
      se imc > 30 entao
         escreva("Acima do peso")
      senao
         escreva("Peso normal")
      fimse


Fimalgoritmo