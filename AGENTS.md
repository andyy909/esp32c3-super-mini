# AGENTS.md

## Übersicht

Diese Datei dokumentiert alle eingesetzten Agents (Firmware, Skripte, Services) im Projekt – insbesondere für ESP32 und Raspberry Pi.

---

## ESP32-Agents

### 1. Name: `wifi_scan_oled`
- **Gerät:** ESP32-C3 Super Mini
- **Typ:** Firmware (Arduino)
- **Beschreibung:**  
  Scannt nach WLAN-Netzen und zeigt die SSIDs auf einem 0.96" OLED (I2C) an.
- **Wichtige Pins:**  
  I2C: SDA = GPIO8, SCL = GPIO9
- **Kommunikation:**  
  Standalone, Ausgabe nur am OLED
- **Pfad zur Datei:**  
  `docs/examples/ESP32_C3_Super_Mini_WiFi_Scan_OLED/ESP32_C3_Super_Mini_WiFi_Scan_OLED.ino`

---

### 2. Name: `sensor_node`
- **Gerät:** ESP32 (verschiedene Modelle)
- **Typ:** Firmware (Arduino/ESP-IDF)
- **Beschreibung:**  
  Misst Umweltdaten (z.B. Temperatur, Luftfeuchte) und sendet sie per MQTT an den Broker.
- **Kommunikation:**  
  MQTT zu zentralem Broker (Raspberry Pi)
- **Pfad zur Datei:**  
  `src/sensor_node.ino`
- **Hinweis:**  
  Unterstützt OTA-Update

---

## Raspberry Pi-Agents

### 3. Name: `mqtt_broker`
- **Gerät:** Raspberry Pi 4
- **Typ:** Service (Mosquitto MQTT)
- **Beschreibung:**  
  Empfängt und verteilt Nachrichten von/zu allen Nodes (ESP32, Pi).
- **Kommunikation:**  
  MQTT (Standard-Port: 1883)
- **Installationspfad:**  
  Systemdienst

---

### 4. Name: `data_collector`
- **Gerät:** Raspberry Pi 4/5
- **Typ:** Python-Skript
- **Beschreibung:**  
  Sammelt Sensordaten vom MQTT-Broker und schreibt sie in eine Datenbank (z.B. InfluxDB, SQLite).
- **Kommunikation:**  
  MQTT (Empfang), ggf. HTTP (API)
- **Pfad zur Datei:**  
  `scripts/data_collector.py`

---

### 5. Name: `web_dashboard`
- **Gerät:** Raspberry Pi
- **Typ:** Webserver (z.B. Flask/Node-RED)
- **Beschreibung:**  
  Zeigt alle Sensordaten im Browser an, optional Steuerung einzelner Nodes.
- **Kommunikation:**  
  HTTP (Webinterface), MQTT (optional)
- **Pfad zur Datei:**  
  `dashboard/` (Ordner)

---

## Übersichtstabelle

| Agent-Name        | Gerät/Plattform   | Typ            | Kommunikation             | Kurzbeschreibung                 |
|-------------------|-------------------|----------------|---------------------------|----------------------------------|
| wifi_scan_oled    | ESP32-C3          | Firmware       | OLED-Display              | WLAN-Scan auf OLED               |
| sensor_node       | ESP32             | Firmware       | MQTT                      | Umweltmessung & MQTT-Sende       |
| mqtt_broker       | Raspberry Pi      | Service        | MQTT                      | Zentrale Nachrichtenverteilung   |
| data_collector    | Raspberry Pi      | Python-Skript  | MQTT, Datenbank           | Sensordaten sammeln/loggen       |
| web_dashboard     | Raspberry Pi      | Webserver      | HTTP, MQTT                | Visualisierung & Steuerung       |

---

## Hinweise

- Neue Agents bitte nach gleichem Schema ergänzen!
- Pinouts & Kommunikationswege immer mit angeben!
- Für komplexere Projekte ggf. Diagramm ergänzen.

---

## Maintainer

- Andi (andyy909)
- [Deine weiteren Contributor eintragen]
