package br.com.model;

import jakarta.persistence.*;

import java.math.BigDecimal;

@Entity
@Table(name = "produtos")
public class Produto {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(length = 60)
    private String nome;

    @Column(length = 60)
    private String descricao;

    private BigDecimal preco;

    @ManyToOne(fetch = FetchType.LAZY) // Relacionamento muitos-para-um com a entidade Categoria. 'fetch = FetchType.LAZY' indica carregamento tardio.
    @JoinColumn(name = "categoria_id") // Define a chave estrangeira que associa o produto à sua categoria.
    private Categoria categoria; // Referência à entidade Categoria.

    public Produto() {
    }

    public Produto(String nome, String descricao, BigDecimal preco, Categoria categoria) {
        this.nome = nome;
        this.descricao = descricao;
        this.preco = preco;
        this.categoria = categoria;
    }

    public Long getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public BigDecimal getPreco() {
        return preco;
    }

    public void setPreco(BigDecimal preco) {
        this.preco = preco;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Produto{")
                .append("id=").append(id)
                .append(", nome=").append(nome)
                .append(", descricao=").append(descricao)
                .append(", preco=").append(preco)
                .append(", categoria=").append(categoria)
                .append('}');
        return sb.toString();
    }
}
