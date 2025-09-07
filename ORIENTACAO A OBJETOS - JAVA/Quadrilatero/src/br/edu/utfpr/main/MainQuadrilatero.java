package br.edu.utfpr.main;

import br.edu.utfpr.quadrilatero.Quadrilatero;

public class MainQuadrilatero {
    public static void main(String[] args) {
        Quadrilatero q = new Quadrilatero(4, 4);

        System.out.println(q.toString());
        System.out.println("É quadrado: " + q.isQuadrado());
        System.out.println("É retangulo: " + q.isRetangulo());
    }
}
