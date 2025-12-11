
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

**Documento elaborado por:** Rafael Xavier  
**Data:** 11 de Dezembro de 2025  
**Versão:** 1.0 - Final

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