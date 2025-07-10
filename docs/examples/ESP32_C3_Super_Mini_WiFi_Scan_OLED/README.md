# ESP32-C3 Super Mini WiFi Scanner with OLED

Dieses Beispiel zeigt, wie man verfügbare WLAN-Netzwerke scannt und deren Namen mit Signalstärke auf einem 0,96" OLED Display ausgibt. Die Signalstärke wird als Prozentwert hinter dem Netzwerknamen angezeigt.

## Schaltplan

Verbinde das OLED Display über I2C mit dem ESP32-C3 Super Mini.
Der Sketch initialisiert den I2C-Bus explizit auf folgenden Pins:

- **SDA** -> GPIO8
- **SCL** -> GPIO9
- **VCC** -> 3.3V
- **GND** -> GND

![Schematic](images/schematic.jpg)

## Bibliotheken

Stelle sicher, dass folgende Bibliotheken in der Arduino IDE installiert sind:

- **WiFi** (bereits in den ESP32 Boards enthalten)
- **Adafruit SSD1306**
- **Adafruit GFX Library**
- **Wire** (Standardbibliothek)

## Code Hochladen

1. Öffne die Datei `ESP32_C3_Super_Mini_WiFi_Scan_OLED.ino` in der Arduino IDE.
2. Wähle unter **Werkzeuge > Board** dein ESP32-C3 Board aus.
3. Schließe das Board an und wähle den entsprechenden Port.
4. Lade den Sketch hoch.

Nach dem Upload zeigt das Display die gefundenen WLAN-Netze mit ihrer Signalstärke an.

Der Sketch zeigt beim Starten kurz "Scanning..." an und listet anschließend bis zu fünf Netzwerke nummeriert auf. Hinter jedem Namen erscheint die empfangene Signalstärke in Prozent.
