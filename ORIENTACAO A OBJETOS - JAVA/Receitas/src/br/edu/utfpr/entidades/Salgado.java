package br.edu.utfpr.entidades;

import br.edu.utfpr.enuns.Dificuldade;

public class Salgado extends Receita{
    private String tipoProteina;

    public Salgado(){
        super();
    }

    public Salgado(String nome, int tempoPreparo, Dificuldade dificuldade, String tipoProteina) {
        super(nome, tempoPreparo, dificuldade);
        this.tipoProteina = tipoProteina;
    }

    public String getTipoProteina() {
        return this.tipoProteina;
    }

    public void setTipoProteina(String tipoProteina) {
        this.tipoProteina = tipoProteina;
    }

    @Override
    public String toString(){
        return "\n" + this.tipoProteina;
    }
}
