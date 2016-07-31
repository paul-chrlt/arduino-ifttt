#include <SPI.h>
#include <EEPROM.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client = EthernetClient();

void setup() {
Serial.begin(9600);
Ethernet.begin(mac);
Serial.println("réusite ethernet begin :");
delay(1000);
}

void loop() {

delay(1000);
Serial.println(IPAddress());
client.connect("maker.ifttt.com", 80);
Serial.println(client.connect("maker.ifttt.com", 80));
Serial.println("connexion serveur");
delay(500);
client.print("POST /trigger/XXXXXXXXXXX/with/key/XXXXXXXXXXXX HTTP/1.1\r\nHost: maker.ifttt.com\r\nContent-type: application/x-www-form-urlencoded\r\nContent-Length: 0\r\n\r\n");

delay(1000);
client.stop();
delay(1000000);
}
