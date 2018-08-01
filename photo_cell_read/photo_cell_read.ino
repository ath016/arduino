// use to manage digital output ie. led
class Flasher {
  int ledPin;
  int state;

public:
  // input the pin the digital output is connected to
  Flasher(int pin) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
  } // end of ctor

  // turn on the digital output
  void on() {
    state = HIGH;
    digitalWrite(ledPin, state);
  } // end of on

  // turn off the digital output
  void off() {
    state = LOW;
    digitalWrite(ledPin, state);
  } // end of off

  // switch the digitial output
  void turn() {
    state = state == HIGH ? LOW : HIGH;
    digitalWrite(ledPin, state);
  } // end of switch
}; // end of class flasher


// use to read in sensor value
class AnalogRead {
  int analogPin;
  int analogData;
  
public:
  // input pin that is connected to sensor
  AnalogRead(int pin) {
    analogPin = pin;
  } // end of ctor

  // return sensor value range from 0 to 1023
  int val() {return analogData = analogRead(analogPin);} // end of set data
}; // end of class analog read


/* ************************************************************************** */


// construct objects
Flasher laser(13);
AnalogRead photocell(0);

// set trigger
bool trigger = false;
int threshold = 1000;


/* ************************************************************************** */


void setup(void) {
  // Serial monitor
  Serial.begin(9600);

  // flip the laser off
  laser.off();
} // end of setup


/* ************************************************************************** */


void loop(void) {
  // check trigger
  trigger = photocell.val() > threshold? true: false;

  // set led
  if (trigger)
    laser.on();
  else
    laser.off();

  // print out to serial monitor
  //Serial.println(photocell.val());
  //Serial.println(trigger);
} // end of loop






