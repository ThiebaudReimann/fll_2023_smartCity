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

int maxAh = 100; 
int leftAh = 100; //enery left -> percentage: (leftA / maxA) * 100

//totalA = 50A
int consumerCount = 2;
int consumerAmphere[1];
bool consumerActive[1];

void setup(){
  
}
void loop(){
  
}

void consume(){ //each hour consume energy  
  int totalA = 0; //total amphere
  for(int i=0; i<consumerCount; i++){
    if(consumerActive[i]){
      totalA += consumerAmphere[i];
    }
  }

  
  if(leftAh - totalA >= 0){
    leftAh -= totalA;
  }else{ //not enough enery: disable leds
    
  }
}
