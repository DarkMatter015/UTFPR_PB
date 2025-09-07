/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author User
 */
public class Cachorro extends Animal {

    public Cachorro() {
        
    }

    public Cachorro(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public String getTipo() {
        return "cahorro";
    }
    @Override
    public String emitirSom() {
        return "Au au au";
    }

    @Override
    public String toString() {
       return super.toString();
    }


}
