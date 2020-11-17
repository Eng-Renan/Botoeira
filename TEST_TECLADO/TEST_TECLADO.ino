#include <Keyboard.h>

int led=13;
int est=0;
int pin=0;
int tecla=0;
int meusPinos[] = {2,4,5,6,7,8,9,10,11,12};
char minhasTeclas[]= {'0','1','2','3','4','5','6','7','8','9'};
int taly[]={0,14,15,16,17,17,17,17,17,17};
void setup()
{
 for (int i = 1; i <10; i++) {
     pinMode(meusPinos[i], INPUT);
  } 
  Keyboard.begin();
  pinMode(led, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  
}

void loop()
{
   est=digitalRead(meusPinos[0]);
   digitalWrite(led,est);  
   digitalWrite(A0,HIGH); digitalWrite(A1,HIGH); digitalWrite(A2,HIGH); digitalWrite(A3,HIGH);  
   delay(10000);
   digitalWrite(A0,LOW); digitalWrite(A1,LOW); digitalWrite(A2,LOW); digitalWrite(A3,LOW);
   delay(10000);
   digitalWrite(A0,HIGH); digitalWrite(A1,HIGH); digitalWrite(A2,HIGH); digitalWrite(A3,HIGH);
    if(est==1){
         for (int i = 1; i <10; i++) {    
          pin=digitalRead(meusPinos[i]);
          //digitalWrite(taly[i],1-pin);
          if(pin==0 && tecla!=meusPinos[i]){ 
              Keyboard.press(KEY_LEFT_ALT);                
              Keyboard.press(minhasTeclas[i]);                
              Keyboard.release(KEY_LEFT_ALT);        
              Keyboard.release(minhasTeclas[i]);  
              tecla=meusPinos[i];              
              delay(100);                             
              break;
          }
          delay(10); 
      }       
    }  
  }
