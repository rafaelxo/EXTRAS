# SPRINT 5 – MÉTRICAS E MEDIÇÕES DE SOFTWARE
## Sistema de Gestão Logística

---

## 1. INTRODUÇÃO

Este documento apresenta a análise completa de métricas, medições e estimativas do projeto **Sistema de Gestão Logística**, utilizando a técnica de **Análise de Pontos de Função (APF)** segundo o método IFPUG.

O objetivo é responder às questões fundamentais da Engenharia de Software:
- **Quanto custará o desenvolvimento?**
- **Quanto tempo levará?**
- **Qual o tamanho do sistema?**
- **Quais métricas garantirão a qualidade esperada?**

A análise foi baseada nas sprints anteriores: 
- **Sprint 1:** Histórias de Usuário
- **Sprint 2:** Levantamento de Requisitos
- **Sprint 3:** Casos de Uso
- **Sprint 4:** Diagrama de Classes (31 classes identificadas)

---

## 2. PARTE 1 - IDENTIFICAÇÃO E CONTAGEM DOS ELEMENTOS

### 2.1.  Entradas Externas (EE)

**Definição:** Entradas Externas representam processos onde dados atravessam a fronteira do sistema de fora para dentro, com o objetivo de **manter** (incluir, alterar, excluir) Arquivos Lógicos Internos. 

| # | Funcionalidade | Complexidade | Justificativa Técnica | Peso | Total |
|---|----------------|--------------|----------------------|------|-------|
| 1 | Cadastro de Cliente (Usuario+Cliente) | **Alta** | 10+ campos (nome, CPF/CNPJ, login, senha, email, telefone, tipoCliente, limiteCredito, statusConta, numeroContrato) + validação CPF/CNPJ + hash senha + criação Endereço agregado + envio notificação | 6 | 6 |
| 2 | Cadastro de Pedido completo | **Alta** | Múltiplas entidades (Cliente, Endereços origem/destino, Cargas compostas, Itens compostos, cálculo Tarifa, alocação Veículo/Motorista) + 15+ campos + validações complexas | 6 | 6 |
| 3 | Cadastro de Motorista (Usuario+Funcionario+Motorista) | **Média** | Herança múltipla (Usuario→Funcionario→Motorista), campos:  habilitacao, catHabilitacao, disponibilidade, setor, cargo, matricula + validações | 4 | 4 |
| 4 | Cadastro de Veículo | **Média** | Campos: placa, tipo, capacidade, status, GPS, agregação a CentroDistribuicao + validações | 4 | 4 |
| 5 | Agendamento de Coleta | **Alta** | Integração:  Cliente, Endereços, Carga, verificação disponibilidade Veículos/Motoristas, cálculo Tarifa, criação Pedido completo + notificações | 6 | 6 |
| 6 | Agendamento Entrada/Saída Pátio | **Média** | GestorPatio cria Agendamento, reserva Vaga, valida horários, associa Veículo, envia notificação Motorista | 4 | 4 |
| 7 | Registro de Ocorrências/Avarias | **Média** | Captura GPS automática (LocalIncidente), descrição, anexos, criação Incidente, notificação automática ao setor responsável | 4 | 4 |
| 8 | Registro de Feedback de Rota (Incidente) | **Média** | Captura GPS, identificação Estrada, validação duplicidade no IncidenteDatabase, criação ticket, notificação Roteirista | 4 | 4 |
| 9 | Registro de Manutenção Veículo | **Alta** | Composição: ManutencaoVeiculo + PecaSubstituida (1. .*), cálculo custo total, atualização status Veículo, histórico | 6 | 6 |
| 10 | Registro de Abastecimento (Combustivel) | **Baixa** | Campos simples: tipo, quantidade, custo, KM atual, data + cálculo consumo médio | 3 | 3 |
| 11 | Avaliação de Serviço | **Baixa** | Nota (1-5), comentário opcional, associação 1:1 com Pedido | 3 | 3 |
| 12 | Realizar Pagamento | **Alta** | Gateway externo, múltiplos métodos (cartão, PIX, boleto), agregação Transacao (1..*), segurança PCI-DSS, atualização status Pedido + notificações | 6 | 6 |
| 13 | Geração de Nota Fiscal (Fatura) | **Média** | Consolidação Pedidos, cálculo valores, geração XML, associação Cliente + Pedidos (1..*) | 4 | 4 |
| 14 | Checklist Digital (Código Barras) | **Baixa** | Leitura QR/Barcode, marcação status entrega, update simples | 3 | 3 |
| 15 | Cadastro/Atualização de Rota | **Alta** | Algoritmo otimização, integração APIs externas (Maps, Clima, Pedágios), composição Estradas (1..*), cálculo ETA, recálculo dinâmico | 6 | 6 |
| 16 | Atualização Status Pedido | **Baixa** | Update simples com trigger automático para notificações | 3 | 3 |
| 17 | Alocação Veículo/Motorista a Pedido | **Média** | Validação disponibilidade (Motorista. disponibilidade, Veículo.status), compatibilidade Carga, atualização associações | 4 | 4 |
| 18 | Controle Liberação Veículo (Saída Pátio) | **Média** | Validações múltiplas (autorização, pendências), atualização RegistroMovimentacao, liberação Vaga, logs auditoria | 4 | 4 |
| 19 | Cadastro de CentroDistribuicao | **Baixa** | Campos básicos + Endereço (1:1) | 3 | 3 |
| 20 | Registro Entrada Veículo Pátio | **Média** | Criação RegistroMovimentacao, atualização Vaga, validação Agendamento | 4 | 4 |
| **TOTAL EE** | | | | | **87** |

