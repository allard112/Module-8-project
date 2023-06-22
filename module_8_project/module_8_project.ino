//import libraries
#include <AddicoreRFID.h>
#include <SPI.h>

#define uchar unsigned char
#define uint unsigned int


//nfc

uchar fifobytes;
uchar fifoValue;

AddicoreRFID myRFID;  // create AddicoreRFID object to control the RFID module

#define nfc_japan 155
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
const int chipSelectPin = 10;  // nfc
const int NRSTPD = 5;          // nfc

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
#define nothing_detected 18

//variables
int modeState = 0;
int nfcState = 0;
#define MAX_LEN 16  // Maximum length of NFC array


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  SPI.begin();

  pinMode(chipSelectPin, OUTPUT);    // Set digital pin 10 as OUTPUT to connect it to the RFID /ENABLE pin
  digitalWrite(chipSelectPin, LOW);  // Activate the RFID reader
  pinMode(NRSTPD, OUTPUT);           // Set digital pin 10 , Not Reset and Power-down
  digitalWrite(NRSTPD, HIGH);

  myRFID.AddicoreRFID_Init();
  for (int i = 3; i <= 19; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  uchar i, tmp, checksum1;
  uchar status;
  uchar str[MAX_LEN];
  uchar RC_size;
  uchar blockAddr;  //Selection operation block address 0 to 63
  String mynum = "";

  str[1] = 0x4400;
  //Find tags, return tag type
  status = myRFID.AddicoreRFID_Request(PICC_REQIDL, str);
  if (status == MI_OK) {
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
  if (status == MI_OK) {
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
    if (str[0] == 197)  //You can change this to the first byte of your tag by finding the card's ID through the Serial Monitor
    {
      Serial.println("\nHello Craig!\n");
    } else if (str[0] == 244) {  //You can change this to the first byte of your tag by finding the card's ID through the Serial Monitor
      Serial.println("\nHello Erin!\n");
    }
    Serial.println();
    switch (checksum1) {
      case nfc_japan:
        modeState = earthquake_japan;
        break;

      case nfc_haiti:
        modeState = earthquake_haiti;
        break;

      case nfc_nepal:
        modeState = earthquake_nepal;
        break;

      case nfc_the_netherlands:
        modeState = earthquake_the_netherlands;
        break;

      case nfc_mexico:
        modeState = earthquake_mexico;
        break;

      case nfc_turkey:
        modeState = earthquake_turkey;
        break;

      case nfc_usa:
        modeState = earthquake_usa;
        break;

      case nfc_china:
        modeState = earthquake_china;
        break;

      case nfc_italy:
        modeState = earthquake_italy;
        break;

      case nfc_chile:
        modeState = earthquake_chile;
        break;

      case nfc_egypt:
        modeState = earthquake_egypt;
        break;

      case nfc_greece:
        modeState = earthquake_greece;
        break;

      case nfc_guatemala:
        modeState = earthquake_guatemala;
        break;

      case nfc_myanmar:
        modeState = earthquake_myanmar;
        break;

      case nfc_russia:
        modeState = earthquake_russia;
        break;

      case nfc_indonesia:
        modeState = earthquake_indonesia;
        break;

      case nfc_new_zealand:
        modeState = earthquake_new_zealand;
        break;

      default:
        modeState = 0;
        break;
    }

    delay(1000);
  } else {
    modeState = 0;
    modeState = 18;
  }

  myRFID.AddicoreRFID_Halt();  //Command tag into hibernation

  switch (modeState) {
    case earthquake_japan:
      Serial.print("works jap");
      break;

    case earthquake_haiti:
      Serial.print("works haiti");
      break;

    case earthquake_nepal:
      Serial.print("works nepal");
      break;

    case earthquake_turkey:
      digitalWrite(6, HIGH);
      Serial.print("works turk");
      break;

    case earthquake_the_netherlands:
      digitalWrite(7, HIGH);
      Serial.print("works nl");
      break;

    case earthquake_usa:
      Serial.print("works usa");
      break;

    case earthquake_china:
      Serial.print("works china");
      digitalWrite(9, HIGH);
      break;

    case earthquake_italy:
      Serial.print("works italy");
      digitalWrite(10, HIGH);
      break;

    case earthquake_chile:
      Serial.print("works chile");
      digitalWrite(11, HIGH);
      break;

    case earthquake_egypt:
      Serial.print("works egypt");
      digitalWrite(12, HIGH);
      break;

    case earthquake_greece:
      Serial.print("works greece");
      digitalWrite(13, HIGH);
      break;

    case earthquake_guatemala:
      Serial.print("works guatemala");
      digitalWrite(14, HIGH);
      break;

    case earthquake_myanmar:
      Serial.print("works myanmar");
      digitalWrite(15, HIGH);
      break;

    case earthquake_russia:
      Serial.print("works russia");
      digitalWrite(16, HIGH);
      break;

    case earthquake_indonesia:
      Serial.print("works indonesia");
      digitalWrite(17, HIGH);
      break;

    case earthquake_new_zealand:
      Serial.print("works new zealand");
      digitalWrite(18, HIGH);
      break;

    case earthquake_mexico:
      Serial.print("works mexico");
      digitalWrite(19, HIGH);
      break;

    case nothing_detected:
      Serial.println("it goes here");
      // digitalWrite(3, LOW);
      // digitalWrite(4, LOW);
      // digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      // digitalWrite(8, LOW);
      // digitalWrite(9, LOW);
      // digitalWrite(10, LOW);
      // digitalWrite(11, LOW);
      // digitalWrite(12, LOW);
      // digitalWrite(13, LOW);
      // digitalWrite(14, LOW);
      // digitalWrite(15, LOW);
      // digitalWrite(16, LOW);
      // digitalWrite(17, LOW);
      // digitalWrite(18, LOW);
      break;

    default:
      break;
  }
}
