package br.com.model;

// Importação das anotações necessárias do JPA (Java Persistence API).
import jakarta.persistence.*;

@Entity // Define que a classe é uma entidade JPA, ou seja, será mapeada para uma tabela no banco de dados.
@Table(name = "categorias") // Define o nome da tabela no banco de dados que essa entidade irá representar.
// Neste caso, a tabela 'categorias'.
public class Categoria {

    // Atributo que será usado como chave primária na tabela do banco de dados.
    @Id // Indica que o campo 'id' é a chave primária da tabela.
    @GeneratedValue(strategy = GenerationType.IDENTITY) // Define a estratégia de geração do valor da chave primária. // 'IDENTITY' significa que o valor será gerado automaticamente // pelo banco de dados.
    private Long id;

    private String nome;

    // Construtor padrão sem parâmetros. Necessário para que o JPA possa instanciar a classe ao recuperar dados do BD.
    public Categoria() {
    }

    // Construtor com o parâmetro 'nome'. Permite criar uma instância de 'Categoria' com um nome específico.
    public Categoria(String nome) {
        this.nome = nome;
    }

    public Long getId() {
        return id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    // Sobrescrita do metodo 'toString', usado para retornar uma representação em String da instância da classe.
    // Isso é útil para depuração e exibição de dados da entidade de forma legível.
    @Override
    public String toString() {
        // StringBuilder é utilizado para construir a string de forma eficiente.
        StringBuilder sb = new StringBuilder();
        sb.append("Categoria{")
                .append("id=").append(id)
                .append(", nome=").append(nome)
                .append('}');
        return sb.toString();
    }
}
