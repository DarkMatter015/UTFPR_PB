package br.com.model;

import jakarta.persistence.*;

import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

@Entity
@Table(name = "reunioes")
public class Reuniao extends Entidade {

    private String descricao;

    @Column(name = "data_hora_reuniao", nullable = false)
    private LocalDateTime dataHoraReuniao;

    @ManyToMany
    @JoinTable(
            name = "reuniao_tema",
            joinColumns = @JoinColumn(name = "reuniao_id"),
            inverseJoinColumns = @JoinColumn(name = "tema_id")
    )
    private List<Tema> temas = new ArrayList<>();

    @ManyToMany
    @JoinTable(
            name = "reuniao_pais",
            joinColumns = @JoinColumn(name = "reuniao_id"),
            inverseJoinColumns = @JoinColumn(name = "pais_id")
    )
    private List<Pais> paises = new ArrayList<>();

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "presidente_id")
    private Representante presidente;

    protected Reuniao() {
    }

    public Reuniao(String nome, LocalDateTime dataHoraReuniao, List<Tema> temas, List<Pais> paises, Representante presidente) {
        setNome(nome);
        this.dataHoraReuniao = dataHoraReuniao;
        this.temas = temas != null ? temas : new ArrayList<>();
        this.paises = paises != null ? paises : new ArrayList<>();
        this.presidente = presidente;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public LocalDateTime getDataHoraReuniao() {
        return dataHoraReuniao;
    }

    public void setDataHoraReuniao(LocalDateTime dataReuniao) {
        this.dataHoraReuniao = dataReuniao;
    }

    public List<Tema> getTemas() {
        return temas;
    }

    public void setTemas(List<Tema> temas) {
        this.temas = temas != null ? temas : new ArrayList<>();
    }

    public List<Pais> getPaises() {
        return paises;
    }

    public void setPaises(List<Pais> paises) {
        this.paises = paises != null ? paises : new ArrayList<>();
    }

    public Representante getPresidente() {
        return presidente;
    }

    public void setPresidente(Representante presidente) {
        this.presidente = presidente;
    }

    public Integer getTotalPaises() {
        return paises != null ? paises.size() : 0;
    }

    public Integer getTotalTemas() {
        return temas != null ? temas.size() : 0;
    }

    public void adicionarTema(Tema tema) {
        if (tema != null) temas.add(tema);
    }

    public void removerTema(Tema tema) {
        if (tema != null) temas.remove(tema);
    }

    public void adicionarPais(Pais pais) {
        if (pais != null) paises.add(pais);
    }

    public void removerPais(Pais pais) {
        if (pais != null) paises.remove(pais);
    }

    private String imprimeTemas() {
        return this.temas.stream()
                .sorted(Comparator.comparing(Tema::getNome))
                .map(Tema::getNome)
                .collect(Collectors.joining(", "));

    }

    private String imprimePaises() {
        return this.paises.stream()
                .sorted(Comparator.comparing(Pais::getNome))
                .map(Pais::getNome)
                .collect(Collectors.joining(", "));
    }

    @Override
    public String toString() {
         DateTimeFormatter FORMATTER_UTC = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm 'UTC'").withZone(ZoneOffset.UTC);

        StringBuilder str = new StringBuilder();
        str.append("\nReunião {")
                .append(super.toString())
                .append("\nDescricao= ").append(descricao != null ? descricao : "(Sem descrição)")
                .append("\nData= ").append(FORMATTER_UTC.format(dataHoraReuniao.atZone(ZoneOffset.UTC)))
                .append("\nTemas= ").append(imprimeTemas())
                .append("\nPaíses= ").append(imprimePaises())
                .append("\nPresidente= ").append(presidente != null ? presidente.getNome() : "(Sem Presidente)")
                .append("\nTotal de Temas= ").append(getTotalTemas())
                .append("\nTotal de Países= ").append(getTotalPaises())
                .append("\n}");

        return str.toString();
    }

}
