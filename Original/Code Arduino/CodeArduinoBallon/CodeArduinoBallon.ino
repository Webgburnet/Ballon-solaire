// Ce code permet d'enregistrer les données des capteurs sur une carte microSD au cours du vol
// Il permet aussi de visualier les données sur le "Moniteur série", se référer au tutoriel pour plus de précisions 
// Pour une meilleure visualisation des données à l'aide de courbes, utiliser le code du dossier "CodeArduinoBallon_Courbes"

#include <SD.h> // charge la librairie de la carte SD
#include <SPI.h> // charge la librairie SPI
#include "Wire.h" // charge la librairie pour communiquer avec le bus I2C
#include "Adafruit_BMP280.h" // charge la librairie du capteur de pression

Adafruit_BMP280 mySensor ; // crée l'objet senseur appelé mySensor
int delaiAquisition = 1000; // délai d'aquisition des données (à régler à 100ms pour le vol)
unsigned long temps; // variable pour stocker le temps de vol en secondes (s)
float temperatureC; // variable pour stocker la température en degrés Celcius (°C)
float pression; // variable pour stocker la pression en Pascal (Pa)
float altitude; // variable pour stocker l'altitude en mètres (m)
int niveauCO2 = 0; // variable pour stocker le niveau de CO2 (sans unité)
int pinCarteSD = 10; // sélectionne le pin numero 10
File mySensorData; // cree le fichier mySensorData où vont s'écrire les donnees.

// Initialisation
void setup() {
  Serial.begin(9600); // turn on serial monitor
  if (!mySensor.begin()) {  // initialiser le capteur de pression
    Serial.println("Verifiez les branchements du capteur de pression BMP280 !");
    while (1);
  } 
  if (!SD.begin(pinCarteSD)) {  // initialiser le lecteur de carte microSD
    Serial.println("Verifiez les branchements du lecteur de carte microSD et inserez la carte !");
    while (1);
  } 
  pinMode(pinCarteSD,OUTPUT); // indique la sortie, ici la carte microSD
}

// Boucle
void loop() {
  
  temperatureC = mySensor.readTemperature(); // lire la température depuis BMP180
  pression = mySensor.readPressure(); // lire la pression
  altitude = mySensor.readAltitude(1013); // lire l'altitude
  niveauCO2 = analogRead(0); // lire le niveau de CO2
  mySensorData = SD.open("DONNEES.txt",FILE_WRITE); // ouvrir le fichier
  
  if (mySensorData) { // Cette condition est vérifiée si les données ont été lues correctement
    
    // Ecriture sur le moniteur série   
    Serial.print("Temps depuis le debut de l'aquisition : "); // écrire les résultats sur le Moniteur Série (en haut à droite)
    temps = millis()/1000;
    Serial.print(temps);
    Serial.println(" secondes");
    Serial.print(F("Temperature : ")); 
    Serial.print(temperatureC);
    Serial.println(" degres Celsius");
    Serial.print("Pression : " );
    Serial.print(pression);
    Serial.println(" Pascal");
    Serial.print("Altitude : " );
    Serial.print(altitude);
    Serial.println(" m");
    Serial.print("niveau CO2 : " );                       
    Serial.println(niveauCO2);  
    Serial.println(" ");   

    // Ecriture sur la carte microSD
    mySensorData.print(temps); 
    mySensorData.print("\t");
    mySensorData.print(temperatureC);
    mySensorData.print("\t");
    mySensorData.print(pression); 
    mySensorData.print("\t");
    mySensorData.print(altitude);
    mySensorData.print("\t");
    mySensorData.println(niveauCO2);
    
    mySensorData.close(); // fermer le fichier
    delay(delaiAquisition); // attente entre chaque écriture
  }
}
