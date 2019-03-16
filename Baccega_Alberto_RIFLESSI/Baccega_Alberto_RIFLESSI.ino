//PROGRAMMA RIFLESSI BACCEGA ALBERTO

int PulsanteAccensione;   //Pulsante per accendere il PROGRAMMA
int LedRandom;            //LED che si accenderà in modo RANDOMICO
int PulsanteTempoLed;     //Pulsante per spegnere il LED
int TempoLed;             //Quanto TEMPO ci mette a premere il PULSANTE del LED RANDOM
int Buzzer;               //BUZZER che si accenderà in modo RANDOM
int PulsanteBuzzer;       //Pulsante per spegnere il BUZZER
int TempoBuzzer;          //Quanto TEMPO ci mette a premere il PULSANTE del BUZZER RANDOM
int LedVerde;             //LED VERDE se il tempo è minore di 1000 ms
int LedRosso;             //LED ROSSO se il tempo è maggiore dei 1000 ms


void setup() {
  //assegno le VARIABILI citate sopra
  PulsanteAccensione = 3;   
  LedRandom = 4;
  PulsanteTempoLed = 5;
  Buzzer = 6;
  PulsanteBuzzer = 7;
  LedVerde = 8;
  LedRosso = 9;
  Serial.begin(9600);
  pinMode(PulsanteAccensione, INPUT);
  pinMode(LedRandom, OUTPUT);
  pinMode(PulsanteTempoLed, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(PulsanteBuzzer, INPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRosso, OUTPUT);
}

void loop() {
  TestRiflessi("Premi il BOTTONE 1 per INIZIARE LA PROVA",PulsanteAccensione,LedRandom)

}

void TestRiflessi(String inizio,int domanda,int risposta)
{
  Serial.println(inizio);
  while(digitalRead(PulsanteAccensione) == HIGH) 
  {
    digitalWrite(LedRandom,HIGH);
    delay(random(1000, 10000));
    while(digitalRead(PulsanteTempoLed) == HIGH)
    {
      
    }
  }
  
}

