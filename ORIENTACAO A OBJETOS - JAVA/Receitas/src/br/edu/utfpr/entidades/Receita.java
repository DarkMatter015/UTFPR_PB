package br.edu.utfpr.entidades;

import br.edu.utfpr.enuns.Dificuldade;

import java.util.ArrayList;
import java.util.List;

public class Receita {
    private String nome;
    private int tempoPreparo;
    private Dificuldade dificuldade;
    private List<Ingrediente> listaIngredientes;

    public Receita() {
        this.listaIngredientes = new ArrayList();
    }

    public Receita(String nome, int tempoPreparo, Dificuldade dificuldade) {
        this.nome = nome;
        this.tempoPreparo = tempoPreparo;
        this.dificuldade = dificuldade;
        this.listaIngredientes = new ArrayList();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getTempoPreparo() {
        return tempoPreparo;
    }

    public void setTempoPreparo(int tempoPreparo) {
        this.tempoPreparo = tempoPreparo;
    }

    public Dificuldade getDificuldade() {
        return dificuldade;
    }

    public void setDificuldade(Dificuldade dificuldade) {
        this.dificuldade = dificuldade;
    }

    public List<Ingrediente> getListaIngredientes() {
        return listaIngredientes;
    }

    public void adicionarIngredientes(Ingrediente ingrediente){
        this.listaIngredientes.add(ingrediente);
    }

    @Override
    public String toString() {
        return "Receita: " + nome +
                " | Tempo de Preparo: " + tempoPreparo +
                " | Dificuldade: " + dificuldade;

    }
}
