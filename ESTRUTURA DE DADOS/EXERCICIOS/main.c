#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int EX1(){
    typedef struct pedido Pedido;

    struct pedido {
        char nomeCliente[50];
        char descricao[50];
        float valorTotal;
    };

    Pedido p;
    printf("Nome do cliente: ");
    gets(p.nomeCliente);

    printf("Descricao do pedido: ");
    gets(p.descricao);

    printf("Valor total do pedido: R$");
    scanf("%f", &p.valorTotal);


    printf("\nNome: %s", p.nomeCliente);
    printf("\nDescricao: %s", p.descricao);
    printf("\nvalor: R$%.2f", p.valorTotal);

    return 0;
}

int EX2(){

    typedef struct instrumento Instrumento;
    typedef struct instrumentos Instrumentos;

    struct instrumento {
        char modelo[30];
        char marca[30];
        float preco;
    };

    Instrumento vetInstrumentos[5];

    strcpy(vetInstrumentos[0].modelo, "Violao");
    strcpy(vetInstrumentos[1].modelo, "Piano");
    strcpy(vetInstrumentos[2].modelo, "Teclado");
    strcpy(vetInstrumentos[3].modelo, "Violino");
    strcpy(vetInstrumentos[4].modelo, "Bateria");

    strcpy(vetInstrumentos[0].marca, "Tagima");
    strcpy(vetInstrumentos[1].marca, "Takumi");
    strcpy(vetInstrumentos[2].marca, "Aplle");
    strcpy(vetInstrumentos[3].marca, "Nokia");
    strcpy(vetInstrumentos[4].marca, "Yamaha");

    vetInstrumentos[0].preco = 10;
    vetInstrumentos[1].preco = 20;
    vetInstrumentos[2].preco = 15;
    vetInstrumentos[3].preco = 90;
    vetInstrumentos[4].preco = 9.03;

    int p;

    do{

        printf("\nInforme um valor: R$");
        scanf("%d", &p);



        for(int i = 0; i < 5; i++){
            if(vetInstrumentos[i].preco < p){
                printf("\n%d - Modelo: %s", i+1, vetInstrumentos[i].modelo);
                printf("\n%d - Marca: %s", i+1, vetInstrumentos[i].marca);
                printf("\n%d - Preco: R$%.2f\n", i+1, vetInstrumentos[i].preco);
            }
        }
    }while(p != 0);

    return 0;
}

int EX3(){

    typedef struct  dosesVacinas DosesVacinas;

    struct dosesVacinas {
        char nomePaciente[30];
        char cidade[30];
        int idade;
    };

    DosesVacinas vetDoses[5];

    for(int i = 0; i < 5; i++){
            fflush(stdin);
        printf("\nInforme o nome do %d paciente: ", i+1);
        gets(vetDoses[i].nomePaciente);

        printf("Informe a cidade do %d paciente: ", i+1);
        gets(vetDoses[i].cidade);

        printf("Informe a idade do %d paciente: ", i+1);
        scanf("%d", &vetDoses[i].idade);
    }

    for(int i = 0; i < 5; i++){
        printf("\n\nPaciente %d\nNome: %s\nCidade: %s\nIdade: %d", i+1, vetDoses[i].nomePaciente, vetDoses[i].cidade, vetDoses[i].idade);
    }

    return 0;
}

int EX4(){

    typedef struct aluno Aluno;

    struct aluno {
        int matricula;
        char nome[30];
        float n1;
        float n2;
        float n3;
    };

    Aluno vetAlunos[5];

    for(int i = 0; i < 5; i++){
        printf("\n%d - Informe a matricula: ", i+1);
        scanf("%d", &vetAlunos[i].matricula);

        fflush(stdin);
        printf("%d - Informe o nome: ", i+1);
        gets(vetAlunos[i].nome);

        printf("%d - Informe a nota 1: ", i+1);
        scanf("%f", &vetAlunos[i].n1);

        printf("%d - Informe a nota 2: ", i+1);
        scanf("%f", &vetAlunos[i].n2);

        printf("%d - Informe a nota 3: ", i+1);
        scanf("%f", &vetAlunos[i].n3);
    }

    float media = 0;

    float maiorN1 = vetAlunos[0].n1;
    float maiorMedia = (vetAlunos[0].n1 + vetAlunos[0].n2 + vetAlunos[0].n3) / 3;
    float menorMedia = (vetAlunos[0].n1 + vetAlunos[0].n2 + vetAlunos[0].n3) / 3;

    for(int i = 0; i < 5; i++){

        media = (vetAlunos[i].n1 + vetAlunos[i].n2 + vetAlunos[i].n3) / 3;

        if(vetAlunos[i].n1 > maiorN1){
            maiorN1 = vetAlunos[i].n1;
        }

        if(media > maiorMedia){
            maiorMedia = media;
        }

        if(media < menorMedia){
            menorMedia = media;
        }
    }

    printf("\nO aluno com a maior nota da primeira prova com a nota %.2f", maiorN1);
    printf("\nO aluno com a maior media das provas foi com a media %.2f", maiorMedia);
    printf("\nO aluno com a menor media das provas foi com a media %.2f", menorMedia);

    for(int i = 0; i < 5; i++){
        media = (vetAlunos[i].n1 + vetAlunos[i].n2 + vetAlunos[i].n3) / 3;

        if(media >= 6){
            printf("\nO aluno %d foi APROVADO com media %.2f", i+1, media);
        }
        else{
            printf("\nO aluno %d foi REPROVADO com media %.2f", i+1, media);
        }
    }

    return 0;
}

