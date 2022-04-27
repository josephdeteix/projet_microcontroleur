
/********************************************************
   Affichage de la masse en grammes avec un module HX711
   branché à l'Arduino.
   Nécessite le bibliothèque HX711 par Bodge:
   https://github.com/bogde/HX711
   Pour plus d'infos:
   https://electroniqueamateur.blogspot.com/2020/10/balance-base-darduino.html
 **********************************************************/

#include "HX711.h"

// HX711 circuit wiring
const int broche_DT = 2;
const int broche_SCK = 3;

HX711 balance;

void setup() {
  Serial.begin(115200);

  Serial.println("Initialisation de la balance...");

  balance.begin(broche_DT, broche_SCK);

  while (!balance.is_ready())
  {
    ;
  }

  balance.set_scale(2118); //calibration: le paramètre dépend de votre cellule de charge.
  balance.tare(); //ajustement du zéro

  Serial.println("La balance est prete!");

}

void loop() {

  Serial.print(balance.get_units(1));
  Serial.println();

}