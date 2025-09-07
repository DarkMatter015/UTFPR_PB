package org.example.models;

import java.util.List;

public class CarrinhoModel {
    private int id;
    private ClienteModel cliente;
    private List<ItemCarrinhoModel> itens;

    public CarrinhoModel() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public ClienteModel getCliente() {
        return cliente;
    }

    public void setCliente(ClienteModel cliente) {
        this.cliente = cliente;
    }

    public List<ItemCarrinhoModel> getItens() {
        return itens;
    }

    public void setItens(List<ItemCarrinhoModel> itens) {
        this.itens = itens;
    }

    public List<ItemCarrinhoModel> listarItenscarrinho(int idUsuario) {
        return itens;
    }

    @Override
    public String toString() {
        return "CarrinhoModel{" +
                "id=" + id +
                ", cliente=" + cliente +
                ", itens=" + itens +
                '}';
    }
}
