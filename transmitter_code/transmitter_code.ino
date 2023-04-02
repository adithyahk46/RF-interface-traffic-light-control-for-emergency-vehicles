//TRANSMITTER CODE FOR GREEN LIGHT



#include <VirtualWire.h>

#define button1 2
#define button2 3
#define button3 4
#define button4 5

char *data;
int val1;
int val2;
int val3;
int val4;

void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
}

void loop()
{
  val1 = digitalRead(button1);
  val2 = digitalRead(button2);
  val3 = digitalRead(button3);
  val4 = digitalRead(button4);
  if(val1 == 0 && val2==1 && val3 == 1 && val4 ==1)
  {
    data="a";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else if(val1 ==1 && val2 == 0 && val3 ==1 && val4 == 1)
  {
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }

  else if(val1 ==1 && val2 == 1 && val3 ==0 && val4 == 1)
  {
    data="c";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else if(val1 ==1 && val2 == 1 && val3 ==1 && val4 == 0)
  {
    data="d";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  } 
  
}