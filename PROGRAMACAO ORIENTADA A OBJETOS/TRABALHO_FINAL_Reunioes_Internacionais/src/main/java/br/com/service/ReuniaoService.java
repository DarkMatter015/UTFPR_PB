package br.com.service;

import br.com.dao.ReuniaoDao;
import br.com.model.Reuniao;
import jakarta.persistence.EntityManager;



public class ReuniaoService extends GenericService<Reuniao> {

    private ReuniaoDao reuniaoDao;

    public ReuniaoService(EntityManager manager) {
        super(new ReuniaoDao(manager));
        this.reuniaoDao = new ReuniaoDao(manager);
    }

}
