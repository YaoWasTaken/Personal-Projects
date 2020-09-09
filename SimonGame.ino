// all LEDs and buttons
#define RED_LED 13
#define YELLOW_LED 12
#define BLUE_LED 11
#define GREEN_LED 10
#define WON_LED 9
#define LOST_LED 8
#define RED_BUTTON 7
#define YELLOW_BUTTON 6
#define BLUE_BUTTON 5
#define GREEN_BUTTON 4

// other symbolic constants and timing
#define ONE_SEC 1000

void setup()
{
  // LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WON_LED, OUTPUT);
  pinMode(LOST_LED, OUTPUT);
  
  // Buttons
  pinMode(RED_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  
}


void loop()
{
  int N = 1;
  int i;
  const int SEQUENCE_LENGTH = 5;
  int verification;
  int sequence[SEQUENCE_LENGTH];
  int enteredColors[SEQUENCE_LENGTH];
  generateSequence(SEQUENCE_LENGTH, sequence);
  newGame();
  
  // infinite loop
  // only thing that causes it to break if user entered wrong
  // or if N has reached the seqeunce length
  while (true) {
    displaySequence(sequence, N);
    for (i = 0; i < N; ++i) {
      enteredColors[i] = getUserInput();
    }
    verification = gameVerification(N, sequence, enteredColors);
    if (verification == 1) {
      if (N == SEQUENCE_LENGTH) {
        flashLED(WON_LED, 5);
        break;
      }
      else {
        ++N;
        delay(0.5 * ONE_SEC);
      }
    }
    else {
      flashLED(LOST_LED, 5);
      break;
    }
  }  
}

// User-Defined Functions
// generates a sequence of numbers from 10 to 13 representing LED
void generateSequence(int length, int data[]) {
  int i;
  
  randomSeed(analogRead(0));
  
  for (i = 0; i < length; ++i) {
    data[i] = (random() % 4) + 10;
  }
}

// gets user Input
int getUserInput(void) {
  int buttonState1;
  int buttonState2;
  int buttonState3;
  int buttonState4;
  int userInput;
  int color;
  
  while (true) {
    buttonState1 = digitalRead(RED_BUTTON);
    buttonState2 = digitalRead(YELLOW_BUTTON);
    buttonState3 = digitalRead(BLUE_BUTTON);
    buttonState4 = digitalRead(GREEN_BUTTON);
    
    if (buttonState1 == HIGH) {
      color = RED_LED;
      
      digitalWrite(RED_LED, HIGH);
      
      while(digitalRead(RED_BUTTON) == HIGH);
      
      digitalWrite(RED_LED, LOW);
      delay(10);
      break;
    }
    else if (buttonState2 == HIGH) {
      color = YELLOW_LED;
      
      digitalWrite(YELLOW_LED, HIGH);
      
      while(digitalRead(YELLOW_BUTTON) == HIGH);
      
      digitalWrite(YELLOW_LED, LOW);
      delay(10);
      break;
    }
    else if (buttonState3 == HIGH) {
      color = BLUE_LED;
      
      digitalWrite(BLUE_LED, HIGH);
      
      while(digitalRead(BLUE_BUTTON) == HIGH);
      
      digitalWrite(BLUE_LED, LOW);
      break;
    }
    else if (buttonState4 == HIGH) {
      color = GREEN_LED;
      
      digitalWrite(GREEN_LED, HIGH);
      
      while (digitalRead(GREEN_BUTTON) == HIGH);
      
      digitalWrite(GREEN_LED, LOW);
      delay(10);
      break;
    }
  }
  return color;
}

void flashLED(int LED, int numSeconds) {
  int i;
  for (i = 0; i < numSeconds; ++i) {
    digitalWrite(LED, HIGH);
    delay(0.5 * ONE_SEC);
    digitalWrite(LED, LOW);
    delay(0.5 * ONE_SEC);
  }
}

// verifies whether the user entered entries are equal to the sequence
int gameVerification(int count, int data[], int color[]) {
  int i;
  int result;
  
  for(i = 0; i < count; ++i) {
    if (color[i] == data[i]) {
      continue;
    }
    else {
      break;
    }
  }
  
  if (i == count) {
    result = 1;
  }
  else {
    result = 0;
  }
  
  return result;
}

// displays the sequence
void displaySequence(int data[], int count) {
  int i = 0;
  while (i < count) {
    if (data[i] == RED_LED) {
      flashLED(RED_LED, 1);
    }
    else if (data[i] == YELLOW_LED) {
      flashLED(YELLOW_LED, 1);
    }
    else if (data[i] == BLUE_LED) {
      flashLED(BLUE_LED, 1);
    }
    else {
      flashLED(GREEN_LED, 1);
    }
    ++i;
  }
}
// indicates new game start by turning on and off LEDs for two seconds
void newGame(void) {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  
  delay(2 * ONE_SEC);
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  
  delay(2 * ONE_SEC);
}
