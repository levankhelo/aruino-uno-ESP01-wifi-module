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
    wifiserial.println("AT+CWJAP=\"SSID\",\"Password\""); //login on wifi
    delay(300);
    wifiserial.println("AT+CIFSR"); //display IP

    Serial.println("Connected");

    
    

}

void Send( String str ) {
    Serial.println( "Sending: " + str ); 
    wifiserial.println( "Sending: " + str ); 
}

String data = "";
void Capture( char c ) {
    data += c;
    if( c == '\n' ) {
        Send( data );
        data = "";
    }
}

void loop() {

  // listen for communication from the ESP8266 and then write it to the serial monitor

  if ( wifiserial.available() ) { 
    char c = wifiserial.read();
    Capture( c );
    // Serial.write( c ); 
  }

  // listen for user input and send it to the ESP8266

  if ( Serial.available() ) { 
    char c = Serial.read();
    Capture( c );
    // wifiserial.write( c ); 
  }

  

}
