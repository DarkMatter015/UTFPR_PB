package br.com.vo;

import java.io.Serializable;

public class RelatorioPresencaRepresentanteVo implements Serializable {

    private static final long serialVersionUID = 1L;

    private String nomeRepresentante;
    private String paisOrigem;
    private Long totalPresidencias;

    public RelatorioPresencaRepresentanteVo() {
    }

    public RelatorioPresencaRepresentanteVo(String nomeRepresentante, String paisOrigem, Long totalPresidencias) {
        this.nomeRepresentante = nomeRepresentante;
        this.paisOrigem = paisOrigem;
        this.totalPresidencias = totalPresidencias;
    }

    public String getNomeRepresentante() {
        return nomeRepresentante;
    }

    public void setNomeRepresentante(String nomeRepresentante) {
        this.nomeRepresentante = nomeRepresentante;
    }

    public String getPaisOrigem() {
        return paisOrigem;
    }

    public void setPaisOrigem(String paisOrigem) {
        this.paisOrigem = paisOrigem;
    }

    public Long getTotalPresidencias() {
        return totalPresidencias;
    }

    public void setTotalPresidencias(Long totalPresidencias) {
        this.totalPresidencias = totalPresidencias;
    }

    @Override
    public String toString() {
        return "Representante: " + nomeRepresentante +
                " - País de Origem: " + paisOrigem +
                " - Reuniões Presididas: " + totalPresidencias;
    }
}
