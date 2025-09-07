package br.utfpr.edu.Pessoa;

public class Diretor extends Empregado{
    private double gratificacao;

    public Diretor(String nome, String endereco, String telefone, int codcodigoSetor, double salarioBase, double gratificacao) {
        super(nome, endereco, telefone, codcodigoSetor, salarioBase);
        this.gratificacao = gratificacao;
    }

    public double getGratificacao() {
        return gratificacao;
    }

    public void setGratificacao(double gratificacao) {
        this.gratificacao = gratificacao;
    }

    @Override
    public double calcularSalarioTotal(){
        return super.getSalarioBase() + gratificacao;
    }

    @Override
    public String toString() {
        return super.toString() + ", Gratificacao: " + gratificacao;
    }
}
