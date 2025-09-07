package br.com.service;

import br.com.dao.GenericDao;
import br.com.interfaces.ServiceInterface;

import java.util.List;

public abstract class GenericService<T> implements ServiceInterface<T> {

    protected final GenericDao<T> dao;

    public GenericService(GenericDao<T> dao) {
        this.dao = dao;
    }

    @Override
    public void inserir(T obj) {
        dao.cadastrar(obj);
    }

    @Override
    public void alterar(T obj) {
        dao.atualizar(obj);
    }

    @Override
    public void excluir(Long id) {
        T obj = dao.buscarPorId(id);

        if (obj != null) {
            dao.remover(obj);
        }
    }

    @Override
    public T buscarPorId(Long id) {
        return dao.buscarPorId(id);
    }

    @Override
    public T buscarPorNome(String nome) {
        return dao.buscarPorNome(nome);
    }

    @Override
    public List<T> listar() {
        return dao.buscarTodos();
    }
}
