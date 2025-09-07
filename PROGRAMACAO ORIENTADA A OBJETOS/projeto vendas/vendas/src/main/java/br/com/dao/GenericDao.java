package br.com.dao;

import br.com.exception.DataAccessException;
import jakarta.persistence.EntityManager;

import java.util.List;

// Classe genérica para operações CRUD no banco de dados.
// <T>: parametro de tipo genérico, representa um tipo que será definido quando a classe for instanciada ou herdada.
// Esse T que pode ser qualquer letra ou palavra, mas por convenção usa-se T para "Type".
// O <T> indica que essa classe é genérica e pode trabalhar com qualquer tipo de entidade. Isso permite que a mesma
// implementação seja reutilizada para diferentes classes de entidade sem precisar reescrever o código para cada uma.
public abstract class GenericDao<T> {

    protected EntityManager manager;

    private final Class<T> entityClass;

    public GenericDao(EntityManager manager, Class<T> entityClass) {
        this.manager = manager;
        this.entityClass = entityClass;
    }

    public void cadastrar(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.persist(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao cadastrar a entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public void atualizar(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.merge(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao atualizar a entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public void remover(T entity) {
        try {
            this.manager.getTransaction().begin();
            this.manager.remove(entity);
            this.manager.getTransaction().commit();
        } catch (Exception e) {
            this.manager.getTransaction().rollback();
            throw new DataAccessException("Erro ao remover a entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public T buscarPorId(Long id) {
        try {
            return this.manager.find(entityClass, id);
        } catch (Exception e) {
            throw new DataAccessException("Erro ao buscar o id: " + id
                    + " da entidade: " + e.getClass().getSimpleName(), e);
        }
    }

    public List<T> buscarTodos() {
        try {
            // Monta uma consulta JPQL para buscar todas as entidades.
            String jpql = "SELECT e FROM " + entityClass.getSimpleName() + " e";

            return manager.createQuery(jpql, entityClass).getResultList();

        } catch (Exception e) {
            throw new DataAccessException("Erro ao buscar todos de: " + entityClass.getSimpleName(), e);
        }
    }
}
