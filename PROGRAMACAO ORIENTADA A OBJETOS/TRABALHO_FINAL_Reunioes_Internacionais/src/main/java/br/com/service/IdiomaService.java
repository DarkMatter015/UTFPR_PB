package br.com.service;

import br.com.dao.IdiomaDao;
import br.com.model.Idioma;
import jakarta.persistence.EntityManager;


public class IdiomaService extends GenericService<Idioma> {
    
    public IdiomaService(EntityManager manager) {
        super(new IdiomaDao(manager));
    }
}
