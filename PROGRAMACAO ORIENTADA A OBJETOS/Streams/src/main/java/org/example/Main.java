package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.OptionalDouble;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {

        List<Integer> numeros = Arrays.asList(1, 2, 3, 4, 5);


        List<Integer> dobroNumerosPares = new ArrayList<>();


        // Stream
        List<Integer> dobroNumerosParesStream = numeros.stream()
                .filter(n -> n % 2 == 0)
                .map(n -> n*2)
                .collect(Collectors.toList());
        System.out.println("Lista pares stream: " + dobroNumerosParesStream);

        List<Pessoa> pessoas = Arrays.asList(
                new Pessoa("Tatiane", 23),
                new Pessoa("Kleiro", 20),
                new Pessoa("rogerin", 12),
                new Pessoa("higor", 78)
        );

        // filtrar pessoas por idade 18+
        List<Pessoa> pessoasStream = pessoas.stream()
                .filter(p -> p.getIdade() > 18)
                .collect(Collectors.toList());
        System.out.println("Pessoas com 18+ : " + pessoasStream.toString());

        List<String> nomePessoas = pessoas.stream()
                .map(Pessoa::getNome)
                .collect(Collectors.toList());
        System.out.println("Nome das pessoas: " + nomePessoas);

        Double mediaIdadePessoas = pessoas.stream()
                .mapToInt(Pessoa::getIdade)
                .average().getAsDouble();

        System.out.println("Media das idades: " + mediaIdadePessoas);

        OptionalDouble mediaIdadePessoas2 = pessoas.stream()
                .mapToInt(Pessoa::getIdade)
                .average();


        System.out.println("Media das idades 2: " + (mediaIdadePessoas2.isPresent() ? "sla" : "nao"));
    }
}