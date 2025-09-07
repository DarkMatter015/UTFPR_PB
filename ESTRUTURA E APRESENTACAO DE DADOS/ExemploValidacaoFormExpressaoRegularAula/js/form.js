import {Modal} from './modal.js';

const modal = new Modal("myModal");

function validarCampoObrigatorio(input, elementoErro, elementoSucesso, mensagem) {
    if (input.value.trim() === "") {
        elementoErro.textContent = mensagem;
        input.classList.add("input-error");
        input.classList.remove("input-success");
        elementoSucesso.textContent = "";
        return false;
    }
    elementoErro.textContent = "";
    input.classList.remove("input-error");
    input.classList.add("input-success");
    elementoSucesso.textContent = "Campo preenchido com sucesso!";
    return true;
}

function validarEmail(input, elementoErro, elementoSucesso) {
    const regexEmail = /^[a-zA-Z0-9._%]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

    if (input.value.trim() === "") {
        elementoErro.textContent = "O email é de preenchimento obrigatório.";
        input.classList.add("input-error");
        input.classList.remove("input-success");
        elementoSucesso.textContent = "";
        return false;
    } else if (!regexEmail.test(input.value.trim())) {
        elementoErro.textContent = "O formato email inválido! Ex: example@example.com";
        input.classList.add("input-error");
        return false;
    }

    elementoErro.textContent = "";
    input.classList.remove("input-error");
    input.classList.add("input-success");
    elementoSucesso.textContent = "Email preenchido com sucesso!";
    return true;
}

document.getElementById("nome").addEventListener("blur", function() {
    validarCampoObrigatorio(
        this, 
        document.getElementById("erroNome"),
        document.getElementById("sucessoNome"),
        "O nome é de preenchimento obrigatório.");
})

document.getElementById("email").addEventListener("blur", function() {
    validarEmail(
        this,
        document.getElementById("erroEmail"),
        document.getElementById("sucessoEmail")
    );
})

document.getElementById("meuFormulario").addEventListener("submit", function(event) {
    event.preventDefault();

    const nome = document.getElementById("nome");
    const email = document.getElementById("email");
    
    
    const erroNome = document.getElementById("erroNome");
    const erroEmail = document.getElementById("erroEmail");

    const sucessoNome = document.getElementById("sucessoNome");
    const sucessoEmail = document.getElementById("sucessoEmail");

    const nomeValido = validarCampoObrigatorio(nome, erroNome, sucessoNome, "O nome é de preenchimento obrigatório.");
    const emailValido = validarEmail(email, erroEmail, sucessoEmail);

    if (nomeValido && emailValido) {
        modal.open();
        nome.value = "";
        email.value = "";
        nome.classList.remove("input-success");
        email.classList.remove("input-success");
        document.getElementById("sucessoNome").textContent = "";
        document.getElementById("sucessoEmail").textContent = "";
    }
})