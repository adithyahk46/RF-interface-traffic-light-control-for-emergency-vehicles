#include <VirtualWire.h>
#define ledPin1 2
#define ledPin2 3
#define ledPin3 4
#define ledPin4 5

#define ledPin5 6
#define ledPin6 7
#define ledPin7 8
#define ledPin8 9

int value;

void setup()
{
    vw_set_rx_pin(12);
    vw_setup(2000);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);  
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin6, OUTPUT);
    pinMode(ledPin7, OUTPUT);
    pinMode(ledPin8, OUTPUT);

    
    vw_rx_start();
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
    
    if (vw_get_message(buf, &buflen))
    {       
      if(buf[0]=='a')
      {  
       digitalWrite(ledPin1,HIGH);
       digitalWrite(ledPin2,LOW); 
       digitalWrite(ledPin3,LOW);
       digitalWrite(ledPin4,LOW);

       digitalWrite(ledPin5,LOW);
       digitalWrite(ledPin7,LOW);
       digitalWrite(ledPin8,LOW);
       digitalWrite(ledPin6,LOW);  

      }  
      else if(buf[0]=='b')
      {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,LOW);
       digitalWrite(ledPin4,LOW);
       
       digitalWrite(ledPin5,LOW);
       digitalWrite(ledPin7,LOW);
       digitalWrite(ledPin8,LOW);
       digitalWrite(ledPin6,LOW); 

      }
      else if(buf[0]=='c')
      {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,LOW);

       digitalWrite(ledPin5,LOW);
       digitalWrite(ledPin7,LOW);
       digitalWrite(ledPin8,LOW);
       digitalWrite(ledPin6,LOW);       
      }
      else if(buf[0]=='d')
      {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,LOW);
       digitalWrite(ledPin4,HIGH);

       digitalWrite(ledPin5,LOW);
       digitalWrite(ledPin7,LOW);
       digitalWrite(ledPin8,LOW);
       digitalWrite(ledPin6,LOW);        
      }
      else{
       delay(2000);
       ledblink1();
       delay(2000);
       ledblink2();       
       delay(2000);
       ledblink3();
       delay(2000);
       ledblink4();  
                      
      }
    }
}

void ledblink1()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin7,LOW);
  digitalWrite(ledPin8,LOW);
  delay(1500);     
  digitalWrite(ledPin6,HIGH);
  
}
void ledblink2()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);

  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin8,LOW);
  delay(1500);     
  digitalWrite(ledPin7,HIGH);
}
void ledblink3()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,LOW);

  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,LOW);
  delay(1500);     
  digitalWrite(ledPin8,HIGH);
}
void ledblink4()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,HIGH);

  digitalWrite(ledPin8,LOW);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,LOW);
  delay(1500);     
  digitalWrite(ledPin5,HIGH);
}
