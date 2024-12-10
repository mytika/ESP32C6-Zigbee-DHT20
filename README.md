# ESP32-C6 Zigbee mit DHT20: Integration in Home Assistant über Zigbee2MQTT

ESP32C6 Sketeche mit Arduino IDE.
Sketch funktioniert nur, wenn man in Arduino IDE unter Tools folgende Einstellungen wählt
- zigbee Enddevice
- Partion Scheme 4mb zigbee spiffs

## zigbee2mqtt in HA

- in HA über Add-ons Mosquitto-Broker installieren
- Custom Add-ons fuer zigbee2mqtt anlegen mit folgendern url
  - https://github.com/zigbee2mqtt/hassio-zigbee2mqtt
- Browser aktualisieren
- Jetzt im Add-on Store zigbee2mqtt installieren
- Unter Einstellungen - System - Hardware - gesamte Hardware den USB Port für den Zigbee Sonoff Dongle suchen
  - Falls nicht gefunden und Proxmox verwendet wird
  - Proxmox - VE - Hardware - Add USB Device - Use USB Vendor/Device ID - Sonoff auswähen
  - VM neustarten!
- Einstellungen - Add-ons - zigbee2mqtt - Konfiguration - port
  - port: /dev/ttyUSB0
- zigbee2mqtt - Informationen - starten
- zigbee2mqtt - log 
  - checken ob start oder Fehlermeldungen
- zigbee2mqtt - anlernmodus aktivieren
  - esp32c6 restart
  - esp32c6 sollte erkannt werden
- MQTT Explorer Topics überprüfen

## Links
- ESP32C6 Zigbee Thermostat https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee/examples/Zigbee_Temperature_Sensor
- DHT20: https://github.com/RobTillaart/DHT20/blob/master/examples/DHT20/DHT20.ino
- zigbee2mqtt Repo: https://github.com/Koenkk/zigbee2mqtt
- MQTT Explorer: https://mqtt-explorer.com/
