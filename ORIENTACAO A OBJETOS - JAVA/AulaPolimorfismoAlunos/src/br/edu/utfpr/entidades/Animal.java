package br.edu.utfpr.entidades;

public abstract class Animal {

    private String nome;
    private int idade;
    private String tipo;

    public Animal() {
    }

    public Animal(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    
    public abstract String getTipo();
    
    public abstract String emitirSom();
    
    @Override
    public String toString() {
        return "Nome:" + getNome()
                + "\nIdade:" + getIdade();
    }

}
