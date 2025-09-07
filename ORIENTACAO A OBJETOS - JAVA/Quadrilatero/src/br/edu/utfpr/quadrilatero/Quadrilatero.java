package br.edu.utfpr.quadrilatero;

public class Quadrilatero {
    private int lado1;
    private int lado2;


    public Quadrilatero(int lado1, int lado2) {
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    public Quadrilatero() {

    }

    public int getLado1() {
        return lado1;
    }

    public void setLado1(int lado1) {
        this.lado1 = lado1;
    }

    public int getLado2() {
        return lado2;
    }

    public void setLado2(int lado2) {
        this.lado2 = lado2;
    }

    public double getAreaPlana(){
        return lado1 * lado2;
    }

    public double getPerimetro(){
        return lado1 * 2 + lado2 * 2;
    }

    public boolean isQuadrado(){
        return lado1 == lado2;
    }

    public boolean isRetangulo(){
        return lado1 != lado2;
    }

    public String toString() {
        return "Quadrilatero{" +
                "lado1=" + lado1 +
                ", lado2=" + lado2 +
                '}';
    }
}
