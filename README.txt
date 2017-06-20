This software is released under the MIT License, see LICENSE.txt.

!!! NOTICE !!!
ILI9328 requires SPI_MODE3. But SPI_MODE2 and SPI_MODE3 configuration are inverted in my arduino-esp32 now.
If your arduino-esp32 has correct SPI configuration, you need to change to SPI_MODE3. 
See ili9328.cpp.

Controller configuration and WiFi UDP setting (SSID, Password, Port) : See  esp32_ILI9328_Pacman.ino. 

You can set configuration by loading "WiFi_UDP_Controller_config.txt" for WiFi TCP/UDP Controller.
