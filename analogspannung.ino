extern "C" {
#include "user_interface.h"
}
ADC_MODE(ADC_VCC); // Muss global sein!
uint16 system_get_vdd33(void); // Prototy muss angegeben sein!

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(system_get_vdd33());
  delay(1000);
}
