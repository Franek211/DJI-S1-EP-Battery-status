#include <Wire.h>

// PCAK- = BAT-
// SDA
// SCL
// PCAK+ = BAT+


#define BATTERY_ADDR 0x0B // default battery addres

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Battery Parametr DJI S1");
}

void loop() {
  readRegister(0x09, "Voltage (mV)");     // Voltage in mV
  readRegister(0x0A, "Current (mA)");     // Curent (negativ = discharge)
  readRegister(0x10, "Remaining (mAh)");  // Remaining Capacity
  readRegister(0x18, "Temp (0.1°C)");     // Temperature
  readRegister(0x16, "Status");           // error flag
  Serial.println("-------------------");
  delay(2000);
}

void readRegister(uint8_t reg, String name) {
  Wire.beginTransmission(BATTERY_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);  // restart

  Wire.requestFrom(BATTERY_ADDR, (uint8_t)2);
  if (Wire.available() >= 2) {
    uint16_t value = Wire.read() | (Wire.read() << 8);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
  } else {
    Serial.print(name);
    Serial.println(": no response");
  }
}