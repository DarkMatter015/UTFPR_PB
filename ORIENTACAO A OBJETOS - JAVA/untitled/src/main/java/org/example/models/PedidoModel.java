package org.example.models;

import org.example.enums.MetodoPagamentoEnum;
import org.example.enums.StatusEnum;

import java.time.LocalDate;
import java.util.List;

public class PedidoModel {
    private int id;
    private LocalDate dataPedido;
    private StatusEnum status;
    private MetodoPagamentoEnum metodoPagamento;
    private double valorTotal;
    private String codigoRastreavel;
    private String cupom;
    private ClienteModel cliente;
    private EnderecoModel endereco;
    private List<ItemPedidoModel> itens;

    public PedidoModel() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public LocalDate getDataPedido() {
        return dataPedido;
    }

    public void setDataPedido(LocalDate dataPedido) {
        this.dataPedido = dataPedido;
    }

    public StatusEnum getStatus() {
        return status;
    }

    public void setStatus(StatusEnum status) {
        this.status = status;
    }

    public MetodoPagamentoEnum getMetodoPagamento() {
        return metodoPagamento;
    }

    public void setMetodoPagamento(MetodoPagamentoEnum metodoPagamento) {
        this.metodoPagamento = metodoPagamento;
    }

    public double getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(double valorTotal) {
        this.valorTotal = valorTotal;
    }

    public String getCodigoRastreavel() {
        return codigoRastreavel;
    }

    public void setCodigoRastreavel(String codigoRastreavel) {
        this.codigoRastreavel = codigoRastreavel;
    }

    public String getCupom() {
        return cupom;
    }

    public void setCupom(String cupom) {
        this.cupom = cupom;
    }

    public ClienteModel getCliente() {
        return cliente;
    }

    public void setCliente(ClienteModel cliente) {
        this.cliente = cliente;
    }

    public EnderecoModel getEndereco() {
        return endereco;
    }

    public void setEndereco(EnderecoModel endereco) {
        this.endereco = endereco;
    }

    public List<ItemPedidoModel> getItens() {
        return itens;
    }

    public void setItens(List<ItemPedidoModel> itens) {
        this.itens = itens;
    }

    public boolean validaExclusaoProduto(ProdutoModel produto) {
        return true;
    }

    public ProdutoModel buscaProdutoPedido(int idProduto) {
        return new ProdutoModel();
    }

    public void registrarPedido(String compra, String retornoOperadora) {
    }

    @Override
    public String toString() {
        return "PedidoModel{" +
                "id=" + id +
                ", dataPedido=" + dataPedido +
                ", status=" + status +
                ", metodoPagamento=" + metodoPagamento +
                ", valorTotal=" + valorTotal +
                ", codigoRastreavel='" + codigoRastreavel + '\'' +
                ", cupom='" + cupom + '\'' +
                ", cliente=" + cliente +
                ", endereco=" + endereco +
                ", itens=" + itens +
                '}';
    }
}
