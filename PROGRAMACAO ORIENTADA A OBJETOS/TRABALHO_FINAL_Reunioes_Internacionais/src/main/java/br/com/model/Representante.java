package br.com.model;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

@Entity
@Table(name = "representantes")
public class Representante extends Entidade{

    @Column(nullable = false, unique = true, length = 100)
    private String email;

    @ManyToMany
    @JoinTable(
            name = "representante_idioma",
            joinColumns = @JoinColumn(name = "representante_id"),
            inverseJoinColumns = @JoinColumn(name = "idioma_id")
    )
    private List<Idioma> idiomas = new ArrayList<>();

    @OneToOne(mappedBy = "representante")
    private Pais pais;

    @OneToMany(mappedBy = "presidente")
    private List<Reuniao> reunioesPresididas = new ArrayList<>();

    protected Representante() {
    }

    public Representante(String nome, String email, List<Idioma> idiomas) {
        setNome(nome);
        this.email = email;
        this.idiomas = idiomas != null ? idiomas : new ArrayList<>();
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public List<Idioma> getIdiomas() {
        return idiomas;
    }

    public void setIdiomas(List<Idioma> idiomas) {
        this.idiomas = idiomas;
    }

    public Pais getPais() {
        return pais;
    }

    public void setPais(Pais pais) {
        this.pais = pais;
    }

    public List<Reuniao> getReunioesPresididas() {
        return reunioesPresididas;
    }

    public void setReunioesPresididas(List<Reuniao> reunioesPresididas) {
        this.reunioesPresididas = reunioesPresididas;
    }

    public void adicionarIdioma(Idioma idioma) {
        this.idiomas.add(idioma);
    }

    public void removerIdioma(Idioma idioma) {
        this.idiomas.remove(idioma);
    }

    private String imprimeIdiomas() {
        return this.idiomas.stream()
                .sorted(Comparator.comparing(Idioma::getNome))
                .map(Idioma::getNome)
                .collect(Collectors.joining(", "));
    }

    private String imprimeReunioesPresididas() {
        return this.reunioesPresididas.stream()
                .sorted(Comparator.comparing(Reuniao::getNome))
                .map(Reuniao::getNome)
                .collect(Collectors.joining(", "));
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("\nRepresentante: {")
                .append(super.toString())
                .append("\nEmail= ").append(email)
                .append("\nIdiomas= ").append(imprimeIdiomas())
                .append("\nPais= ").append(pais != null ? pais.getNome() : " (sem pais) ")
                .append("\nReuniões Presididas= ").append(imprimeReunioesPresididas())
                .append("\n}");

        return str.toString();
    }
}
