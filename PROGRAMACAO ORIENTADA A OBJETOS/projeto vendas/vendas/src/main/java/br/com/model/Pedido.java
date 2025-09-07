package br.com.model;

import jakarta.persistence.*;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "pedidos")
public class Pedido {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private LocalDate data = LocalDate.now();

    @Column(name = "valor_total")
    private BigDecimal valorTotal = BigDecimal.ZERO;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "cliente_id")
    private Cliente cliente;

    // coloca mappedBy na entidade que possui chave estrangeira
    @OneToMany(mappedBy = "pedido", cascade = CascadeType.ALL)
    private List<PedidoItem> itens = new ArrayList<>();

    public Pedido() {
    }

    public Pedido(Cliente cliente) {
        this.cliente = cliente;
    }

    // Metodo para adicionar um item ao pedido.
    public void adicionarItem(PedidoItem item) {
        item.setPedido(this); // Define a referência do pedido no item.
        this.getItens().add(item); // Adiciona o item à lista.
        processaValorTotal(); // Atualiza o valor total do pedido.
    }

    // Metodo para remover um item do pedido.
    public void removerItem(PedidoItem item) {
        this.getItens().remove(item); // Remove o item da lista.
        processaValorTotal(); // Atualiza o valor total do pedido.
    }


    public Long getId() {
        return id;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public BigDecimal getvalorTotal() {
        return valorTotal;
    }

    public void setvalorTotal(BigDecimal valorTotal) {
        this.valorTotal = valorTotal;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public List<PedidoItem> getItens() {
        return itens;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Pedido{")
                .append("id=").append(id)
                .append(", valorTotal=").append(valorTotal)
                .append(", data=").append(data)
                .append(", cliente=").append(cliente.getNome())
                .append(", itens=[");

        for (int i = 0; i < itens.size(); i++) {
            PedidoItem item = itens.get(i);
            sb.append("{")
                    .append("produto=").append(item.getProduto().getNome())
                    .append(", quantidade=").append(item.getQuantidade())
                    .append(", valor=").append(item.getValor())
                    .append("}");
            if (i < itens.size() - 1) {
                sb.append(", ");
            }
        }
        sb.append("]}");
        return sb.toString();
    }

    // Metodo privado para calcular e atualizar o valor total do pedido com base nos itens.
    private void processaValorTotal() {
        BigDecimal total = itens.stream() // Processa a lista de itens.
                .map(PedidoItem::getValor) // Mapeia os valores dos itens.
                .reduce(BigDecimal.ZERO, BigDecimal::add); // Soma os valores.
        this.valorTotal = total; // Atualiza o valor total do pedido.
    }
}
