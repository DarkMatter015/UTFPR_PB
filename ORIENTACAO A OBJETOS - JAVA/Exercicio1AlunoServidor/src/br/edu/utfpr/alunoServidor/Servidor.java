/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.utfpr.alunoServidor;

/**
 *
 * @author Andreia
 */
public class Servidor extends Pessoa {
    private long siape;

    public Servidor() {
    }

    public Servidor(long siape, String nome, String email) {
        super(nome, email);
        this.siape = siape;
    }

    public long getSiape() {
        return siape;
    }

    public void setSiape(long siape) {
        this.siape = siape;
    }

    @Override
    public String toString() {
         return super.toString() + "\nSIAPE = " + getSiape();
    }
    
    
}
