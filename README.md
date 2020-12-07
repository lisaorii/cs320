# Heart Beatz

This is a repository that contains code that was used for the project in CS320 Tangible User Interfaces (Fall 2020).

The code 'testing.ino' is an Arduino code (C++) that is compatible with Adafruit Flora. 
The code is intended to 1) sense the pulse of the user (BPM) via the pulse sensor and 2) change the Neopixel colors to correspond to the BPM range.

The pulse sensor is attached to a wrist wearable. When the wearable is worn, the pulse sensor touches the underside of the user's wrist to monitor the BPM. The BPM values can be displayed on the Serial Monitor.
Simulataneously, the color of the Neopixels change depending on BPM values. Currently, the age of the user is set to 20 which also affects the maximum BPM. Please change the value of the variable 'age' to correspond to your age. The colors of the Neopixels are intended to help the user regulate their mood and their BPM so that it is within the 'normal' range. However, since BPM means something different for each person and their body, we intentionally did not tell the user that their BPM is too high/low. Instead, the interpretation of BPM via colors is subjective. 

To execute the code to the Flora, attach the Flora to the computer and upload the code. Open the Serial Monitor to observe the BPM values.
