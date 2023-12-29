
#include <SoftwareSerial.h>


const byte rxPin = 2;

const byte txPin = 3;
char response [4];
int i;

// Set up a new SoftwareSerial object
char c;

SoftwareSerial mySerial (rxPin, txPin);
void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);
 mySerial.begin(9600);
 mySerial.println("H101");
 while (mySerial.available() > 0) {

      
         if(i>=4)
         i=0;
         c=(char)mySerial.read();
         
        response[i]=c;
        i++;
    }
  
}
//char nullstr[4]={'0\;

void loop() {
  // put your main code here, to run repeatedly:

delay(3000);

while (mySerial.available() > 0 ) {

         if(i>=4)
         i=0;
         c=(char)mySerial.read();
         
        response[i]=c;
        i++;
         
      
    }

if (strlen(response)>= 4){
 mySerial.println(response);}
 else {strcpy(response,"\0\0\0\0");
 mySerial.println("xuy");
  i=0;}
}
