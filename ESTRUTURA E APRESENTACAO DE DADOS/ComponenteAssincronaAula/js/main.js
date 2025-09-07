import { renderizarProdutos } from "./RenderizarProdutoComponent.js";

window.onload = async () => {
    try {
        await renderizarProdutos(); // Chama a função para renderizar os produtos
        console.log('Produtos carregados e renderizados com sucesso.');
    } catch (error) {
        console.error('Erro ao carregar os produtos:', error);
    }
}