// ===============================================================================
// --- Biblioteca Auxiliar ---
#include  <dht.h>   //biblioteca do sensor de umidade e temperatura
// ===============================================================================
// --- Mapeamento de Hardware ---
#define   dht_pin    5   //pino de sinal do dht11 ligado no digital 5
// ===============================================================================
// --- Declaração de Objetos ---
dht       my_dht;   //objeto para o sensor
// ===============================================================================
// --- Variáveis Globais ---
int     temperatura = 0x00,   //armazena a temperatura em inteiro
        umidade     = 0x00;   //armazena a umidade em inteiro
#define ledBranco   9
#define ledAmarelo  10
// ===============================================================================
// --- Configurações Iniciais ---
void setup()
{
  pinMode(ledBranco, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  Serial.begin(9600);   //serial em 9600 baud rate
}
// ===============================================================================
// --- Loop Infinito ---
void loop()
{
  my_dht.read11(dht_pin);

  temperatura = my_dht.temperature;
  umidade     = my_dht.humidity;

  if(temperatura>25){
    digitalWrite(ledBranco,HIGH);
    }
    else{
      digitalWrite(ledBranco,LOW);
    }
  
  if(umidade>70){
    digitalWrite(ledAmarelo,HIGH);
    }
    else{
      digitalWrite(ledAmarelo,LOW);
    }
  
  Serial.print(temperatura);
  Serial.print("°C ");
  Serial.print(umidade);
  Serial.println("% ");
  delay(1000);
  
}
