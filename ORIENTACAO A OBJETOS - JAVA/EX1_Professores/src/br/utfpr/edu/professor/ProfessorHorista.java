package br.utfpr.edu.professor;

public class ProfessorHorista extends Professor {
    private int qtdHoras;
    private double valorHora;

    public ProfessorHorista() {}

    public ProfessorHorista(String nome, String email, int qtdHoras, double valorHora) {
        super(nome, email);
        this.qtdHoras = qtdHoras;
        this.valorHora = valorHora;
    }

    public int getQtdHoras() {
        return qtdHoras;
    }

    public void setQtdHoras(int qtdHoras) {
        this.qtdHoras = qtdHoras;
    }

    public double getValorHora() {
        return valorHora;
    }

    public void setValorHora(double valorHora) {
        this.valorHora = valorHora;
    }

    @Override
    public double calcularSalarioTotal() {
        return valorHora * qtdHoras;
    }

    @Override
    public String toString(){
        return super.toString() + ", qtdHoras: " + qtdHoras + ", valorHora: " + valorHora;
    }
}
