import java.util.Scanner;

static boolean existeNoVetor(int vet[], int valor){

    for(int i = 0; i < vet.length; i++){
        if (vet[i] == valor) {
            return true;
        }
        else{
            return false;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tam;

        System.out.print("Tamanho do vetor: ");
        tam = sc.nextInt();

        int vet[] = new int[tam];

        for (int i = 0; i < vet.length; i++) {
            System.out.print("vet ["+ i + "] = ");
            vet[i] = sc.nextInt();
        }

        System.out.println("Elementos do vetor");
        for (int i = 0; i < vet.length; i++) {
            System.out.println("vet ["+ i + "] = " + vet[i]);
        }

        System.out.print("Informe o valor a ser procurado: ");
        int valor = sc.nextInt();

        for (int i = 0; i < vet.length; i++) {
            if(existeNoVetor(vet, valor)){
                System.out.println("o valor " + valor + " esta no indice " + i + " do vetor");
            }
        }
        if(existeNoVetor(vet, valor)){
            System.out.println("o valor " + valor + " nao esta no vetor");
        }
    }
}