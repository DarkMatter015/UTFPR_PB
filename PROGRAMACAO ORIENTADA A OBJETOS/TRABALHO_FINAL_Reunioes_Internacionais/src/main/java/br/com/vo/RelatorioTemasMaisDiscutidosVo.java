package br.com.vo;

import java.io.Serializable;

public class RelatorioTemasMaisDiscutidosVo implements Serializable {

    private static final long serialVersionUID = 1L;
    private String nomeTema;
    private Long ocorrencias;

    public RelatorioTemasMaisDiscutidosVo() {
    }

    public RelatorioTemasMaisDiscutidosVo(String nomeTema, Long ocorrencias) {
        this.nomeTema = nomeTema;
        this.ocorrencias = ocorrencias;
    }

    public String getNomeTema() {
        return nomeTema;
    }

    public void setNomeTema(String nomeTema) {
        this.nomeTema = nomeTema;
    }

    public Long getOcorrencias() {
        return ocorrencias;
    }

    public void setOcorrencias(Long ocorrencias) {
        this.ocorrencias = ocorrencias;
    }

    @Override
    public String toString() {
        return "Tema: " + nomeTema +
                " - Ocorrências: " + ocorrencias;
    }
}
