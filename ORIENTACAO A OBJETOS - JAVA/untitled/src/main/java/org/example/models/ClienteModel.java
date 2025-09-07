package org.example.models;

import java.util.List;

public class ClienteModel {
    private int id;
    private String nome;
    private String cpf;
    private String telefone;
    private String email;
    private List<EnderecoModel> endereco;
    private List<ProdutoModel> favoritos;
    private CarrinhoModel carrinho;
    private List<PedidoModel> pedidos;
    private List<NotificacaoModel> notificacoes;

    public ClienteModel() {
    }

    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public List<EnderecoModel> getEndereco() {
        return endereco;
    }

    public void setEndereco(List<EnderecoModel> endereco) {
        this.endereco = endereco;
    }

    public List<ProdutoModel> getFavoritos() {
        return favoritos;
    }

    public void setFavoritos(List<ProdutoModel> favoritos) {
        this.favoritos = favoritos;
    }

    public CarrinhoModel getCarrinho() {
        return carrinho;
    }

    public void setCarrinho(CarrinhoModel carrinho) {
        this.carrinho = carrinho;
    }

    public List<PedidoModel> getPedidos() {
        return pedidos;
    }

    public void setPedidos(List<PedidoModel> pedidos) {
        this.pedidos = pedidos;
    }

    public List<NotificacaoModel> getNotificacoes() {
        return notificacoes;
    }

    public void setNotificacoes(List<NotificacaoModel> notificacoes) {
        this.notificacoes = notificacoes;
    }

    @Override
    public String toString() {
        return "ClienteModel{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", cpf='" + cpf + '\'' +
                ", telefone='" + telefone + '\'' +
                ", email='" + email + '\'' +
                ", endereco=" + endereco +
                ", favoritos=" + favoritos +
                ", carrinho=" + carrinho +
                ", pedidos=" + pedidos +
                ", notificacoes=" + notificacoes +
                '}';
    }
}
