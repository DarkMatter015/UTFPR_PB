function novoProduto(produto) { //objeto 
    const novaTr = `
        <tr>
            <td>${produto.nome}</td>
            <td>${produto.preco}</td>
            <td><input class="quantity" type="number" value="${produto.quant}"></td>
            <td class="total">${(produto.preco * produto.quant)}</td>
            <td class=""><i class="fa fa-trash"></i></td>
        </tr>
    `
    return novaTr;
}

document.addEventListener('DOMContentLoaded', function () {
    const produtos = JSON.parse(localStorage.getItem('produtos')) || [];
    produtos.forEach(prod => {
        addProdutoTabela(prod);
    });
})

function addProdutoTabela(produto) {
    const tableBody = document.querySelector('#tbProducts tbody');
    tableBody.insertAdjacentHTML('beforeend', novoProduto(produto));

}

document.querySelector('#tbProducts tbody').addEventListener('input', (e) => {
    // console.log(e.target);
    const target = e.target;
    const row = e.target.closest('tr');
    // console.log(row);

    const novaQuant = Number(target.value.trim());
    
    if( isNaN(novaQuant) || novaQuant <= 0) {
        alert('Quantidade não pode ser menor ou igual a zero. Por favor, insira um número válido.');
        target.value = '';
        target.classList.add('erro');
        
        return;
    }

    target.classList.remove('erro');

    const nome = row.querySelector('td:first-child').textContent;

    atualizarStorage(nome, novaQuant, row);
})


function atualizarStorage(nome, novaQuant, row) {
    const produtos = JSON.parse(localStorage.getItem('produtos')) || [];

    const produtoIndex = produtos.findIndex(prod => prod.nome === nome);
    // console.log(produtoIndex);

    if (produtoIndex !== -1) {
        produtos[produtoIndex].quant = novaQuant;
        localStorage.setItem('produtos', JSON.stringify(produtos));

        const preco = parseFloat(row.querySelector('td:nth-child(2)').textContent);
        row.querySelector('.total').textContent = parseFloat(preco * novaQuant).toFixed(2);
    }

    // const produtoIndex = produtos.findIndex(prod => prod.nome === nome);

    // if (produtoIndex !== -1) {
    //     const quantity = parseFloat(row.querySelector('.quantity').value);
    //     produtos[produtoIndex].quant = quantity;
    //     produtos[produtoIndex].total = (preco * quantity).toFixed(2);
    //     localStorage.setItem('produtos', JSON.stringify(produtos));
    // }
}

document.querySelector('#tbProducts tbody').addEventListener('click', (e) => {
    const target = e.target;

    if (target.classList.contains('fa-trash')) {

        // removerProduto(nome);
        console.log('Remover produto');

        // console.log(target.closest('tr'));
        const row = target.closest('tr');
        const nome = row.querySelector('td:first-child').textContent;
        if(confirm('Deseja remover o produto ' + nome + '?')) {
            row.remove();
            removerDoStorage(nome)
        }
    }
});

// remove apenas o primeiro produto com o mesmo nome
function removerDoStorage(nome) {
    const produtos = JSON.parse(localStorage.getItem('produtos')) || [];

    const produto = produtos.find(prod => prod.nome === nome);
    
    if (produto) {
        const produtoIndex = produtos.indexOf(produto);
        produtos.splice(produtoIndex, 1);
        localStorage.setItem('produtos', JSON.stringify(produtos));
    }
}

// remove todos com o mesmo nome
// function removerDoStorage(nome) {
//     const produtos = JSON.parse(localStorage.getItem('produtos')) || [];

//     const produto = produtos.filter(prod => prod.nome !== nome);
//     localStorage.setItem('produtos', JSON.stringify(produto));
// }