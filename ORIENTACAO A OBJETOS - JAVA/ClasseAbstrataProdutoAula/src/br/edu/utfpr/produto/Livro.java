/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.produto;

/**
 *
 * @author Andreia
 */
public class Livro extends Produto {
    private String autor;
    
    // Construtor
    public Livro(String nome, double preco, String autor) {
        super(nome, preco);
        this.autor = autor;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    @Override
    public String toString() {
        return super.toString() +  "\nAutor: " + autor ;
    }

    @Override
    public double calcularDesconto() {
        return super.getPreco() * 0.1;
    }
    

}
