#include <rom/rtc.h>
#define uS_TO_S_FACTOR 1000000


void Motivo_de_Reiniciar(RESET_REASON reason){
  switch ( reason){
    case 1  : Serial.println ("Vbat power on reset");break;
    case 3  : Serial.println ("Software reset digital core");break;
    case 4  : Serial.println ("Legacy watch dog reset digital core");break;
    case 5  : Serial.println ("Deep Sleep reset digital core");break;
    case 6  : Serial.println ("Reset by SLC module, reset digital core");break;
    case 7  : Serial.println ("Timer Group0 Watch dog reset digital core");break;
    case 8  : Serial.println ("Timer Group1 Watch dog reset digital core");break;
    case 9  : Serial.println ("RTC Watch dog Reset digital core");break;
    case 10 : Serial.println ("Instrusion tested to reset CPU");break;
    case 11 : Serial.println ("Time Group reset CPU");break;
    case 12 : Serial.println ("Software reset CPU");break;
    case 13 : Serial.println ("RTC Watch dog Reset CPU");break;
    case 14 : Serial.println ("for APP CPU, reseted by PRO CPU");break;
    case 15 : Serial.println ("Reset when the vdd voltage is not stable");break;
    case 16 : Serial.println ("RTC Watch dog reset digital core and rtc module");break;
    default : Serial.println ("NO_MEAN");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
  delay(2500);

  Serial.print("Motivo RESET CPU0:  ");
  Motivo_de_Reiniciar(rtc_get_reset_reason(0)); // Passar o número da CPU 0 ou 1

  Serial.print("Motivo RESET CPU1:  ");
  Motivo_de_Reiniciar(rtc_get_reset_reason(1));  // Passar o número da CPU 0 ou 1

}

void loop() {

}
