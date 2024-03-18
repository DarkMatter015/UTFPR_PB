Algoritmo "ReajusteSalario"

Var
   salario, reajuste, salario_final: real


Inicio
      escreva("Informe o valor do salario: ")
      leia(salario)
      
      escreva("Informe o percentual de reajuste do salario: ")
      leia(reajuste)
      
      reajuste <- reajuste / 100
      
      salario_final <- salario + (salario * reajuste)
      
      escreva("O salario reajustado é: ", salario_final)


Fimalgoritmo