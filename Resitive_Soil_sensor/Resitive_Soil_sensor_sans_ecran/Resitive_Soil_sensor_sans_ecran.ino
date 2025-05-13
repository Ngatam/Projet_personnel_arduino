// Définition des broches des capteurs sur l'Arduino
#define CAPTEUR_RESISTIF A0     // Capteur résistif branché sur A0
#define CAPTEUR_CAPACITIF_V1 A1 // Capteur capacitif branché sur A1
#define CAPTEUR_CAPACITIF_V2 A2 // Capteur capacitif branché sur A2

// Seuils pour le capteur résistif
#define SECHERESSE_RESISTIF 0 // Valeur brute lorsque le sol est sec
#define HUMIDITE_RESISTIF 900 // Valeur brute lorsque le sol est très humide

// Seuils pour le capteur capacitif V1
#define SECHERESSE_CAPACITIF_V1 520 // Valeur brute lorsque le sol est sec
#define HUMIDITE_CAPACITIF_V1 260   // Valeur brute lorsque le sol est très humide

// Seuils pour le capteur capacitif V2
#define SECHERESSE_CAPACITIF_V2 590 // Valeur brute lorsque le sol est sec
#define HUMIDITE_CAPACITIF_V2 260   // Valeur brute lorsque le sol est très humide

// Seuil en % d’humidité
#define SEUIL_HUMIDITE 30


void setup() {
  Serial.begin(9600);

}

void loop() {
  // Lecture du capteur résistif
  int valeur_Resistif = analogRead(CAPTEUR_RESISTIF);
  int humidite_Resistif = map(valeur_Resistif, SECHERESSE_RESISTIF, HUMIDITE_RESISTIF, 0, 100);

  // Lecture du capteur capacitif V1
  int valeur_Capacitif_V1 = analogRead(CAPTEUR_CAPACITIF_V1);
  int humidite_Capacitif_V1 = map(valeur_Capacitif_V1, SECHERESSE_CAPACITIF_V1, HUMIDITE_CAPACITIF_V1, 0, 100);

  // Lecture du capteur capacitif V2
  int valeur_Capacitif_V2 = analogRead(CAPTEUR_CAPACITIF_V2);
  int humidite_Capacitif_V2 = map(valeur_Capacitif_V2, SECHERESSE_CAPACITIF_V2, HUMIDITE_CAPACITIF_V2, 0, 100);

  // Affichage des valeurs
  Serial.print("Resistif : Valeur brute : "); Serial.print(valeur_Resistif);
  Serial.print(" | Humidité : "); Serial.print(humidite_Resistif); Serial.println("%");
  
  Serial.print("Capacitif V1 : Valeur brute : "); Serial.print(valeur_Capacitif_V1);
  Serial.print(" | Humidité : "); Serial.print(humidite_Capacitif_V1); Serial.println("%");
  
  Serial.print("Capacitif V2 : Valeur brute : "); Serial.print(valeur_Capacitif_V2);
  Serial.print(" | Humidité : "); Serial.print(humidite_Capacitif_V2); Serial.println("%");
  
  
  delay(200); // Pause de 200 ms entre chaque mesure
}
