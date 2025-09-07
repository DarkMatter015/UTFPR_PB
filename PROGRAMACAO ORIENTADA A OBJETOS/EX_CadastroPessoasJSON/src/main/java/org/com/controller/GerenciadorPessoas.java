package org.com.controller;

import org.com.model.Pessoa;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class GerenciadorPessoas {
    private final ManipuladorJSON manipuladorJSON;
    private List<Pessoa> pessoas;

    public GerenciadorPessoas() {
        this.manipuladorJSON = new ManipuladorJSON();
        try {
            this.pessoas = manipuladorJSON.carregarPessoas(); // Carrega dados existentes
        } catch (IOException e) {
            System.out.println("Erro ao carregar pessoas: " + e.getMessage());
            this.pessoas = new ArrayList<>();
        }
    }

    public List<Pessoa> getPessoas() {
        return pessoas;
    }

    public void cadastrarPessoa(Scanner scanner) {
        System.out.print("Digite o nome: ");
        String nome = scanner.nextLine();

        System.out.print("Digite a idade: ");
        int idade = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Digite os hobbies (separados por vírgula): ");
        String hobbiesInput = scanner.nextLine();
        List<String> hobbies = Arrays.asList(hobbiesInput.split(",\\s*"));

        Pessoa pessoa = new Pessoa(nome, idade, new ArrayList<>(hobbies));
        pessoas.add(pessoa);
        try {
            manipuladorJSON.salvarPessoas(pessoas);
        } catch (IOException e) {
            System.out.println("Erro ao salvar pessoas: " + e.getMessage());
        }
    }

    public void listarPessoas() {
        if (pessoas.isEmpty()) {
            System.out.println("Nenhuma pessoa cadastrada.");
        } else {
            System.out.println("\n--- Pessoas Cadastradas ---");
            for (int i = 0; i < pessoas.size(); i++) {
                Pessoa p = pessoas.get(i);
                System.out.printf("%d. Nome: %s, Idade: %d, Hobbies: %s%n",
                        i + 1, p.getNome(), p.getIdade(), p.getHobbies());
            }
        }
    }

    public void buscarPessoa(Scanner scanner) {
        System.out.print("Digite o nome para buscar: ");
        String nomeBusca = scanner.nextLine().toLowerCase();

        boolean encontrou = false;
        for (Pessoa p : pessoas) {
            if (p.getNome().toLowerCase().contains(nomeBusca)) {
                System.out.printf("Encontrado: Nome: %s, Idade: %d, Hobbies: %s%n",
                        p.getNome(), p.getIdade(), p.getHobbies());
                encontrou = true;
            }
        }
        if (!encontrou) {
            System.out.println("Nenhuma pessoa encontrada com esse nome.");
        }
    }
}