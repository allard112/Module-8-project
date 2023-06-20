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
  for(int i=3; i<=19; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for(int i=3; i<=19; i++) {
    digitalWrite(i, LOW);
  }

  // put your main code here, to run repeatedly:
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
  }
}
