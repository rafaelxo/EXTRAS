var Cadastro = [{
    "nome": "Rommel Carneiro",
    "cidade": "Belo Horizonte",
    "idade": 25,
    "veiculos": [{
        "marca": "Fiat",
        "modelo": "Toro",
        "ano": 2020,
        "placa": "HMV-1010"
    }]
}, {
    "nome": "Maria Tereza",
    "cidade": "São Paulo",
    "idade": 28,
    "veiculos": []
}, {
    "nome": "Pedro Augusto",
    "cidade": "Rio de Janeiro",
    "idade": 48,
    "veiculos": [{
        "marca": "Ford",
        "modelo": "Territory",
        "ano": 2021,
        "placa": "XYZ-4321",
    }, {
        "marca": "Toyota",
        "modelo": "Etios",
        "ano": 2019,
        "placa": "XWY-1368",
    }]
}];

function ExibirCadastro() {
    var textoHTML = '';
    for (let x = 0; x < Cadastro.length; x++) {
        textoHTML += `Pessoa: ${Cadastro[x].nome} <br>`;
        if (Cadastro[x].veiculos.length > 0) {
            textoHTML += '<ul>';
        }
        for (let y = 0; y < Cadastro[x].veiculos.length; y++) {
            let marca = Cadastro[x].veiculos[y].marca;
            let modelo = Cadastro[x].veiculos[y].modelo;
            let ano = Cadastro[x].veiculos[y].ano;
            let placa = Cadastro[x].veiculos[y].placa;
            textoHTML += `<li>${marca} - ${modelo} - ${ano} - ${placa}</li>`;
        }
        if (Cadastro[x].veiculos.length > 0) {
            textoHTML += '</ul>';
        }
    }
    var tela = document.getElementById('tela');
        tela.innerHTML = textoHTML;
}