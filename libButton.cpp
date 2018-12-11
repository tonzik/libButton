/*
 * 
 * libButton.cpp - Kirjasto painikkeiden hallintaa varten
 * sekä myös esimerkki oman kirjaston luontiin
 *
 * by Jani Lehto
 *
 */

#include <Arduino.h>
#include "Button.h"

/*
Konstruktori - Funktio joka luo uuden ilmentymän Button-luokasta. 
Täällä alustetaan kaikki painkeen toiminnot
*/
Button::Button(int pin)
{
  //Tuttuun tapaan määritetään pinni lähdöksi
  pinMode(pin, INPUT_PULLUP);
  //Tallennetaan omaksi tiedoksi mihin pinnin liityttiin
  _pin=pin;
  //Luetaan painikkeen tila ensimmäistä vertailua varten
  _prevPState=digitalRead(pin);
  _prevRState=digitalRead(pin);
  //Aikaleiman nollaus
  _timeStamp=0;
  _keepTime=5000;
}



Button::Button(int pin, int keepTime)
{
  //Tuttuun tapaan määritetään pinni lähdöksi
  pinMode(pin, INPUT_PULLUP);
  //Tallennetaan omaksi tiedoksi mihin pinnin liityttiin
  _pin=pin;
  //Luetaan painikkeen tila ensimmäistä vertailua varten
  _prevPState=digitalRead(pin);
  _prevRState=digitalRead(pin);
  //Aikaleiman nollaus
  _timeStamp=0;
  _keepTime=keepTime;
}

/*
Funktio joka kertoo jos painike on painettu. bool paluuarvo voi olla 
tosi tai epätosi. buttonPressed() funktiolle ei tarvitse kertoa mitä
pinniä tutkaillaan koska se tieto saatiin jo konstruktorilla.
*/
bool Button::pressed(){
  bool ret=0;
  int x=digitalRead(_pin);
  if(x!=_prevPState && x==BUTTONPRESSED){
    ret=1;
    delay(BOUNCE);
  }
  _prevPState=x;
  return ret;
}

/*
Funktio joka kertoo jos painike on vapautettu. bool paluuarvo voi olla 
tosi tai epätosi. buttonPressed() funktiolle ei tarvitse kertoa mitä
pinniä tutkaillaan koska se tieto saatiin jo konstruktorilla.
*/
bool Button::released(){
  bool ret=0;
  int x=digitalRead(_pin);
  if(x!=_prevRState && x!=BUTTONPRESSED){
    ret=1;
    delay(BOUNCE);
  }
  _prevRState=x;
  return ret;
}

/*
 * Funktio kertoo viiden sekunnin välein painikkeen
 * pohjassapidosta
 */
bool Button::kept(){
  bool ret=0;
  int x=digitalRead(_pin);
  if(x == BUTTONPRESSED){
      if(_timeStamp == 0){//Uuusi painallus
        _timeStamp = millis();//Eli otetaan uusi aikaleima
      }else if(millis()-_timeStamp > _keepTime){
        ret = 1;
        _timeStamp += _keepTime;        
      }
  }else{
    _timeStamp=0;
  }
  return ret;
}
