document.addEventListener('DOMContentLoaded', function() {
    // navbar
    fetch('../../components/navbar/navbar.html')
        .then(response => response.text())
        .then(data => {
            document.getElementById('navbar-container').innerHTML = data;
        })
        .catch(error => console.error('Error loading navbar:', error));
        
        
    // footer
    fetch('../../components/footer/footer.html')
        .then(response => response.text())
        .then(data => {
            document.getElementById('footer-container').innerHTML = data;
        })
        .catch(error => console.error('Error loading footer:', error));

    // Função para adicionar CSS de um componente
    function addComponentCSS(component) {
        const cssPath = `../../components/${component}/${component}.css`;
        if (!document.querySelector(`link[data-component-css="${component}"]`)) {
            const link = document.createElement('link');
            link.rel = 'stylesheet';
            link.href = cssPath;
            link.setAttribute('data-component-css', component);
            document.head.appendChild(link);
        }
    }

    // Função para remover CSS de um componente
    function removeComponentCSS(component) {
        const link = document.querySelector(`link[data-component-css="${component}"]`);
        if (link) link.parentNode.removeChild(link);
    }

    // Função para remover todos os CSS de componentes
    function removeAllComponentCSS() {
        document.querySelectorAll('link[data-component-css]').forEach(link => link.parentNode.removeChild(link));
    }

    // Função para restaurar o CSS da home
    function restoreHomeCSS() {
        if (!document.querySelector('link[href$="index.css"]')) {
            const link = document.createElement('link');
            link.rel = 'stylesheet';
            link.href = 'index.css';
            document.head.appendChild(link);
        }
    }

    // Função para remover o CSS da home
    function removeHomeCSS() {
        const homeCss = document.querySelector('link[href$="index.css"]');
        if (homeCss) homeCss.parentNode.removeChild(homeCss);
    }

    function showHome() {
    document.getElementById('home-component').style.display = 'block';
    document.getElementById('dynamic-content').innerHTML = '';
    removeAllComponentCSS();
    restoreHomeCSS();
    // Mostra navbar e footer
    document.getElementById('navbar-container').style.display = 'block';
    document.getElementById('footer-container').style.display = 'block';
    window.scrollTo(0, 0);
}

// Páginas Dinamicas de Componentes
document.body.addEventListener('click', async function (e) {
    const link = e.target.closest('[data-component]');
    if (link) {
        e.preventDefault();
        const component = link.getAttribute('data-component');
        if (component.toLowerCase() === 'home') {
            showHome();
            return;
        }
        const container = document.getElementById('dynamic-content');
        if (container) {
            // Esconde a home
            document.getElementById('home-component').style.display = 'none';
            removeHomeCSS();
            removeAllComponentCSS();

            // Carrega o componente
            const response = await fetch(`../../components/${component}/${component}.html`);
            const html = await response.text();
            container.innerHTML = html;

            // Adiciona o CSS do componente
            addComponentCSS(component);

            // Esconde navbar/footer se for login ou signup
            if (component.toLowerCase() === 'login' || component.toLowerCase() === 'signup') {
                document.getElementById('navbar-container').style.display = 'none';
                document.getElementById('footer-container').style.display = 'none';
            } else {
                document.getElementById('navbar-container').style.display = 'block';
                document.getElementById('footer-container').style.display = 'block';
            }

            // Permite que links com data-component="home" voltem para a home dentro do componente carregado
            container.querySelectorAll('[data-component="home"]').forEach(homeLink => {
                homeLink.addEventListener('click', function (event) {
                    event.preventDefault();
                    showHome();
                });
            });

            window.scrollTo(0, 0);
            }
        }
    });
});