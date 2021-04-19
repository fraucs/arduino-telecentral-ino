#include <SPI.h>
#include <Ethernet.h>


int statoint = LOW;
int statoest = LOW;
bool dip1;
bool dip2;
bool dip3;

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 50, 123);
EthernetServer server(63000);


void setup()
{
  Serial.begin(9600);
  //Relè
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);

  //Sensori D
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  pinMode(39, INPUT);

  //Pulsanti
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);
  pinMode(44, INPUT);

  //DIPSWITCH
  pinMode(46, INPUT);
  pinMode(47, INPUT);
  pinMode(48, INPUT);



  if (digitalRead(46) == HIGH)
  {
    if (digitalRead(47) == HIGH)
    {
      if (digitalRead(48) == HIGH)
      {
        Serial.println("se tutti sono on"); //se tutti sono on
        digitalWrite(5, HIGH);
      }
      else
      {
        Serial.println("solo dip1 dip2 on");//solo dip1 dip2 on
      }
    }
    else
    {
      Serial.println("solo dip1  on");//solo dip1
    }
  }
  else
  {
    if (digitalRead(47) == HIGH)
    {
      if (digitalRead(48) == HIGH)
      {
        Serial.println("solo dip2 dip3 on");//solo dip2 dip3
        digitalWrite(5, HIGH);

      }
      else
      {
        Serial.println("solo  dip2 on") ;//solo dip2 on
      }
    }
    else
    {
      if (digitalRead(48) == HIGH)
      {
        Serial.println("solo dip3 on");
        digitalWrite(5, HIGH);
      }
      else
      {
        Serial.println("no dip  on");//nessun dip
      }
    }
  }

  //AUX D
  pinMode(45, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);

  //Sensori A
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);

  //AUX A
  //pinMode(A10, OUTPUT);
  //pinMode(A11, OUTPUT);
  //pinMode(A12, OUTPUT);
  //pinMode(A13, OUTPUT);
  //pinMode(A14, OUTPUT);
  //pinMode(A15, OUTPUT);

  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop()
{
// listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 5");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.print("<h1>Analogue Values</h1>");
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
    if ( digitalRead ( 40 ) == HIGH) {
    statoint = ! statoint;
    delay ( 600 );
  }

  if (statoint == HIGH) {
    digitalWrite ( 2 , HIGH);
  } else {
    digitalWrite ( 2 , LOW);
  }
  //luce ext
  if ( digitalRead ( 41 ) == HIGH) {
    statoest = ! statoest;
    delay ( 600 );
  }

  if (statoest == HIGH) {
    digitalWrite ( 3 , HIGH);
  } else {
    digitalWrite ( 3 , LOW);
  }
}
