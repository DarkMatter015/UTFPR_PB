package br.edu.utfpr.usandoContato;

import br.edu.utfpr.contato.Contato;
import br.edu.utfpr.dao.ContatoDao;

import java.util.Scanner;

public class UsandoContato {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int opcao;

        ContatoDao contatoDao = new ContatoDao();

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Inserir contato");
            System.out.println("2. Imprimir contatos");
            System.out.println("3. Excluir contato por ID");
            System.out.println("4. Buscar por nome");
            System.out.println("5. Ordenar pessoas");
            System.out.println("6. Pesquisar por substring");
            System.out.println("7. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir nova linha

            switch (opcao) {
                case 1:
                    System.out.print("Nome: ");
                    String nome = scanner.nextLine();

                    System.out.print("Email: ");
                    String email = scanner.nextLine();

                    System.out.print("Telefone: ");
                    String telefone = scanner.nextLine();

                    System.out.print("Tipo de contato: ");
                    String tipoContato = scanner.nextLine();

                    Contato novoContato = new Contato(nome, email, telefone, tipoContato);

                    contatoDao.adicionar(novoContato);

                    System.out.println("\nContato adicionado com sucesso!");

                    break;

                case 2:
                    System.out.println("Lista de todos os contatos:");
                    System.out.println(contatoDao.imprimir());

                    break;

                case 3:
                    System.out.print("Digite o ID do contato para excluir: ");
                    int id = scanner.nextInt();
                    boolean excluiu = contatoDao.excluirPorId(id);
                    System.out.println(excluiu ? "COntato excluido com sucesso!" : "Contato não encontrado para exclusão");

                    break;

                case 4:

                    System.out.println("Digite o nome do contato para pesquisar: ");
                    String nomePesquisado = scanner.nextLine();
                    Contato contato = contatoDao.pesquisarPorNome(nomePesquisado);

                    System.out.println(contato != null ? "Contato encontrado: " + contato : "Contato não encontrado!");

                    break;

                case 5:
                    System.out.println("Ordenando todos os contatos:");
                    contatoDao.ordenar();
                    break;

                case 6:
                    System.out.println("Digite uma substring para pesquisar: ");
                    String substring = scanner.nextLine();
                    System.out.println("Lista de pessoas que possuem essa substring: ");

                    System.out.println(contatoDao.pesquisarContatoPorSubstring(substring));

                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 7);

        scanner.close();
    }

    }
