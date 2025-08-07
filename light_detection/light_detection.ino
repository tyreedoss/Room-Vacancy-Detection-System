#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define LIGHT_SENSOR_PIN 2  // Change this to the actual GPIO you're using

//Replace with your network credentials
const char* ssid = "CHANGE_THIS";
const char* password = "CHANGE_THIS";
WebServer server(80);

void handleRoot() {
  int lightLevel = digitalRead(LIGHT_SENSOR_PIN);
  String message = "<html><head><title>Bathroom Status</title>";
  message += "<style> body { font-size: 48px; font-family: Arial, sans-serif; } </style>";
  message += "</head><body>";
  message += "<h1>Bathroom Occupancy Status:</h1>";
  message += "<h2>";
  if (lightLevel == LOW) {
    // Occupied = red
    message += "<strong style='color:red;'>Occupied</strong>";
  } else {
    // Vacant = green
    message += "<strong style='color:green;'>Vacant</strong>";
  }
  message += "</h2>";
  message += "<p><em>(Refresh the page to update the status)</em></p>";
  message += "</body></html>";

  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_SENSOR_PIN, INPUT);

  // connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  if (!MDNS.begin("bathroom")) {  // set host name here
  Serial.println("Error setting up MDNS responder!");
  } 
  else {
  Serial.println("mDNS responder started: http://bathroom.local");
  }
  Serial.println(WiFi.localIP()); //Print IP

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

