/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.uttfpr.main;


import br.edu.utfpr.entidades.Animal;
import br.edu.utfpr.entidades.Cachorro;
import br.edu.utfpr.entidades.Gato;
import br.edu.utfpr.entidades.Macaco;

/**
 *
 * @author andre
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Animal animal;

        System.out.println("---- CACHORRO ----");
        animal = new Cachorro("Bob", 4);

        System.out.println("---- GATO ----");
        animal = new Gato("Pepe", 3);

        System.out.println("---- MACACO ----");
        animal = new Macaco("Pedro", -4);

        

    }

}
