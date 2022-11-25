/*
 * dezentrales System: jeder hat seinen eigenen Akku
 * System: autakes Haus: stellt Energie bereit & verbraucht Energie
 * Grundgedanke: Strom haben -> Zahlen; Strom einspreisen -> Verdienen
 * Intelligenz: Möglichst effektive Nutzung der Ressourcen (Energie) 
 * Aber auch faire Verteilung gewährleisten: Verpflichtung einen gewissen Anteil einzuspeisen? Optional noch mehr Einspeisen möglich um Geld zu verdienen?
 * 
 * Umsetzung:
 * - Akku mit Ah
 * - versch. Verbraucher mit Amphere Angabe
 * - Solar-Panel(s) mit Angabe Effektivität; Nutzen abhängig von Lichtverhältnissen (Sensor)
 * - Status Anzeige (LED): Akku Stand; Energie-Verbrauch
 * - Energie-Überschuss erst in eigenen Akkue einspeisen; Geld für Abgabe ins Netz / an andere Häuser 
 * - Energie-Mangel: Gegen Geld Strom aus anderen Akkus
 * - komplette Energieknappheit: alle Häuser werden gedrosselt
 */


#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "SmartCity";
const char* password = "123456789";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Create an Event Source on /events
AsyncEventSource events("/events");


// Timer variables
unsigned long lastTime = 0;  
unsigned long timerDelay = 3000;

int maxAh = 100; 
int leftAh = 100; //enery left -> percentage: (leftA / maxA) * 100

//totalA = 50A
int consumerCount = 2;
int consumerAmphere[2] {10, 10};
int consumerPin[2] {D6, D7};
bool consumerActive[2] {true, true};


void loop(){
  if ((millis() - lastTime) > timerDelay) {
    // Send Events to the Web Server with the Sensor Readings
    events.send("ping",NULL,millis());
    events.send(String(maxAh).c_str(),"temperature",millis());
    events.send(String(leftAh).c_str(),"humidity",millis());
    events.send(String(consumerCount).c_str(),"pressure",millis());
    
    lastTime = millis();
  }
}
