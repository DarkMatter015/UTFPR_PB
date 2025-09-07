package org.example.models;

import java.util.ArrayList;
import java.util.List;

public class ProdutoModel {
    private int id;
    private String nome;
    private String descricao;
    private String marca;
    private int quantidade;
    private double precoCompra;
    private double precoVenda;
    private String imagemURL;
    private double desconto;
    private List<String> avaliacoes =  new ArrayList<String>();
    private CategoriaModel categoria;
    private String notaFiscal;

    public ProdutoModel() {
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

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getPrecoCompra() {
        return precoCompra;
    }

    public void setPrecoCompra(double precoCompra) {
        this.precoCompra = precoCompra;
    }

    public double getPrecoVenda() {
        return precoVenda;
    }

    public void setPrecoVenda(double precoVenda) {
        this.precoVenda = precoVenda;
    }

    public String getImagemURL() {
        return imagemURL;
    }

    public void setImagemURL(String imagemURL) {
        this.imagemURL = imagemURL;
    }

    public double getDesconto() {
        return desconto;
    }

    public void setDesconto(double desconto) {
        this.desconto = desconto;
    }

    public List<String> getAvaliacoes() {
        return avaliacoes;
    }

    public void setAvaliacoes(List<String> avaliacoes) {
        this.avaliacoes = avaliacoes;
    }

    public CategoriaModel getCategoria() {
        return categoria;
    }

    public void setCategoria(CategoriaModel categoria) {
        this.categoria = categoria;
    }

    public String getNotaFiscal() {
        return notaFiscal;
    }

    public void setNotaFiscal(String notaFiscal) {
        this.notaFiscal = notaFiscal;
    }

    public boolean validarCampo(String campo) {
        return campo != null && !campo.isEmpty();
    }

    public boolean validaPrecos(double precoCompra, double precoVenda) {
        return precoVenda >= precoCompra;
    }

    public boolean validaImagem(String imagem) {
        return imagem != null && !imagem.isEmpty();
    }

    public boolean validaQuantidade(int quantidadeProduto) {
        return quantidadeProduto >= 1;
    }

    public boolean validaNotaFiscal(String notaFiscal) {
        return notaFiscal != null && !notaFiscal.isEmpty();
    }

    public void cadastrarProduto(ProdutoModel produto) {
    }

    public List<ProdutoModel> consultaProdutos() {
        List<ProdutoModel> produtos = new ArrayList<ProdutoModel>();
        return produtos;
    }

    public ProdutoModel buscaProduto(int idProduto) {
        ProdutoModel produto = new ProdutoModel();
        return produto;
    }

    public boolean salvarProduto(ProdutoModel produto) {
        return produto != null;
    }

    public boolean excluirProduto(int idProduto) {
        return idProduto > 0;
    }

    @Override
    public String toString() {
        return "ProdutoModel{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", descricao='" + descricao + '\'' +
                ", marca='" + marca + '\'' +
                ", quantidade=" + quantidade +
                ", precoCompra=" + precoCompra +
                ", precoVenda=" + precoVenda +
                ", imagemURL='" + imagemURL + '\'' +
                ", desconto=" + desconto +
                ", avaliacoes=" + avaliacoes +
                ", categoria=" + categoria +
                ", notaFiscal='" + notaFiscal + '\'' +
                '}';
    }
}
