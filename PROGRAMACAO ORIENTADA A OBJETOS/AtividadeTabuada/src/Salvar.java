import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Salvar {

    private List<String> linhas;

    public void criar(String nomeArquivo){
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo, false))) {
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void salvarTabelaEmArquivoTexto(String nomeArquivo) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo, false))) {
            for (int i = 1; i <= 10; i++) {
                writer.write( "5 * " + i + " = " +
                        5*i);
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Erro ao salvar arquivo: " + e.getMessage());
        }
    }

    public void salvarEmArquivoTexto(String nomeArquivo) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo, false))) {
            for (int i = 0; i < linhas.size(); i++) {
                writer.write(linhas.get(i) + "\n");
            }
        } catch (IOException e) {
            System.out.println("Erro ao salvar arquivo: " + e.getMessage());
        }
    }

    public void carregarDeArquivoTexto(String nomeArquivo) {
        try(BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            linhas = new ArrayList<>();
            while((linha = reader.readLine()) != null) {
                linhas.add(linha);
            }
        } catch (IOException e) {
            System.out.println("Erro ao carregar arquivo: " + e.getMessage());
        }
    }
}
