package org.example.models;

public class ItemCarrinhoModel {
    private int id;
    private int quantidade;
    private double precoUnitario;
    private ProdutoModel produto;

    public ItemCarrinhoModel() {
    }

    public int getId() {
        return id;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPrecoUnitario() {
        return precoUnitario;
    }

    public void setPrecoUnitario(double precoUnitario) {
        this.precoUnitario = precoUnitario;
    }

    public ProdutoModel getProduto() {
        return produto;
    }

    public void setProduto(ProdutoModel produto) {
        this.produto = produto;
    }

    @Override
    public String toString() {
        return "ItemCarrinhoModel{" +
                "id=" + id +
                ", quantidade=" + quantidade +
                ", precoUnitario=" + precoUnitario +
                ", produto=" + produto +
                '}';
    }
}
