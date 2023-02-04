# ComfoAir
This is a clone of https://github.com/wichers/esphome-comfoair repo with a few modifications:

1. It contains the fixes to the Climate control modifciations made in https://github.com/nilsbebelaar/esphome-comfoair fork. 
  - Set prefered temp.
  - Proper checksum computation.
1. More cannonical C++ style of the code (e.g. no this-> all over the place). 
1. Supports connecting a ComfoSense remote to a second UART and proxies commands back and forth.
1. Support for status leds
1. Support for filter reset command
1. Support for a phisical button on the device

## Building the thing

BOM:
1. ESP8266 serial WIFI Witty cloud Development Board ESP-12F module MINI nodemcu [buy here](https://www.aliexpress.com/item/32832264128.html)
1. Mini RS232 MAX3232 Levels to TTL level converter board serial converter board  [buy here](https://www.aliexpress.com/item/32261741207.html)
1. 12V zu 5V 3A 15W DC-DC Step Down Buck Converter Power Supply Module Mini USB [buy here](https://www.aliexpress.com/item/33032878289.html)
1. Aerial Butt Welding Type 5EDGRKC-5.08mm 5pin Male [buy here](https://www.aliexpress.com/item/1005003988825751.html)
1. Aerial Butt Welding Type 5EDGRKC-5.08mm 5pin Female [buy here](https://www.aliexpress.com/item/1005003988825751.html)

![Schematic](doc/schematic.png)
[Schematic](doc/esp_comfoair.pdf)

The MAX2323 board only breaks out the second tranciever channel so I soldered cables directly to pins 11,12 (TTL TX,RX) and 13,14 (RS232 TX,RX) on the MAX2323 chip.

The ESPHome application uses pins GPIO5 and GPIO14 for the second software serial interface because almost all other pins are already claimed by the LED light (GPIO12, GPIO13, GPIO15), the button (GPIO4) or the light sensor (ADC) or have some other special function.

Eventually I might move to an ESP32 board to be able to use two hardware UART ports.