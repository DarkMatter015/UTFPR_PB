/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.ex2;

import java.util.Scanner;

/**
 *
 * @author Lucas.M
 */
public class Ex2 {

    /**
     * 2) Escreva um programa (utilize a classe JOptionPane para entrada e sa�da de dados)
que calcule a m�dia salarial dos funcion�rios da empresa. O usu�rio dever� informar
o n�mero de funcion�rios e os valores dos sal�rios de cada funcion�rio.
     */
    public static void main(String[] args) {
        
        int nFuncionarios = 0, i = 0;
        float sal = 0, media = 0;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Digite o numero de funcionarios: ");
        nFuncionarios = sc.nextInt();
        
        for (i = 0; i < nFuncionarios; i++) {
            System.out.println("Digite o salario do funcionario " + (i+1) + ": R$");
            sal += sc.nextFloat();
            
        }
        
        media = sal / i;
        
        System.out.println("A media dos salarios eh de R$" + media);
        
        
    }
    
}
