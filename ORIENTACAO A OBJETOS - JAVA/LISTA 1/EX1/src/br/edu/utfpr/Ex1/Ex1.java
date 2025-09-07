/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.Ex1;

import java.util.Scanner;

/**
 *
 * @author Lucas.M
 */
public class Ex1 {

    /**
     * 1) Escreva um programa (utilize a classe Scanner) que calcule o volume de uma caixa
(volume = comprimento * altura * largura). O usuário deverá informar
(utilize a classe Scanner) a altura, comprimento e largura da caixa. 
     */
    public static void main(String[] args) {
        float alt, comp, larg;
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Informe a altura: ");
        alt = sc.nextFloat();
        
        System.out.println("Informe o comprimento: ");
        comp = sc.nextFloat();
        
        System.out.println("Informe a largura: ");
        larg = sc.nextFloat();
        
        float volume = comp * alt * larg;
        
        System.out.println("O volume da caixa é: " + volume);
    }
    
}
