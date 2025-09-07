package org.example.models;

public class CategoriaModel {
    private int id;
    private String nome;
    private String descricao;

    public CategoriaModel() {
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

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public CategoriaModel verificaCategoria(int idCategoria) {
        return this;
    }

    @Override
    public String toString() {
        return "CategoriaModel{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", descricao='" + descricao + '\'' +
                '}';
    }
}
