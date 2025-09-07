package br.com.view;

import br.com.model.Pais;
import br.com.model.Representante;
import br.com.model.Reuniao;
import br.com.model.Tema;
import br.com.service.PaisService;
import br.com.service.RepresentanteService;
import br.com.service.ReuniaoService;
import br.com.service.TemaService;
import jakarta.persistence.EntityManager;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import static br.com.util.ViewUtil.*;

public class ReuniaoView extends GenericView<Reuniao> {

    private final TemaService temaService;
    private final PaisService paisService;
    private final RepresentanteService representanteService;

    public ReuniaoView(EntityManager manager) {
        super(new ReuniaoService(manager), "Reunião");
        this.temaService = new TemaService(manager);
        this.paisService = new PaisService(manager);
        this.representanteService = new RepresentanteService(manager);
    }

    @Override
    protected Reuniao criarEntidade() {
        String nome = lerString("Nome: ");
        LocalDateTime dataHora = LocalDateTime.now();

        long idTema;
        List<Tema> temas = new ArrayList<>();
        System.out.println(temaService.listar());
        do {
            idTema = lerID("ID do tema da Reunião (0 para pular): ");
            if (idTema != 0) {
                temas.add(temaService.buscarPorId((idTema)));
            } else if (temas.isEmpty()) {
                System.out.println("É necessário associar no mínimo um tema para a reunião.");
            }
        } while (idTema != 0 || temas.isEmpty());

        long idPais;
        List<Pais> paises = new ArrayList<>();
        System.out.println(paisService.listar());
        do {
            idPais = lerID("ID dos países participantes da Reunião (0 para pular): ");
            if (idPais != 0) {
                paises.add(paisService.buscarPorId((idPais)));
            } else if (paises.isEmpty()) {
                System.out.println("É necessário associar no mínimo um País para a reunião.");
            }
        } while (idPais != 0 || paises.isEmpty());

        System.out.println(representanteService.listar());
        long idRepresentante = lerID("ID do Representante Presidente: ");
        Representante representante = representanteService.buscarPorId(idRepresentante);

        return new Reuniao(nome, dataHora, temas, paises, representante);
    }

    @Override
    protected void atualizarEntidade(Reuniao reuniao) {
        String novoNome = lerString("Novo nome (0 para pular): ");
        if (!novoNome.equals("0")) reuniao.setNome(novoNome);

        String descricao = lerString("Nova descrição (0 para pular)");
        if (!descricao.equals("0")) reuniao.setDescricao(descricao);

        long idTema;
        List<Tema> temas = reuniao.getTemas();
        System.out.println(temaService.listar());
        do {
            idTema = lerID("ID do tema da Reunião (0 para pular): ");
            if (idTema != 0) {
                temas.add(temaService.buscarPorId((idTema)));
            }
        } while (idTema != 0);
        if (!temas.isEmpty()) reuniao.setTemas(temas);

        long idPais;
        List<Pais> paises = reuniao.getPaises();
        System.out.println(paisService.listar());
        do {
            idPais = lerID("ID dos países participantes da Reunião (0 para pular): ");
            if (idPais != 0) {
                paises.add(paisService.buscarPorId((idPais)));
            }
        } while (idPais != 0);
        if (!paises.isEmpty()) reuniao.setPaises(paises);

        System.out.println(representanteService.listar());
        long idRepresentante = lerID("ID do Representante Presidente (0 para pular): ");
        if (idRepresentante != 0) {
            Representante representante = representanteService.buscarPorId(idRepresentante);
            reuniao.setPresidente(representante);
        }

        String novoStatus = lerString("Desativar? (S/N): ");
        if (novoStatus.equals("S") || novoStatus.equals("s")) reuniao.setAtivo(false);

    }
}
