/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author User
 */
public class Macaco extends Animal {

    public Macaco() {
    }

    public Macaco(String nome, int idade) {
        super(nome, idade);
    }



    @Override
    public String getTipo() {
        return "macaco";
    }
    @Override
    public String emitirSom() {
        return "uhu ahah uhu ahah";
    }

    public String subir(){
        return super.getNome() + " subindo em árvore.";
    }

    @Override
    public String toString() {
        return super.toString();
    }

}
