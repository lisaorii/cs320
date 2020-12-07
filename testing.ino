
/*  Wellesley College CS320 Tangible User Interface
 *  Authors: Lisa Orii, Jessica Flores, Valeria Yang, Anaina Malik
 *  Date: December 7, 2020
 *
--------Use This Sketch To------------------------------------------
1) Displays user's live and changing BPM, Beats Per Minute, in Arduino's native Serial Monitor.
2) Change the Neopixel colors to correspond to the BPM.
--------------------------------------------------------------------*/

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math
#define LED_PIN    6                    // Pin on the Flora connected to the Neopixels
#define LED_COUNT 3                   // Number of NeoPixels are attached to the Flora
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library 
#include <Adafruit_NeoPixel.h>      //Includes the Adafruit_NeoPixel Library

//  Variables
const int PulseWire = 10;       // PulseSensor PURPLE WIRE connected to PIN 10 on Florath
const int age = 20;            //Initialize age for maxBPM calculation. Default set to 20.
const int maxBPM = 220 - age;  //Calculate maxBPM by subtracting age from 220
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {   
  
  Serial.begin(9600);          // For Serial Monitor
  
  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal.  
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}



void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 

 if (myBPM > maxBPM) { //very high BPM
  colorWipe(strip.Color(255,   255,   255), 100); // White 
 }
 
 else if (140 <= myBPM  && myBPM <= maxBPM) { //high BPM
  colorWipe(strip.Color(0,   0,   255), 100); // Blue has the effect to calm people down
 }
 
 else if (80 <= myBPM && myBPM  < 140) { //regular BPM
  colorWipe(strip.Color(0,   255,   0), 100); // Green for regular BPM
 }
 
 else { //low BPM
  colorWipe(strip.Color(255,   0,   0), 100); // Red has the effect to excite people 
 }
 
}

  delay(20);    // considered best practice in a simple sketch.

}

/*
 * Assings and displays a designated color for each NeoPixel.
*/
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Send updated pixel colors to the hardware
    delay(wait);                           //  Pause for a moment
  }
}
