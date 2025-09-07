package br.com.vo;

import java.io.Serializable;

public class RelatorioParticipacaoPaisVo implements Serializable {

    private static final long serialVersionUID = 1L;
    private String nomePais;
    private Long totalParticipacoes;

    public RelatorioParticipacaoPaisVo(){
    }

    public RelatorioParticipacaoPaisVo(String nomePais, Long totalParticipacoes) {
        this.nomePais = nomePais;
        this.totalParticipacoes = totalParticipacoes;
    }

    public String getNomePais() {
        return nomePais;
    }

    public void setNomePais(String nomePais) {
        this.nomePais = nomePais;
    }

    public Long getTotalParticipacoes() {
        return totalParticipacoes;
    }

    public void setTotalParticipacoes(Long totalParticipacoes) {
        this.totalParticipacoes = totalParticipacoes;
    }

    @Override
    public String toString() {
        return "País: " + nomePais +
                " - Total de Participações: " + totalParticipacoes;
    }
}
