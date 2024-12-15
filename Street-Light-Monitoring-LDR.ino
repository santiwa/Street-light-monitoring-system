/*
Name: Tiwari Ramesh Sanjana
Date: 23-3-2024
Title: Street Light Monitoring Based on LDR Sensor
Description: Based on the resistance value of LDR sensor
(Light Dependent Resistor), an LED is controlled.
If light intensity increases, resistance increases, current decreases.
Thus, if resistance value falls below certain range, then LED is turned on,
to mirror the action of street lamp turning on during sunset.
*/

//Input and output sensor and pin declaration
int ldrPin = A0;
int ledPin = LED_BUILTIN;
int ldrValue = 0;

void setup() {
  //Configure serial communication
  Serial.begin(9600);

  //Configure pins
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin); // Read ldr sensor value
  Serial.println(ldrValue); // Print it on serial monitor

  // Control LED
  if(ldrValue < 150) { // Turn LED on if light intensity < 150
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
  } else { // Else, ample sunlight is presesnt, turn LED off 
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }

  delay(200); // Short delay to read better values
}
