package br.com.view;

import br.com.persistence.JsonPersistence;
import br.com.persistence.TextoPersistence;
import br.com.service.RelatoriosService;
import br.com.vo.RelatorioParticipacaoPaisVo;
import br.com.vo.RelatorioPresencaRepresentanteVo;
import br.com.vo.RelatorioTemasMaisDiscutidosVo;
import jakarta.persistence.EntityManager;

import java.util.List;

import static br.com.util.ViewUtil.exibirMensagem;
import static br.com.util.ViewUtil.lerOpcao;

public class RelatoriosView{

    private final RelatoriosService service;

    public RelatoriosView(EntityManager manager) {
        this.service = new RelatoriosService(manager);
    }

    private void exibirMenu() {
        System.out.println("""
            === RELATÓRIOS ===
            1. Participação por País
            2. Temas mais discutidos
            3. Presença por Representante
            0. Voltar
            """);
    }

    private void imprimeMenuRelatorio() {
        System.out.println("""
            O que deseja fazer com o relatório?
            1. Salvar em Texto (.txt)
            2. Salvar em JSON (.json)
            3. Carregar de Texto (.txt)
            4. Carregar de JSON (.json)
            0. Cancelar
            """);
    }

    public void iniciar() {
        int opcao;
        do {
            exibirMenu();
            opcao = lerOpcao();
            processarOpcao(opcao);
        } while (opcao != 0);
    }

    private void processarOpcao(int opcao) {
        switch (opcao) {
            case 1 -> relatorioParticipacaoPais(service.gerarRelatorioParticipacao(), "relatorio_participacao");
            case 2 -> relatorioTemasMaisDiscutidos(service.gerarRelatorioTemasMaisDiscutidos(), "relatorio_temas");
            case 3 -> relatorioPresencaRepresentante(service.gerarRelatorioPresenca(), "relatorio_presenca");
            case 0 -> exibirMensagem("Voltando...");
            default -> exibirMensagem("Opção inválida!");
        }
    }

    private void relatorioParticipacaoPais(List<RelatorioParticipacaoPaisVo> lista, String nomeBase) {
        if (lista == null || lista.isEmpty()) {
            exibirMensagem("Nenhum dado encontrado para exportar.");
            return;
        }

        imprimeMenuRelatorio();
        int opcao = lerOpcao();

        JsonPersistence<RelatorioParticipacaoPaisVo> persistenciaJSON;
        TextoPersistence<RelatorioParticipacaoPaisVo> persistenciaTexto;
        String caminhoArquivo;

        switch (opcao) {
            case 1 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.salvar(lista, caminhoArquivo);
            }
            case 2 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioParticipacaoPaisVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.salvar(lista, caminhoArquivo);
            }
            case 3 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.carregarRelatorioParticipacaoPais(caminhoArquivo);
            }
            case 4 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioParticipacaoPaisVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.carregar(caminhoArquivo);
            }
            case 0 -> exibirMensagem("Exportação cancelada.");
            default -> exibirMensagem("Opção inválida.");
        }

    }

    private void relatorioTemasMaisDiscutidos(List<RelatorioTemasMaisDiscutidosVo> lista, String nomeBase) {
        if (lista == null || lista.isEmpty()) {
            exibirMensagem("Nenhum dado encontrado para exportar.");
            return;
        }

        imprimeMenuRelatorio();

        int opcao = lerOpcao();

        JsonPersistence<RelatorioTemasMaisDiscutidosVo> persistenciaJSON;
        TextoPersistence<RelatorioTemasMaisDiscutidosVo> persistenciaTexto;
        String caminhoArquivo;

        switch (opcao) {
            case 1 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.salvar(lista, caminhoArquivo);
            }
            case 2 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioTemasMaisDiscutidosVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.salvar(lista, caminhoArquivo);
            }
            case 3 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.carregarRelatorioTemasMaisDiscutidos(caminhoArquivo);
            }
            case 4 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioTemasMaisDiscutidosVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.carregar(caminhoArquivo);
            }
            case 0 -> exibirMensagem("Exportação cancelada.");
            default -> exibirMensagem("Opção inválida.");
        }
    }

    private void relatorioPresencaRepresentante(List<RelatorioPresencaRepresentanteVo> lista, String nomeBase) {
        if (lista == null || lista.isEmpty()) {
            exibirMensagem("Nenhum dado encontrado para exportar.");
            return;
        }

        imprimeMenuRelatorio();

        int opcao = lerOpcao();

        JsonPersistence<RelatorioPresencaRepresentanteVo> persistenciaJSON;
        TextoPersistence<RelatorioPresencaRepresentanteVo> persistenciaTexto;
        String caminhoArquivo;

        switch (opcao) {
            case 1 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.salvar(lista, caminhoArquivo);
            }
            case 2 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioPresencaRepresentanteVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.salvar(lista, caminhoArquivo);
            }
            case 3 -> {
                persistenciaTexto = new TextoPersistence<>();
                caminhoArquivo = nomeBase + ".txt";
                persistenciaTexto.carregarRelatorioPresencaRepresentante(caminhoArquivo);
            }
            case 4 -> {
                persistenciaJSON = new JsonPersistence<>(RelatorioPresencaRepresentanteVo.class);
                caminhoArquivo = nomeBase + ".json";
                persistenciaJSON.carregar(caminhoArquivo);
            }
            case 0 -> exibirMensagem("Exportação cancelada.");
            default -> exibirMensagem("Opção inválida.");
        }
    }


}
