package br.com.dao;

import br.com.model.Cliente;
import jakarta.persistence.EntityManager;


public class ClienteDao extends GenericDao<Cliente> {

    public ClienteDao(EntityManager manager) {
        super(manager, Cliente.class);
    }
}
