package br.com.view;

import jakarta.persistence.EntityManager;

import static br.com.util.ViewUtil.exibirMensagem;
import static br.com.util.ViewUtil.lerOpcao;

public class MainView {
    private static MainView instancia;
    private final EntityManager manager;

    private MainView(EntityManager manager) {
        this.manager = manager;
    }

    public static MainView getInstance(EntityManager manager) {
        if (instancia == null) {
            instancia = new MainView(manager);
        }
        return instancia;
    }

    public void iniciar() {
        int opcao;
        do {
            exibirMenu();
            opcao = lerOpcao();
            processarOpcao(opcao);
        } while (opcao != 0);
    }

    private static void exibirMenu() {
        System.out.println("""
                
                --- Gerenciador de Reuniões Internacionais ---
                Selecione o menu que deseja acessar:
                1. Idioma
                2. Pais
                3. Representante
                4. Tema
                5. Reuniao
                6. Relatórios Gerais
                0. Sair\s""");
    }

    private void processarOpcao(int opcao) {
        switch (opcao) {
            case 1 -> new IdiomaView(manager).iniciar();
            case 2 -> new PaisView(manager).iniciar();
            case 3 -> new RepresentanteView(manager).iniciar();
            case 4 -> new TemaView(manager).iniciar();
            case 5 -> new ReuniaoView(manager).iniciar();
            case 6 -> new RelatoriosView(manager).iniciar();
            case 0 -> exibirMensagem("Saindo...");
            default -> exibirMensagem("Opção inválida!");
        }
    }
}
