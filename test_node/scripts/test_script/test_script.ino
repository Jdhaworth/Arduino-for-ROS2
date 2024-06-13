String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  // reserve 2 bytes for the inputString:
  inputString.reserve(2);
  
  //Setup Serial Monitor
  Serial.begin (2400); //Set to your bot rate

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {
  //Collect button states  
  if(stringComplete){
    String val = inputString;
    //Char a
    if (val == "a"){
      //Do something
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      Serial.println("LED ON");
    }
    //Char b
    else if (val == "b"){
      //Do something
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);                       // wait for a second
      Serial.println("LED OFF");
    }else{
      Serial.println("Invalid Command");
    }

    //Clear the string
    stringComplete = false;
    inputString = "";
  }
}



/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }else{
      // add it to the inputString:
      inputString += inChar;
    }
  }
}
