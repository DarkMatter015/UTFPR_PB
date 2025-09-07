import javax.swing.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nomes[] = new String[3];
        float notas[] = new float[3];
        int soma = 0;
        float media;

        for(int i = 0; i < 3; i++){

            System.out.print("Informe o nome do aluno n° " + (i + 1) + ": ");
            nomes[i] = sc.next();
            System.out.print("Informe a nota do aluno n° " + (i+1) + ": ");
            notas[i] = sc.nextFloat();
        }

        for(int i = 0; i < 3; i++){
            System.out.println("Alunos ["+i+"]: " + nomes[i] + " - Nota ["+i+"]: " + notas[i]);
            soma += notas[i];
        }

        media = soma / 3;

        System.out.println("Média: " + media);

        for(int i = 0; i < 3; i++){
            if(notas[i] > media){
                System.out.println("Aluno n°" + i + " passou com a nota: " + notas[i]);
            }
        }
    }
}