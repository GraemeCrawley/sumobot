#define trigPin 4// GREY
#define echoPin 5// PURPLE
//#define trigPin2 5
//#define echoPin2 4
//5 & 6 are free

// ULTRASONICS
// BACK:
// 6 Grey, 7 Purple

//Front Right:
// 2 Grey, 3 Purple


//Front Left:
// 2 Grey, 3 Purple

//LEFT:
// 9 Grey, 8 Purple

//RIGHT:



int prevDist = 0;
//int prevDist2 = 0;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//  pinMode(trigPin2, OUTPUT);
//  pinMode(echoPin2, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  
//  long duration2, distance2;
//  digitalWrite(trigPin2, LOW);  
//  delayMicroseconds(2); 
//  digitalWrite(trigPin2, HIGH);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if(abs(prevDist - distance) > 1 & distance < 50){
    Serial.println(("FRONT RIGHT", distance));
    prevDist = distance;
  }
//  digitalWrite(trigPin2, LOW);
//  duration2 = pulseIn(echoPin2, HIGH);
//  distance2 = (duration2/2) / 29.1;
//  if(abs(prevDist2 - distance2) > 1 & distance2 < 50){
//    Serial.println(("TWO:", distance2));
//    prevDist2 = distance2;
//  }
  
}
