/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.produto;

/**
 *
 * @author Andreia
 */
public class Eletronico extends Produto {
      private String marca;
    
    // Construtor
    public Eletronico(String nome, double preco, String marca) {
        super(nome, preco);
        this.marca = marca;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    @Override
    public String toString() {
        return super.toString() + "\nMarca: " + marca;
    }

    @Override
    public double calcularDesconto() {
        return getPreco() * 0.05;
    }
    

}
