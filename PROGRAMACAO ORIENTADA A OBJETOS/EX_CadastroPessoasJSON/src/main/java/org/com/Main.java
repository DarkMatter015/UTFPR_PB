package org.com;

import org.com.controller.GerenciadorPessoas;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GerenciadorPessoas gerenciador = new GerenciadorPessoas();
        int opcao;

        do {
            System.out.println("\n--- Gerenciador de Lista de Compras ---");
            System.out.println("1. Cadastrar pessoa");
            System.out.println("2. Listar pessoas cadastradas");
            System.out.println("3. Buscar pessoa pelo nome");
            System.out.println("4. Encerrar programa");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();
            scanner.nextLine(); // Limpa o buffer

            switch (opcao) {
                case 1:
                    gerenciador.cadastrarPessoa(scanner);
                    break;
                case 2:
                    gerenciador.listarPessoas();
                    break;
                case 3:
                    gerenciador.buscarPessoa(scanner);
                    break;
                case 4:
                    System.out.println("Programa encerrado.");
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        } while (opcao != 4);

        scanner.close();
    }
}