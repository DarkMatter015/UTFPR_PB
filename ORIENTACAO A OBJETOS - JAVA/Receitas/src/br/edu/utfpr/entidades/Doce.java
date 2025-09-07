package br.edu.utfpr.entidades;

import br.edu.utfpr.enuns.Dificuldade;

public class Doce extends Receita{
    private boolean possuiAcucar;

    public Doce() {
        super();
    }

    public Doce(String nome, int tempoPreparo, Dificuldade dificuldade, boolean possuiAcucar) {
        super(nome, tempoPreparo, dificuldade);
        this.possuiAcucar = possuiAcucar;
    }

    public boolean isPossuiAcucar() {
        return possuiAcucar;
    }

    public void setPossuiAcucar(boolean possuiAcucar) {
        this.possuiAcucar = possuiAcucar;
    }

    @Override
    public String toString(){
        return "\n" + this.possuiAcucar;
    }

}