---

### 2.2. Saídas Externas (SE)

**Definição:** Saídas Externas são processos que **geram dados derivados** através de processamento lógico além de simples recuperação. 

| # | Funcionalidade | Complexidade | Justificativa Técnica | Peso | Total |
|---|----------------|--------------|----------------------|------|-------|
| 1 | Relatório Desempenho Entregas | **Alta** | Agregações:  tempo médio entrega, taxa sucesso, ocorrências, KPIs múltiplos, filtros (período, região, motorista), gráficos | 7 | 7 |
| 2 | Relatório Utilização Frota | **Alta** | Consolidação:  KM rodados, horas uso, taxa ocupação, custos operacionais, consumo combustível, múltiplos veículos | 7 | 7 |
| 3 | Relatório Consumo Combustível | **Alta** | Cálculos:  consumo médio, eficiência (KM/L), custos, tendências, comparações entre veículos | 7 | 7 |
| 4 | Análise Comparativa Custos Frete | **Alta** | Comparação: rotas, distâncias, tipos carga, cálculo margem lucro, sugestões otimização tarifas | 7 | 7 |
| 5 | Relatório Rotas com Atrasos Frequentes | **Média** | Identificação padrões, agregação Incidentes por Estrada, cálculo frequência, análise temporal | 5 | 5 |
| 6 | Relatório Tempo Médio Entrega | **Média** | Cálculos:  ETA vs real, desvios padrão, análise por região/tipo carga | 5 | 5 |
| 7 | Dashboard Monitoramento Frota (Tempo Real) | **Alta** | Processamento: posição GPS, status múltiplos veículos, agregação alertas, atualização WebSocket ≤5s | 7 | 7 |
| 8 | Relatório Manutenções Preventivas | **Média** | Consolidação: custos, peças substituídas, tempo parado, próximas manutenções previstas | 5 | 5 |
| 9 | Relatório Financeiro (Faturas x Pagamentos) | **Alta** | Reconciliação: valores faturados, recebidos, pendentes, análise fluxo caixa | 7 | 7 |
| 10 | Painel Incidentes Ativos (Roteirista) | **Média** | Filtros múltiplos, agregação por Estrada, priorização gravidade, mapas | 5 | 5 |
| **TOTAL SE** | | | | | **62** |

---

### 2.3. Consultas Externas (CE)

**Definição:** Consultas Externas recuperam dados **sem processamento significativo**, sem alterar ALIs. 

| # | Funcionalidade | Complexidade | Justificativa Técnica | Peso | Total |
|---|----------------|--------------|----------------------|------|-------|
| 1 | Rastreamento Encomenda (Tempo Real) | **Alta** | Consulta:  Pedido + Veículo + HistoricoRota + cálculo ETA dinâmico + renderização mapa | 6 | 6 |
| 2 | Consultar Status Pedido | **Média** | Consulta: Pedido + status + última atualização HistoricoRota | 4 | 4 |
| 3 | Visualizar Rota Otimizada (Motorista) | **Alta** | Consulta: Rota + Estradas + Incidentes ativos + instruções navegação + integração API Maps | 6 | 6 |
| 4 | Consultar Localização Frota (GPS) | **Alta** | Consulta: múltiplos Veículos + posições GPS + status + renderização mapa | 6 | 6 |
| 5 | Visualizar Previsão Entrega | **Média** | Consulta:  Pedido + Rota + HistoricoRota + cálculo ETA | 4 | 4 |
| 6 | Painel Entregas em Andamento | **Média** | Consulta: Pedidos ativos + status + filtros simples | 4 | 4 |
| 7 | Consultar Posição Veículos no Pátio | **Média** | Consulta: Patio + Vagas + Veículos + RegistroMovimentacao | 4 | 4 |
| 8 | Visualizar Histórico Avaliações | **Baixa** | Consulta simples: AvaliacaoServico + filtros | 3 | 3 |
| 9 | Consultar Disponibilidade Veículos | **Média** | Consulta: Veículos + status + Agendamentos + validações | 4 | 4 |
| 10 | Consultar Feedbacks Rotas (Incidentes) | **Baixa** | Consulta: IncidenteDatabase + filtros básicos | 3 | 3 |
| 11 | Visualizar Detalhes Veículo | **Média** | Consulta: Veículo + ManutencaoVeiculo + Combustivel + Seguro + histórico | 4 | 4 |
| 12 | Consultar Histórico Pedidos Cliente | **Baixa** | Consulta: Cliente + Pedidos + filtros data | 3 | 3 |
| **TOTAL CE** | | | | | **51** |

