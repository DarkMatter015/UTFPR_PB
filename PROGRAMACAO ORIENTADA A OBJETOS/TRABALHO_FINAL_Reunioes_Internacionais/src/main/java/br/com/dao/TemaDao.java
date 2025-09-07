package br.com.dao;

import br.com.model.Tema;
import jakarta.persistence.EntityManager;

public class TemaDao extends GenericDao<Tema> {

    public TemaDao(EntityManager manager) {
        super(Tema.class, manager);
    }
}
