package br.edu.utfpr.main;

import br.edu.utfpr.entidades.*;
import br.edu.utfpr.enums.TipoPagamento;

import java.time.LocalDate;

public class UsandoVenda {
    public static void main(String[] args) {
        LocalDate data = LocalDate.now();
        Cliente cliente = new Cliente("DARTH VADER", 1234000193);
        Vendedor vendedor = new Vendedor(1000000, "Mestre YODA", 00000000);


        Produto produto1 = new Produto("Sabre de Luz", 10000);
        Produto produto2 = new Produto("Mileniun Falcon", 8000000);
        Produto produto3 = new Produto("Lagarto do Espaco", 5);
        ItemVenda item1 = new ItemVenda(produto1, 1);
        ItemVenda item2 = new ItemVenda(produto2, 1);
        ItemVenda item3 = new ItemVenda(produto3, 5);

        Venda venda = new Venda(data, cliente, vendedor, TipoPagamento.PIX);
        venda.adicionarItemVenda(item1);
        venda.adicionarItemVenda(item2);
        venda.adicionarItemVenda(item3);

        System.out.println(venda);
    }
}
