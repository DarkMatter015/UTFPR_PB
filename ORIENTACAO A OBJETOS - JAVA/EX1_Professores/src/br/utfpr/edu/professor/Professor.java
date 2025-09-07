package br.utfpr.edu.professor;

public abstract class Professor {
    private String nome;
    private String email;

    public Professor() {}

    public Professor(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public abstract double calcularSalarioTotal();

    @Override
    public String toString() {
        return "nome= " + nome + ", email= " + email;
    }
}
