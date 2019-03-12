int motorL[]={3,2};
int motorR[]={5,4}; 
const int zpin = A1;                 
const int ypin = A2;                 
const int xpin = A3;              
const int powerpin = A4;             
const int groundpin = A5;
void setup()
{   
    Serial.begin(9600);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);  
    pinMode(5,OUTPUT);
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
  }  
void loop()
{             int x=analogRead(xpin); 
              int y=analogRead(ypin);
              int z=analogRead(zpin);            
              /*
              Serial.println("x");
              Serial.println(x);
              delay(2000);
              Serial.println("y");
              Serial.println(y);
              delay(2000);
              Serial.println("z");
              Serial.println(z);
              delay(2000);
              */
              if(335<x<35)
              {
              Serial.println("Moving Backward");
              bck();
              }
              else if(345<x<360)
              {
              Serial.println("Moving Forward");
              fwd(); 
              }
              else if(350<y<370)
              {
                if(360<z<370)
                {
                  Serial.println("Moving Right");
                  right();
                }
                else if(340<z<355)
                {
                  Serial.println("Moving Left");
                  left();
                }
                else
                {
                  Serial.println("reset sensor");
                }  
              }
              else if(340<x<350 && 340<y<350 && 415<z<425) 
              {
                Serial.println("Not moving");
                nomove();
              }
              else
              {
                Serial.println("reset sensor");
              }
}
void fwd()
{ 
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);
}         
void bck()
{ 
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}
  void left()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);

}
void right()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);

}
void nomove()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],LOW);
}
