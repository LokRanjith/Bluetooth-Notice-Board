#include <LiquidCrystal.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);

  // Print a message to the LCD
  lcd.print("Send text via BT");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Clear the LCD screen
    lcd.clear();

    // Read the incoming data
    String incomingData = Serial.readString();

    // Set the cursor to the beginning of the first row
    lcd.setCursor(0, 0);

    // Print the incoming data to the LCD
    lcd.print(incomingData);

    // If the text is longer than 16 characters, display the second part on the second row
    if (incomingData.length() > 16) {
      // Set the cursor to the beginning of the second row
      lcd.setCursor(0, 1);

      // Print the remaining part of the incoming data
      lcd.print(incomingData.substring(16));
    }
  }
}
