//configurations variables
#define LOOP_COUNT 200
#define CYCLE_TIME_MILLIS 100

// Define pins for ultrasonic sensor
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin
const int outputLed = 5;
const int startButton = 6;

// function protorype
double calcDistance();


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Define pin modes for the ultrasonic sensor
  pinMode(trigPin, OUTPUT); // Trigger pin as output
  pinMode(echoPin, INPUT);  // Echo pin as input
  pinMode(outputLed, OUTPUT);
  pinMode(startButton, INPUT);


  // sending comfiguration data to python
  // sending value of LOOP_COUNT
  digitalWrite(outputLed, HIGH);
  Serial.print("s ");

  // sending value of CYCLE_TIME_MILLIS
  Serial.println(LOOP_COUNT);
  Serial.print("t ");
  Serial.println(CYCLE_TIME_MILLIS);
  delay(1000);
}

int state = 1; // state is used to make the code runs only once

void loop() {
  if(state){ // checks if we on the first excutes

  // sending data for calibraion
  Serial.print("c ");
  Serial.println(calcDistance());

  // if button is clicked it will start sending data for recording
  if(digitalRead(startButton)){
    delay(1000);
    for(int i = 0; i< LOOP_COUNT;i++){
    
      // Print the distance to the serial monitor
      Serial.print("r ");
      Serial.println(calcDistance());
      digitalWrite(outputLed, HIGH);
      delay(CYCLE_TIME_MILLIS / 2);
      // Wait for a short while before next measurement
      
      digitalWrite(outputLed, LOW);
      delay(CYCLE_TIME_MILLIS / 2);
    }
    
    state = 0; // end the excution of the program
    }
  }
}

//function define
double calcDistance(){
  // Clear the trigger pin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
    
      // Set the trigger pin HIGH for 10 microseconds to send a pulse
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
    
      // Read the echo pin, and calculate the duration the signal took to return
      long duration = pulseIn(echoPin, HIGH);
    
      // Calculate the distance in centimeters
      // Speed of sound is 343 m/s or 34300 cm/s
      // Distance = (duration * speed of sound) / 2, because the signal goes and returns
      double distanceCm = duration * 0.034 / 2;
      return distanceCm;
}
