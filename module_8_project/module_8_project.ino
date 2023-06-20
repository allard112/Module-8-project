//import libraries

//nfc
#define nfc_japan 1
#define nfc_haiti 2
#define nfc_nepal 3
#define nfc_turkey 4
#define nfc_the_netherlands 5
#define nfc_usa 6
#define nfc_china 7
#define nfc_italy 8
#define nfc_chile 9
#define nfc_egypt 10
#define nfc_greece 11
#define nfc_guatemala 12
#define nfc_myanmar 13
#define nfc_russia 14
#define nfc_indonesia 15
#define nfc_new_zealand 16
#define nfc_mexico 17

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(modeState) {
    case earthquake_japan:

      break;
    case earthquake_haiti:
    
      break;
    case earthquake_nepal:

      break;
    case earthquake_turkey:

      break;
    case earthquake_the_netherlands:

      break;
    case earthquake_use:

      break;
    case earthquake_china:

      break;
    case earthquake_italy:

      break;
    case earthquake_chile:

      break;
    case earthquake_egypt:

      break;
    case earthquake_greece:

      break;
    case earthquake_guatemala:

      break;
    case earthquake_myanmar:

      break;
    case earthquake_russia:

      break;
    case earthquake_indonesia:

      break;
    case earthquake_new_zealand:

      break;
    case earthquake_mexico:

      break;
  }


}
