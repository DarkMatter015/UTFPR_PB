package org.com.controller;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.com.model.Pessoa;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ManipuladorJSON {
    private final String nomeArquivo = "pessoas.json";

    public void salvarPessoas(List<Pessoa> pessoas) throws IOException {
        if (!pessoas.isEmpty()) {
            ObjectMapper objectMapper = new ObjectMapper();
            objectMapper.writeValue(new File(nomeArquivo), pessoas);
            System.out.println("Dados salvos com sucesso!");
        } else {
            System.out.println("Lista vazia!");
        }
    }

    public List<Pessoa> carregarPessoas() throws IOException {
        File file = new File(nomeArquivo);
        if (file.exists()) {
            ObjectMapper objectMapper = new ObjectMapper();
            return objectMapper.readValue(file, objectMapper.getTypeFactory().constructCollectionType(List.class, Pessoa.class));
        }
        return new ArrayList<>();
    }
}