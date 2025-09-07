package br.utfpr.edu.Pessoa;

public abstract class Empregado extends Pessoa{
    private int codcodigoSetor;
    private double salarioBase;

    public Empregado(String nome, String endereco, String telefone, int codcodigoSetor, double salarioBase) {
        super(nome, endereco, telefone);
        this.codcodigoSetor = codcodigoSetor;
        this.salarioBase = salarioBase;
    }

    public int getCodcodigoSetor() {
        return codcodigoSetor;
    }

    public void setCodcodigoSetor(int codcodigoSetor) {
        this.codcodigoSetor = codcodigoSetor;
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    public abstract double calcularSalarioTotal();

    @Override
    public String toString() {
        return super.toString() + "codcodigoSetor=" + codcodigoSetor +
                ", salarioBase=" + salarioBase;
    }
}