---

### 2.4. Arquivos Lógicos Internos (ALI)

**Definição:** ALIs são grupos de dados logicamente relacionados, **mantidos** dentro da fronteira da aplicação.

| # | Entidade/Tabela | Complexidade | Justificativa Técnica | Peso | Total |
|---|-----------------|--------------|----------------------|------|-------|
| 1 | Pedido | **Alta** | 20+ atributos, chave composta possível, múltiplas FK (Cliente, Motorista, 2 Endereços, Tarifa), composição Carga+Item | 15 | 15 |
| 2 | Cliente (Usuario herdado) | **Média** | Herança Usuario, 10+ atributos (tipoCliente, limiteCredito, statusConta, numeroContrato), agregação Endereços (1..*) | 10 | 10 |
| 3 | Motorista (Usuario→Funcionario) | **Média** | Herança múltipla, atributos específicos (habilitacao, catHabilitacao, disponibilidade), FK Veículo | 10 | 10 |
| 4 | Veículo | **Alta** | 15+ atributos, múltiplas associações (Motorista, Rota, Carga, HistoricoRota, ManutencaoVeiculo, Combustivel, Seguro, Agendamento, RegistroMovimentacao), agregação CentroDistribuicao | 15 | 15 |
| 5 | Rota | **Alta** | Algoritmo otimização, composição Estradas (1..*), FK múltiplas (Veículo, Endereços 2..*), HistoricoRota (1: 1) | 15 | 15 |
| 6 | Entrega (implícito em Pedido+HistoricoRota) | **Média** | Status, datas, confirmação, FK Pedido+Motorista | 10 | 10 |
| 7 | Manutenção (ManutencaoVeiculo) | **Média** | Composição PecaSubstituida (1..*), FK Veículo+Funcionario, cálculo custos | 10 | 10 |
| 8 | Ocorrências/Incidente | **Média** | Composição em Estrada, agregação IncidenteDatabase, associação LocalIncidente (1:1), status, gravidade | 10 | 10 |
| 9 | Avaliação (AvaliacaoServico) | **Baixa** | 5 atributos, FK Pedido (1:1) | 7 | 7 |
| 10 | Feedback Rota (subset Incidente) | **Baixa** | Subset de Incidente, FK Motorista+Estrada | 7 | 7 |
| 11 | Agendamento | **Média** | FK GestorPatio+Veículo, datas, tipo operação | 10 | 10 |
| 12 | Nota Fiscal (Fatura) | **Média** | FK Cliente, associação Pedidos (1..*), cálculos valores, datas vencimento | 10 | 10 |
| 13 | Usuario (base) | **Média** | 8 atributos, herança (Cliente, Funcionario), segurança (hash senha) | 10 | 10 |
| 14 | Funcionario (Usuario herdado) | **Média** | Herança Usuario, atributos (setor, cargo, matricula), herança p/ Motorista+Gestor+GestorPatio | 10 | 10 |
| 15 | Endereco | **Média** | 10+ atributos (coordenadas GPS, CEP, cidade), agregado a Cliente (1..*), múltiplas associações (Rota, Pedido origem/destino, CentroDistribuicao, Estrada) | 10 | 10 |
| 16 | CentroDistribuicao | **Média** | Agregação Veículos (1:0. .*), associação Endereço (1:1) | 10 | 10 |
| 17 | Estrada | **Média** | Composição Incidentes (1:0..*), associações Rota+Endereços, atributos (distância, tempo, custo) | 10 | 10 |
| 18 | Patio | **Média** | Composição Vagas (1:1. .*), associação RegistroMovimentacao (1:0..*) | 10 | 10 |
| 19 | Vaga | **Baixa** | Composição em Patio, atributos simples (status, número) | 7 | 7 |
| 20 | RegistroMovimentacao | **Baixa** | FK Patio+Veículo, timestamps entrada/saída | 7 | 7 |
| 21 | HistoricoRota | **Média** | FK Veículo+Rota (1:1 cada), timestamps, desvios, ocorrências | 10 | 10 |
| 22 | Pagamento | **Média** | Agregação Transacao (1:1..*), FK Pedido+Cliente, status, valores | 10 | 10 |
| 23 | Transacao | **Média** | Agregado em Pagamento, dados gateway, segurança PCI-DSS | 10 | 10 |
| 24 | Combustivel | **Baixa** | FK Veículo, atributos simples (tipo, quantidade, custo, KM) | 7 | 7 |
| 25 | Seguro | **Baixa** | FK Veículo (1:1), dados apólice | 7 | 7 |
| 26 | Tarifa | **Média** | FK Pedido (1:1), regras cálculo, alíquotas | 10 | 10 |
| 27 | Carga | **Média** | Composição em Pedido (1:1..*), FK Veículo, atributos (peso, dimensões, tipo) | 10 | 10 |
| 28 | Item | **Baixa** | Composição em Pedido (1:1..*), atributos simples (descrição, quantidade, preço) | 7 | 7 |
| 29 | Notificacao | **Baixa** | FK Usuario (1:1), herança possível Mensagem, atributos (tipo, conteúdo, data) | 7 | 7 |
| 30 | IncidenteDatabase | **Baixa** | Agregação Incidentes (1:0..*), métodos gerenciamento | 7 | 7 |
| 31 | LocalIncidente | **Baixa** | FK Incidente (1:1), coordenadas GPS, raio impacto | 7 | 7 |
| **TOTAL ALI** | | | | | **297** |

