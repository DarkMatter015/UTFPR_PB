package br.edu.utfpr.carro;

public class Veiculo {
    private String marca;
    private String modelo;
    private int velocidade;

    // metodo construtor
    public Veiculo(){

    }

    // Getters e Setters
    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getVelocidade() {
        return velocidade;
    }

    public void setVelocidade(int velocidade) {
        this.velocidade = velocidade;
    }

    public void desacelerar(){
        this.velocidade -= 10;
    }

    public void acelerar(){
        this.velocidade += 20;
    }

    public String buzinar(){
        return "BEEEEP";
    }

    // metodo para saida de dados
    public String toString(){
        return "Marca: " + marca
            + "\nModelo: " + modelo
            + "\nVelocidade: " + velocidade;
    }
}
