
const int TRIG_PIN = 5; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 4; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PINR  = 12; // Arduino pin connected to LED's pin Red
const int LED_PING  = 10; // Arduino pin connected to LED's pin Green
const int DISTANCE_LONG=100;
const int DISTANCE_SHORT=60;
 // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PINR, OUTPUT);  // set arduino pin to output mode
  pinMode(LED_PING, OUTPUT);  // set arduino pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

 if(distance_cm > DISTANCE_LONG){
    digitalWrite(LED_PING, HIGH); // turn on LED
  digitalWrite(LED_PINR, LOW);
  }
  
  else if(distance_cm < DISTANCE_SHORT){
   	digitalWrite(LED_PINR, HIGH);
  	digitalWrite(LED_PING, LOW);
  }
                 
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(5);
}