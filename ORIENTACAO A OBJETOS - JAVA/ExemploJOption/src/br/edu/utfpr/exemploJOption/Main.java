package br.edu.utfpr.exemploJOption;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Aioioiioioii");

        String nome = JOptionPane.showInputDialog(null, "Digite o seu nome: ");
        JOptionPane.showMessageDialog(null, "Olá " + nome);
        int opcao = JOptionPane.showConfirmDialog(null, "Você? ");

        switch (opcao) {
            case JOptionPane.YES_OPTION:
                JOptionPane.showMessageDialog(null, "Tao ta");
                break;
            case JOptionPane.NO_OPTION:
                JOptionPane.showMessageDialog(null, "Tao não tá");
                break;
            default:
                JOptionPane.showMessageDialog(null, "Cancelou ne");
                break;
        }
    }
}