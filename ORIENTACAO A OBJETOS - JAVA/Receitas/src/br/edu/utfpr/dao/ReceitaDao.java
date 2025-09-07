package br.edu.utfpr.dao;

import br.edu.utfpr.entidades.Receita;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ReceitaDao {


    private List<Receita> listaReceitas;

    public ReceitaDao() {
        listaReceitas = new ArrayList<>();
    }

    public void inserirReceita(Receita receita) {
        listaReceitas.add(receita);
    }

    public boolean excluirReceitaPorNome(String nomeReceita) {
        if(!listaReceitas.isEmpty()){
            for(Receita receita : listaReceitas) {
                if(receita.getNome().equalsIgnoreCase(nomeReceita)) {
                    listaReceitas.remove(receita);
                    return true;
                }
            }
        }

        return false;
    }

    public void ordenarReceitasPorTempoDePreparo(){
        listaReceitas.sort((r1, r2) -> {
            return r1.getTempoPreparo() < r2.getTempoPreparo() ? 1 : 0;
        });
    }

    public Receita pesquisarReceitaPorNome(String nomeReceita) {
        if(!listaReceitas.isEmpty()){
            for(Receita receita : listaReceitas) {
                if(receita.getNome().equalsIgnoreCase(nomeReceita)) {
                    return receita;
                }
            }
        }
        return null;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("\n");
        for(Receita receita : listaReceitas){
            str.append(receita).append("\n");
        }

        return str.toString();
    }

}
