package br.edu.utfpr.dao;


import br.edu.utfpr.contato.Contato;

import java.util.ArrayList;
import java.util.List;

public class ContatoDao {
    public List<Contato> contatos = new ArrayList();

    public ContatoDao() {
        contatos = new ArrayList<>();
    }

    public void adicionar(Contato contato){
        contatos.add(contato);
    }

    public String imprimir(){
        StringBuilder str = new StringBuilder("\n");
        for(Contato contato : contatos){
            str.append(contato).append("\n");
        }

        return str.toString();
    }

    // ORDENAR

    public boolean excluirPorId(int id){

        if(!contatos.isEmpty()){
            for(int i = 0; i < contatos.size(); i++){
                if(contatos.get(i).getId() == id){
                    contatos.remove(contatos.indexOf(contatos.get(i)));
                    return true;
                }
            }
        }

        return false;
    }

    public Contato pesquisarPorNome(String nome){

        for(Contato contato : contatos){
            if(contato.getNome().equals(nome)){
                return contato;
            }
        }

        return null;
    }

    public void ordenar(){
        contatos.sort((c1, c2) -> {
            return c1.getNome().compareToIgnoreCase(c2.getNome());
        });
    }

    public List<Contato> pesquisarContatoPorSubstring(String substring){
        String substringLower = substring.toLowerCase();
        List<Contato> resultado = new ArrayList<>();
        contatos.forEach(contato -> {
            if(contato.getNome().toLowerCase().contains(substringLower)){
                resultado.add(contato);
            }
        });

        return resultado;
    }
}
