package br.com.service;

import br.com.dao.TemaDao;
import br.com.model.Tema;
import jakarta.persistence.EntityManager;


public class TemaService extends GenericService<Tema> {

    public TemaService(EntityManager manager) {
        super(new TemaDao(manager));
    }
}
