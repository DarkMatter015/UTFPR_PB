package br.utfpr.edu.professor;

public class ProfessorEfetivo extends Professor {
    private double adicionalTitulacao;
    private double salarioBase;

    public ProfessorEfetivo(){}

    public ProfessorEfetivo(String nome, String email, double adicionalTitulacao, double salarioBase) {
        super(nome, email);
        this.adicionalTitulacao = adicionalTitulacao;
        this.salarioBase = salarioBase;
    }

    public double getAdicionalTitulacao() {
        return adicionalTitulacao;
    }

    public void setAdicionalTitulacao(double adicionalTitulacao) {
        this.adicionalTitulacao = adicionalTitulacao;
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    @Override
    public double calcularSalarioTotal(){
        return salarioBase + adicionalTitulacao;
    }

    @Override
    public String toString() {
        return super.toString() + ", Adicional Titulacao: " + adicionalTitulacao + ", SalarioBase: " + salarioBase;
    }
}
