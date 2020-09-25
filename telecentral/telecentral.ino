#include <SPI.h>
#include <Ethernet.h>

// SET VAR

bool prespomp = 0;
bool sensumi = 0;
/*bool dswpred1 = 0;
  bool dswpred2 = 0;
  bool dswpred3 = 0;
  bool dswpred4 = 0;
  bool dswpred5 = 0;
  bool dswpred6 = 0;*/


// SET ETH

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //MAC address scheda di rete
IPAddress ip(192, 168, 0, 177); //ip arduino
EthernetServer server(80); // su che porta gira il server

void setup() {

  // SETUP OUTPUT

  pinMode(2, OUTPUT);//evalvola
  pinMode(3, OUTPUT);//evalvola
  pinMode(5, OUTPUT);//evalvola
  pinMode(6, OUTPUT);//evalvola
  pinMode(7, OUTPUT);//evalvola
  pinMode(8, OUTPUT);//evalvola
  pinMode(9, OUTPUT);//Pompa

  // SETUP DIPSW

  pinMode(33, INPUT);//dipsw presenza pompa
  pinMode(34, INPUT);//dipsw 3/6 sensori umidità
  /*pinMode(35, INPUT);//dipsw n.d.
    pinMode(36, INPUT);//dipsw n.d.
    pinMode(37, INPUT);//dipsw n.d.
    pinMode(38, INPUT);//dipsw n.d.
    pinMode(39, INPUT);//dipsw n.d.
    pinMode(40, INPUT);//dipsw n.d.*/

  // SETUP INPUT DIGITAL
  pinMode(28, INPUT);//dipsw presenza pompa
  pinMode(29, INPUT);//dipsw presenza pompap

  // SETUP INPUT ANALOG

  pinMode(A1, INPUT);//sensore fila 1
  pinMode(A2, INPUT);//sensore fila 2
  pinMode(A3, INPUT);//sensore fila 3
  pinMode(A4, INPUT);//sensore fila 4
  pinMode(A5, INPUT);//sensore fila 5
  pinMode(A6, INPUT);//sensore fila 6

  // LETTURA DIPSW

  if (digitalRead(33) == HIGH) //presenza pompa
  {
    prespomp = 1;
  }
  if (digitalRead(34) == HIGH) //6 sensori umidità
  {
    sensumi = 1;
  }
  /*   if (digitalRead(35)== HIGH) //predisposizione
    {
    dswpred1 = 0;
    }
    if (digitalRead(36)== HIGH) //predisposizione
    {
    dswpred2 = 0;
    }
    if (digitalRead(37)==HIGH) //predisposizione
    {
    dswpred3 = 0;
    }
    if (digitalRead(38)==HIGH) //predisposizione
    {
    dswpred4 = 0;
    }
     if (digitalRead(39)== HIGH)//predisposizione
    {
    dswpred5 = 0;
    }
    if (digitalRead(40)== HIGH) //predisposizione
    {
    dswpred6 = 0;
    }*/

  // INIZIO CONNESSIONE ETH

  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("il server gira su ");
  Serial.println(Ethernet.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
