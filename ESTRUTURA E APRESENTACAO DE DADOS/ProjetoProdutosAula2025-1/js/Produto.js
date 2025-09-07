export class Produto{
    constructor(nome, preco, quant){
        this.nome = nome;
        this.preco = preco;
        this.quant = quant;
    }

    getTotal(){
        return this.preco * this.quant;
    }
}

