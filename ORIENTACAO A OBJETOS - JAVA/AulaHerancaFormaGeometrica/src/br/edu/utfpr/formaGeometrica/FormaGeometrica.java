package br.edu.utfpr.formaGeometrica;

public class FormaGeometrica {

    private int lado1;
    private int lado2;

    public FormaGeometrica() {
    }

    public FormaGeometrica(int lado1, int lado2) {
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    public int getLado1() {
        return lado1;
    }

    public void setLado1(int lado1) {
        this.lado1 = lado1;
    }

    public int getLado2() {
        return this.lado2;
    }

    public void setLado2(int lado2) {
        this.lado2 = lado2;
    }


    @Override
    public String toString() {
        return "Lado 1: " + lado1
                + "\nLado 2: " + lado2;
                
    }


}
