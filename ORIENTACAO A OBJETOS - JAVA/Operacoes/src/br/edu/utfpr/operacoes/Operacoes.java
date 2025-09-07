package br.edu.utfpr.operacoes;

public class Operacoes {
    private double a;
    private double b;

    public void Operacoes(){

    }

    public void Operacoes(double a, double b){
        this.a = a;
        this.b = b;
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public double somar(){
        return a + b;
    }

    public double subtrair(){
        return a - b;
    }

    public double multiplicar(){
        return a * b;
    }

    public double dividir(){
        if(b != 0){
            return a / b;
        }
        else{
            return 0;
        }
    }

    public String toString(){
        return "a = " + a
                + ", b = " + b + "\n";
    }
}
