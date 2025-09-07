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
public class Aluno extends Pessoa {
    private long ra;

    public Aluno() {
    }

    public Aluno(long ra, String nome, String email) {
        super(nome, email);
        this.ra = ra;
    }

    public long getRa() {
        return ra;
    }

    public void setRa(long ra) {
        this.ra = ra;
    }

    @Override
    public String toString() {
        return super.toString() + "\nR.A = " + ra;
    }
    
    
}
