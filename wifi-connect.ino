#include <SoftwareSerial.h>

SoftwareSerial wifiserial(2, 3); // RX | TX

void setup() {

  Serial.begin(115200); // communication with the host computer

  //while (!Serial) { ; }

  // Start the software serial for communication with the ESP8266

  wifiserial.begin(115200);

    Serial.println("");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("Ready");
    Serial.println("");

    wifiserial.println("AT+CWMODE=1"); // connect to wifi
    delay(100);
    wifiserial.println("AT+CWLAP"); // list all available wifis
    delay(300);
    wifiserial.println("AT+CWJAP=\"SSID\",\"PASSWORD\""); //login on wifi
    delay(300);
    wifiserial.println("AT+CIFSR"); //display IP

    Serial.println("Connected");

    
    

}

void loop() {

  // listen for communication from the ESP8266 and then write it to the serial monitor

  if ( wifiserial.available() ) { 
    Serial.write( wifiserial.read() ); 
  }

  // listen for user input and send it to the ESP8266

  if ( Serial.available() ) { 
    wifiserial.write( Serial.read() ); 
  }

}
