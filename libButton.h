/*
 * 
 * libButton.h - Kirjasto painikkeiden hallintaa varten
 * sekä myös esimerkki oman kirjaston luontiin
 *
 * by Jani Lehto
 *
 */

#ifndef Button_h
#define Button_h

#include <Arduino.h>

const int BUTTONPRESSED=LOW;
const int BOUNCE=20;
/*
Luodaan luokka joka muodostuu metodeista painikkeen käsittelyä varten,
sekä muuttujuat joita tarvitaan
*/
class Button
{
  //Julkinen tieto
  public:
    //Konstruktori joka liittää metodit valitulle tulolle
    Button(int pin);
    Button(int pin, int keepTime);
    //Metodi joka kertoo painkkeen painalluksesta
    bool pressed();
    bool released();
    bool kept();
  //Yksityinen tieto
  private:
    //Mihin tuloon painike liitetään
    int _pin;
    //Tilatieto vanhasta painikkeen tilasta
    int _prevPState;
    int _prevRState;
    //Aikaleima
    unsigned long _timeStamp;
    unsigned long _keepTime;
};

#endif
