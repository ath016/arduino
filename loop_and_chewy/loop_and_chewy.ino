int pwmPin = 11;

int stage1 = 30;
int speed1 = 100;

int stage2 = 29;
int speed2 = 200;

void setup() {
  // Serial monitor
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pwmPin, OUTPUT);
  //digitalWrite(pwmPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly
  //Serial.println(millis()/1000);
  
  if(millis()/1000 < stage1) {
    analogWrite(pwmPin, speed1);
    //Serial.println("stage 1");
  }
  else if(millis()/1000 < (stage1 + stage2)) {
    analogWrite(pwmPin, speed2);
    //Serial.println("stage 2");
  }
  else {
    analogWrite(pwmPin, 0);
    //Serial.println("stage 3");
  }//*/

  delay(1000);
}
