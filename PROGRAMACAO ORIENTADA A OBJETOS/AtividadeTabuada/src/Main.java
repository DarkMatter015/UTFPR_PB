import java.io.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

    Salvar salvar = new Salvar();

    salvar.criar("arquivo1.txt");
    salvar.criar("arquivo2.txt");

    salvar.salvarTabelaEmArquivoTexto("arquivo1.txt");

    salvar.carregarDeArquivoTexto("arquivo1.txt");

    salvar.salvarEmArquivoTexto("arquivo2.txt");

    }
}