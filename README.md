# ESP32-C6 Zigbee avec DHT20: Intégration dans Home Assistant via Zigbee2MQTT

ESP32C6 Sketeche mit Arduino IDE.
Sketch funktioniert nur, wenn man in Arduino IDE unter Tools folgende Einstellungen wählt
- zigbee Enddevice
- Partion Scheme 4mb zigbee spiffs

## zigbee2mqtt in HA

- in HA über Add-ons Mosquitto-Broker installieren
- Créez des modules complémentaires personnalisés pour zigbee2mqtt avec l'URL suivante
  - https://github.com/zigbee2mqtt/hassio-zigbee2mqtt
- Mettre à jour le navigateur
- Installez maintenant dans le magasin complémentaire Zigbee2MQTT
- Sous Paramètres - Système - Matériel - Toutes les recherches matérielles pour le port USB du dongle Zigbee Sonoff
  - S'il n'est pas trouvé et que Proxmox est utilisé
  - Proxmox - VE - Hardware - Add USB Device - Use USB Vendor/Device ID - Sonoff auswähen
  - Redémarrez la VM !
- Paramètres - Modules complémentaires - Zigbee2mqtt - Configuration - Port
  - port: /dev/ttyUSB0
- zigbee2mqtt - Informations - starten
- zigbee2mqtt - log 
  - vérifier si les messages de démarrage ou d'erreur
- zigbee2mqtt - activer le mode d'apprentissage
  - redémarrage de l'esp32c6
  - esp32c6 devrait être reconnu
- Consultez les rubriques de l'explorateur MQTT

## Links
- ESP32C6 Zigbee Thermostat https://github.com/espressif/arduino-esp32/tree/master/libraries/Zigbee/examples/Zigbee_Temperature_Sensor
- DHT20: https://github.com/RobTillaart/DHT20/blob/master/examples/DHT20/DHT20.ino
- zigbee2mqtt Repo: https://github.com/Koenkk/zigbee2mqtt
- MQTT Explorer: https://mqtt-explorer.com/
