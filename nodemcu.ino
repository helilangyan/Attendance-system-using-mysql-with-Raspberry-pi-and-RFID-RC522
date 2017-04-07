#include <RFID.h>
/* Include the standard Arduino SPI library */
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 2
#define RESET_DIO 15
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 

void setup()
{ 
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
}

void loop()
{
  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.print("Card detected:");
    Serial.print("  ");
    for(int i=0;i<5;i++)
    {
    Serial.print(RC522.serNum[i],DEC);
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    }
    Serial.print("  ");

 Serial.print("RFID NAME SERIES: ");
 Serial.print("  ");
 Serial.print(522);
 Serial.println("  ");
  }
  delay(2000);
}
