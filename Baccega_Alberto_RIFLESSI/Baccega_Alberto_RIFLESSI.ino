//PROGRAMMA RIFLESSI BACCEGA ALBERTO

int PulsanteAccensione;   //Pulsante per accendere il PROGRAMMA
int LedRandom;            //LED che si accenderà in modo RANDOMICO
int PulsanteTempoLed;     //Pulsante per spegnere il LED e poter calcolare i MILLISECONDI INIZIALI
int Buzzer;               //BUZZER che si accenderà in modo RANDOMDOMICO
int PulsanteBuzzer;       //Pulsante per spegnere il BUZZER e poter calcolare i MILLISECONDI FINALI
int LedVerde;             //LED VERDE se il tempo è minore di 1000 ms
int LedRosso;             //LED ROSSO se il tempo è maggiore dei 1000 ms
int AppoggioA;            //Campo per poter utilizzare la VARIABILE A nel METODO TestRiflessi
int AppoggioB;            //Campo per poter utilizzare la VARIABILE B nel METODO TestRiflessi
int AppoggioC;            //Campo per poter utilizzare la VARIABILE C nel METODO TestRiflessi
int AppoggioD;            //Campo per poter utilizzare la VARIABILE D nel METODO TestRiflessi
int AppoggioE;            //Campo per poter utilizzare la VARIABILE E nel METODO TestRiflessi
int AppoggioF;            //Campo per poter utilizzare la VARIABILE F nel METODO TestRiflessi

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
  pinMode(PulsanteAccensione, INPUT);  //Inserisco INPUT per tutti i PULSANTI
  pinMode(LedRandom, OUTPUT);
  pinMode(PulsanteTempoLed, INPUT);    //Inserisco INPUT per tutti i PULSANTI
  pinMode(Buzzer, OUTPUT);
  pinMode(PulsanteBuzzer, INPUT);      //Inserisco INPUT per tutti i PULSANTI
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRosso, OUTPUT);
}

void loop() {
  TestRiflessi("Premi il PULSANTE DI ACCENSIONE per iniziare il TEST",PulsanteAccensione,LedRandom,AppoggioA,AppoggioB,AppoggioC,AppoggioD,AppoggioE,AppoggioF);
}

void TestRiflessi(String inizio,int domanda,int risposta, int a, int b, int c, int d, int e,int f)
{
  Serial.println(inizio);
  while(digitalRead(PulsanteAccensione) == LOW) {};
  while(digitalRead(PulsanteAccensione) == HIGH)
  {
    d = millis();
    digitalWrite(LedRandom,HIGH);
    delay(random(1000, 5000));
    a = millis();
    e = a - d;
    while(digitalRead(PulsanteTempoLed) == HIGH)
    {
      f = millis();
      digitalWrite(Buzzer,HIGH);
      delay(random(1000,5000));
      b = millis();
      c = b - f;
      while(digitalRead(PulsanteBuzzer) == HIGH)
      {
        Serial.println("LED:" + String(e) + "BUZZER:" + String(c));
        if ( e > 1000 && c > 1000 )
        {
          digitalWrite(LedRosso, HIGH);
        }
        else
        {
          digitalWrite(LedVerde, HIGH);
        }
      }    
    }
  }
  
}
