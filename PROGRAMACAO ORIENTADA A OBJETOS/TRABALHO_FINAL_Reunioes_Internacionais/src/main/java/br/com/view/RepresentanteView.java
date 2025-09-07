package br.com.view;

import br.com.model.Idioma;
import br.com.model.Representante;
import br.com.service.IdiomaService;
import br.com.service.RepresentanteService;
import jakarta.persistence.EntityManager;

import java.util.ArrayList;
import java.util.List;

import static br.com.util.ViewUtil.*;

public class RepresentanteView extends GenericView<Representante> {

    private final IdiomaService idiomaService;

    public RepresentanteView(EntityManager manager) {
        super(new RepresentanteService(manager), "Representante");
        this.idiomaService = new IdiomaService(manager);
    }

    @Override
    protected Representante criarEntidade() {
        String nome = lerString("Nome: ");
        String email = lerString("Email: ");

        long idIdioma;
        List<Idioma> idiomas = new ArrayList<>();
        System.out.println(idiomaService.listar());
        do {
            idIdioma = lerID("ID do idioma que o representante fala (0 para pular)");
            if (idIdioma != 0) {
                idiomas.add(idiomaService.buscarPorId((idIdioma)));
            } else if (idiomas.isEmpty()) {
                System.out.println("É necessário associar no mínimo um idioma ao Representante.");
            }
        } while (idIdioma != 0 || idiomas.isEmpty());

        return new Representante(nome, email, idiomas);
    }

    @Override
    protected void atualizarEntidade(Representante representante) {
        String novoNome = lerString("Novo nome (0 para pular): ");
        if (!novoNome.equals("0")) representante.setNome(novoNome);

        String novoEmail = lerString("Novo email do representante (0 para pular): ");
        if (!novoEmail.equals("0")) representante.setEmail(novoEmail);

        long idIdioma;
        List<Idioma> idiomas = new ArrayList<>();
        System.out.println(idiomaService.listar());
        do {
            idIdioma = lerID("ID do idioma que o representante fala (0 para pular)");
            if (idIdioma != 0) {
                idiomas.add(idiomaService.buscarPorId((idIdioma)));
            }
        } while (idIdioma != 0);

        if (!idiomas.isEmpty()) representante.setIdiomas(idiomas);

        String novoStatus = lerString("Desativar? (S/N): ");
        if (novoStatus.equals("S") || novoStatus.equals("s")) representante.setAtivo(false);
    }
}
