package br.com.view;

import br.com.model.Pais;
import br.com.model.Representante;
import br.com.service.PaisService;
import br.com.service.RepresentanteService;
import jakarta.persistence.EntityManager;

import static br.com.util.ViewUtil.*;


public class PaisView extends GenericView<Pais> {

    private final RepresentanteService representanteService;

    public PaisView(EntityManager manager) {
        super(new PaisService(manager), "País");
        this.representanteService = new RepresentanteService(manager);
    }

    @Override
    protected Pais criarEntidade() {
        String nome = lerString("Nome: ");
        String sigla = lerString("Sigla (Máx 3): ");

        System.out.println(representanteService.listar());
        long idRepresentante = lerID("ID do Representante: ");
        Representante representante = representanteService.buscarPorId(idRepresentante);

        return new Pais(nome, sigla, representante);
    }

    @Override
    protected void atualizarEntidade(Pais pais) {
        String novoNome = lerString("Novo nome (0 para pular): ");
        if (!novoNome.equals("0")) pais.setNome(novoNome);

        String novaSigla = lerString("Nova sigla (Máx 3) (0 para pular): ");
        if (!novaSigla.equals("0")) pais.setSigla(novaSigla);

        System.out.println(representanteService.listar());
        long idRepresentante = lerID("ID do novo Representante (0 para pular): ");
        if (idRepresentante != 0) {
            Representante representante = representanteService.buscarPorId(idRepresentante);
            pais.setRepresentante(representante);
        }

        String novoStatus = lerString("Desativar? (S/N): ");
        if (novoStatus.equals("S") || novoStatus.equals("s")) pais.setAtivo(false);
    }
}