int EX5(){

    typedef struct data Data;
    typedef struct atleta Atleta;

    struct data{
        int dia;
        int mes;
        int ano;
    };

    struct atleta{
        char nome[30];
        char CPF[9];
        Data dtNascimento;
        char modalidade[30];
        float salario;
    };

    Atleta a;

    printf("Informe o nome do atleta: ");
    gets(a.nome);

    printf("Informe o CPF do atleta: ");
    gets(a.CPF);

    printf("Informe o dia de nascimento: ");
    scanf("%d", &a.dtNascimento.dia);

    printf("Informe o mes de nascimento: ");
    scanf("%d", &a.dtNascimento.mes);

    printf("Informe o ano de nascimento: ");
    scanf("%d", &a.dtNascimento.ano);

    fflush(stdin);

    printf("Informe a modalidade do atleta: ");
    gets(a.modalidade);

    printf("Informe o salario do atleta: R$");
    scanf("%f", &a.salario);

    printf("\nNome: %s", a.nome);
    printf("\nCPF: %s", a.CPF);
    printf("\nData de Nascimento: %d/%d/%d", a.dtNascimento.dia, a.dtNascimento.mes, a.dtNascimento.ano);
    printf("\nModalidade: %s", a.modalidade);
    printf("\nSalario: R$%.2f", a.salario);

    return 0;
}

int EX6(){

    typedef struct aluno Aluno;

    struct aluno{
        char nome[30];
        int matricula;
        float mediaFinal;
    };

    Aluno a[8];
    int num = 0, j = 0, k = 0;

    for(int i = 0; i < 8; i++){
        fflush(stdin);
        printf("\n%d - Informe o nome do aluno: ", i+1);
        gets(a[i].nome);

        printf("%d - Informe a matricula: ");
        scanf("%d", &a[i].matricula);

        printf("Informe a media final do aluno: ");
        scanf("%f", &a[i].mediaFinal);
    }

    for(int i = 0; i < 8; i++){
        if(a[i].mediaFinal >= 5){
            num++;
        }
    }

    Aluno vetAprovados[num];
    Aluno vetReprovados[8-num];

    for(int i = 0; i < 8; i++){
        if(a[i].mediaFinal >= 5){
            vetAprovados[j] = a[i];
            j++;
        }
        else{
            vetReprovados[k] = a[i];
            k++;
        }
    }

    printf("\nAPROVADOS");
    for(int i = 0; i < num; i++){
        printf("\n%s", vetAprovados[i].nome);
    }

    printf("\n\nREPROVADOS");
    for(int i = 0; i < (8-num); i++){
        printf("\n%s", vetReprovados[i].nome);
    }

    return 0;
}

int EX7(){

    typedef struct coordenadaPolar CoordenadaPolar;
    typedef struct coordenadaCartesiano CoordenadaCartesiano;

    struct coordenadaPolar{
        float r;
        float a;
    };

    struct coordenadaCartesiano{
        float x;
        float y;
    };

    CoordenadaPolar cp;
    CoordenadaCartesiano cc;

    printf("Informe o raio da coordenada: ");
    scanf("%f", &cp.r);

    printf("Informe o argumento da coordenada: ");
    scanf("%f", &cp.a);

    cc.x = cp.r * cos(cp.a);

    cc.y = cp.r * sin(cp.a);

    printf("\nPONTO: (%.2f, %.2f)", cc.x, cc.y);

    return 0;
}

int EX8(){

    typedef struct livro Livro;

    struct livro{
        char titulo[30];
        char autor[30];
        int ano;
    };

    Livro l[5];
    int opcao, i = 0, pesquisaAno;
    char pesquisaNome[30];

    do{
        printf("\n0 - SAIR DO PROGRAMA\n\n1 - Cadastrar um livro\n2 - Buscar livros pelo título\n3 - Buscar livros pelo ano\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                fflush(stdin);
                printf("\nInforme o nome do livro: ");
                gets(l[i].titulo);

                printf("Informe o autor: ");
                gets(l[i].titulo);

                printf("Informe o ano: ");
                scanf("%d", &l[i].ano);

                i++;

                break;

            case 2:
                printf("\nPesquise o nome do livro: ");
                gets(pesquisaNome);

                for(int j = 0; j < i; j++){
                    if(pesquisaNome == l[j].titulo){
                        printf("\n%d - %s", j+1, l[j].titulo);
                    }
                }

                break;

            case 3:
                printf("\nPesquise o ano do livro: ");
                scanf("%d", &pesquisaAno);

                for(int j = 0; j < i; j++){
                    if(pesquisaAno == l[j].ano){
                        printf("\n%s - %d", l[j].titulo, l[j].ano);
                    }
                }

                break;
        }

    }while(opcao != 0);

    return 0;
}

int main()
{
    // EX1();
    // EX2();
    // EX3();
    // EX4();
    // EX5();
    // EX6();
    // EX7();
    EX8();
    return 0;
}
