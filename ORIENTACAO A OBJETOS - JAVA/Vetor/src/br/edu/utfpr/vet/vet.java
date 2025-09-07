package br.edu.utfpr.vet;

public class vet{

    public static void main(String[] args) {
        int vetor[] = new int[10];
        int tam = 0;

        for (int i = 0; i < vetor.length; i++) {
            vetor[i] = (int)(Math.random() * 10) + 1;
        }

        for (int i = 0; i < vetor.length; i++) {
            if(vetor[i] % 2 == 0){
                tam++;
            }
        }

        int vetPar[] = new int[tam];
        int j = 0;

        for(int i = 0; i < vetor.length; i++){
            System.out.println(vetor[i]);
            if(vetor[i] % 2 == 0){
                vetPar[j] = vetor[i];
                j++;
            }
        }

        for(int i = 0; i < vetPar.length; i++){
            System.out.println("VetPar["+i+"] = "+vetPar[i]);
        }
    }

}