---

### 2.5. Arquivos de Interface Externa (AIE)

**Definição:** AIEs são dados referenciados, **mantidos por outra aplicação**. 

| # | Integração Externa | Complexidade | Justificativa Técnica | Peso | Total |
|---|-------------------|--------------|----------------------|------|-------|
| 1 | API Google Maps / OpenStreetMap | **Alta** | Múltiplos endpoints (geocoding, routing, directions), dados complexos (polígonos, ETA dinâmico), alta frequência chamadas | 10 | 10 |
| 2 | Sistema GPS/Telemetria Veículos | **Alta** | Dados em tempo real (MQTT/WebSocket), volume alto (50k+ dispositivos), parsing proprietário | 10 | 10 |
| 3 | API Serviço Meteorológico | **Média** | Dados estruturados (JSON), consultas por coordenadas, previsões horárias | 7 | 7 |
| 4 | Sistema Pedágios (Sem Parar/ConectCar) | **Média** | Integração específica, dados transacionais, cálculo custos | 7 | 7 |
| 5 | API Nota Fiscal Eletrônica (SEFAZ) | **Média** | Protocolo específico (SOAP/REST), XML estruturado, validações fiscais | 7 | 7 |
| 6 | Gateway SMS (Twilio/AWS SNS) | **Média** | API REST simples, mas volume alto, controle rate limiting | 7 | 7 |
| 7 | Serviço Push Notifications (Firebase/OneSignal) | **Média** | Integração SDKs mobile/web, gerenciamento tokens, segmentação | 7 | 7 |
| 8 | Gateway Pagamento (Stripe/PagSeguro/Cielo) | **Alta** | Múltiplos métodos pagamento, segurança PCI-DSS, webhooks complexos, reconciliação | 10 | 10 |
| 9 | API Correios (Rastreamento/CEP) | **Baixa** | API simples, dados estruturados, baixa frequência | 5 | 5 |
| **TOTAL AIE** | | | | | **70** |

---

### 2.6. Resumo Contagem Pontos de Função Brutos

| Tipo | Quantidade | Total Pontos |
|------|-----------|--------------|
| **EE** (Entradas Externas) | 20 | **87** |
| **SE** (Saídas Externas) | 10 | **62** |
| **CE** (Consultas Externas) | 12 | **51** |
| **ALI** (Arquivos Lógicos Internos) | 31 | **297** |
| **AIE** (Arquivos Interface Externa) | 9 | **70** |
| **TOTAL PF BRUTO** | **82** | **567** |

---

## 3.  PARTE 2 - AJUSTE DOS PONTOS DE FUNÇÃO

### 3.1. Avaliação dos 14 Fatores de Ajuste

Cada fator recebe nota de **0 a 5**: 
- **0** = Nenhuma influência
- **1** = Influência mínima
- **2** = Influência baixa
- **3** = Influência moderada
- **4** = Influência significativa
- **5** = Influência muito forte

