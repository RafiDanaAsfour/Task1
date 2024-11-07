#define trigPin 11
#define echoPin 10
// LED pins
#define green 2
#define yellow 4
#define red 7

// Joystick pin
#define joystick A4 // استخدم الـ potentiometer للضبط

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Ensure the Trigger pin is LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Allow time for stabilization
  
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration
  long duration = pulseIn(echoPin, HIGH); // Measure the time of the echo pulse
  int distance = duration / 29.1; // Convert to cm
  distance = distance / 2; // Divide by 2 to get the actual distance

  // Print the distance in centimeters
  Serial.print(distance);
  Serial.println(" cm");

  // Read potentiometer value for adjusting thresholds
  int potentiometerValue = analogRead(joystick); // Read the potentiometer value

  // Map potentiometer value to dynamic thresholds
  int minThreshold = map(potentiometerValue, 0, 1023, 5, 30); // النطاق الأدنى
  int midThreshold = minThreshold +10; // النطاق الأوسط

  // Control LEDs based on distance and dynamic thresholds
  if (distance < minThreshold) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    printf("reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeed");
  } else if (distance >= minThreshold && distance < midThreshold) {
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    printf("ylllllllllllllllllllllllllll");
  } else {
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH); // يضيء الأخضر إذا كانت المسافة أكبر من أو تساوي midThreshold
    printf("greeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
  }

 
  Serial.print("Min Threshold: ");
  Serial.print(minThreshold);
  Serial.print(" cm | Mid Threshold: ");
  Serial.println(midThreshold);
  Serial.print(" cm | Distance: ");
  Serial.println(distance);


}
