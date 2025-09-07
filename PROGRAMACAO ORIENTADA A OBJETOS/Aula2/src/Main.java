import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        File novo_arquivo = new File("novo_arquivo.bin");

        String nome = "Lucas";
        int idade = 18;

        // gravando dado primitivo e string
        try (DataOutputStream data = new DataOutputStream(new FileOutputStream(novo_arquivo))) {
            data.writeUTF(nome);
            data.writeInt(idade);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // lendo dados do arquivo
        StringBuilder str = new StringBuilder();
        try (DataInputStream data = new DataInputStream(new FileInputStream(novo_arquivo))) {
            str.append(data.readUTF()).append("\n").append(data.readInt());
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println(str.toString());

        File pessoas_arquivo = new File("pessoas.bin");

        Pessoa p1 = new Pessoa("Lucas", 18);
        Pessoa p2 = new Pessoa("Matheus", 78);
        Pessoa p3 = new Pessoa("Joção", 21);

        List<Pessoa> pessoas = new ArrayList<>();
        pessoas.add(p1);
        pessoas.add(p2);
        pessoas.add(p3);

        try (ObjectOutput data = new ObjectOutputStream(new FileOutputStream(pessoas_arquivo))) {
            data.writeObject(pessoas);
        } catch (IOException e) {
            e.printStackTrace();
        }

        List<Pessoa> pessoasArquivo = new ArrayList<>();

        try (ObjectInput data = new ObjectInputStream(new FileInputStream(pessoas_arquivo))) {
            pessoasArquivo = (List<Pessoa>)data.readObject();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }

        for(Pessoa p : pessoasArquivo) {
            System.out.println(p.toString());
        }
    }
}