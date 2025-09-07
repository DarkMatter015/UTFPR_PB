/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.ex3;

import java.util.Scanner;

/**
 *
 * @author Lucas.M
 */
public class Ex3 {

    /**
     * 3) Escreva um programa (utilize a classe JOptionPane para entrada e saída de dados)
que calcule o valor do produto de acordo com a taxa de aumento (%). Solicite ao
usuário que informe o valor do produto e a taxa de aumento. O programa retorna o
novo valor do produto. Exemplo: valor do produto = R$ 2.000,00, Taxa de aumento =
10%. O novo valor do produto é R$ 2.200,00.
     */
    public static void main(String[] args) {
        float valProduto = 0, txAumento = 0;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Informe o valor do produto: R$");
        valProduto = sc.nextFloat();
        
        System.out.println("Informe a taxa de aumento: %");
        txAumento = sc.nextFloat();
        
        valProduto = (valProduto * txAumento) + valProduto;
        
        System.out.println("O novo valor do produto é R$" + valProduto);
    }
    
}
