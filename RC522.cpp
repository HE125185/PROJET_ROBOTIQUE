

#include <SPI.h>
#include <MFRC522.h>
#include <wire.h>
#define RST_PIN         9          // configure  RST sur la pin 9
#define SS_PIN          10         // configure SS sur la pin 10

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
	Serial.begin(9600);		// initialise la communication avec le pc
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// initialise SPI
	mfrc522.PCD_Init();		// initialise MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	// reset la boucle si aucune carte est présente 
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Verifie si une nouvelle carte est présentée
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
//affichage de l'ID
Serial.println("un badge est détecté");
Serial.println("L'UID du tag ");
lcd.println("badge détecté");
delay(2000);
lcd.clear();