| # | Fator de Ajuste | Nota | Justificativa Detalhada |
|---|----------------|------|------------------------|
| 1 | **Backup e Recovery confiável** | **5** | Dados críticos de entregas, pedidos, pagamentos e localização em tempo real não podem ser perdidos.  RTO ≤ 1h, RPO ≤ 15min, backups diários, replicação multi-região |
| 2 | **Comunicação de dados especializada** | **5** | Múltiplas integrações:  GPS/telemetria (MQTT), APIs externas (Maps, Clima, Pedágios, SEFAZ), WebSocket tempo real, gateway pagamento |
| 3 | **Processamento distribuído** | **5** | Arquitetura distribuída:  servidores telemetria, APIs, banco geoespacial (PostGIS), cache (Redis), filas (RabbitMQ/Kafka), balanceadores carga |
| 4 | **Desempenho crítico** | **5** | Rastreamento tempo real (latência ≤10s), recálculo rotas (≤5s), atualização GPS (≤5s), processamento 50k+ dispositivos simultâneos, SLA 99,9% |
| 5 | **Ambiente operacional intenso** | **5** | Sistema 24/7 nacional, compartilha infraestrutura com outros serviços (ERP, CRM), alta concorrência (clientes, motoristas, gestores simultâneos) |
| 6 | **Entrada de dados online** | **5** | Totalmente online: app motoristas, portal clientes, painel gestores, checklist digital, feedback tempo real, pagamentos online |
| 7 | **Transação entrada em múltiplas telas** | **4** | Pedido:  múltiplas etapas (dados cliente → endereços → cargas → itens → pagamento). Agendamento coleta:  3-4 telas. Manutenção: dados + peças |
| 8 | **ALIs atualizados online** | **5** | Todos ALIs críticos atualizados online:  Pedidos, Veículos, HistoricoRota, Incidentes, Pagamentos, RegistroMovimentacao em tempo real |
| 9 | **Entradas/Saídas/Consultas complexas** | **5** | Rastreamento tempo real (GPS+ETA+mapa), dashboard frota (WebSocket), algoritmo otimização rotas (IA), relatórios analíticos complexos, gateway pagamento |
| 10 | **Processamento interno complexo** | **5** | Algoritmos:  otimização rotas (Dijkstra/A*), cálculo ETA dinâmico, manutenção preventiva preditiva, análise padrões atrasos, reconciliação financeira, detecção duplicidade incidentes |
| 11 | **Código reutilizável** | **4** | Arquitetura microserviços, APIs RESTful, bibliotecas compartilhadas (autenticação, notificações, geolocalização), SDKs mobile, design patterns (Repository, Factory) |
| 12 | **Conversão e instalação** | **3** | Migração dados de sistema legado, carga inicial:  clientes, veículos, motoristas, centros distribuição.  Scripts ETL, validações, rollback.  Instalação: ambientes dev/staging/prod |
| 13 | **Múltiplas instalações** | **4** | Implantação em múltiplos CentrosDistribuicao (regiões Brasil), configurações específicas por região (tarifas, regulamentações), multi-tenancy potencial para clientes corporativos |
| 14 | **Facilitar mudanças/uso pelo usuário** | **4** | Interfaces responsivas (web+mobile), dashboards configuráveis, notificações personalizáveis, modo offline (app motorista), acessibilidade (WCAG 2.1), treinamento integrado, help contextual |

**SOMA DOS FATORES:** 5+5+5+5+5+5+4+5+5+5+4+3+4+4 = **64**

---

### 3.2. Cálculo dos Pontos de Função Ajustados

**Fórmula:**
PF Ajustado = PF Bruto × [0,65 + (0,01 × Soma Fatores)]

**Cálculo:**
PF Ajustado = 567 × [0,65 + (0,01 × 64)]
PF Ajustado = 567 × [0,65 + 0,64]
PF Ajustado = 567 × 1,29
PF Ajustado = 731,43 ≈ 731 PF

**✅ RESULTADO:  731 Pontos de Função Ajustados**

---

## 4. PARTE 3 - ESTIMATIVAS DO PROJETO

### 4.1. Definição da Produtividade

**Produtividade assumida:  12 PF/pessoa-mês**

**Justificativa:**
- **Tecnologias:** Stack moderna mas madura (React/Vue. js, Node.js/Java Spring, PostgreSQL+PostGIS)
- **Equipe:** Desenvolvedores com experiência **média** em sistemas logísticos
- **Complexidade:** Sistema complexo (integração múltiplas APIs, tempo real, algoritmos otimização)
- **Infraestrutura:** Cloud (AWS/Azure), microserviços, CI/CD estabelecido
- **Domínio:** Logística tem regras de negócio complexas mas documentadas

**Referência:** Pressman (2016) indica 10-15 PF/pessoa-mês para sistemas de complexidade média-alta com equipes experientes.

---

### 4.2. Estimativa de Esforço

**Fórmula:**
Esforço Total (pessoa-mês) = PF Ajustado / Produtividade


**Cálculo:**
Esforço Total = 731 / 12 = 60,92 ≈ 61 pessoa-meses


**✅ RESULTADO: 61 pessoa-meses de esforço**

---

### 4.3. Estimativa de Prazo

**Composição da Equipe (mínimo 3 devs):**

Para um sistema desta magnitude, equipe sugerida:
- **5 Desenvolvedores Full-Stack**
- **2 Desenvolvedores Mobile** (iOS + Android)
- **1 Especialista DevOps/Infraestrutura**
- **1 Especialista em Algoritmos** (otimização rotas)
- **TOTAL: 9 profissionais técnicos**

**Cálculo Prazo:**
Prazo (meses) = Esforço Total / Tamanho Equipe Prazo = 61 / 9 = 6,78 ≈ 7 meses


**Distribuição temporal considerando modelo iterativo:**

| Fase | Duração | Atividades |
|------|---------|-----------|
| **Planejamento e Setup** | 0,5 mês | Arquitetura, infraestrutura, CI/CD, protótipos |
| **Sprint 1-2** | 2 meses | Core (Pedidos, Clientes, Veículos, Motoristas, autenticação) |
| **Sprint 3-4** | 2 meses | Rastreamento tempo real, rotas, integrações APIs |
| **Sprint 5-6** | 2 meses | Pagamentos, relatórios, pátio, manutenção |
| **Testes e Ajustes** | 0,5 mês | Testes integração, carga, segurança, correções |
| **TOTAL** | **7 meses** | |

