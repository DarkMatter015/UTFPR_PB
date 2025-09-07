package br.edu.utfpr.views;

import br.edu.utfpr.carro.Veiculo;

public class UsandoVeiculo {
    public static void main(String[] args) {
        Veiculo veiculo1 = new Veiculo();

        veiculo1.setMarca("Ford");
        veiculo1.setModelo("KA");
        veiculo1.setVelocidade(12);

        Veiculo veiculo2 = new Veiculo();

        veiculo2.setMarca("Hyundai");
        veiculo2.setModelo("HB20");
        veiculo2.setVelocidade(135);

        System.out.println(veiculo1);

        System.out.println(veiculo2);

        veiculo2.desacelerar();

        System.out.println(veiculo2);

        veiculo1.acelerar();

        System.out.println(veiculo1);
        System.out.println(veiculo1.buzinar());
    }
}
