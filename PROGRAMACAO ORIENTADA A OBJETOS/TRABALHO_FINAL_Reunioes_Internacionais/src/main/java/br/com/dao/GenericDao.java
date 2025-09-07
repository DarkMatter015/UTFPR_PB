package br.com.dao;

import br.com.exception.DataAccessException;
import br.com.exception.NotFoundException;
import jakarta.persistence.EntityManager;
import jakarta.persistence.NoResultException;

import java.util.List;

public abstract class GenericDao<T> {

    protected EntityManager manager;

    private final Class<T> entityClass;

    public GenericDao(Class<T> entityClass, EntityManager manager) {
        this.entityClass = entityClass;
        this.manager = manager;
    }

    public void cadastrar(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.persist(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao cadastrar entidade: " + e.getClass().getSimpleName(), e);
        }
    }


    public void atualizar(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.merge(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao atualizar entidade: " + e.getClass().getSimpleName(), e);
        }
    }


    public void remover(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.remove(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao remover entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public T buscarPorId(Long id) {
        try {
            return this.manager.find(entityClass, id);
        } catch (Exception e) {
            throw new NotFoundException("Erro ao buscar o id: " + id
                    + " da entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public T buscarPorNome(String nome) {
        try {
            String jpql = "SELECT e FROM " + entityClass.getSimpleName() + " e WHERE LOWER(e.nome) LIKE LOWER(:nome)";
            return this.manager.createQuery(jpql, entityClass)
                    .setParameter("nome", "%" + nome + "%")
                    .getSingleResult();
        } catch (NoResultException e) {
            throw new NotFoundException("Erro ao buscar o nome " + nome + " da entidade: " + entityClass.getSimpleName(), e);
        }
    }

    public List<T> buscarTodos() {
        try {
            String jpql = "SELECT e FROM " + entityClass.getSimpleName() + " e";

            return manager.createQuery(jpql, entityClass).getResultList();
        } catch (Exception e) {
            throw new DataAccessException("Erro ao buscar todos os registros de: " + entityClass.getSimpleName(), e);
        }
    }
}
