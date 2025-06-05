# Simulação de Interação entre Usuário, Alexa e Inversor (Prova de Conceito)

Este projeto apresenta um protótipo funcional simulado, que representa uma das possíveis interações do usuário com o sistema final proposto no Challenge. A ideia é demonstrar de forma prática como o usuário poderia, por meio de um assistente virtual (Alexa), consultar o status de seu inversor fotovoltaico, com respostas baseadas em dados simulados via equações de energia.
---
## Objetivo desta Simulação

- Simular uma conversa com a Alexa usando o Serial Monitor do ESP32.
- Exibir dados energéticos simulados como se fossem respondidos pela Alexa, com base em equações reais.
- Demonstrar a resposta visual do sistema usando LEDs (verde = o usuário aceitou receber informações sobre o status do inversor / vermelho = o usuário não aceitou receber estas informações).
---
##  Dados e Equações Utilizadas

Os dados exibidos no protótipo são simulados, mas calculados com base em equações reais de energia. As equações utilizadas foram: 

- **Potência Atual:**  
  `P = V × I 

- **Temperatura Operacional:**  
  `T = T_amb + [(G × (NOCT - 20)) / 800] × 1000 

- **Potencial de Geração Mensal:**  
  `E = P_inst × H_média × 30 × η 

- **Status Geral do Inversor:**  
  Se `P ≥ 80% de P_inst` e `T < 60°C` → *Operando em condições ideais*  
  Caso contrário → *Desempenho reduzido*
---
##  O que o protótipo faz?

1. Simula a Alexa perguntando: "Deseja saber o status do inversor?"
2. Usuário responde (via Serial Monitor): `1` (sim) ou `2` (não).
3. O sistema:
   - Acende o LED correspondente
   - Calcula os dados
   - Mostra a resposta no monitor serial
---
## Tecnologias e Componentes Utilizados

-  (1) **ESP32** com comunicação serial
-  (2)**LEDs**
-  (3) **Jumpers** macho x macho
-  (2) **Resistores** de 202V
-  (1) **Protoboard**
-  Plataforma **Arduino IDE**
