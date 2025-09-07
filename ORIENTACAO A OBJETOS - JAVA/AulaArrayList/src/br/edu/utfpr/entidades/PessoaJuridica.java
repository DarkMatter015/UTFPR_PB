/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.edu.utfpr.entidades;

/**
 *
 * @author Andreia
 */
public class PessoaJuridica extends Pessoa{
    private String cnpj;

    public PessoaJuridica() {
        super();
    }

    
    public PessoaJuridica(String nome, String cnpj) {
        super(nome);
        this.cnpj = cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    
    public String getCnpj() {
        return cnpj;
    }

    @Override
    public String tipo() {
        return "Pessoa Jurídica";
    }

    @Override
    public String toString() {
        return super.toString() +  ", CNPJ: " + cnpj + ", Tipo: " + tipo();
    }
}
