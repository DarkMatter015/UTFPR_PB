package br.com.view;

import br.com.model.Tema;
import br.com.service.TemaService;
import jakarta.persistence.EntityManager;

import static br.com.util.ViewUtil.*;

public class TemaView extends GenericView<Tema> {

    public TemaView(EntityManager manager) {
        super(new TemaService(manager), "Tema");
    }

    @Override
    protected Tema criarEntidade() {
        String nome = lerString("Nome: ");
        String descricao = lerString("Descrição: ");
        return new Tema(nome, descricao);
    }

    @Override
    protected void atualizarEntidade(Tema tema) {
        String novoNome = lerString("Novo nome (0 para pular): ");
        if (!novoNome.equals("0")) tema.setNome(novoNome);

        String descricao = lerString("Nova descrição (0 para pular): ");
        if (!descricao.equals("0")) tema.setDescricao(descricao);

        String novoStatus = lerString("Desativar? (S/N): ");
        if (novoStatus.equals("S") || novoStatus.equals("s")) tema.setAtivo(false);

    }
}
