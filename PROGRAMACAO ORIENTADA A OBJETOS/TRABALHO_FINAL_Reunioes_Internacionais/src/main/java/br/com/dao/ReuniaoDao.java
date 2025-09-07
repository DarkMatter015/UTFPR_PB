package br.com.dao;

import br.com.model.Reuniao;
import jakarta.persistence.EntityManager;



public class ReuniaoDao extends GenericDao<Reuniao> {

    public ReuniaoDao(EntityManager manager) {
        super(Reuniao.class, manager);
    }

}