**✅ RESULTADO:  7 meses de desenvolvimento**

---

### 4.4. Estimativa de Custo

**Salário Médio Dev Pleno (2025 - Brasil):** R$ 8.500/mês

**Composição Custos:**

| Item | Cálculo | Valor |
|------|---------|-------|
| **Salários Equipe** | 9 profissionais × 7 meses × R$ 8.500 | R$ 535.500 |
| **Encargos Trabalhistas (80%)** | R$ 535.500 × 0,80 | R$ 428.400 |
| **Infraestrutura Cloud** | R$ 15.000/mês × 7 meses | R$ 105.000 |
| **Licenças/APIs Externas** | (Maps, SMS, Push, Pagamento) × 7 meses | R$ 35.000 |
| **Gestão Projeto** | 1 PM × 7 meses × R$ 12.000 | R$ 84.000 |
| **Contingência (15%)** | (soma anterior) × 0,15 | R$ 178.185 |
| **CUSTO TOTAL ESTIMADO** | | **R$ 1.366.085** |

**Custo por Ponto de Função:**
Custo/PF = R$ 1.366.085 / 731 PF = R$ 1.868,79/PF

**✅ RESULTADO: R$ 1.366.085,00 (aproximadamente R$ 1,37 milhões)**

---

### 4.5. Estimativa de Tamanho em LOC

**Taxa de Conversão:  1 PF ≈ 53 LOC**

**Justificativa:**
- **Linguagens:** TypeScript/JavaScript (React, Node.js) + Java (backend services)
- **Frameworks:** Alto nível (React, Spring Boot) reduzem linhas boilerplate
- **Geração código:** ORM (TypeORM/Hibernate), swagger codegen
- **Referência:** Tabela IFPUG indica 50-55 LOC/PF para Java/JavaScript moderno

**Cálculo:**
LOC Total = 731 PF × 53 LOC/PF = 38.743 LOC ≈ 38,7 KLOC

**Distribuição por componente:**

| Componente | % Código | LOC Estimado |
|-----------|----------|--------------|
| Backend (APIs REST) | 40% | 15. 497 |
| Frontend Web (React) | 25% | 9.686 |
| Mobile (React Native) | 20% | 7.749 |
| Algoritmos (Rotas, IA) | 10% | 3.874 |
| DevOps/Infra (IaC, scripts) | 5% | 1.937 |
| **TOTAL** | **100%** | **38.743** |

**✅ RESULTADO: ~38,7 KLOC (Mil Linhas de Código)**

---

## 5. PARTE 4 - MÉTRICAS E INDICADORES DE QUALIDADE

### 5.1. Métricas para Sistema WEB

| Métrica | O que Mede | Por que é Importante | Meta |
|---------|-----------|---------------------|------|
| **Tempo de Resposta (API)** | Latência média requisições REST (ms) | Usuários (gestores, clientes) precisam de respostas rápidas para consultas de pedidos e rastreamento | ≤ 300ms (p95) |
| **Disponibilidade (Uptime)** | % tempo sistema acessível | Sistema logístico 24/7 não pode ter downtime prolongado, impacta operação nacional | ≥ 99,9% (8h/ano) |
| **Taxa de Erro (HTTP 5xx)** | % requisições com erro servidor | Erros impactam diretamente operações críticas (pedidos, pagamentos, rastreamento) | ≤ 0,1% |
| **Cobertura de Testes** | % código coberto por testes automatizados | Garante confiabilidade em sistema complexo com múltiplas integrações | ≥ 80% (backend) <br> ≥ 70% (frontend) |
| **Tempo de Carregamento (FCP)** | First Contentful Paint - tempo até primeira renderização (s) | Experiência usuário em dashboards e rastreamento | ≤ 1,5s |
| **Throughput (Requisições/s)** | Capacidade processamento simultâneo | Sistema deve suportar picos (horários comerciais, múltiplos centros distribuição) | ≥ 1. 000 req/s |
| **Taxa de Conversão (Checkout)** | % pedidos iniciados que completam pagamento | Indica fricção no processo de compra | ≥ 75% |
| **Densidade de Defeitos** | Bugs/KLOC em produção | Mede qualidade código e testes | ≤ 0,5 bugs/KLOC |
| **Mean Time To Recovery (MTTR)** | Tempo médio para restaurar serviço após falha (min) | Minimiza impacto de incidentes em operação | ≤ 15 min |
| **Segurança (Vulnerabilidades)** | CVEs críticas/altas não corrigidas | Protege dados sensíveis (pagamentos, localização, CPF/CNPJ) | 0 críticas <br> ≤ 5 altas |
| **Performance Score (Lighthouse)** | Score Google Lighthouse (0-100) | Otimização web (SEO, performance, acessibilidade) | ≥ 85 |
| **Taxa de Cache Hit** | % requisições servidas por cache | Reduz carga banco, melhora performance consultas frequentes (rastreamento) | ≥ 70% |

