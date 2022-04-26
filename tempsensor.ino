// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

DHT dht(D6, DHT11);

void setup() {

 pinMode(D6, OUTPUT);
 Serial.begin(9600); 
 dht.begin();
 
}

void loop() {
    // get temperature
    float t = dht.getTempCelcius();
    String temp = String(t);


    // if temperature is not a value, print error
    if (isnan(t)) {
        Serial.println("DHT sensor failed");
        return;
    } else {
        Particle.publish("temp", temp, PRIVATE);
          delay(30000); //30sec delay between readings
    }
}