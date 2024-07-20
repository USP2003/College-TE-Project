#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

const int pirPin = 2;
const int buzzerPin = 4;
const int gsmTx = 1; // Replace with your GSM module's Tx pin
const int gsmRx = 3; // Replace with your GSM module's Rx pin
const int lcd_address = 0x27; // Replace with your LCD I2C address

LiquidCrystal_I2C lcd(lcd_address, 16, 2); // 16 columns, 2 rows

SoftwareSerial gsm(gsmTx, gsmRx);

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  gsm.begin(9600); // Adjust baud rate if necessary

  lcd.init();
  lcd.backlight();

  // Replace with your actual GSM library initialization code
  // Example for SIM800L:
   gsm.println("AT+CPOWER=1"); // Power on the module
   delay(1000);
   gsm.println("AT+CSQ"); // Check network signal quality
   delay(1000);
}

void loop() {
  int pirValue = digitalRead(pirPin);

  if (pirValue == HIGH) {
    tone(buzzerPin, 1000); // Play a tone at 1 kHz
    delay(500); // Play the tone for half a second
    noTone(buzzerPin);

    lcd.clear();
    lcd.print("Animal Detected!");
    delay(2000); // Wait 5 seconds before sending message

    // Send SMS using GSM module (replace with your library functions)
    gsm.println("AT+CMGS=\"+8530370624\"\r"); // Replace with recipient's phone number
    delay(2000);
    gsm.println("Alert: Animal detected in your crop field!");
    delay(2000);
    gsm.println(char(26)); // CTRL+Z to send SMS
    delay(2000); // Wait 5 seconds before sending another message
  } else {
    lcd.clear();
    lcd.print("No motion detected");
  }

  delay(100); // Check sensor reading every 100 milliseconds
}
