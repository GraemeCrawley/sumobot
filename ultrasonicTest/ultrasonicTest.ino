#define trigPin 2// GREY
#define echoPin 3// PURPLE
#define trigPin2 4
#define echoPin2 5

//5 & 6 are free

// ULTRASONICS
// BACK:
// 6 Grey, 7 Purple

//Front Right:
// 2 Grey, 3 Purple


//Front Left:cd p
// 4 Grey, 5 Purple

//LEFT:
// 9 Grey, 8 Purple

//RIGHT:



int prevDist = 0;
int prevDist2 = 0;
int prevLeftAngle = 0;
int prevRightAngle = 0;
int prevFarAngle = 0;


void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  if(abs(prevDist - distance) > 1 & distance < 50){
    prevDist = distance;
  }

  if(abs(prevDist2 - distance2) > 1 & distance2 < 50){
    prevDist2 = distance2;
  }
  
  
  if(abs(prevDist2 - prevDist) > 5 & (prevDist2 > prevDist)){
    String two = "TWO: ";
    String stringTwo = two + prevDist2;
    //Serial.println((stringTwo));
  }
  else if((abs(prevDist2 - prevDist) > 5) & (prevDist > prevDist2)){
    String one = "ONE: ";
    String stringOne = one + prevDist;
    //Serial.println((stringOne));
    //Serial.println(prevDist);
    //Serial.println(prevDist2);
    Serial.println(prevDist^2 - ((prevDist2)^2));
    //Serial.println(2*4*prevDist);
    //float farAngle = (prevDist^2 - (prevDist2)^2 + 4^2)/(2*4*prevDist);
    //Serial.println(farAngle);
    
    
  }
  else {
    String both = "BOTH: ";
    String stringThree = both + (prevDist+prevDist2)/2;
    //Serial.println((stringThree));
  }
  
  //angles
  //Serial.println(prevDist^2 - (prevDist2)^2 + 4^2);
  //Serial.println(2*4*prevDist);
 
  //float farAngle = (prevDist^2 - (prevDist2)^2 + 4^2)/(2*4*prevDist);
  //float leftAngle = acos((2*sin(farAngle))/4);
  //float rightAngle = 180 - (leftAngle + farAngle);
  
   //if(abs(((prevLeftAngle) - (leftAngle)) > 1) or (abs((prevRightAngle) - (rightAngle)) > 1)){
     //Serial.println(farAngle);
     //Serial.println(rightAngle);
     //prevLeftAngle = leftAngle;
     //prevRightAngle = rightAngle;
  //}

   
  
}
