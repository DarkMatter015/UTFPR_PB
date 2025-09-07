package br.edu.utfpr.views;

import br.edu.utfpr.imc.Imc;

import javax.swing.*;

public class CalculaImc {
    public static void main(String[] args) {
        Imc imc = new Imc();

        imc.setPeso(Double.parseDouble(JOptionPane.showInputDialog("Peso(Kg): ")));
        imc.setAltura(Double.parseDouble(JOptionPane.showInputDialog("Altura(Kg): ")));

        System.out.println(imc);
        System.out.println("IMC: " + imc.calcularImc());

        System.out.println(imc.interpretaImc(imc.calcularImc()));
    }
}
