int encoderL_PinA = 2;
int encoderL_PinB = 5;
int encoderR_PinA = 3;
int encoderR_PinB = 4;

volatile int ticksL=0;
volatile int ticksR=0; 

void setup()
{
  pinMode (encoderL_PinA,INPUT_PULLUP); 
  pinMode (encoderL_PinB,INPUT);
  pinMode (encoderR_PinA,INPUT_PULLUP);
  pinMode (encoderR_PinB,INPUT);

  Serial.begin (9600);
  
  attachInterrupt(0, CountL, FALLING);
  attachInterrupt(1, CountR, FALLING);
}

void loop()
{
  Serial.println(ticksL);  
  Serial.println(ticksR); 
  delay(10); 

}

void CountL()
{
  if(digitalRead(encoderL_PinB)==1){
    ticksL ++;
    if(ticksL==30000) ticksL==0;
  }
  else{
    ticksL --;
    if(ticksL==30000) ticksL==0;
  }
   
}
void CountR()
{
  if(digitalRead(encoderR_PinB)==1){
    ticksR --;
    if(ticksR==30000) ticksR=0;
  }
  else{
    ticksR ++;
    if(ticksR==30000) ticksR=0;
  }
   
}
