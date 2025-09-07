/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.usandoPessoa;


import br.edu.utfpr.dao.PessoaDao;
import br.edu.utfpr.entidades.Pessoa;
import br.edu.utfpr.entidades.PessoaFisica;
import br.edu.utfpr.entidades.PessoaJuridica;

import java.util.Scanner;

/**
 *
 * @author Andreia
 */
public class UsandoPessoa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {


        PessoaFisica pf1 = new PessoaFisica("Lucas de Camargo", "12230213946");
        PessoaJuridica pj = new PessoaJuridica("Seu Zé do caxao", "157980001-01");
        PessoaFisica pf2 = new PessoaFisica("Methaus de Luka", "46139122302");
        PessoaFisica pf3 = new PessoaFisica("Methaus da Silva", "46139122305");

        PessoaDao pessoaDao = new PessoaDao();
        pessoaDao.inserir(pf1);
        pessoaDao.inserir(pf2);
        pessoaDao.inserir(pf3);
        pessoaDao.inserir(pj);

        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Pesquisar pessoa por nome");
            System.out.println("2. Exibir todas as pessoas");
            System.out.println("3. Excluir pessoa por ID");
            System.out.println("4. Ordenar pessoas");
            System.out.println("5. Buscar pessoas contendo nome");
            System.out.println("6. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir nova linha

            switch (opcao) {
                case 1:
                    System.out.print("Digite o nome da pessoa para pesquisar: ");
                    String nomePesquisado = scanner.nextLine();
                    Pessoa pessoa = pessoaDao.pesquisar(nomePesquisado);

                    System.out.println(pessoa != null ? "Pessoa encontrada: " + pessoa : "Pessoa não encontrada com esse nome");
                   
                    break;

                case 2:
                    System.out.println("Lista de todas as pessoas:");
                    System.out.println(pessoaDao.imprimir());

                    break;

                case 3:
                    System.out.print("Digite o ID da pessoa para excluir: ");
                    int id = scanner.nextInt();
                    boolean excluiu = pessoaDao.excluirPorIdPessoa(id);
                    System.out.println(excluiu ? "Pessoa excluida com sucesso!" : "Pessoa não encontrada para exclusão");

                    break;

                case 4:

                    System.out.println("Pessoas ordenadas:");
                 
                    break;

                case 5:
                    System.out.print("Digite a substring do nome para buscar: ");
                    
                    break;

                case 6:
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 6);

        scanner.close();
    }

}