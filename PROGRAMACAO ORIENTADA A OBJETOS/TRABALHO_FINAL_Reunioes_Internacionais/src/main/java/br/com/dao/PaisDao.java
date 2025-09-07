package br.com.dao;

import br.com.model.Pais;
import jakarta.persistence.EntityManager;
import jakarta.transaction.Transactional;

import java.util.List;

public class PaisDao extends GenericDao<Pais> {

    public PaisDao(EntityManager manager) {
        super(Pais.class, manager);
    }

}
