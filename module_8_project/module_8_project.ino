//import libraries
#include <AddicoreRFID.h>
#include <SPI.h>

#define	uchar	unsigned char
#define	uint	unsigned int


//nfc

uchar fifobytes;
uchar fifoValue;

AddicoreRFID myRFID; // create AddicoreRFID object to control the RFID module

#define nfc_japan 102
#define nfc_haiti 209
#define nfc_nepal 25
#define nfc_turkey 116
#define nfc_the_netherlands 76
#define nfc_usa 42
#define nfc_china 131
#define nfc_italy 59
#define nfc_chile 102
#define nfc_egypt 252
#define nfc_greece 90
#define nfc_guatemala 186
#define nfc_myanmar 112
#define nfc_russia 159
#define nfc_indonesia 26
#define nfc_new_zealand 183
#define nfc_mexico 215


//pins
const int chipSelectPin = 10; // nfc
const int NRSTPD = 5; // nfc

//earthquake
#define earthquake_japan 1
#define earthquake_haiti 2
#define earthquake_nepal 3
#define earthquake_turkey 4
#define earthquake_the_netherlands 5
#define earthquake_usa 6
#define earthquake_china 7
#define earthquake_italy 8
#define earthquake_chile 9
#define earthquake_egypt 10
#define earthquake_greece 11
#define earthquake_guatemala 12
#define earthquake_myanmar 13
#define earthquake_russia 14
#define earthquake_indonesia 15
#define earthquake_new_zealand 16
#define earthquake_mexico 17

//variables
int modeState = 0;
int nfcState = 0;
#define MAX_LEN 16 // Maximum length of NFC array


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  SPI.begin();

  pinMode(chipSelectPin,OUTPUT);              // Set digital pin 10 as OUTPUT to connect it to the RFID /ENABLE pin
    digitalWrite(chipSelectPin, LOW);         // Activate the RFID reader
  pinMode(NRSTPD,OUTPUT);                     // Set digital pin 10 , Not Reset and Power-down
    digitalWrite(NRSTPD, HIGH);

  myRFID.AddicoreRFID_Init();
  for(int i=3; i<=19; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for(int i=3; i<=19; i++) {
    digitalWrite(i, LOW);
  }

  // put your main code here, to run repeatedly:
    	uchar i, tmp, checksum1;
	uchar status;
        uchar str[MAX_LEN];
        uchar RC_size;
        uchar blockAddr;	//Selection operation block address 0 to 63
        String mynum = "";

        str[1] = 0x4400;
	//Find tags, return tag type
	status = myRFID.AddicoreRFID_Request(PICC_REQIDL, str);
	if (status == MI_OK)
	{
          Serial.println("RFID tag detected");
          Serial.print("Tag Type:\t\t");
          uint tagType = str[0] << 8;
          tagType = tagType + str[1];
          switch (tagType) {
            case 0x4400:
              Serial.println("Mifare UltraLight");
              break;
            case 0x400:
              Serial.println("Mifare One (S50)");
              break;
            case 0x200:
              Serial.println("Mifare One (S70)");
              break;
            case 0x800:
              Serial.println("Mifare Pro (X)");
              break;
            case 0x4403:
              Serial.println("Mifare DESFire");
              break;
            default:
              Serial.println("Unknown");
              break;
          }
	}

	//Anti-collision, return tag serial number 4 bytes
	status = myRFID.AddicoreRFID_Anticoll(str);
	if (status == MI_OK)
	{
          checksum1 = str[0] ^ str[1] ^ str[2] ^ str[3];
          Serial.print("The tag's number is:\t");
    	    Serial.print(str[0]);
            Serial.print(" , ");
    	    Serial.print(str[1]);
            Serial.print(" , ");
    	    Serial.print(str[2]);
            Serial.print(" , ");
    	    Serial.println(str[3]);

          Serial.print("Read Checksum:\t\t");
    	      Serial.println(str[4]);
          Serial.print("Calculated Checksum:\t");
            Serial.println(checksum1);

            // Should really check all pairs, but for now we'll just use the first
            if(str[0] == 197)                      //You can change this to the first byte of your tag by finding the card's ID through the Serial Monitor
            {
                Serial.println("\nHello Craig!\n");
            } else if(str[0] == 244) {             //You can change this to the first byte of your tag by finding the card's ID through the Serial Monitor
                Serial.println("\nHello Erin!\n");
            }
            Serial.println();
			switch(checksum1){
				case nfc_the_netherlands:
					modeState = earthquake_the_netherlands;
					break;
				case nfc_mexico:
					modeState = earthquake_mexico;
					break;
				default:
					modeState = 0;
					break;
			}

            delay(1000);
	} else {
    modeState = 0;
	}

        myRFID.AddicoreRFID_Halt();		   //Command tag into hibernation


  switch(modeState) {
    case earthquake_japan:
      digitalWrite(3, HIGH);
      break;
    case earthquake_haiti:
      digitalWrite(4, HIGH);

		break;
    case earthquake_nepal:
      digitalWrite(5, HIGH);

		break;
    case earthquake_turkey:
      digitalWrite(6, HIGH);

		break;
    case earthquake_the_netherlands:
      digitalWrite(7, HIGH);

      break;
    case earthquake_use:
      digitalWrite(8, HIGH);

      break;
    case earthquake_china:
      digitalWrite(9, HIGH);

		break;
    case earthquake_italy:
      digitalWrite(10, HIGH);

		break;
    case earthquake_chile:
      digitalWrite(11, HIGH);

		break;
    case earthquake_egypt:
      digitalWrite(12, HIGH);

		break;
    case earthquake_greece:
      digitalWrite(13, HIGH);

		break;
    case earthquake_guatemala:
      digitalWrite(14, HIGH);

		break;
    case earthquake_myanmar:
      digitalWrite(15, HIGH);

		break;
    case earthquake_russia:
      digitalWrite(16, HIGH);

		break;
    case earthquake_indonesia:
      digitalWrite(17, HIGH);

		break;
    case earthquake_new_zealand:
      digitalWrite(18, HIGH);

		break;
    case earthquake_mexico:
      digitalWrite(19, HIGH);

      break;

    default:
    
      break;
  }
}
