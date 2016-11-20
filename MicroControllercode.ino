// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"


    // DHT parameters

    #define DHTPIN 5

    #define DHTTYPE DHT11

    // Variables

    int temperature;

    int humidity;

    // int light;

    // Pins

    // int light_sensor_pin = A0;

    // DHT sensor

    DHT dht(DHTPIN, DHTTYPE);

void setup() {

        Serial.begin(9600);

        // Start DHT sensor

        dht.begin();

    }

void loop() {

        

        // Humidity measurement

        temperature = dht.getTempCelcius();

        // Humidity measurement

        humidity = dht.getHumidity();

        Particle.publish("Temperature (°C)",String(temperature),360,PRIVATE);

        Particle.publish("Humidity (%)",String(humidity),360,PRIVATE);


        Particle.variable("temperature", temperature);

        Particle.variable("humidity", humidity);


        Serial.println("Temperature: " + String(temperature) + " °C");

        Serial.println("Humidity: " + String(humidity) + "%");

        delay(1500);




    }


