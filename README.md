# Smart Crop Protection System
**Overview**
Farmers often face challenges in protecting their crops from animals. The Smart Crop Protection System aims to mitigate this issue by using an ESP32-based system. This system detects animals with a motion sensor, scares them away with an alarm, and sends SMS alerts to the farmer for additional action.

**Features**
Motion Detection: Detects the presence of animals using a motion sensor.
Alarm Activation: Activates an alarm to scare away the animals.
SMS Alerts: Sends an SMS alert to the farmer for additional action.
**Components**
ESP32
PIR Motion Sensor
Buzzer or Alarm
SIM800L GSM Module
Power Supply
Connecting Wires
Breadboard (optional for prototyping)

**Installation and Setup**
--Hardware Setup--
1.Connect the PIR Motion Sensor:
VCC to 3.3V on the ESP32
GND to GND on the ESP32
OUT to a digital input pin on the ESP32 (e.g., GPIO 13)

2.Connect the Buzzer/Alarm:
Positive pin to a PWM-capable digital output pin on the ESP32 (e.g., GPIO 12)
Negative pin to GND

3.Connect the SIM800L GSM Module:
VCC to an appropriate power supply (e.g., 4.2V)
GND to GND on the ESP32
RXD to TXD on the ESP32 (e.g., GPIO 17)
TXD to RXD on the ESP32 (e.g., GPIO 16)

**Software Setup**
git clone https://github.com/USP2003/College-TE-Project.git

cd College-TE-Project


Install Dependencies
Ensure you have the necessary libraries installed in your Arduino IDE:

ESP32 board support
SoftwareSerial library
Adafruit_Sensor library
Upload the Code

Open the smart_crop_protection.ino file in the Arduino IDE, configure the necessary parameters (such as GSM module settings and phone number for SMS alerts), and upload the code to your ESP32.

**Usage**
Power up the system.
The motion sensor will start detecting the presence of animals.
Upon detection, the alarm will sound to scare away the animal.
An SMS alert will be sent to the configured phone number.
