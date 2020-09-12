#define YELLOW 12
#define GREEN 11
#define BLUE 10
#define RED 9
#define BUZZER 5
#define ONE_SEC 1000
#define BPM 500

unsigned int G = 392;
unsigned int A = 440;
unsigned int C = 523;
unsigned int B = 494;
unsigned int D = 587;
unsigned int G1 = 784;
unsigned int E = 659;
unsigned int F = 698;

void setup() {
  //LEDs
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

  //Piezo Buzzer
  pinMode(BUZZER, OUTPUT);
}

void FlashLED(void);

void loop() {

  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM * 2 / 3);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM / 3);
  noTone(BUZZER);
  digitalWrite(YELLOW, LOW);
  tone(BUZZER, A);
  digitalWrite(GREEN, HIGH);
  delay(BPM);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM);
  digitalWrite(YELLOW, LOW);
  tone(BUZZER, C);
  digitalWrite(BLUE, HIGH);
  delay(BPM);
  digitalWrite(BLUE, LOW);
  tone(BUZZER, B);
  digitalWrite(GREEN, HIGH);
  delay(BPM);
  digitalWrite(GREEN, LOW);
  noTone(BUZZER);
  delay(BPM);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM * 2 / 3);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM / 3);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  tone(BUZZER, A);
  digitalWrite(GREEN, HIGH);
  delay(BPM);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM);
  digitalWrite(YELLOW, LOW);
  tone(BUZZER, D);
  digitalWrite(RED, HIGH);
  delay(BPM);
  digitalWrite(RED, LOW);
  tone(BUZZER, C);
  digitalWrite(BLUE, HIGH);
  delay(BPM);
  digitalWrite(BLUE, LOW);
  noTone(BUZZER);
  delay(BPM);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM * 2 / 3);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  tone(BUZZER, G);
  digitalWrite(YELLOW, HIGH);
  delay(BPM / 3);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  tone(BUZZER, G1);
  digitalWrite(RED, HIGH);
  delay(BPM);
  digitalWrite(RED, LOW);
  tone(BUZZER, E);
  digitalWrite(BLUE, HIGH);
  delay(BPM);
  digitalWrite(BLUE, LOW);
  tone(BUZZER, C);
  digitalWrite(GREEN, HIGH);
  delay(BPM * 4 / 3);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, B);
  digitalWrite(YELLOW, HIGH);
  delay(BPM * 5 / 3);
  digitalWrite(YELLOW, LOW);
  tone(BUZZER, A);
  digitalWrite(YELLOW, HIGH);
  delay(2 * BPM);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  delay(2 * BPM);
  tone(BUZZER, F);
  digitalWrite(BLUE, HIGH);
  delay(BPM * 2 / 3);
  digitalWrite(BLUE, LOW);
  noTone(BUZZER);
  tone(BUZZER, F);
  digitalWrite(BLUE, HIGH);
  delay(BPM / 3);
  digitalWrite(BLUE, LOW);
  noTone(BUZZER);
  tone(BUZZER, E);
  digitalWrite(GREEN, HIGH);
  delay(BPM * 4 / 3);
  digitalWrite(GREEN, LOW);
  tone(BUZZER, C);
  digitalWrite(YELLOW, HIGH);
  delay(BPM * 4 / 3);
  digitalWrite(YELLOW, LOW);
  tone(BUZZER, D);
  digitalWrite(BLUE, HIGH);
  delay(BPM * 5 / 3);
  digitalWrite(BLUE, LOW);
  tone(BUZZER, C);
  digitalWrite(YELLOW, HIGH);
  delay(2 * BPM);
  digitalWrite(YELLOW, LOW);
  noTone(BUZZER);
  FlashLED();
  delay(2 * ONE_SEC);
  
}

void FlashLED(void) {
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  delay(2 * ONE_SEC);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
}