---

### 5.2. Métricas para APP MOBILE

| Métrica | O que Mede | Por que é Importante | Meta |
|---------|-----------|---------------------|------|
| **Consumo de Bateria** | mAh/hora de uso ativo | Motoristas usam app o dia todo (8-12h), bateria crítica | ≤ 5% bateria/hora |
| **Uso de Dados Móveis** | MB consumidos por hora de uso | Motoristas nem sempre têm Wi-Fi, dados 4G/5G custam | ≤ 10 MB/hora (modo normal) <br> ≤ 3 MB/hora (modo econômico) |
| **Taxa de Crash** | % sessões que terminam em crash | Motorista perde rastreamento, pedido pode atrasar | ≤ 0,5% |
| **Tempo de Inicialização** | Tempo até app estar interativo (s) | Motorista precisa abrir app rapidamente durante entrega | ≤ 2s (cold start) <br> ≤ 0,5s (warm start) |
| **Frequência Atualização GPS** | Intervalo entre atualizações localização (s) | Balanço entre precisão rastreamento e consumo bateria/dados | 30s (modo padrão) <br> 5s (modo alta prioridade) |
| **Taxa de Sucesso Sincronização Offline** | % dados offline sincronizados sem erros | Motoristas trabalham em áreas sem sinal, dados críticos (entregas, incidentes) | ≥ 99% |
| **Tamanho do APK/IPA** | MB do instalador | Download rápido, economiza espaço dispositivo | ≤ 50 MB (Android) <br> ≤ 60 MB (iOS) |
| **Framerate (FPS)** | Frames por segundo em animações/mapas | Fluidez interação, especialmente em mapas de rastreamento | ≥ 55 FPS |
| **Tempo de Resposta Touch** | Latência entre toque e resposta (ms) | Usabilidade durante condução (paradas), interações rápidas | ≤ 100ms |
| **Taxa de Retenção** | % usuários que continuam usando app após 30 dias | Indica qualidade experiência motorista/cliente | ≥ 80% (motoristas) <br> ≥ 60% (clientes) |
| **Suporte Versões SO** | Versões Android/iOS suportadas | Garante compatibilidade frota de dispositivos heterogênea | Android ≥ 8. 0 <br> iOS ≥ 13.0 |
| **Precisão GPS** | Desvio médio localização real vs reportada (m) | Rastreamento preciso essencial para cliente e operação | ≤ 10m (95% do tempo) |
| **Taxa de ANR (Android)** | % Application Not Responding | App trava/congela, frustra usuário | ≤ 0,3% |
| **Tempo Funcionalidade Offline** | Tempo máximo app funciona sem internet (h) | Motoristas em áreas rurais sem sinal | ≥ 4h (funcionalidades críticas) |

---

### 5.3. Métricas de Processo e Qualidade de Código

| Métrica | O que Mede | Meta |
|---------|-----------|------|
| **Complexidade Ciclomática** | Complexidade lógica dos métodos | ≤ 10 (ideal) <br> ≤ 15 (aceitável) |
| **Code Churn** | % código alterado entre sprints | ≤ 20% (estabilidade) |
| **Technical Debt Ratio** | % tempo para corrigir dívida técnica | ≤ 5% |
| **Duplicação de Código** | % linhas duplicadas | ≤ 3% |
| **Vulnerabilidades Segurança (SAST)** | Issues críticas em análise estática | 0 críticas antes deploy |
| **Code Review Coverage** | % commits revisados por pares | 100% |
| **Build Success Rate** | % builds CI/CD bem-sucedidos | ≥ 95% |

---

## 6. ANÁLISE FINAL

### 6.1. Viabilidade do Projeto

**Pontos Fortes:**
- ✅ Escopo bem definido (31 classes, 567 PF brutos)
- ✅ Tecnologias maduras e amplamente suportadas
- ✅ Modelo de desenvolvimento iterativo (sprints 2 meses) permite validação incremental
- ✅ Custo estimado (R$ 1,37 milhões) competitivo para sistema enterprise desta complexidade
- ✅ Prazo realista (7 meses) permite time-to-market adequado

**Riscos Identificados:**

| Risco | Probabilidade | Impacto | Mitigação |
|-------|---------------|---------|-----------|
| Integração APIs externas (Maps, Pagamento) | Média | Alto | Mockar APIs em dev, contratos claros SLA, fallback providers |
| Performance tempo real (50k+ dispositivos) | Média | Crítico | Arquitetura escalável (microserviços), testes carga desde início, cache agressivo |
| Complexidade algoritmo rotas | Baixa | Alto | Contratar especialista, bibliotecas maduras (GraphHopper), MVP simplificado |
| Cumprimento PCI-DSS (pagamentos) | Baixa | Crítico | Usar gateway certificado (Stripe), não armazenar dados cartão, auditoria externa |
| Disponibilidade 99,9% | Média | Alto | Multi-região, auto-scaling, monitoramento 24/7, runbooks incidentes |

