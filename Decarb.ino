/*

ignITE Challenge 2023
Decarbonisation at Home
Programme Written by Freddy Tay

/*
Change variable here
*/

//////////////////////////////////////////////////////////////////////

int dist = 16; // in cm
int delayt = 5; //in seconds
int LEDPin = 11; // enter PIN number that controls the LED

////////////////////////////////////////////////////////////////////// 

// defines pins numbers
const int trigPin = 4;
const int echoPin = 3;

// defines variables
long duration;
int distance;

void setup() {
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LEDPin, OUTPUT); // Sets the LEDPin as an Output
  Serial.begin(9600); // Starts the serial communication

  pinMode(9, OUTPUT); // Initialise communication with solenoid valve
  
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance > dist) {
  digitalWrite(9, HIGH);
  digitalWrite(LEDPin, HIGH);
  }
  else {
  digitalWrite(9, LOW);
  digitalWrite(LEDPin, LOW);
  delay(delayt * 1000);
  }
  
}
