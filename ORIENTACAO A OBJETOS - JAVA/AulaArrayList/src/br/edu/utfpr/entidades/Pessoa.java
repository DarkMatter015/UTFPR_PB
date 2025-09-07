/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author Andreia
 */
public abstract class Pessoa {
    
    /*
    A vari�vel contador deve ser static porque ela precisa manter o valor entre todas as inst�ncias 
    da classe em que est� sendo usada. 
    Ao torn�-la static, todas as inst�ncias da classe acessam o mesmo contador, 
    garantindo a continuidade dos IDs gerados.
    */
      private static int contador = 0; // Contador para gerar IDs �nicos
    private int id;
    private String nome;

    
    public Pessoa() {
        this.id = ++contador; // Incrementa o contador para gerar um novo ID
    }

    
    public Pessoa(String nome) {
        this.nome = nome;
        this.id = ++contador; // Incrementa o contador para gerar um novo ID
    }

    
    public void setNome(String nome) {
        this.nome = nome;
    }

    
    public int getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public abstract String tipo();

    @Override
    public String toString() {
        return "Id:" + id + ", Nome:" + nome;
    }
    
}
