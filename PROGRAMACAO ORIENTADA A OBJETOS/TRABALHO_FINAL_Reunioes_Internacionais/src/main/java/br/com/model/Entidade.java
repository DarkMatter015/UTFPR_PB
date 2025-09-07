package br.com.model;

import br.com.exception.NullException;
import jakarta.persistence.*;

@MappedSuperclass
public abstract class Entidade {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false)
    private String nome;

    @Column(nullable = false)
    private Boolean ativo = true;

    protected Entidade() {
    }

    public Long getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome != null & !nome.isBlank()) {
            this.nome = nome;
        } else {
            throw new NullException("Nome não pode ser nulo ou vazio.");
        }

    }

    public Boolean getAtivo() {
        return ativo;
    }

    public void setAtivo(Boolean ativo) {
        this.ativo = ativo != null ? ativo : true;
    }

    @Override
    public String toString() {
        return "\nid= " + id +
                "\nNome= " + nome +
                "\nAtivo= " + (ativo ? "Sim" : "Não");
    }
}
