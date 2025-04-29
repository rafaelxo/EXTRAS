const dados = {
    usuarios: [{
        id: 1,
        nome: "João Santos",
        login: "joao",
        senha: "abc123",
        email: "joao@gmail.com"
    }, {
        id: 2,
        nome: "Maria Oliveira",
        login: "maria",
        senha: "123456",
        email: "mariaol@gmail.com"
    }]
}

let usuario = null;

function checkLoggedUser () {
    const usuarioStr = sessionStorage.getItem('usuario');
    if (!usuarioStr) {
        location.href = 'login.html';
    }

    usuario = JSON.parse (usuarioStr);
    return true;
}

function loginUser (login, password) {
    const usuarioObj = dados.usuarios.find (elem => (elem.login === login) && (elem.senha === password));
    if (!usuarioObj) {
        return false;
    } else {
        sessionStorage.setItem('usuario', JSON.stringify(usuarioObj));
        return true;
    }
}

function logoutUser () {
    sessionStorage.clear();
    location.href = 'login.html';
}