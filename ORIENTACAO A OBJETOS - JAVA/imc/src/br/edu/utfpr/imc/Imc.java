package br.edu.utfpr.imc;

public class Imc {
    private double peso;
    private double altura;

    // construtor
    public void Imc(){

    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double calcularImc(){
        return (peso / (altura * altura));
    }

    public String interpretaImc(double valorImc){
        String res;
        if(valorImc < 20){
            res = "Magro";
        }
        else if(valorImc >= 20 && valorImc <= 24){
            res = "Normal";
        }
        else if(valorImc >= 25 && valorImc <= 29){
            res = "Acima do Peso";
        }
        else if(valorImc >= 30 && valorImc <= 34){
            res = "Obeso";
        }
        else{
            res = "Muito Obeso";
        }

        return res;
    }

    public String toString(){
        return "Peso: " + peso
                + "\nAltura: " + altura;
    }
}
