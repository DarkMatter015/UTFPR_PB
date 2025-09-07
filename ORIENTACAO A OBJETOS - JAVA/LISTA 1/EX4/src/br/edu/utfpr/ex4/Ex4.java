/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.ex4;

import java.util.Scanner;

/**
 *
 * @author Lucas.M
 */
public class Ex4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        float peso, altura;
        
        System.out.println("Informe o peso: ");
        peso = sc.nextFloat();
        
        System.out.println("Informe a altura: ");
        altura = sc.nextFloat();
        
        float imc = (peso / (altura * altura));
        
        if(imc < 20){
            System.out.println("Magro");
        }
        else if(imc >= 20 && imc <= 24){
            System.out.println("Normal");
        }
        else if(imc >= 25 && imc <= 29){
            System.out.println("Acima do Peso");
        }
        else if(imc >= 30 && imc <= 34){
            System.out.println("Obeso");
        }
        else{
            System.out.println("Muito Obeso");
        }
    }
    
}
