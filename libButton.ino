#include "libButton.h"

Button S1(12, 2000);
Button S2(11);

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(S1.pressed()){
    Serial.println("Jep");
  }
  if(S1.released()){
    Serial.println("Jup");
  }
  if(S1.kept()){
    Serial.println("S1 Pito");
  }
  if(S2.kept()){
    Serial.println("S2 Pito");
  }
}
