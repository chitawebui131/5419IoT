
const int photocellPin = A0;  
const int yellowLedPin = 5;   // Yellow LED connected to Digital 5
// Range is 0 (pitch black) to 1023 (blindingly bright)

const int darknessThreshold = 400; 
void setup() {   // Initialize the hardware pins
  pinMode(yellowLedPin, OUTPUT); // Start serial communication to monitor the light levels
  Serial.begin(9600); 
}
void loop() {   // Read the raw analog value from the photocell
  int lightLevel = analogRead(photocellPin);   
  Serial.print("Current Light Level: ");
  Serial.println(lightLevel);   // Check if it is dark enough to turn on the LED
  if (lightLevel < darknessThreshold) {
    digitalWrite(yellowLedPin, HIGH); // Turn yellow LED ON
  } else {
    digitalWrite(yellowLedPin, LOW);  // Turn yellow LED OFF
  }
  
  delay(100); 
}
