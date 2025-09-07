package br.com.persistence;

import br.com.vo.RelatorioParticipacaoPaisVo;
import br.com.vo.RelatorioPresencaRepresentanteVo;
import br.com.vo.RelatorioTemasMaisDiscutidosVo;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class TextoPersistence<T> {

    public TextoPersistence() {
    }

    public void salvar(List<T> lista, String nomeArquivo) {
        if (lista != null && !lista.isEmpty()) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo, false))) {
                for (T objeto : lista) {
                    writer.write(objeto.toString());
                    writer.newLine();
                    writer.write("--------------------------------------------------------------------------------");
                    writer.newLine();
                }
                System.out.println("Arquivo salvo com sucesso: " + nomeArquivo);
            } catch (IOException e) {
                System.err.println("Erro ao salvar o arquivo: " + e.getMessage());
            }
        } else {
            System.out.println("Lista vazia! Nada a salvar.");
        }
    }

    public List<RelatorioParticipacaoPaisVo> carregarRelatorioParticipacaoPais(String nomeArquivo) {
        try (BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            List<RelatorioParticipacaoPaisVo> relatorios = new ArrayList<>();
            String linha;

            while ((linha = reader.readLine()) != null) {
                if (!linha.trim().isEmpty() && !linha.trim().contains("----")) {
                    StringBuilder texto = new StringBuilder();

                    texto.append(linha.trim());

                    relatorios.add(criaRelatorioParticipacaoPais(texto.toString()));
                }
            }

            System.out.println("Lista do Arquivo de Texto");
            System.out.println(relatorios);
            return relatorios;
        } catch (IOException e) {
            System.out.println("Erro ao carregar o arquivo: "+e.getMessage());
            return null;
        }
    }

    public List<RelatorioTemasMaisDiscutidosVo> carregarRelatorioTemasMaisDiscutidos(String nomeArquivo) {
        try (BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            List<RelatorioTemasMaisDiscutidosVo> relatorios = new ArrayList<>();
            String linha;

            while ((linha = reader.readLine()) != null) {
                if (!linha.trim().isEmpty() && !linha.trim().contains("----")) {
                    StringBuilder texto = new StringBuilder();

                    texto.append(linha.trim());

                    relatorios.add(criaRelatorioTemasMaisDiscutidos(texto.toString()));
                }
            }

            System.out.println("Lista do Arquivo de Texto");
            System.out.println(relatorios);
            return relatorios;
        } catch (IOException e) {
            System.out.println("Erro ao carregar o arquivo: "+e.getMessage());
            return null;
        }
    }

    public List<RelatorioPresencaRepresentanteVo> carregarRelatorioPresencaRepresentante(String nomeArquivo) {
        try (BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            List<RelatorioPresencaRepresentanteVo> relatorios = new ArrayList<>();
            String linha;

            while ((linha = reader.readLine()) != null) {
                if (!linha.trim().isEmpty() && !linha.trim().contains("----")) {
                    StringBuilder texto = new StringBuilder();

                    texto.append(linha.trim());

                    relatorios.add(criaRelatorioPresencaRepresentante(texto.toString()));
                }
            }

            System.out.println("Lista do Arquivo de Texto");
            System.out.println(relatorios);
            return relatorios;
        } catch (IOException e) {
            System.out.println("Erro ao carregar o arquivo: "+e.getMessage());
            return null;
        }
    }

    private RelatorioParticipacaoPaisVo criaRelatorioParticipacaoPais(String texto) {
    String[] partes = texto.split(" - ");
    String nomePais = partes[0].substring("País:".length()).trim();
    Long totalParticipacoes = Long.parseLong(partes[1].substring("Total de Participações:".length()).trim());

    return new RelatorioParticipacaoPaisVo(nomePais, totalParticipacoes);
    }

    private RelatorioPresencaRepresentanteVo criaRelatorioPresencaRepresentante(String texto) {
        String[] partes = texto.split(" - ");
        String nomeRepresentante = partes[0].substring("Representante:".length()).trim();
        String paisOrigem = partes[1].substring("País de Origem:".length()).trim();
        Long reunioesPresididas = Long.parseLong(partes[2].substring("Reuniões Presididas:".length()).trim());

        return new RelatorioPresencaRepresentanteVo(nomeRepresentante, paisOrigem, reunioesPresididas);
    }

    private RelatorioTemasMaisDiscutidosVo criaRelatorioTemasMaisDiscutidos(String texto) {
        String[] partes = texto.split(" - ");
        String nomeTema = partes[0].substring("Tema:".length()).trim();
        Long ocorrencias = Long.parseLong(partes[1].substring("Ocorrências:".length()).trim());

        return new RelatorioTemasMaisDiscutidosVo(nomeTema, ocorrencias);
    }
}
