
/*int alteraVetor(int *vet, int n){

    vet[0] = n;

}

char *match(char c, char *s){

    while(c != *s && *s){
        s = s + 1;
    }

    return s;
}
*/

typedef struct cliente Cliente;

struct cliente{
    char nome[30];
    char rua[30];
    int numero;
};

int alterarEndereco(Cliente *cli, char rua[], int num){
    strcpy(cli -> rua, rua);
    cli -> numero = num;
}

void imprimeCliente(Cliente *cli){
    printf("\nNome: %s", cli -> nome);
    printf("\nRua: %s", cli -> rua);
    printf("\nNumero: %d", cli -> numero);
}

void main(){

   /* char c = 'a';
    int n = 10;
    char *pc; //ponteiro
    int *pn; // ponteiro

    printf("\nValor de C: %c", c);
    printf("\nValor de N: %d", n);

    printf("\nEndereco de C: %ld", &c);
    printf("\nEndereco de N: %ld", &n);

    pc = &c;
    pn = &n;

    printf("\npc aponta para o endereco de c que eh: %ld", pc);
    printf("\npn aponta para o endereco de n que eh: %ld", pn);
    printf("\nO endereco apontado por pc para este conteudo: %c", *pc);
    printf("\nO endereco apontado por pn para este conteudo: %ld", *pn);

    *pn = 20;

    printf("\nValor de N: %d", n);
    */

    /*short int vet[] = {20, 30, 40, 50, 60};
    short int *p = vet;

    printf("p aponta para o endereco: %ld\n", p);
    printf("o valor guardado no enderco acima eh: %d\n", *p);

    p = p + 2;
    printf("p eh incrementado em 2:\n");
    printf("p aponta para o endereco: %ld\n", p);
    printf("o valor guardado no enderco acima eh: %d\n", *p);

    p = p - 1;
    printf("p eh decrementado em 1:\n");
    printf("p aponta para o endereco: %ld\n", p);
    printf("o valor guardado no enderco acima eh: %d\n", *p);*/

    /*int i, n = 5;
    int v[] = {1, 2, 3, 4, 5};
    alteraVetor(v, n);

    for(i = 0; i < n; i++){
        printf("%d\t", v[i]);
    }


    char str[] = "Boa noite";
    char c = 'a';
    char *p;

    p = match(c, str);

    if(*p){
        printf("\n%s", p);
    }
    else{
        printf("nao encontrou o caractere.");
    }
    */

    Cliente c1;
    strcpy(c1.nome, "Maria");
    strcpy(c1.rua, "Rua guarani");
    c1.numero = 13;

    imprimeCliente(&c1);
    alterarEndereco(&c1, "Avenida Tupi", 20);
    imprimeCliente(&c1);

    return 0;
}
