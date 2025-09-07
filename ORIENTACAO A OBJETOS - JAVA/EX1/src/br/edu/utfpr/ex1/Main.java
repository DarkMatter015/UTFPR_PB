package br.edu.utfpr.ex1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam;
        int soma = 0;

        System.out.print("Tamanho do vetor = ");
        tam = sc.nextInt();

        int a[] = new int[tam];

        for(int i = 0; i < a.length; i++){
            System.out.print("Elemento " + i + " = ");
            a[i] = sc.nextInt();
        }

        System.out.println("--------------------");

        System.out.println("Imprimindo vetor: ");
        for(int i = 0; i < a.length; i++){
            System.out.print("a[" + i + "] = " + a[i]);
            soma += a[i];
        }

        System.out.println("--------------------");

        System.out.println("Soma do array: " + soma);
    }
}