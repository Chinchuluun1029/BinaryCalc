/*
 * 4-Bit Binary Calculator:
 * A simple, resource-minimal 4-bit binary to decimal
 * translator. The 4 bit input is toggled by pushbuttons 
 * and results are printed on a 16x2 LCD screen. 
 * 
 * 
 * Requirements:
 * - 26x Male-to-Male jumper wires
 * - 4x 220 Ohm resistors
 * - 4x Pushbutton
 * - 1x Arduino Uno R3
 * - 1x Arduino ProtoShield
 * - (Optional) 1x 170 tie-point breadboard
 * - 1x 16x2 LCD Screen
 * 
 * 
 * By: Chuka Munkh-Achit (Jan 2019)
 */


/*
  LiquidCrystal Library Description

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 */

#include <LiquidCrystal.h>

const int  buttonPin = 2;   
const int  buttonPin2 = 3;    
const int  buttonPin3 = 4;    
const int  buttonPin4 = 5;    


/*
 * buttonPushCounters - Counting how many times each button was pushed
 * buttonStates - Current state of button (1 or 0)
 * lastButtonStates - Last state of button (1 or 0)
 * binaryPrints - Binary number later translated to decimals
 * 
 */
int buttonPushCounter = 0, buttonState = 0, lastButtonState = 0, binaryPrint = 0;
int buttonPushCounter2 = 0, buttonState2 = 0, lastButtonState2 = 0, binaryPrint2 = 0;
int buttonPushCounter3 = 0, buttonState3 = 0, lastButtonState3 = 0, binaryPrint3 = 0;
int buttonPushCounter4 = 0, buttonState4 = 0, lastButtonState4 = 0, binaryPrint4 = 0;
int decimal = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BINARYCALCULATOR");
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  //Placeholders for 2 digit decimals from binary input
  int decimalDigitTwo;
  int decimalDigitOne;

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter2++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

  if (buttonState3 != lastButtonState3) {
    // if the state has changed, increment the counter
    if (buttonState3 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter3++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }

  if (buttonState4 != lastButtonState4) {
    // if the state has changed, increment the counter
    if (buttonState4 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter4++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;


  if (buttonPushCounter % 2 == 0) {
    binaryPrint = 1;
  } else {
    binaryPrint = 0;
  }

  if (buttonPushCounter2 % 2 == 0) {
    binaryPrint2 = 1;
  } else {
    binaryPrint2 = 0;
  }

  if (buttonPushCounter3 % 2 == 0) {
    binaryPrint3 = 1;
  } else {
    binaryPrint3 = 0;
  }

  if (buttonPushCounter4 % 2 == 0) {
    binaryPrint4 = 1;
  } else {
    binaryPrint4 = 0;
  }

  decimal = (binaryPrint * 8) + (binaryPrint2 * 4) + (binaryPrint3 * 2) + (binaryPrint4 * 1);
  decimalDigitTwo = decimal / 10;
  decimalDigitOne = decimal % 10;

  //Printing calculation on screen
  lcd.print(binaryPrint);
  lcd.print(binaryPrint2);
  lcd.print(binaryPrint3);  
  lcd.print(binaryPrint4);

  lcd.print(" = "); 
  
  lcd.print(decimalDigitTwo);
  lcd.print(decimalDigitOne);
  
  lcd.setCursor(0, 1);
  
}
