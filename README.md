# ESP32 Room Vacancy Detector
This project uses an ESP32C3 board and a photoresistor light sensor module to detect bathroom occupancy. The ESP32 runs a simple Wi-Fi web server that serves a webpage showing whether a room is occupied or vacant.

## Hardware Required
* [Seeed Studio XIAO ESP32-C3](https://a.co/d/3HdG4hU)
* [5MM LDR Light Sensor](https://a.co/d/fW6FoNX)
* 3.7 V Lithium Battery (Optional)
* If using battery: diode (schottky, signal, power)
* Jumper Cables + Breadboard
* USB-C cable

## Wiring (Using USB-C as Voltage Source)
* D0 pin (or any other Digital Input) of ESP32 to D0 of photoresistor
* GND pin of ESP32 to GND of photoresistor
* 3V3 pin of ESP32 to VCC of photoresistor
* Plug USB-C from outlet or computer into ESP32

## Wiring (Using Lithium Battery as Voltage Source)
* Wire the photoresistor and ESP32 the same as above
* Connect cathode of diode to 5V pin of ESP32 and connect anode to battery (*NOTE: It is not recommended to use an LED since it is not designed for power routing. I only used one here since it was all I had access to at the time*)
* Ground the battery with GND pin of ESP32

## Software Setup
1. Install Arduino
2. Install ESP32 Board Support
3. Select XIAO_ESP32C3 board
4. Install Libraries: 'Wifi.h', 'WebServer.h', 'ESPmDNS.h'
5. Open light_detection.ino
6. Change the `LIGHT_SENSOR_PIN` variable if you used a pin other than D0
7. Update `ssid` and `password` to reflect your WiFi credentials
8. Alter the html in `handleRoot()` according to your needs; the original configuration displays a webpage for "Bathroom Status"
9. Set hostname in `setup()`: `if (!MDNS.begin("bathroom")) {  // set host name here`
10. Compile and upload program to ESP32

## Usage
1. Place the unit in the room where the light can reach it
2. Adjust the poteniometer until the D0 LED on the photoresistor turns on. This state will indicate that the room is occupied
3. Turn the lights off in the room and make sure the D0 LED is now off. Fine-tune as needed
4. Open "bathroom.local" (or whatever you named the host) on a device that is connected to the same network, and view the room status. Refresh to update status




