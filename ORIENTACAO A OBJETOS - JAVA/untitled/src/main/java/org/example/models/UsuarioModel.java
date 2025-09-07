package org.example.models;

import org.example.enums.TipoAcessoEnum;

import java.util.List;

public class UsuarioModel {
    private int id;
    private String nome;
    private String email;
    private String senha;
    private TipoAcessoEnum tipoAcesso;
    private List<NotificacaoModel> notificacoes;

    public UsuarioModel() {}

    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public TipoAcessoEnum getTipoAcesso() {
        return tipoAcesso;
    }

    public void setTipoAcesso(TipoAcessoEnum tipoAcesso) {
        this.tipoAcesso = tipoAcesso;
    }

    public List<NotificacaoModel> getNotificacoes() {
        return notificacoes;
    }

    public void setNotificacoes(List<NotificacaoModel> notificacoes) {
        this.notificacoes = notificacoes;
    }

    public UsuarioModel validaLogin(String email, String senha) {
        return this;
    }

    public boolean validaNumeroSessoes(UsuarioModel usuario) {
        return true;
    }

    public UsuarioModel criaSessao() {
        return this;
    }

    @Override
    public String toString() {
        return "UsuarioModel{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", email='" + email + '\'' +
                ", senha='" + senha + '\'' +
                ", tipoAcesso=" + tipoAcesso +
                ", notificacoes=" + notificacoes +
                '}';
    }
}
