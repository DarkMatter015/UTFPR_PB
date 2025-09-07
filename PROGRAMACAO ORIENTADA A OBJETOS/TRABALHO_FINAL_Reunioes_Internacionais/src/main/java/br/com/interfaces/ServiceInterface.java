package br.com.interfaces;

import java.util.List;

public interface ServiceInterface<T>{

    void inserir(T obj);

    void alterar(T obj);

    void excluir(Long id);

    T buscarPorId(Long id);

    T buscarPorNome(String nome);

    List<T> listar();

}
