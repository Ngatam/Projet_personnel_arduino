////////////////////////////////////// Import /////////////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>
#include <Wire.h>



////////////////////////////////////// Définition /////////////////////////////////////////////////////

// Définition des broches des capteurs sur l'Arduino
#define CAPTEUR_RESISTIF A0     // Capteur résistif branché sur A0
#define CAPTEUR_CAPACITIF_V1 A1 // Capteur capacitif branché sur A1
#define CAPTEUR_CAPACITIF_V2 A2 // Capteur capacitif branché sur A2
#define RELAIS_PIN 8            // Broche du relais branché sur 8

// Seuils pour le capteur résistif
#define SECHERESSE_RESISTIF 0 // Valeur brute lorsque le sol est sec
#define HUMIDITE_RESISTIF 900 // Valeur brute lorsque le sol est très humide

// Seuils pour le capteur capacitif V1
//#define SECHERESSE_CAPACITIF_V1 528 // Valeur brute lorsque le sol est sec
//#define HUMIDITE_CAPACITIF_V1 260   // Valeur brute lorsque le sol est très humide

// Seuils pour le capteur capacitif V2
//#define SECHERESSE_CAPACITIF_V2 600 // Valeur brute lorsque le sol est sec
//#define HUMIDITE_CAPACITIF_V2 260   // Valeur brute lorsque le sol est très humide

// Seuil en % d’humidité
#define SEUIL_HUMIDITE 30

// Ecran LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);




////////////////////////////////////// Void setup /////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);

  // Ecran LCD
  lcd.init(); // Démarre l'afficheur
  lcd.backlight(); // Allume le rétro-éclairage

  // Relais
  pinMode(RELAIS_PIN, OUTPUT);
  digitalWrite(RELAIS_PIN, LOW); // Relais désactivé au démarrage (actif HIGH)

  delay(5000);
}



////////////////////////////////////// Void loop /////////////////////////////////////////////////////

void loop() {
  // Lecture du capteur résistif
  int valeur_Resistif = analogRead(CAPTEUR_RESISTIF);
  int humidite_Resistif = map(valeur_Resistif, SECHERESSE_RESISTIF, HUMIDITE_RESISTIF, 0, 100);

  // Lecture du capteur capacitif V1
  //int valeur_Capacitif_V1 = analogRead(CAPTEUR_CAPACITIF_V1);
  //int humidite_Capacitif_V1 = map(valeur_Capacitif_V1, SECHERESSE_CAPACITIF_V1, HUMIDITE_CAPACITIF_V1, 0, 100);

  // Lecture du capteur capacitif V2
  //int valeur_Capacitif_V2 = analogRead(CAPTEUR_CAPACITIF_V2);
  //int humidite_Capacitif_V2 = map(valeur_Capacitif_V2, SECHERESSE_CAPACITIF_V2, HUMIDITE_CAPACITIF_V2, 0, 100);

  // Affichage des valeurs dans le terminal
  Serial.print("Resistif : Valeur brute : "); Serial.print(valeur_Resistif);
  Serial.print(" | Humidité : "); Serial.print(humidite_Resistif); Serial.println("%");
  
  //Serial.print("Capacitif V1 : Valeur brute : "); Serial.print(valeur_Capacitif_V1);
  //Serial.print(" | Humidité : "); Serial.print(humidite_Capacitif_V1); Serial.println("%");
  
  //Serial.print("Capacitif V2 : Valeur brute : "); Serial.print(valeur_Capacitif_V2);
  //Serial.print(" | Humidité : "); Serial.print(humidite_Capacitif_V2); Serial.println("%");
  
  // Affichage des valeurs sur l ecran LCD
  lcd.setCursor(0,0);
  lcd.print("Resistif : "); lcd.print(humidite_Resistif); lcd.print("%   ");

  //lcd.setCursor(0,1);
  //lcd.print("Capa V2  : "); lcd.print(humidite_Capacitif_V2); lcd.print("%   ");
  
  // Controle du relais
  if (humidite_Resistif < SEUIL_HUMIDITE) {
    digitalWrite(RELAIS_PIN, HIGH); // Active la pompe
    Serial.println("Pompe ON");
    delay(5000);
  }
  digitalWrite(RELAIS_PIN, LOW); // Désactive la pompe
  Serial.println("Pompe OFF");
    
  Serial.println("----------------------------");
  // delay(500); // Pause de 500 ms entre chaque mesure
}
