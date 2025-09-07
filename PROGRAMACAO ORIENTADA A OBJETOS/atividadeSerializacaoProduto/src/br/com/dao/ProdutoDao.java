package br.com.dao;

import br.com.model.Produto;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class ProdutoDao {

    public void gravarProdutosNoArquivo(File arquivo, List<Produto> produtos){
        try (ObjectOutput data = new ObjectOutputStream(new FileOutputStream(arquivo))) {
            data.writeObject(produtos);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String leProdutoDoArquivo(File arquivo){
        List<Produto> produtosArquivo = new ArrayList<>();
        StringBuilder str = new StringBuilder();

        try (ObjectInput data = new ObjectInputStream(new FileInputStream(arquivo))) {
            produtosArquivo = (List<Produto>)data.readObject();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }

        for(Produto p : produtosArquivo) {
            str.append(p).append("Total: R$ ").append(p.getTotal());
        }

        return str.toString();
    }

}
