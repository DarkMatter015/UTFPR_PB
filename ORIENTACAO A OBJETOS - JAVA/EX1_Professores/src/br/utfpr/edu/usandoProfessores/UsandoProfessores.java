package br.utfpr.edu.usandoProfessores;

import br.utfpr.edu.professor.ProfessorEfetivo;
import br.utfpr.edu.professor.ProfessorHorista;

import java.util.Scanner;

public class UsandoProfessores {
    public static void main(String[] args) {
        int opcao;
        String nome;
        String email;
        Scanner sc = new Scanner(System.in);

        System.out.println("Crie um objeto professor:\n1 - Professor Efetivo\n2 - Professor Horista");
        opcao = sc.nextInt();

        switch (opcao){
            case 1:
                float adicionalTitulacao;
                float salarioBase;

                System.out.println("=== PROFESSOR EFETIVO ===");
                System.out.println("\nNome: ");
                nome = sc.next();
                System.out.println("\nEmail: ");
                email = sc.next();
                System.out.println("\nAdicional Titulação: R$ ");
                adicionalTitulacao = sc.nextFloat();
                System.out.println("\nSalario Base: R$ ");
                salarioBase = sc.nextFloat();

                ProfessorEfetivo professorEfetivo1 = new ProfessorEfetivo(nome, email, adicionalTitulacao, salarioBase);

                System.out.println("\nSalario Total: R$ " + professorEfetivo1.calcularSalarioTotal());
                System.out.println(professorEfetivo1);
                break;

            case 2:
                int qtdHoras;
                float valorHora;

                System.out.println("=== PROFESSOR HORISTA ===");
                System.out.println("\nNome: ");
                nome = sc.next();
                System.out.println("\nEmail: ");
                email = sc.next();
                System.out.println("\nQuantidade de Horas que trabalha: ");
                qtdHoras = sc.nextInt();
                System.out.println("\nValor da hora: R$ ");
                valorHora = sc.nextFloat();

                ProfessorHorista professorHorista = new ProfessorHorista(nome, email, qtdHoras, valorHora);

                System.out.println("\nSalario Total: R$ " + professorHorista.calcularSalarioTotal());
                System.out.println(professorHorista);
                break;

            default:
                System.out.println("\nValor inválido!!!");
                break;
        }
    }
}
