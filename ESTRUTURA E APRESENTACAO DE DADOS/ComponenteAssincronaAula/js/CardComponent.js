export function cardComponent(arroz) {
  return `
    <div class="card h-100 mx-2">
        <div class="card-body">
            <h2>${arroz.nome}</h2>
            <img src="../img/${arroz.imagem}" class="img-fluid mb-2" alt="${arroz.nome}">
            <p>${arroz.marca}</p>
            <p>${arroz.preco}</p>
            <button data-id="${arroz.id}" class="btn btn-primary btn-adicionar">Adicionar ao carrinho</button>
        </div>
    </div>
  `;
}