---

### 6.2. ROI Estimado

**Premissas:**
- Sistema atende **5. 000 pedidos/mês** inicialmente
- Crescimento **20%/ano**
- Economia operacional:  **15% redução custos logísticos** (rotas otimizadas, manutenção preventiva, redução atrasos)
- Receita adicional: **10% aumento pedidos** (rastreamento tempo real melhora satisfação cliente)

**Projeção 3 anos:**

| Ano | Economia Operacional | Receita Adicional | Custo Manutenção | Resultado Líquido |
|-----|---------------------|------------------|------------------|-------------------|
| 1 | R$ 450.000 | R$ 300.000 | R$ 200.000 | R$ 550.000 |
| 2 | R$ 540.000 | R$ 360.000 | R$ 220.000 | R$ 680.000 |
| 3 | R$ 648.000 | R$ 432.000 | R$ 240.000 | R$ 840.000 |
| **Total 3 anos** | R$ 1.638.000 | R$ 1.092.000 | R$ 660.000 | **R$ 2.070.000** |

**ROI:**
ROI = (Ganho Total - Investimento) / Investimento × 100
ROI = (R$ 2.070.000 - R$ 1.366.085) / R$ 1.366.085 × 100
ROI = 51,5% em 3 anos

**Payback:** ~18 meses

---

## 7. CONCLUSÃO

A análise completa de métricas e medições do **Sistema de Gestão Logística** resultou em:

### 📊 MÉTRICAS PRINCIPAIS:
- **Pontos de Função Ajustados:** 731 PF
- **Esforço Estimado:** 61 pessoa-meses
- **Prazo Desenvolvimento:** 7 meses (equipe 9 pessoas)
- **Tamanho Código:** ~38,7 KLOC
- **Custo Total:** R$ 1.366.085,00
- **ROI 3 anos:** 51,5%

### ✅ VIABILIDADE: 
O projeto é **VIÁVEL** técnica e financeiramente, com: 
- Escopo claramente definido e mensurável
- Tecnologias maduras e equipe dimensionada adequadamente
- Prazo realista permitindo entregas incrementais
- ROI atrativo com payback em 18 meses
- Métricas de qualidade bem estabelecidas para ambas plataformas (web e mobile)

### ⚠️ FATORES CRÍTICOS DE SUCESSO:
1. **Performance tempo real:** Arquitetura escalável testada desde início
2. **Integrações externas:** Contratos SLA claros, fallback plans
3. **Segurança (PCI-DSS):** Gateway certificado, auditoria externa
4. **Disponibilidade 99,9%:** Infraestrutura multi-região, monitoramento 24/7
5. **Experiência Mobile:** Otimização bateria/dados, modo offline robusto

### 🎯 RECOMENDAÇÃO: 
**APROVAR** o desenvolvimento do sistema, com faseamento: 
1. **MVP (3 meses):** Core (Pedidos, Rastreamento básico, Pagamento)
2. **Release 1.0 (7 meses):** Sistema completo conforme escopo
3. **Releases Futuras:** IA preditiva (manutenção, demanda), blockchain (rastreabilidade carga)

---

## 8. REFERÊNCIAS

1. **PRESSMAN, Roger S.; MAXIM, Bruce R. ** *Engenharia de Software: Uma Abordagem Profissional*. 8ª ed.  Porto Alegre:  AMGH, 2016.

2. **FENTON, Norman E.; BIEMAN, James. ** *Software Metrics: A Rigorous and Practical Approach*. 3rd ed. CRC Press, 2014.

3. **SOMMERVILLE, Ian. ** *Engenharia de Software*. 10ª ed. São Paulo: Pearson, 2018.

---

## 🎓 RESUMO PARA ESTUDO RÁPIDO

### Fórmulas Essenciais:

- PF Ajustado = PF Bruto × [0,65 + (0,01 × Soma Fatores)]
- Esforço = PF Ajustado / Produtividade
- Prazo = Esforço / Tamanho Equipe
- LOC = PF Ajustado × Taxa Conversão
- Custo = (Salários + Encargos + Infra + Licenças + Gestão) × (1 + Contingência)


### Classificação Complexidade:
- **Baixa:** ≤ 5 campos, relacionamentos simples → Peso: EE=3, SE=4, CE=3, ALI=7, AIE=5
- **Média:** 6-15 campos, relacionamentos moderados → Peso: EE=4, SE=5, CE=4, ALI=10, AIE=7
- **Alta:** >15 campos, relacionamentos complexos → Peso: EE=6, SE=7, CE=6, ALI=15, AIE=10

### Diferenças Chave:
- **EE (Entrada Externa):** Cadastro, Manutenção de ALI
- **SE (Saída Externa):** Relatórios com PROCESSAMENTO/CÁLCULO
- **CE (Consulta Externa):** Consultas SIMPLES sem processamento
- **ALI:** Tabelas/Entidades MANTIDAS pelo sistema
- **AIE:** Dados EXTERNOS (APIs, sistemas terceiros)

---