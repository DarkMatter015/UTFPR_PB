package br.com.service;

import br.com.dao.RepresentanteDao;
import br.com.model.Representante;
import jakarta.persistence.EntityManager;


public class RepresentanteService extends GenericService<Representante> {

    public RepresentanteService(EntityManager manager) {
        super(new RepresentanteDao(manager));
    }
}
