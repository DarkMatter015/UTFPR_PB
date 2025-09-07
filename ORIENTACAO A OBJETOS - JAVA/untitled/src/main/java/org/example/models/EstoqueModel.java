package org.example.models;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class EstoqueModel {
    private int id;
    private int quantidade;
    private LocalDateTime ultimaAtualizacao;
    private List<ProdutoModel> produtos;
    private List<UsuarioModel> usuarios;
    private char tipoMovimentacao;

    public EstoqueModel() {}

    public int getId() {
        return id;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public LocalDateTime getUltimaAtualizacao() {
        return ultimaAtualizacao;
    }

    public void setUltimaAtualizacao(LocalDateTime ultimaAtualizacao) {
        this.ultimaAtualizacao = ultimaAtualizacao;
    }

    public List<ProdutoModel> getProdutos() {
        return produtos;
    }

    public void setProdutos(List<ProdutoModel> produtos) {
        this.produtos = produtos;
    }

    public List<UsuarioModel> getUsuarios() {
        return usuarios;
    }

    public void setUsuarios(List<UsuarioModel> usuarios) {
        this.usuarios = usuarios;
    }

    public char getTipoMovimentacao() {
        return tipoMovimentacao;
    }

    public void setTipoMovimentacao(char tipoMovimentacao) {
        this.tipoMovimentacao = tipoMovimentacao;
    }

    public List<ProdutoModel> filtraNomeCategoria(String nome, String categoria) {
        return produtos;
    }
}
