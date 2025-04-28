document.addEventListener('DOMContentLoaded', () => {
    // Estrutura JSON para armazenar os feedbacks
    let dados = {
        feedback: JSON.parse(localStorage.getItem('feedbacks')) || []
    };

    // Seleção de elementos do DOM
    const form = document.getElementById('formulario');
    const cancelarBtn = document.getElementById('cancelar');
    const limparBtn = document.getElementById('limpar');
    const registrarBtn = document.getElementById('registrar');
    const inputs = form.querySelectorAll('input');

    // Função para formatar data de YYYY-MM-DD para DD/MM/YYYY
    function formatarData(data) {
        if (!data) return '';
        const [ano, mes, dia] = data.split('-');
        return `${dia}/${mes}/${ano}`;
    }

    // Função para coletar dados do formulário
    function coletarDados() {
        return {
            id_usuario: 1, // Fixo, pode ser ajustado com autenticação
            data_inicio: formatarData(document.getElementById('data').value),
            atrasos_iniciais: document.getElementById('atrasos').value.trim(),
            objetivos_iniciais: document.getElementById('objetivos').value.trim(),
            atividades_realizadas: document.getElementById('atividades').value.trim(),
            dificuldades_encontradas: document.getElementById('dificuldades').value.trim(),
            beneficios_obtidos: document.getElementById('beneficios').value.trim(),
            tempo_duracao: document.getElementById('tempo').value.trim(),
            nivel_satisfacao: parseInt(document.getElementById('satisfacao').value) || 0,
            observacoes: document.getElementById('observacoes').value.trim(),
            proximas_metas: document.getElementById('metas').value.trim(),
            data_registro: new Date().toISOString()
        };
    }

    // Função para limpar mensagens de erro e estilos
    function limparErros() {
        inputs.forEach(input => {
            input.classList.remove('invalid');
            const erroDiv = document.getElementById(`erro-${input.id}`);
            if (erroDiv) {
                erroDiv.style.display = 'none';
                erroDiv.textContent = '';
            }
        });
    }

    // Função para exibir mensagem de erro
    function exibirErro(campoId, mensagem) {
        const input = document.getElementById(campoId);
        const erroDiv = document.getElementById(`erro-${campoId}`);
        if (input && erroDiv) {
            input.classList.add('invalid');
            erroDiv.textContent = mensagem;
            erroDiv.style.display = 'block';
        }
    }

    // Função para validar os campos do formulário
    function validarFormulario(dados) {
        const camposObrigatorios = [
            { id: 'data', key: 'data_inicio', label: 'Data de Início' },
            { id: 'atrasos', key: 'atrasos_iniciais', label: 'Atrasos Iniciais' },
            { id: 'objetivos', key: 'objetivos_iniciais', label: 'Objetivos Iniciais' },
            { id: 'atividades', key: 'atividades_realizadas', label: 'Atividades Realizadas' },
            { id: 'dificuldades', key: 'dificuldades_encontradas', label: 'Dificuldades Encontradas' },
            { id: 'beneficios', key: 'beneficios_obtidos', label: 'Benefícios Obtidos' },
            { id: 'tempo', key: 'tempo_duracao', label: 'Tempo de Duração' },
            { id: 'satisfacao', key: 'nivel_satisfacao', label: 'Nível de Satisfação' },
            { id: 'observacoes', key: 'observacoes', label: 'Observações' },
            { id: 'metas', key: 'proximas_metas', label: 'Próximas Metas' }
        ];
        let isValid = true;
        const mensagensErro = [];

        // Validação de campos obrigatórios
        camposObrigatorios.forEach(campo => {
            if (!dados[campo.key] || dados[campo.key] === '') {
                isValid = false;
                exibirErro(campo.id, `O campo "${campo.label}" é obrigatório.`);
                mensagensErro.push(`O campo "${campo.label}" é obrigatório.`);
            }
        });

        // Validação específica para data
        if (dados.data_inicio) {
            const hoje = new Date();
            const dataInicio = new Date(document.getElementById('data').value);
            if (isNaN(dataInicio.getTime())) {
                isValid = false;
                exibirErro('data', 'A data de início é inválida.');
                mensagensErro.push('A data de início é inválida.');
            } else if (dataInicio > hoje) {
                isValid = false;
                exibirErro('data', 'A data de início não pode ser futura.');
                mensagensErro.push('A data de início não pode ser futura.');
            }
        }

        // Validação do nível de satisfação
        if (isNaN(dados.nivel_satisfacao) || dados.nivel_satisfacao < 1 || dados.nivel_satisfacao > 10) {
            isValid = false;
            exibirErro('satisfacao', 'O nível de satisfação deve ser um número entre 1 e 10.');
            mensagensErro.push('O nível de satisfação deve ser um número entre 1 e 10.');
        }

        return { isValid, mensagensErro };
    }

    // Função para salvar dados no localStorage
    function salvarDados(dadosFeedback) {
        dados.feedback.push(dadosFeedback);
        localStorage.setItem('feedbacks', JSON.stringify(dados.feedback));
        console.log('Dados salvos:', dados);
    }

    // Função para lidar com o envio do formulário
    function handleSubmit(e) {
        e.preventDefault();
        limparErros();
        const dadosFeedback = coletarDados();
        const { isValid, mensagensErro } = validarFormulario(dadosFeedback);

        if (isValid) {
            salvarDados(dadosFeedback);
            alert('Feedback registrado com sucesso! Agradecemos sua colaboração.');
            form.reset();
            limparErros();
            setTimeout(() => {
                window.location.href = 'index.html';
            }, 1000);
        } else {
            alert('Por favor, corrija os seguintes erros:\n' + mensagensErro.join('\n'));
        }
    }

    // Event Listeners
    form.addEventListener('submit', handleSubmit);

    cancelarBtn.addEventListener('click', () => {
        if (confirm('Deseja cancelar? Todas as alterações não salvas serão perdidas!')) {
            limparErros();
            window.location.href = 'index.html';
        }
    });

    limparBtn.addEventListener('click', () => {
        if (confirm('Deseja limpar todos os campos?')) {
            form.reset();
            limparErros();
            alert('Formulário limpo com sucesso!');
        }
    });

    // Reseta estilos de erro ao digitar
    inputs.forEach(input => {
        input.addEventListener('input', () => {
            input.classList.remove('invalid');
            const erroDiv = document.getElementById(`erro-${input.id}`);
            if (erroDiv) {
                erroDiv.style.display = 'none';
                erroDiv.textContent = '';
            }
        });
    });
});