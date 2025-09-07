package org.example.models;

import java.util.ArrayList;
import java.util.List;

public class FornecedorModel {
    private int id;
    private String nome;
    private String cnpj;
    private String telefone;
    private String email;
    private boolean integradoSistema;
    private List<ProdutoModel> produtoModels = new ArrayList<>();

    public FornecedorModel() {
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

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
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

    public boolean isIntegradoSistema() {
        return integradoSistema;
    }

    public void setIntegradoSistema(boolean integradoSistema) {
        this.integradoSistema = integradoSistema;
    }

    public List<ProdutoModel> getProdutos() {
        return produtoModels;
    }

    public void setProdutos(List<ProdutoModel> produtoModels) {
        this.produtoModels = produtoModels;
    }

    @Override
    public String toString() {
        return "FornecedorModel{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", cnpj='" + cnpj + '\'' +
                ", telefone='" + telefone + '\'' +
                ", email='" + email + '\'' +
                ", integradoSistema=" + integradoSistema +
                ", produtos=" + produtoModels +
                '}';
    }
}
