# Ballon-solaire

## Composants

* Carte Arduino_Uno
* Capteur Adafruit_BMP280
* Capteur MQ135
* Lecteur carte microSD
* Connecteur Pile 9V
* 8 cables Male-Femelle
* 5 cables Femelle-Femelle

## Branchement
![Fritzing](/Cablage/Untitled_Sketch.png)

### Shield
* NC

### Analogique
* A0: capteur Gaz
* A1: NC
* A2: NC
* A3: NC
* A4: NC
* A5: NC

### Digital
* D0 : RX rs232 non utilise
* D1 : TX rs232 non utilise
* D2 : NC
* D3 : NC
* D4 : NC
* D5 : NC
* D6 : NC
* D7 : NC
* D8 : NC
* D9 : NC
* D10 : carte SD
* D11 : NC
* D12 : NC
* D13 : NC 

### I2C
* SDA : Adafruit_BMP280
* SCL : Adafruit_BMP280

### Alimentation
* Vin : NC
* GND : Adafruit_BMP280 ; capteur Gaz
* 5V : capteur Gaz
* 3.3V : Adafruit_BMP280
* Vref : NC

### Divers 
* Ioref : NC
* Reset : NC

### ISP
* SCK : carte SD
* MOSI : carte SD
* MISO : carte SD
* VCC : carte SD
* GND : carte SD