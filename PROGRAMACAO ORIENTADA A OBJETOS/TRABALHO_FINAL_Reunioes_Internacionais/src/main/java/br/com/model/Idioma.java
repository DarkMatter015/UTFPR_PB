package br.com.model;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "idiomas")
public class Idioma extends Entidade{

    @ManyToMany(mappedBy = "idiomas")
    private List<Representante> representantes = new ArrayList<>();

    protected Idioma() {
    }

    public Idioma(String nome) {
        this.setNome(nome);
    }

    public List<Representante> getRepresentantes() {
        return representantes;
    }

    public void setRepresentantes(List<Representante> representantes) {
        this.representantes = representantes;
    }

    @Override
    public String toString() {
        return "\nIdioma: {" +
                super.toString() +
                "\n} ";
    }
}
