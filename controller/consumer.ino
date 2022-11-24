void consume(){ //each hour consume energy  
  int totalA = 0; //total amphere
  for(int i=0; i<consumerCount; i++){
    if(consumerActive[i]){
      totalA += consumerAmphere[i];
    }
  }

  
  if(leftAh - totalA >= 0){
    leftAh -= totalA;
    setLight(true);
  }else{ //not enough enery: disable leds
    setLight(false);
  }
}

void setLight(bool enable){
  for(int i=0; i<consumerCount; i++){
    digitalWrite(consumerPin[i], enable ? HIGH : LOW);
  }
}
