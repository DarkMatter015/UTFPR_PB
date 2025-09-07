package org.example.models;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class NotificacaoModel {
    private int id;
    private String mensagem;
    private LocalDateTime dataEnvio;
    private boolean lida;
    private List<ClienteModel> clientes = new ArrayList<>();
    private List<UsuarioModel> usuarios = new ArrayList<>();

    public NotificacaoModel() {
    }

    public int getId() {
        return id;
    }

    public String getMensagem() {
        return mensagem;
    }

    public void setMensagem(String mensagem) {
        this.mensagem = mensagem;
    }

    public LocalDateTime getDataEnvio() {
        return dataEnvio;
    }

    public void setDataEnvio(LocalDateTime dataEnvio) {
        this.dataEnvio = dataEnvio;
    }

    public boolean isLida() {
        return lida;
    }

    public void setLida(boolean lida) {
        this.lida = lida;
    }

    public List<ClienteModel> getClientes() {
        return clientes;
    }

    public void setClientes(List<ClienteModel> clientes) {
        this.clientes = clientes;
    }

    public List<UsuarioModel> getUsuarios() {
        return usuarios;
    }

    public void setUsuarios(List<UsuarioModel> usuarios) {
        this.usuarios = usuarios;
    }

    public boolean enviaEmailVerificacao(UsuarioModel usuario) {
        return true;
    }

    public boolean enviaEmailConfirmacao(UsuarioModel usuario) {
        return true;
    }

    @Override
    public String toString() {
        return "NotificacaoModel{" +
                "id=" + id +
                ", mensagem='" + mensagem + '\'' +
                ", dataEnvio=" + dataEnvio +
                ", lida=" + lida +
                ", clientes=" + clientes +
                ", usuarios=" + usuarios +
                '}';
    }
}
