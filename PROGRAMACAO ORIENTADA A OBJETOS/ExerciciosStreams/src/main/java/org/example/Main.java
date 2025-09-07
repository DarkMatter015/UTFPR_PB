package org.example;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Integer> numeros = Arrays.asList(5, 3, 2, 1, 10, 6, 7, 8, 9);
        List<String> nomes = Arrays.asList("lukas", "joao", "Lukas", "Kleito");
        List<Double> notas = Arrays.asList(7.8,9.9, 8.0, 7.8, 9.1, 7.8, 9.9);

        // 1. Dada uma lista de números inteiros, encontre o maior valor. Dica: Utilize max com um Comparator para comparar os elementos.

        Integer maior = numeros.stream()
                .max(Comparator.comparingInt(Integer::intValue)).get();
        System.out.println("Maior: " + maior);

        // 2. Dada uma lista de números inteiros, crie uma nova lista com os números maiores que 15. Dica: Utilize filter para filtrar os números maiores que 15.

        List<Integer> maiores15 = numeros.stream()
                .filter(n -> n > 15)
                .collect(Collectors.toList());
        System.out.println("Maiores que 15: " + maiores15);

        // 3. Dada uma lista de nomes, crie uma nova lista com todos os nomes em letras maiúsculas. Dica: Utilize map para transformar cada elemento.
        List<String> nomesMaiusculas = nomes.stream()
                .map(String::toLowerCase)
                        .collect(Collectors.toUnmodifiableList());
        System.out.println("Nomes: " + nomesMaiusculas);

        // 4. Dada uma lista de números inteiros, conte quantos números são pares. Dica: Utilize filter para filtrar os números pares e count para contar os elementos resultantes.
        Long pares = numeros.stream()
                .filter(n -> n % 2 == 0)
                .count();
        System.out.println("Numeros de pares: " + pares);

        // 5. Dada uma lista de Double que representa notas de estudantes, crie uma nova lista com as notas sem repetição. Dica: Utilize distinct para pegar apenas as notas sem repetição.
        List<Double> notasSemRepeticao = notas.stream()
                .distinct()
                .collect(Collectors.toList());
        System.out.println("Notas sem repeticao: " + notasSemRepeticao);
    }
}