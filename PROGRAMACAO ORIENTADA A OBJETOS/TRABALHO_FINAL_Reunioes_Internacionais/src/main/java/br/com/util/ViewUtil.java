package br.com.util;

import java.util.Scanner;

public class ViewUtil {

    private static final Scanner sc = new Scanner(System.in);

    public static void exibirMensagem(String mensagem) {
        System.out.println(mensagem);
    }

    public static String lerString(String mensagem) {
        String string = "";
        boolean nomeValido = false;
        while(!nomeValido) {
            exibirMensagem(mensagem);
            string = lerLinha();

            if (string.isEmpty()) {
                exibirMensagem("Erro: informe um string válido.");
            }else{
                nomeValido = true;
            }
        }
        return string;
    }

    public static Long lerID(String mensagem) {
        Long id = null;
        while(id == null) {
            exibirMensagem(mensagem);
            try {
                id = Long.parseLong(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                exibirMensagem("Erro: informe um número válido para o ID.");
            }
        }
        return id;
    }

    public static int lerOpcao() {
        Integer opcao = null;
        while(opcao == null) {
            exibirMensagem("Escolha uma opção: ");

            try {
                opcao = Integer.parseInt(sc.nextLine().trim());

            } catch (NumberFormatException e) {
                exibirMensagem("Erro: informe um número inteiro válido.");
            }
        }
        return opcao;
    }

    public static String lerLinha() {
        return sc.nextLine().trim();
    }
}
