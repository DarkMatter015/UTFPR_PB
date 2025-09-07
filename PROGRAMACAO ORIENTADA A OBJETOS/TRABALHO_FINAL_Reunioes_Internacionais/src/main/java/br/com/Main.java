package br.com;

import br.com.view.MainView;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;


public class Main {
    private static EntityManager manager;

    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("PostgresPU");
        manager = emf.createEntityManager();

        MainView mainView = MainView.getInstance(manager);
        mainView.iniciar();

        manager.close();
        emf.close();

        System.out.println("Programa encerrado.");
    }
}