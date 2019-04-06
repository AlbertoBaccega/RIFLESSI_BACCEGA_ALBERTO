//PROGRAMMA RIFLESSI BACCEGA ALBERTO

int PulsanteAccensione;   //Pulsante per accendere il PROGRAMMA
int LedRandom;            //LED che si accenderà in modo RANDOMICO
int PulsanteTempoLed;     //Pulsante per spegnere il LED e poter calcolare i MILLISECONDI INIZIALI
int Buzzer;               //BUZZER che si accenderà in modo RANDOMDOMICO
int PulsanteBuzzer;       //Pulsante per spegnere il BUZZER e poter calcolare i MILLISECONDI FINALI
int LedVerde;             //LED VERDE se il tempo è minore di 1000 ms
int LedRosso;             //LED ROSSO se il tempo è maggiore dei 1000 ms
int TempoMinimo;          //Tempo minimo così da far crashare il programma in caso di tasti premuti a caso
int TempoMinimoLed;       //Tempo minimo peril LED ROSSO O VERDE a seconda dei millisecondi
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
  TempoMinimo = 70;
  TempoMinimoLed = 1000;
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
    while(digitalRead(PulsanteAccensione) == LOW) {}        
      delay(random(1000, 5000));
      d = millis();       
      digitalWrite(LedRandom,HIGH);         
      while(digitalRead(PulsanteTempoLed) == LOW) {}
      a = millis();  
      e = a - d;           
      digitalWrite(LedRandom,LOW);
      if ( e < TempoMinimo)
      {
        Serial.println("Test non VALIDO perchè" + String(e) + "minore del TEMPO MINIMO DI RISPOSTA");
      }    
      while(digitalRead(PulsanteTempoLed) == LOW) {}        
        delay(random(1000,5000));  
        f = millis();
        digitalWrite(Buzzer,HIGH);
        while(digitalRead(PulsanteBuzzer) == LOW) {}
        b = millis();
        c = b - f;          
        digitalWrite(Buzzer,LOW);
        if ( c < TempoMinimo)
        {
          Serial.println("Test non VALIDO perchè" + String(c) + "minore del TEMPO MINIMO DI RISPOSTA");
        }
        while(digitalRead(PulsanteBuzzer) == LOW) {}
          Serial.println("LED:" + String(e) + "BUZZER:" + String(c));
          if ( e > TempoMinimoLed && c > TempoMinimoLed )
            {
              digitalWrite(LedRosso, HIGH);
              delay(3000);
              digitalWrite(LedRosso, LOW);
            }
            else
            {
              digitalWrite(LedVerde, HIGH);
              delay(3000);
              digitalWrite(LedVerde, LOW);
            }
        }    

