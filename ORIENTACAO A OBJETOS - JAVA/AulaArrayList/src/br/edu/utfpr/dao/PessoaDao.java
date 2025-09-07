package br.edu.utfpr.dao;

import br.edu.utfpr.entidades.Pessoa;

import java.util.ArrayList;
import java.util.List;

public class PessoaDao {

    private List<Pessoa> pessoas;

    public PessoaDao() {
        pessoas = new ArrayList();
    }

    public void inserir(Pessoa pessoa) {
        pessoas.add(pessoa);
    }

    public String imprimir() {
        StringBuilder str = new StringBuilder("\n");
        pessoas.forEach(pessoa -> str.append(pessoa).append("\n"));

        return str.toString();
    }

    public Boolean excluirPorIdArray(int id){
        if(pessoas.isEmpty()){
            return false;
        }
        pessoas.remove(id);
        return true;
    }

    public boolean excluirPorIdPessoa(int codigo){

        if(!pessoas.isEmpty()){
            for(Pessoa pessoa : pessoas){
                if(pessoa.getId() == codigo){
                    pessoas.remove(pessoa);
                    return true;
                }
            }
        }

        return false;
    }

    public Pessoa pesquisar(String nome){
        for(Pessoa pessoa : pessoas) {
            if(pessoa.getNome().equalsIgnoreCase(nome)){
                return pessoa;
            }
        }

        return null;
    }

}
