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
