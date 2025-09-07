/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author Andreia
 */
public class PessoaFisica extends Pessoa{
    private String cpf;

    public PessoaFisica() {
        super();
    }

    
    public PessoaFisica(String nome, String cpf) {
        super(nome);
        this.cpf = cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    
    public String getCpf() {
        return cpf;
    }

    @Override
    public String tipo() {
        return "Pessoa Física";
    }

    @Override
    public String toString() {
        return super.toString() + ", CPF: " + cpf + ", Tipo: " + tipo();
    }
}
