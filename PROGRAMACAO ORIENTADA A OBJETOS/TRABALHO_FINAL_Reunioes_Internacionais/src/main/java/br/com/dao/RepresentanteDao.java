package br.com.dao;

import br.com.model.Representante;
import jakarta.persistence.EntityManager;

public class RepresentanteDao extends GenericDao<Representante> {

    public RepresentanteDao(EntityManager manager) {
        super(Representante.class, manager);
    }
}
