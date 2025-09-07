
import { Produto } from './Produto.js'; 

const btSalvar = document.querySelector('#btSave');
// console.log(btSalvar);

btSalvar.addEventListener('click',function(e){
    e.preventDefault();//cancelar a ação padrão de submit (recarregar a página)
    // console.log('Cliquei');
    const nome = document.getElementById('name').value;
    let preco = document.getElementById('price').value;
    preco = (preco.replace(',', '.'));
    const precoNumerico = parseFloat(preco).toFixed(2);
    const quant = 1;

    if ( isNaN(precoNumerico) || precoNumerico <= 0) {
        alert('Preço inválido. Por favor, insira um valor numérico maior que zero.');
        return;
    }

    // const produto = {
    //     nomeProduto: nome,
    //     precoProduto: preco,
    //     quant: 1
    // }
    // console.log(produto);

    const produto = new Produto(nome, preco, quant);
    console.log(produto);
    limpaCampos();
    salvarProdutoStorage(produto);
})

// function Produto(nome, preco, quant){
//     this.nome = nome;
//     this.preco = preco;
//     this.quant = quant;
// }


function limpaCampos(){
    document.getElementById('name').value='';
    document.getElementById('price').value='';
}

let produtos = JSON.parse(localStorage.getItem('produtos')) || [];
function salvarProdutoStorage(produto){
   produtos.push(produto);
   localStorage.setItem('produtos', JSON.stringify(produtos));
}