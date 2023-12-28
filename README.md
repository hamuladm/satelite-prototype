# satelite-prototype

## loraTransmitterFinal
This folder contains files for transmitter component in satelite. For using conect LoRa SX1278(connection module) and BMP280(pressure and temperature sensor) this properly using .ioc file.  
If you powered STM32 and red diod is blinking: transmitter works properly.  
If orange diod is on and red diod is not blinking: LoRa did not initialize properly.  
If orange diod is blinking with red diod simultaniously: LoRa was properly initioalized but transmittion doesn't work properly.  
  
It transmits 2-bytes arrays of uint8_t values where first value is temperature(in Kelvin's) and the second is pressure(in kilopascals).

## receiverComeback
This folder contains files for receiver component in satelite. For using conect LoRa SX1278(connection module) this properly using .ioc file.  
If you powered STM32 and red diod is blinking: receiver does not properly.
If orange diod is blinking: LoRa did not initialize properly.  
If blue diod is blinking with red diod simultaniously: receiver works properly.  
To observe measurements from satelite you should use live expressions in debug session.