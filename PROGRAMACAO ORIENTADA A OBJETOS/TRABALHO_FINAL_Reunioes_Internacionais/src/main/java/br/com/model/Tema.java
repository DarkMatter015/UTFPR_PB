package br.com.model;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

@Entity
@Table(name = "temas")
public class Tema extends Entidade{

    @Column(nullable = false)
    private String descricao;

    @ManyToMany(mappedBy = "temas", fetch = FetchType.LAZY)
    private List<Reuniao> reunioes = new ArrayList<>();

    protected Tema() {
    }

    public Tema(String nome, String descricao) {
        setNome(nome);
        this.descricao = descricao;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public List<Reuniao> getReunioes() {
        return reunioes;
    }

    public void setReunioes(List<Reuniao> reunioes) {
        this.reunioes = reunioes;
    }

    private String imprimeReunioes() {
        return this.reunioes.stream()
                .sorted(Comparator.comparing(Reuniao::getNome))
                .map(Reuniao::getNome)
                .collect(Collectors.joining(", "));
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("\nTema: {")
                .append(super.toString())
                .append("\nDescricão= ").append(descricao)
                .append("\nReuniões Associadas: ").append(imprimeReunioes())
                .append("\n}");

        return str.toString();
    }
}
