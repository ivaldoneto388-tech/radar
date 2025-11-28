// Medição de distância com sensor ultrassônico HC-SR04

const int trigPin = 9;   // Pino TRIG
const int echoPin = 10;  // Pino ECHO

long duracao;
float distancia;

void setup() {
  Serial.begin(9600);           // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT);     // TRIG como saída
  pinMode(echoPin, INPUT);      // ECHO como entrada
  Serial.println("Sensor HC-SR04 iniciado...");
}

void loop() {
  // Envia um pulso de 10 microssegundos no TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo do ECHO em microssegundos
  duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distancia = duracao * 0.0343 / 2;

  // Mostra a distância no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(500); // Pequena pausa entre as leituras
}

