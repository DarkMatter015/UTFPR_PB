import br.com.dao.ProdutoDao;
import br.com.model.Produto;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Produto> produtos = new ArrayList<>();
        ProdutoDao produtoDao = new ProdutoDao();
        File arquivo = new File("produtos.dat");
        String entrada;

        do {
            System.out.println("\n--- Gerenciador de Lista de Compras ---");
            System.out.println("1. Adicionar Produto");
            System.out.println("2. Imprimir Lista");
            System.out.println("3. Salvar Lista em Arquivo");
            System.out.println("4. Carregar Lista de Arquivo");
            System.out.println("'s' para Sair");
            System.out.print("Escolha uma opção: ");

            entrada = scanner.nextLine();

            if (entrada.equalsIgnoreCase("s")) {
                System.out.println("Encerrando o programa...");
                break;
            }

            int opcao;
            try {
                opcao = Integer.parseInt(entrada);
            } catch (NumberFormatException e) {
                System.out.println("Opção inválida! Tente novamente.");
                continue;
            }

            switch (opcao) {
                case 1: // Adicionar Produto
                    System.out.print("Nome do produto: ");
                    String nome = scanner.nextLine();

                    try {
                        System.out.print("Valor unitário: ");
                        double valorUnitario = Double.parseDouble(scanner.nextLine());

                        System.out.print("Quantidade: ");
                        double quantidade = Double.parseDouble(scanner.nextLine());

                        Produto produto = new Produto();
                        produto.setNome(nome);
                        produto.setValorUnitario(valorUnitario);
                        produto.setQuantidade(quantidade);

                        produtos.add(produto);
                        System.out.println("Produto adicionado com sucesso!");

                    } catch (NumberFormatException e) {
                        System.out.println("Erro: Valores numéricos inválidos!");
                    }
                    break;

                case 2: // Imprimir Lista
                    if (produtos.isEmpty()) {
                        System.out.println("A lista está vazia!");
                    } else {
                        System.out.println("\n--- Lista de Produtos ---");
                        for (Produto p : produtos) {
                            System.out.println(p.toString() + " Total: R$ " + p.getTotal());
                        }
                    }
                    break;

                case 3: // Salvar Lista em Arquivo
                    if (produtos.isEmpty()) {
                        System.out.println("Não há produtos para salvar!");
                    } else {
                        produtoDao.gravarProdutosNoArquivo(arquivo, produtos);
                        System.out.println("Lista salva com sucesso!");
                    }
                    break;

                case 4: // Carregar Lista de Arquivo
                    String produtosLidos = produtoDao.leProdutoDoArquivo(arquivo);
                    if (produtosLidos.isEmpty()) {
                        System.out.println("Nenhum produto encontrado no arquivo!");
                    } else {
                        System.out.println("\n--- Produtos Carregados ---");
                        System.out.println(produtosLidos);
                        // Opcional: recarregar a lista em memória
                        produtos.clear();
                        try (ObjectInputStream data = new ObjectInputStream(new FileInputStream(arquivo))) {
                            produtos.addAll((List<Produto>) data.readObject());
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    break;

                default:
                    System.out.println("Opção inválida! Tente novamente.");
                    break;
            }
        } while (true);

        scanner.close();
    }
}