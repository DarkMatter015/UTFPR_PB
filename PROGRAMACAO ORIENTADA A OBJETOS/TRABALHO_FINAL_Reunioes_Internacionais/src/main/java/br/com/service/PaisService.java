package br.com.service;

import br.com.dao.PaisDao;
import br.com.model.Pais;
import jakarta.persistence.EntityManager;


public class PaisService extends GenericService<Pais> {

    public PaisService(EntityManager manager) {
        super(new PaisDao(manager));
    }
}
