const int RledPin = 9;       
const int GledPin = 10;      
const int BledPin = 11;      
const int buttonPin = 2;     


int buttonState = 0;         
int ledcolor = 0;       
bool ButtonPressed = false;   
String currentcolor = "led"; 

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  Serial.print("Current Color: ");
  Serial.println(currentcolor);
  
  if (buttonState == HIGH && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  
  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }
  
  if (ledcolor == 0) {
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH); 
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
    // 紅色 
    currentcolor = "Red";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2) {
    // 綠色 
    currentcolor = "Green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3) {
    // 藍色
    currentcolor = "Blue";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 4) {
    // 黃色 (YELLOW)
    currentcolor = "Yellow";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5) {
    // 紫色
    currentcolor = "Purple";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6) {
    // 青色 
    currentcolor = "Cyan";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 7) {
    // 白色
    currentcolor = "White";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 8) {
    // 計數器歸零
    ledcolor = 0;
  }
  delay (100);
}