package br.edu.utfpr.main;

import br.edu.utfpr.operacoes.Operacoes;

import javax.swing.*;

public class MainOperacoes {
    public static void main(String[] args) {
        Operacoes op = new Operacoes();

        op.setA(Double.parseDouble(JOptionPane.showInputDialog("Valor de A: ")));
        op.setB(Double.parseDouble(JOptionPane.showInputDialog("Valor de B: ")));

        System.out.println(op.toString());

        System.out.println("Divisão entre a e b: " + op.dividir());

        System.out.println("Soma entre a e b: " + op.somar());

        System.out.println("Subtração entre a e b: " + op.subtrair());

        System.out.println("Multiplicar entre a e b: " + op.multiplicar());
    }
}
