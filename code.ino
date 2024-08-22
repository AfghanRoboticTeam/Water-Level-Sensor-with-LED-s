int sensorPin = A0;    // Analog pin where the sensor is connected
int ledLow = 7;        // Pin for low level LED
int ledMed = 8;        // Pin for medium level LED
int ledHigh = 9;       // Pin for high level LED

void setup() {
  pinMode(ledLow, OUTPUT);
  pinMode(ledMed, OUTPUT);
  pinMode(ledHigh, OUTPUT);
  Serial.begin(9600);   // Start the serial communication
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the value from the sensor
  Serial.println(sensorValue);              // Print the sensor value to the Serial Monitor
  
  // Define thresholds for the water levels
  int lowThreshold = 300;
  int medThreshold = 600;
  
  // Low Level
  if(sensorValue < lowThreshold) {
    digitalWrite(ledLow, HIGH);
    digitalWrite(ledMed, LOW);
    digitalWrite(ledHigh, LOW);
  }
  // Medium Level
  else if(sensorValue >= lowThreshold && sensorValue < medThreshold) {
    digitalWrite(ledLow, LOW);
    digitalWrite(ledMed, HIGH);
    digitalWrite(ledHigh, LOW);
  }
  // High Level
  else {
    digitalWrite(ledLow, LOW);
    digitalWrite(ledMed, LOW);
    digitalWrite(ledHigh, HIGH);
  }
  
  delay(500);  // Delay for half a second before the next reading
}
