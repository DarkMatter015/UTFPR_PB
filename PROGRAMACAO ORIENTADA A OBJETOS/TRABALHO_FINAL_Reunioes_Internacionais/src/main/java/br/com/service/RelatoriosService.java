package br.com.service;

import br.com.dao.ReuniaoDao;
import br.com.model.Pais;
import br.com.model.Representante;
import br.com.model.Reuniao;
import br.com.model.Tema;
import br.com.vo.RelatorioParticipacaoPaisVo;
import br.com.vo.RelatorioPresencaRepresentanteVo;
import br.com.vo.RelatorioTemasMaisDiscutidosVo;
import jakarta.persistence.EntityManager;

import java.util.ArrayList;
import java.util.List;

public class RelatoriosService {

    private final ReuniaoDao reuniaoDao;

    public RelatoriosService(EntityManager manager) {
        this.reuniaoDao = new ReuniaoDao(manager);
    }

    public List<RelatorioParticipacaoPaisVo> gerarRelatorioParticipacao() {
        List<Reuniao> reunioes = reuniaoDao.buscarTodos();
        List<RelatorioParticipacaoPaisVo> lista = new ArrayList<>();

        for (Reuniao reuniao : reunioes) {
            for (Pais pais : reuniao.getPaises()) {
                // Verifica se já existe entrada para o país
                RelatorioParticipacaoPaisVo rel = null;
                for (RelatorioParticipacaoPaisVo item : lista) {
                    if (item.getNomePais().equals(pais.getNome())) {
                        rel = item;
                        break;
                    }
                }
                if (rel == null) {
                    // Não existe, cria e adiciona
                    rel = new RelatorioParticipacaoPaisVo(pais.getNome(), 1L);
                    lista.add(rel);
                } else {
                    // Incrementa contagem
                    rel.setTotalParticipacoes(rel.getTotalParticipacoes() + 1);
                }
            }
        }


        lista.sort((a, b) -> Long.compare(b.getTotalParticipacoes(), a.getTotalParticipacoes()));

        return lista;
    }

    public List<RelatorioTemasMaisDiscutidosVo> gerarRelatorioTemasMaisDiscutidos() {
        List<Reuniao> reunioes = reuniaoDao.buscarTodos();
        List<RelatorioTemasMaisDiscutidosVo> lista = new ArrayList<>();

        for (Reuniao reuniao : reunioes) {
            for (Tema tema : reuniao.getTemas()) {
                RelatorioTemasMaisDiscutidosVo rel = null;
                for (RelatorioTemasMaisDiscutidosVo item : lista) {
                    if (item.getNomeTema().equals(tema.getNome())) {
                        rel = item;
                        break;
                    }
                }
                if (rel == null) {
                    rel = new RelatorioTemasMaisDiscutidosVo(tema.getNome(), 1L);
                    lista.add(rel);
                } else {
                    rel.setOcorrencias(rel.getOcorrencias() + 1);
                }
            }
        }

        lista.sort((a, b) -> Long.compare(b.getOcorrencias(), a.getOcorrencias()));

        return lista;
    }

    public List<RelatorioPresencaRepresentanteVo> gerarRelatorioPresenca() {
        List<Reuniao> reunioes = reuniaoDao.buscarTodos();
        List<RelatorioPresencaRepresentanteVo> lista = new ArrayList<>();

        for (Reuniao reuniao : reunioes) {
            Representante presidente = reuniao.getPresidente();
            if (presidente != null) {
                RelatorioPresencaRepresentanteVo rel = null;
                for (RelatorioPresencaRepresentanteVo item : lista) {
                    if (item.getNomeRepresentante().equals(presidente.getNome())) {
                        rel = item;
                        break;
                    }
                }
                if (rel == null) {
                    String paisNome = (presidente.getPais() != null) ? presidente.getPais().getNome() : "(Sem país)";
                    rel = new RelatorioPresencaRepresentanteVo(presidente.getNome(), paisNome, 1L);
                    lista.add(rel);
                } else {
                    rel.setTotalPresidencias(rel.getTotalPresidencias() + 1);
                }
            }
        }

        lista.sort((a, b) -> Long.compare(b.getTotalPresidencias(), a.getTotalPresidencias()));

        return lista;
    }
}
