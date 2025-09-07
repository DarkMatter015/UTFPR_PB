package org.example.models;

import java.time.LocalDateTime;

public class LogSistemaModel {
    private int id;
    private String acao;
    private LocalDateTime dataHora = LocalDateTime.now();
    private String entidadeAfetada;
    private UsuarioModel usuario;

    public LogSistemaModel() {
    }

    public int getId() {
        return id;
    }

    public String getAcao() {
        return acao;
    }

    public void setAcao(String acao) {
        this.acao = acao;
    }

    public LocalDateTime getDataHora() {
        return dataHora;
    }

    public void setDataHora(LocalDateTime dataHora) {
        this.dataHora = dataHora;
    }

    public String getEntidadeAfetada() {
        return entidadeAfetada;
    }

    public void setEntidadeAfetada(String entidadeAfetada) {
        this.entidadeAfetada = entidadeAfetada;
    }

    public UsuarioModel getUsuario() {
        return usuario;
    }

    public void setUsuario(UsuarioModel usuario) {
        this.usuario = usuario;
    }

    @Override
    public String toString() {
        return "LogSistemaModel{" +
                "id=" + id +
                ", acao='" + acao + '\'' +
                ", dataHora=" + dataHora +
                ", entidadeAfetada='" + entidadeAfetada + '\'' +
                ", usuario=" + usuario +
                '}';
    }
}
