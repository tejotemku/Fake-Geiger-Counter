#include <ESP32Servo.h>

// POTENTIOMETER config
#define POTENTIOMETER_PIN 15
#define POTENTIOMETER_MIN 0
#define POTENTIOMETER_MAX 4098

// DIODE config
#define DIODE_PIN 22
#define DIODE_MIN 0
#define DIODE_MAX 255

// SPEAKER config
#define SPEAKER_PIN 23

// SERVO confug
#define SERVO_DATA_PIN 18
#define SERVO_MIN_DEG 0
#define SERVO_MAX_DEG 180
Servo servo;


// GEIGER 
#define GEIGER_LOW_ACTIVITY 750
#define GEIGER_HIGH_ACTIVITY 50
int superRandomSeed = 36;


void setup() {
  Serial.begin(115200);

  // SERVO
  servo.attach(SERVO_DATA_PIN, 500, 2400);
  servo.write(SERVO_MIN_DEG);

  // POTENTIOMETER
  pinMode(POTENTIOMETER_PIN, INPUT);

  // DIODE
  pinMode(DIODE_PIN, OUTPUT); 

  // GEIGER
  randomSeed(superRandomSeed);
  pinMode(SPEAKER_PIN, OUTPUT);
  digitalWrite(SPEAKER_PIN, LOW);
  delay(1000);
}

void loop() {
  // reading potentioneter (sliding version)
  int potentiometer_value = analogRead(POTENTIOMETER_PIN);

  // remap value from potentiometer range to diode range & send
  int diode_intensity = map(potentiometer_value, POTENTIOMETER_MIN, POTENTIOMETER_MAX, DIODE_MIN, DIODE_MAX);
  analogWrite(DIODE_PIN, diode_intensity);

  // remap value from potentiometer range to servo range & send
  int servo_pos = map(potentiometer_value, POTENTIOMETER_MIN, POTENTIOMETER_MAX, SERVO_MIN_DEG, SERVO_MAX_DEG);
  servo.write(servo_pos);

  // remap value from potentiometer range to geiger activity range
  int geiger_strength = map(potentiometer_value, POTENTIOMETER_MIN, POTENTIOMETER_MAX, GEIGER_LOW_ACTIVITY, GEIGER_HIGH_ACTIVITY);

  // GEIGER
  // generate random noise sample & send
  int ranNumVol = random(diode_intensity);
  digitalWrite(SPEAKER_PIN, ranNumVol);
  // repeat quicker (high activity) for high potentiometer values
  int randNumber = random(geiger_strength);
  delay(randNumber);
  // quiet geiger "pop" sound
  digitalWrite(SPEAKER_PIN, LOW);

  // DEBUG GEIGER
  // Serial.print("Potentiometer value: ");
  // Serial.println(potentiometer_value);
  // Serial.print("Geiger strength value: ");
  // Serial.println(geiger_strength);
}
