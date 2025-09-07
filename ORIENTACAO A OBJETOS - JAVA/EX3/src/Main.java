import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        int a[] = new int[10];
        int qtd = 0;

        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(JOptionPane.showInputDialog("Informe a idade"));
        }

        StringBuilder sb = new StringBuilder("Vetor de idades: ");
        for (int i = 0; i < a.length; i++) {
            sb.append(a[i] + "\n");
            if(a[i] > 35){
                qtd++;
            }
        }

        JOptionPane.showMessageDialog(null, sb.toString() + "\nQuantidade de pessoas com idade superior a 35 anos: " + qtd);


    }
}