package br.com.dao;

import br.com.model.Idioma;
import jakarta.persistence.EntityManager;

public class IdiomaDao extends GenericDao<Idioma> {

    public IdiomaDao(EntityManager manager) {
        super(Idioma.class, manager);
    }
}
