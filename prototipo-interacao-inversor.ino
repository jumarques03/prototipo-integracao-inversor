/*
================== FICHA TÉCNICA SIMULADA DE UM INVERSOR ==================
>> Informações gerais:
- Modelo do inversor: GoodWe GW5000-NS (simulado)
- Potência instalada (P_inst): 6.0 kW
- Área do sistema fotovoltaico (A): 8.0 m²
- Eficiência média do sistema (η): 75% (0.75)
- Tensão nominal de saída (V): 220 V
- Corrente simulada de saída (I): 20.45 A

>> Condições ambientais simuladas:
- Irradiância solar atual (G): 0.85 kW/m²
- Temperatura ambiente (T_amb): 30 °C
- NOCT (Temperatura nominal de operação dos painéis): 45 °C
- Horas médias de sol por dia (H_média): 5.5 h/dia
*/


int led_vermelho = 32;
int led_verde = 25;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  Serial.begin(115200);
}

void limpandoBuffer(){
    while (Serial.available()){
    Serial.read();
    }
}

float potenciaAtual() {
  return 220.0 * 20.45;
}

float temperaturaOperacional() {
  return 30 + ((0.85 * (45 - 20)) / 800.0) * 1000; 
}

float potencialGeracaoMensal() {
  return 6.0 * 5.5 * 30 * 0.75;
}

void statusInversor(float p, float t) {
  if (p >= 0.80 * 6.0 && t < 60.0) {
    Serial.println("Status Geral: Operando em condições ideais.");
  } else {
    Serial.println("Status Geral: Operando com desempenho reduzido.");
  }
}

void loop() {
    float p = potenciaAtual();
    float t = temperaturaOperacional();

    limpandoBuffer();

    Serial.println("Alexa:");
    Serial.println("Deseja saber o status do inversor?");
    Serial.println("1 - sim | 2 - não");

    // Espera o usuário digitar sua escolha
    while (Serial.available() == 0) {}
    int input = Serial.parseInt(); 
    limpandoBuffer();

    Serial.println("---------------------------------------------");
    Serial.print("Usuário: ");
    Serial.println(input);

    if (input == 1) {
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, HIGH);

      Serial.println("---------------------------------------------");
      Serial.println("Alexa:");
      Serial.println("Status do Inversor:");

      Serial.print("Potencial de Geração: ");
      Serial.print(potencialGeracaoMensal());
      Serial.println(" kWh/mês");

      Serial.print("Potência Atual: ");
      Serial.print(p);
      Serial.println(" kW");

      Serial.println("Tensão de Saída: 220 V");

      Serial.print("Temperatura Operacional: ");
      Serial.print(t);
      Serial.println(" °C");

      statusInversor(p, t);

      Serial.println("Última Manutenção: 15/05/2025");
      Serial.println("---------------------------------------------");

    } else if (input == 2) {
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, HIGH);

      Serial.println("---------------------------------------------");
      Serial.println("Alexa:");
      Serial.println("Ok! Tenha um ótimo dia!");
      Serial.println("---------------------------------------------");
    } else {
      Serial.println("Alexa:");
      Serial.println("Entrada inválida!");
    }

    delay(1000);
}