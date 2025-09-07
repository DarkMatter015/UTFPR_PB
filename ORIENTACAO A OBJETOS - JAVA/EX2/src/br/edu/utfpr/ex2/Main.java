package br.edu.utfpr.ex2;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a[] = new int[5];
        int soma = 0;
        float media = 0;

        for(int i = 0; i < a.length; i++){
            System.out.print("Elemento " + i + " = ");
            a[i] = sc.nextInt();
        }

        System.out.println("--------------------");

        System.out.println("Imprimindo array: ");

        for(int i = 0; i < a.length; i++){
            System.out.println("a[" + i + "] = " + a[i]);
            soma += a[i];
        }

        media = soma / a.length;

        System.out.println("Média dos números ímpares do array: " + media);
    }
}