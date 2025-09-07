package br.com.service;

import br.com.dao.VendaDao;
import br.com.vo.RelatorioDeVendasVo;
import br.com.vo.RelatorioFinanceiroVo;
import jakarta.persistence.EntityManager;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;

public class VendaService {

    private VendaDao vendaDAO;

    public VendaService(EntityManager manager) {
        this.vendaDAO = new VendaDao(manager);
    }

    public BigDecimal retornaValorTotalVendido(LocalDate dataIni, LocalDate dataFim){
        return this.vendaDAO.valorTotalVendidoPorPeriodo(dataIni, dataFim);
    }

    public List<RelatorioDeVendasVo> retornaRelatorioDeVendas(){
        return this.vendaDAO.relatorioDeVendas();
    }

    public List<RelatorioFinanceiroVo> retornaRelatorioFinanceiro(){
        return this.vendaDAO.relatorioFinanceiro();
    }
}
