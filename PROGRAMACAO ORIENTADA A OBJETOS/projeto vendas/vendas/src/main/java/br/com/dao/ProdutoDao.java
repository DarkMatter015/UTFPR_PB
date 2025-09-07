package br.com.dao;

import br.com.model.Produto;
import jakarta.persistence.EntityManager;

import java.util.List;

public class ProdutoDao extends GenericDao<Produto> {

    public ProdutoDao(EntityManager manager) {
        super(manager, Produto.class);
    }

    public List<Produto> buscarPorNome(String nome) {
        return this.manager.createQuery("SELECT p FROM Produto p WHERE LOWER(p.nome) = LOWER(:nome)")
                .setParameter("nome", nome)
                .getResultList();
    }

    public List<Produto> buscarPorIdCategoria(Long id) {
        return this.manager.createQuery("SELECT p from Produto p WHERE p.categoria.id = :id")
                .setParameter("id", id)
                .getResultList();
    }
    
}
