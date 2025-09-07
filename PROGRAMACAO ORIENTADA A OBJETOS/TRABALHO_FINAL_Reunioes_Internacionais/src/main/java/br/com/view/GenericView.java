package br.com.view;

import br.com.interfaces.ServiceInterface;

import java.util.List;

import static br.com.util.ViewUtil.*;

public abstract class GenericView<T> {

    protected final ServiceInterface<T> service;
    private final String titulo;

    protected GenericView(ServiceInterface<T> service, String titulo) {
        this.service = service;
        this.titulo = titulo.toUpperCase();
    }

    public void iniciar() {
        int opcao;
        do {
            exibirMenu();
            opcao = lerOpcao();
            processarOpcao(opcao);
        } while (opcao != 0);
    }

    protected void exibirMenu() {
        System.out.printf("""
                
                === %s ===
                1. Cadastrar
                2. Alterar
                3. Excluir
                4. Buscar por ID
                5. Buscar por Nome
                6. Listar Todos
                0. Voltar\s
                """, titulo);
    }

    protected void processarOpcao(int opcao) {
        switch (opcao) {
            case 1 -> adicionar();
            case 2 -> alterar();
            case 3 -> remover();
            case 4 -> buscarPorId();
            case 5 -> buscarPorNome();
            case 6 -> listar();
            case 0 -> exibirMensagem("Voltando...");
            default -> exibirMensagem("Opção inválida!");
        }
    }


    protected void adicionar() {
        System.out.printf("\n=== Cadastrar %s ===\n", titulo);
        T entidade = criarEntidade();
        service.inserir(entidade);
    }

    protected void alterar() {
        System.out.printf("\n=== Alterar %s ===\n", titulo);
        Long id = lerID("ID: ");
        T entidade = service.buscarPorId(id);
        if (entidade != null) {
            atualizarEntidade(entidade);
            service.alterar(entidade);
        } else {
            exibirMensagem("Entidade não encontrada.");
        }
    }

    protected void remover() {
        System.out.printf("\n=== Excluir %s ===\n", titulo);
        Long id = lerID("ID: ");
        service.excluir(id);
    }

    protected void buscarPorId() {
        System.out.printf("\n=== Buscar %s por ID ===\n", titulo);
        Long id = lerID("ID: ");
        System.out.println(service.buscarPorId(id));
    }

    protected void buscarPorNome() {
        System.out.printf("\n=== Buscar %s por Nome ===\n", titulo);
        String nome = lerString("Nome: ");
        System.out.println(service.buscarPorNome(nome));
    }

    protected void listar() {
        System.out.printf("\n=== Listar %s ===\n", titulo);
        List<T> lista = service.listar();
        lista.forEach(System.out::println);
    }


    protected abstract T criarEntidade();
    protected abstract void atualizarEntidade(T entidade);
}
