package br.com.model;

import java.io.Serializable;

public class Produto implements Serializable {

    private String nome;
    private double valorUnitario;
    private double quantidade;
    private transient double total;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getValorUnitario() {
        return valorUnitario;
    }

    public void setValorUnitario(double valorUnitario) {
        this.valorUnitario = valorUnitario;
    }

    public double getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(double quantidade) {
        this.quantidade = quantidade;
    }

    public double getTotal(){
        double total = valorUnitario * quantidade;

        return total;
    }

    @Override
    public String toString() {
        return "Produto{" +
                "nome='" + nome + '\'' +
                ", valorUnitario=" + valorUnitario +
                ", quantidade=" + quantidade +
                '}';
    }
}
