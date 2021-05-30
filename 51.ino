// C++ code
//

  #define echo 2
  #define trig 3
  #define vibr 13

float duration;
float distance;

void setup()
{
  	pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
  	pinMode(vibr, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  	time_Measurement();
    distance = duration * (0.0343) / 2;   
    display_distance();
}

void time_Measurement(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
  
    duration = pulseIn(echo, HIGH);
  }

void display_distance(){
	Serial.print("Distance in Cm: ");
    Serial.println(distance);
  
  if(distance<100.00){
  	digitalWrite(vibr, HIGH);
  }
  else{
  	digitalWrite(vibr, LOW);
  }
  
}