package br.com.dao;

import br.com.model.Pedido;
import br.com.model.PedidoItem;
import jakarta.persistence.EntityManager;

import java.time.LocalDate;
import java.util.List;

public class PedidoDao extends GenericDao<Pedido> {

    public PedidoDao(EntityManager manager) {
        super(manager, Pedido.class);
    }

    @Override
    public void cadastrar(Pedido entity) {
        if (entity.getItens().isEmpty())
            throw new RuntimeException("Pedido precisa de pelo menos um item");
        super.cadastrar(entity);
    }

    public void removerItem(PedidoItem pedidoItem) {
        this.manager.getTransaction().begin();
        this.manager.remove(pedidoItem);
        this.manager.getTransaction().commit();
    }

    public Pedido buscarPedidoPorId(Long id) {
            String jpql = "SELECT p FROM Pedido p WHERE p.id = :id";
            return this.manager.createQuery(jpql, Pedido.class)
                    .setParameter("id", id)
                    .getSingleResult();
    }

    public List<Pedido> buscarPedidosPorPeriodo(LocalDate dataIni, LocalDate dataFim) {
        return this.manager.createQuery("SELECT p FROM Pedido p WHERE p.data BETWEEN :dataIni AND :dataFim")
                .setParameter("dataIni", dataIni)
                .setParameter("dataFim", dataFim)
                .getResultList();
    }

    public List<Pedido> buscarPedidosPorIdDeCliente(Long id) {
        return this.manager.createQuery("SELECT p from Produto p WHERE p.categoria.id = :id")
                .setParameter("id", id)
                .getResultList();
    }
}
