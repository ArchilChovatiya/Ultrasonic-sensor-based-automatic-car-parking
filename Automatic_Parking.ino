
const int trigPin = A0;
const int echoPin = A1;

const int FaceIR = 10;
const int BackIR = 11;

const int BackR1 = 2;
const int BackR2 = 3;

const int BackL1 = 4;
const int BackL2 = 5;

const int FaceR1 = 6;
const int FaceR2 = 7;

const int FaceL1 = 8;
const int FaceL2 = 9;

long duration;
int distance;

int ReadFaceIR;
int ReadBackIR;


int i=0;
int j=0;

void setup() 
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input

    pinMode(FaceIR, INPUT); // Sets the trigPin as an Output
    pinMode(BackIR, INPUT); // Sets the echoPin as an Input
    

    
    pinMode(BackR1, OUTPUT); // Sets the trigPin as an Output
    pinMode(BackR2, OUTPUT); // Sets the echoPin as an Input
    
    pinMode(BackL1, OUTPUT); // Sets the trigPin as an Output
    pinMode(BackL2, OUTPUT); // Sets the echoPin as an Input
    
    pinMode(FaceR1, OUTPUT); // Sets the trigPin as an Output
    pinMode(FaceR2, OUTPUT); // Sets the echoPin as an Input
    
    pinMode(FaceL1, OUTPUT); // Sets the trigPin as an Output
    pinMode(FaceL2, OUTPUT); // Sets the echoPin as an Input
    
    pinMode(13, OUTPUT);
    digitalWrite(FaceIR,LOW);
    digitalWrite(BackIR,LOW);

    Serial.begin(9600); // Starts the serial communication
}



void loop() 
{
     ReadFaceIR = digitalRead(FaceIR);
     ReadBackIR = digitalRead(BackIR);
     
      digitalWrite(trigPin, LOW);
      
      delay(2);
      
      digitalWrite(trigPin, HIGH);
     
      delay(2);
      digitalWrite(trigPin, LOW);
      
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
     
      // Calculating the distance
      distance= duration*0.034/2;
      

      delay(100);
      
      Serial.print("Distance: ");
      
      Serial.println(distance);
     
      
  if(distance > 2000){  }
      else if(((distance <= 10) || (distance < 30)))
      {
        digitalWrite(BackR1, HIGH); 
        digitalWrite(BackR2, LOW);
        digitalWrite(BackL1, HIGH); 
        digitalWrite(BackL2, LOW);
        digitalWrite(FaceR1, HIGH); 
        digitalWrite(FaceR2, LOW);
        digitalWrite(FaceL1, HIGH); 
        digitalWrite(FaceL2, LOW);
        
        if(ReadFaceIR == LOW)
        {
          Stop();
        }
        if((ReadFaceIR == HIGH) && (ReadFaceIR == HIGH))
        {
        i=0; 
        }
      }
      
      else if(((distance > 10) && (distance >= 30)) )
      {
        counter();
        digitalWrite(BackR1, HIGH); 
        digitalWrite(BackR2, LOW);
        digitalWrite(BackL1, HIGH); 
        digitalWrite(BackL2, LOW);
        digitalWrite(FaceR1, HIGH); 
        digitalWrite(FaceR2, LOW);
        digitalWrite(FaceL1, HIGH); 
        digitalWrite(FaceL2, LOW);
        if((ReadFaceIR == LOW) || (ReadBackIR == LOW))
        {
          Stop();
        }
         
        if(i>=20)
        {
            

            Stop();
            delay(750);
            LeftF_RightR();
            delay(750);
            Rev();
            delay(750);
            LeftF_RightR();
            delay(750);
            Rev();
            delay(750);
            RightF_LeftR();
            delay(750);
            Rev();
            delay(700);
            RightF_LeftR();
            delay(750);
            Rev();
            delay(750);
            while(1)
            {
                Stop();
            }
      
        }
      }
      
      
       
}
void Stop()
{
            digitalWrite(BackR1, LOW); 
            digitalWrite(BackR2, LOW);
            digitalWrite(BackL1, LOW);
            digitalWrite(BackL2, LOW);
            digitalWrite(FaceR1, LOW); 
            digitalWrite(FaceR2, LOW);
            digitalWrite(FaceL1, LOW); 
            digitalWrite(FaceL2, LOW);
}
void LeftF_RightR()
{
           if( ReadBackIR == HIGH)
            {
             
            digitalWrite(BackR1, LOW); 
            digitalWrite(BackR2, HIGH);
            digitalWrite(BackL1, HIGH);
            digitalWrite(BackL2, LOW);
            digitalWrite(FaceR1, LOW); 
            digitalWrite(FaceR2, HIGH);
            digitalWrite(FaceL1, HIGH); 
            digitalWrite(FaceL2, LOW);
              digitalWrite(13,HIGH);
             while ( ReadBackIR == LOW)
            {
              digitalWrite(13,LOW);
              Stop();
            }
              
            }
            
            
            
            
            
}


void Rev()
{
            while( ReadBackIR != HIGH)
            {
              Stop();
            }
            
            
            digitalWrite(BackR1, LOW); 
            digitalWrite(BackR2, HIGH);
            digitalWrite(BackL1, LOW);
            digitalWrite(BackL2, HIGH);
            digitalWrite(FaceR1, LOW); 
            digitalWrite(FaceR2, HIGH);
            digitalWrite(FaceL1, LOW); 
            digitalWrite(FaceL2, HIGH);
            
            
}

void RightF_LeftR()
{
            while( ReadBackIR != HIGH)
            {
              Stop();
            }
            
            digitalWrite(BackR1, HIGH); 
            digitalWrite(BackR2, LOW);
            digitalWrite(BackL1, LOW);
            digitalWrite(BackL2, HIGH);
            digitalWrite(FaceR1, HIGH); 
            digitalWrite(FaceR2, LOW);
            digitalWrite(FaceL1, LOW); 
            digitalWrite(FaceL2, HIGH);
            
            
}
void counter()
{
    delay(250);
    if((ReadFaceIR == HIGH) && (ReadFaceIR == HIGH))
    i++;
    Serial.println(i);
}





