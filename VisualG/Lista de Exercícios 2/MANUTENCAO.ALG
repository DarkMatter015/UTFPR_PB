Algoritmo "Manutencao"

Var
   total_pecas, pecas_defeituosas, porcentagem: real


Inicio
      escreva("Informe o total de peças produzidas: ")
      leia(total_pecas)
      
      escreva("Informe o total de peças defeituosas: ")
      leia(pecas_defeituosas)
      
      porcentagem <- (pecas_defeituosas / total_pecas) * 100
      
      escreval("Porcentagem: ", porcentagem)

      se porcentagem > 10 entao
         escreva("A máquina precisa de manutenção")
      senao
         escreva("A máquina não precisa de manutenção")
      fimse


Fimalgoritmo