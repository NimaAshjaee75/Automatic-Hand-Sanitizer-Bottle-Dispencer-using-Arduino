// Nima Ashjaee Arduino Project
// ID: 40028793


// defining the pin numbers: 
const int servo = 9;
const int trigPin = 10;
const int echoPin = 11;

// defining variables:
int dist;
long dur;

#include <Servo.h>

Servo servomotor;  // the servo function controls the servo motor

int servoposition = 0;  //set a variable to store the position of servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Setting the trigPin as the Output
  pinMode(echoPin, INPUT); // Setting the echoPin as the Input
  servomotor.attach(servo);  // Sets the servo's pin 9 to the servo function  
  servomotor.write(0);   // Initialize the servo position to 0 degree
  Serial.begin(9600);
}

void loop() {
  
    // Setting the trigPin on LOW for 2 micro seconds:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Setting the trigPin on HIGH for 10 micro seconds and then back to LOW:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Finds how long it takes for the sound wave to travel (in micro-seconds)
    dur = pulseIn(echoPin, HIGH);
    
    // Calculates the distance
    dist= dur*0.034/2;
    
    // This section was made for testing the distance, using the serial monitor feature: 
    Serial.print("Distance: ");
    Serial.println(dist);

    if(dist<10){ //When the distance is less than 10cm:
       servomotor.write(50);
       delay(100);
       servomotor.write(90);
       delay(100);
       servomotor.write(135);
       delay(100);
       servomotor.write(180); //I found the best result and power from the motor with 180 degrees
       delay(1000); //Delay the servo motor for 1s at the 180 position, the maximize the force on the soap dispenser
       servomotor.write(0); // Reset the servo motor back to 0 Degrees
       delay(3000);   //Delay 3s for the next round
    }                 
}
