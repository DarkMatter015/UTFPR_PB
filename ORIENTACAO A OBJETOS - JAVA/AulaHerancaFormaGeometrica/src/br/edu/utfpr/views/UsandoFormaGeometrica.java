/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package br.edu.utfpr.views;

import javax.swing.JOptionPane;

/**
 *
 * @author Andreia
 */
public class UsandoFormaGeometrica {

    public static int menu() {
        return Integer.parseInt(JOptionPane.showInputDialog("Informe a opção:\n[1] Quadrilátero \n[2] Cubo \n[3] Sair\n"));
    }

    public static void main(String[] args) {
        while (true) {
            int opcao = menu();
            switch (opcao) {
                case 1:
                    
                    break;
                case 2:
                    break;

                case 3:
                    JOptionPane.showMessageDialog(null, "Saindo do programa.");
                    System.exit(0);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida! Tente novamente.");
                    break;

            }
        }

    }

}
