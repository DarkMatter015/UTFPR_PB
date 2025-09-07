package br.com.dao;

import br.com.exception.DataAccessException;
import br.com.model.Categoria;
import jakarta.persistence.EntityManager;

import java.util.List;

public class CategoriaDao extends GenericDao<Categoria> {

    public CategoriaDao(EntityManager manager) {
        super(manager, Categoria.class);
    }

    public List<Categoria> buscarPorNome(String nome) {
        try {
            return this.manager.createQuery("SELECT c FROM Categoria c WHERE c.nome = :nome")
                    .setParameter("nome", nome)
                    .getResultList();
        } catch (Exception e) {
            throw new DataAccessException("Erro ao buscar categorias por nome: " +
                    nome, e);
        }
    }
}
