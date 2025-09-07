import {cardComponent} from './CardComponent.js';   

async function carregaProdutos() {
    try {
        const response = await fetch('../data/produtos.json'); // Buscando dados de um arquivo JSON externo
        const produtos = await response.json();
        console.log(produtos);
        return produtos; // Retorna os produtos carregados
    } catch (error) {
        console.error('Erro ao carregar os produtos:', error);
    }
}

export async function renderizarProdutos() {
    const produtos = await carregaProdutos();
    const container = document.getElementById('produtosContainer');

     try {
        produtos.forEach(produto => {
            const produtoCard = document.createElement("div");
            produtoCard.classList.add("col-lg-3", "col-md-4", "col-sm-6", "mb-4");
            produtoCard.innerHTML = cardComponent(produto);
            produtoCard.querySelector('.btn-adicionar').addEventListener('click', adicionarAoCarrinho);
            container.appendChild(produtoCard);
        });

        // Armazenando os produtos no localStorage
        localStorage.setItem('produtos', JSON.stringify(produtos)); // Armazenando os produtos no localStorage
        console.log('Produtos renderizados e armazenados no localStorage.');
    } catch (error) {
        console.error('Erro ao renderizar os produtos:', error);
    }
}

function adicionarAoCarrinho(event) {
    const produtoId = Number(event.target.getAttribute('data-id')); // Obtendo o ID do produto do botão clicado
    console.log(`Produto com ID ${produtoId} adicionado ao carrinho.`); 
    
    let arrayProdutos = JSON.parse(localStorage.getItem('produtos')) || [];
    let carrinho = JSON.parse(localStorage.getItem("carrinho")) || [];

    const produtoSelecionado = arrayProdutos.find(produto => produto.id === produtoId); // Encontrando o produto selecionado pelo ID

    if (!produtoSelecionado) {
        console.error(`Produto com ID ${produtoId} não encontrado.`);
        return; // Se o produto não for encontrado, sai da função
    }

    const jaExiste = carrinho.some(produto => produto.id === produtoId); // Verifica se o produto já está no carrinho
    if (jaExiste) {
        alert(`Produto ${produtoSelecionado.nome} já está no carrinho.`);
        return; // Se o produto já estiver no carrinho, sai da função
    }
    carrinho.push(produtoSelecionado); // Adicionando o produto selecionado ao carrinho
    localStorage.setItem("carrinho", JSON.stringify(carrinho)); // Armazenando o carrinho atualizado no localStorage
    console.log(`Produto com ID ${produtoId} adicionado ao carrinho:`, produtoSelecionado);
}