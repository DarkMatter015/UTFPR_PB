package br.edu.utfpr.Classes;

public class Empregado {
    private String nome;
    private String cpf;
    private double salario;
    private double horas_semanais;
    private double horas_trabalhadas;

    public Empregado() {
    }

    public Empregado(String nome, String cpf, double salario, double horas_semanais, double horas_trabalhadas) {
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
        this.horas_semanais = horas_semanais;
        this.horas_trabalhadas = horas_trabalhadas;
    }

    public double getHoras_trabalhadas() {
        return horas_trabalhadas;
    }

    public void setHoras_trabalhadas(double horas_trabalhadas) {
        this.horas_trabalhadas = horas_trabalhadas;
    }

    public double getHoras_semanais() {
        return horas_semanais;
    }

    public void setHoras_semanais(double horas_semanais) {
        this.horas_semanais = horas_semanais;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double calculaHoraExtra(){
        return (salario / horas_semanais) * 1.5;
    }

    @Override
    public String toString() {
        return "Empregado{" +
                "nome='" + nome + '\'' +
                ", cpf='" + cpf + '\'' +
                ", salario=" + salario +
                ", horas_semanais=" + horas_semanais +
                ", horas_trabalhadas=" + horas_trabalhadas +
                '}';
    }
}
