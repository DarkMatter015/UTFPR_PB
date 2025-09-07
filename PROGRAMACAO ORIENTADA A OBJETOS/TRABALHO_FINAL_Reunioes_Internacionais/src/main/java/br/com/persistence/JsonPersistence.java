package br.com.persistence;

import br.com.interfaces.PersistenciaInterface;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;

import java.io.File;
import java.io.IOException;
import java.util.List;

public class JsonPersistence<T> implements PersistenciaInterface<T> {

    private final Class<T> classe;

    public JsonPersistence(Class<T> classe) {
        this.classe = classe;
    }

    @Override
    public void salvar(List<T> lista, String nomeArquivo) {
        if (lista != null && !lista.isEmpty()) {
            try {
                ObjectMapper objectMapper = new ObjectMapper();
                objectMapper.enable(SerializationFeature.INDENT_OUTPUT); // JSON formatado
                objectMapper.writeValue(new File(nomeArquivo), lista);
                System.out.println("Arquivo JSON salvo com sucesso: " + nomeArquivo);
            } catch (IOException e) {
                System.err.println("Erro ao salvar o arquivo JSON: " + e.getMessage());
            }
        } else {
            System.out.println("Lista vazia! Nada a salvar.");
        }
    }

    @Override
    public List<T> carregar(String nomeArquivo) {
        try {
            ObjectMapper objectMapper = new ObjectMapper();
            return objectMapper.readValue(new File(nomeArquivo),
                    objectMapper.getTypeFactory().constructCollectionType(List.class, classe));
        } catch (IOException e) {
            System.err.println("Erro ao carregar o arquivo JSON: " + e.getMessage());
            return null;
        }
    }
}
