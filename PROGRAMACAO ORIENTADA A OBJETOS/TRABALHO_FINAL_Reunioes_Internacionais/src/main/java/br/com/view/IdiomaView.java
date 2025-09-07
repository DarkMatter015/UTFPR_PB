package br.com.view;

import br.com.model.Idioma;
import br.com.service.IdiomaService;
import jakarta.persistence.EntityManager;

import static br.com.util.ViewUtil.*;

public class IdiomaView extends GenericView<Idioma> {

    public IdiomaView(EntityManager manager) {
        super(new IdiomaService(manager), "Idioma");
    }

    @Override
    protected Idioma criarEntidade() {
        String nome = lerString("Nome: ");
        return new Idioma(nome);
    }

    @Override
    protected void atualizarEntidade(Idioma idioma) {
        String novoNome = lerString("Novo nome (0 para pular): ");
        if (!novoNome.equals("0")) idioma.setNome(novoNome);

        String novoStatus = lerString("Desativar? (S/N): ");
        if (novoStatus.equals("S") || novoStatus.equals("s")) idioma.setAtivo(false);
    }
}
