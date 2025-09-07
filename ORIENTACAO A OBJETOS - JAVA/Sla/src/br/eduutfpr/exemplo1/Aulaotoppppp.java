/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.eduutfpr.exemplo1;

import java.util.Scanner;

/**
 *
 * @author Lucas.M
 */
public class Aulaotoppppp {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int u, t;
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Informe o primeiro valor: ");
        u = sc.nextInt();
        
        System.out.println("Informe o segundo valor: ");
        t = sc.nextInt();
        
        System.out.println("A soma de " + u + " + " + t + " é " + (u+t));
        
        // tabuada 
        
        if(u > 0){
            for (int i = 0; i <= 10; i++) {
                System.out.println(u + " * " + i + " = " + (u*i));
            }
        }
        else{
            System.out.println("O primeiro numero deve ser maior que 0");
        }
        
        
        
        
    }
    
}
