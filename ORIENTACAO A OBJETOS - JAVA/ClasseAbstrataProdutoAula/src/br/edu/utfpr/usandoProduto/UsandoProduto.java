package br.edu.utfpr.usandoProduto;

import br.edu.utfpr.produto.Eletronico;
import br.edu.utfpr.produto.Livro;
import java.text.DecimalFormat;

public class UsandoProduto {
    public static void main(String[] args) {
        
        
        int quantidadeLivro = 2;
        int quantidadeEletronico = 3;
        
        Livro livro = new Livro("Dom Casmurro", 30, "Machado de Assis");
        Eletronico eletronico = new Eletronico("Smartphone", 2000, "Samsung");
        
        System.out.println(livro);
        System.out.println("");
        System.out.println(eletronico);
        
        DecimalFormat df = new DecimalFormat("0.00");
        System.out.println("-------------Preços do Livro-------------------");
        System.out.println("valor do desconto: " + df.format(livro.calcularDesconto()));
        System.out.println("Valor sem desconto: " + df.format(livro.calcularPrecoSemDesconto(quantidadeLivro)));
        System.out.println("Valor com desconto: " + df.format(livro.calcularPrecoTotal(quantidadeLivro)));
        
        System.out.println("-------------Preços do Eletrônico-------------------");
        System.out.println("valor do desconto: " + df.format(eletronico.calcularDesconto()));
        System.out.println("Valor sem desconto: " + df.format(eletronico.calcularPrecoSemDesconto(quantidadeEletronico)));
        System.out.println("Valor com desconto: " + df.format(eletronico.calcularPrecoTotal(quantidadeEletronico)));
    }
    
}
