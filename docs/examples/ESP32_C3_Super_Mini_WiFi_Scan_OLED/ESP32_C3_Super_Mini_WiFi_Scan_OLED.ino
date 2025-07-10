#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  // Initialize I2C explicitly on GPIO8 (SDA) and GPIO9 (SCL)
  Wire.begin(8, 9);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("WiFi Scan");
  display.display();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Scanning...");
  display.display();
  int n = WiFi.scanNetworks();
  display.clearDisplay();
  display.setCursor(0,0);
  if(n < 0) {
    display.println("Scan failed");
  } else if(n == 0) {
    display.println("No networks found");
  } else {
    display.print(n);
    display.println(" networks:");
    for (int i = 0; i < n && i < 5; ++i) {
      display.print(i + 1);
      display.print('.');
      display.print(' ');
      display.print(WiFi.SSID(i));
      display.print(' ');
      int rssi = WiFi.RSSI(i);
      int quality = 0;
      if (rssi <= -100) {
        quality = 0;
      } else if (rssi >= -50) {
        quality = 100;
      } else {
        quality = 2 * (rssi + 100);
      }
      display.print(quality);
      display.println('%');
    }
  }
  display.display();
  delay(5000);
}
