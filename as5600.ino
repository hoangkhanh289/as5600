#include <Wire.h>
#include <AS5600.h>

AMS_5600 ams5600;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Detect the magnet before proceeding
  if (ams5600.detectMagnet() == 0) {
    while (1) {
      if (ams5600.detectMagnet() == 1) {
        Serial.println("Magnet detected");
        break;
      } else {
        Serial.println("Cannot detect magnet");
      }
      delay(1000); // Check every second
    }
  }
}

void loop() {

  Serial.println(ams5600.getRawAngle());
  delay(500); // Delay to avoid flooding the serial output
}

