package br.com.model;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "paises")
public class Pais extends Entidade{

    @Column(length = 3, nullable = false)
    private String sigla;

    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "representante_id")
    private Representante representante;

    @ManyToMany(mappedBy = "paises")
    private List<Reuniao> reunioes = new ArrayList<>();

    protected Pais() {
    }

    public Pais(String nome, String sigla, Representante representante) {
        setNome(nome);
        this.sigla = sigla;
        this.representante = representante;
    }

    public String getSigla() {
        return sigla;
    }

    public void setSigla(String sigla) {
        this.sigla = sigla;
    }

    public Representante getRepresentante() {
        return representante;
    }

    public void setRepresentante(Representante representante) {
        this.representante = representante;
    }

    public List<Reuniao> getReunioes() {
        return reunioes;
    }

    public void setReunioes(List<Reuniao> reunioes) {
        this.reunioes = reunioes;
    }

    @Override
    public String toString() {
        return "\nPais: {" +
                super.toString() +
                "\nSigla: " + sigla +
                "\nRepresentante: " + (representante != null ? representante.getNome() : "(Sem Representante)") +
                "\n} ";
    }
}
