/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author Andreia
 */
public class Vendedor extends Pessoa {
    private double comissao;

    public Vendedor() {
    }

    public Vendedor(double comissao, String nome, long cpf) {
        super(nome, cpf);
        this.comissao = comissao;
    }

    public double getComissao() {
        return comissao;
    }

    public void setComissao(double comissao) {
        this.comissao = comissao;
    }
    
    @Override
    public String toString() {
        return super.toString() + "\nComissão: " + comissao;
    }

}
