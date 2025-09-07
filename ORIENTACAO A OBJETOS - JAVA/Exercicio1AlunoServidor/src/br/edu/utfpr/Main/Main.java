package br.edu.utfpr.Main;

import br.edu.utfpr.alunoServidor.Aluno;
import br.edu.utfpr.alunoServidor.Servidor;
import javax.swing.JOptionPane;

public class Main {

    /*private static int menu() {
        int opcao = Integer.parseInt(JOptionPane.showInputDialog(
                "Informe uma opção: "
                + "\n[1] Aluno"
                + "\n[2] Servidor"
                + "\n[3] Sair"
        ));
        return opcao;
    }*/
    public static void main(String[] args) {
        Aluno aluno = new Aluno();
        aluno.setRa(Long.parseLong(JOptionPane.showInputDialog("RA:")));
        aluno.setNome(JOptionPane.showInputDialog("Nome: "));
        aluno.setEmail(JOptionPane.showInputDialog("E-mail: "));
        JOptionPane.showMessageDialog(null, aluno);

        Servidor servidor = new Servidor(
                Long.parseLong(JOptionPane.showInputDialog("SIAPE:")),
                JOptionPane.showInputDialog("Nome: "),
                JOptionPane.showInputDialog("E-mail: "));
        JOptionPane.showMessageDialog(null, servidor);
        /*int opcao = menu();

        while (true) {
            switch (opcao) {
                case 1:
                    Aluno aluno = new Aluno();
                    aluno.setRa(Long.parseLong(JOptionPane.showInputDialog("RA:")));
                    aluno.setNome(JOptionPane.showInputDialog("Nome: "));
                    aluno.setEmail(JOptionPane.showInputDialog("E-mail: "));
                    JOptionPane.showMessageDialog(null, aluno);
                    opcao = menu();
                    break;
                case 2:
                    Servidor servidor = new Servidor(
                            Long.parseLong(JOptionPane.showInputDialog("SIAPE:")),
                            JOptionPane.showInputDialog("Nome: "),
                            JOptionPane.showInputDialog("E-mail: "));
                    JOptionPane.showMessageDialog(null, servidor);
                    opcao = menu();
                    break;
                case 3:
                    System.exit(0);
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida.", "Erro", JOptionPane.ERROR_MESSAGE);
                    opcao = menu();
                    break;
            }
        }*/

    }

}
