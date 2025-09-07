package br.com.interfaces;

import java.util.List;

public interface PersistenciaInterface<T> {
    void salvar(List<T> produtos, String caminhoArquivo);
    List<T> carregar(String caminhoArquivo);
}
