#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);      // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  Serial.println("Attempting to get card info");
  while (true)
  {
    SPI.begin();          // Init SPI bus
    mfrc522.PCD_Init();   // Init MFRC522
    delay(10000);
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  
    if (mfrc522.PICC_ReadCardSerial())
    {
      Serial.println("ReadCardSerial was successful");
    }
    else
    {
      Serial.println("ReadCardSerial failure");
    }
  }
}


void loop() {
  return;
}
