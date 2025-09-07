package br.utfpr.edu.Pessoa;

public class Admnistrador extends Empregado{
    private double ajudaDeCusto;

    public Admnistrador(String nome, String endereco, String telefone, int codcodigoSetor, double salarioBase, double ajudaDeCusto) {
        super(nome, endereco, telefone, codcodigoSetor, salarioBase);
        this.ajudaDeCusto = ajudaDeCusto;
    }

    public double getAjudaDeCusto() {
        return ajudaDeCusto;
    }

    public void setAjudaDeCusto(double ajudaDeCusto) {
        this.ajudaDeCusto = ajudaDeCusto;
    }

    @Override
    public double calcularSalarioTotal() {
        return super.getSalarioBase() + ajudaDeCusto;
    }

    @Override
    public String toString(){
        return super.toString() + ", ajuda de custo: " + ajudaDeCusto;
    }
}
