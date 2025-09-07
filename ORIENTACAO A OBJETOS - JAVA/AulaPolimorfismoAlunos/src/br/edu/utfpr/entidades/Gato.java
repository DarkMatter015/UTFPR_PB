/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author User
 */
public class Gato extends Animal {

    public Gato() {
    }

    public Gato(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public String getTipo() {
        return "gato";
    }

    @Override
    public String emitirSom() {
        return "miau";
    }

    @Override
    public String toString() {
        return super.toString();
    }

}
