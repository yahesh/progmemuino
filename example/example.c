// contains the PROGMEM wrapper
#include "progmemuino.h"

// needed for "while (true)" loop
#include <stdbool.h>

#ifndef ARDUINO
// needed for printf()
#include <stdio.h>
// needed for sleep()
#include <unistd.h>
#endif

const uint8_t myLength = 17;
PROGMEM prog_uchar myString[] = "Das ist ein Test.";

void setup() {
#ifdef ARDUINO
    Serial.begin(9600);
    while (!Serial) {
    } // for Leonardo
#endif
}

void loop() {
    uint8_t index;

    for (index = 0; index < myLength; index++) {
#ifdef ARDUINO
        Serial.print((char) pm_byte(myString, index));
#else
        printf("%c", pm_byte(myString, index));
#endif
    }

#ifdef ARDUINO
    Serial.println("");
    delay(1000);
#else
    printf("%s", "\n");
    sleep(1);
#endif
}

// emulates the Arduino loop
#ifndef ARDUINO
int main() {
    setup();
    do {
        loop();
    } while (true);

    return 0;
}
#endif
