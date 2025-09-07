package br.edu.utfpr.entidades;

import br.edu.utfpr.enums.TipoPagamento;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Venda {
    private LocalDate data;
    private Cliente cliente;
    private Vendedor vendedor;
    private TipoPagamento tipoPagamento;
    private List<ItemVenda> listaItensVenda;

    public Venda(LocalDate data, Cliente cliente, Vendedor vendedor, TipoPagamento tipoPagamento) {
        this.data = data;
        this.cliente = cliente;
        this.vendedor = vendedor;
        this.tipoPagamento = tipoPagamento;
        this.listaItensVenda = new ArrayList<>();
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Vendedor getVendedor() {
        return vendedor;
    }

    public void setVendedor(Vendedor vendedor) {
        this.vendedor = vendedor;
    }

    public TipoPagamento getTipoPagamento() {
        return tipoPagamento;
    }

    public void setTipoPagamento(TipoPagamento tipoPagamento) {
        this.tipoPagamento = tipoPagamento;
    }

    public List<ItemVenda> getListaItensVenda() {
        return listaItensVenda;
    }

    public void setListaItensVenda(List<ItemVenda> listaItensVenda) {
        this.listaItensVenda = listaItensVenda;
    }

    public void adicionarItemVenda(ItemVenda itemVenda) {
        this.listaItensVenda.add(itemVenda);

    }

    @Override
    public String toString() {
        return "data: " + data +
                "\ncliente: " + cliente +
                "\nvendedor: " + vendedor +
                "\ntipoPagamento: " + tipoPagamento +
                "\nlistaItensVenda: " + listaItensVenda;
    }
}
