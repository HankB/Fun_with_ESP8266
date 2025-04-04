# PlatformIO extension for VS Code using ESP8266_RTOS_SDK

This is a followup to `../PlatformIO`, choosing a different board to widen the framework selection. 

## 2025-04-04 Create a project

This time I chose `WeMos D1 R2 and mini` and could choose from Arduino, RTOS and NONOS. I selected ESP8266_RTOS_SDK. The resulting files were created and committed.

```text
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/PlatformIO_RTOS$ tree
.
├── PIO_RTOS
│   ├── include
│   │   └── README
│   ├── lib
│   │   └── README
│   ├── platformio.ini
│   ├── src
│   └── test
│       └── README
└── README.md

6 directories, 5 files
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/PlatformIO_RTOS$ 
```

Build

```text
Error: Nothing to build. Please put your source code files to the '/home/hbarta/Programming/ESP8266/Fun_with_ESP8266/PlatformIO_RTOS/PIO_RTOS/src' folder
```

Ah! No source file. Start with the one from `../SDK_bare`.

```text
cp ../SDK_bare/hello_world/main/hello_world_main.c PIO_RTOS/src/
cp ../SDK_bare/hello_world/main/my_gpio.c PIO_RTOS/src/
```

Build fails and full outpput is

```text
Processing d1_mini (platform: espressif8266; board: d1_mini; framework: esp8266-rtos-sdk)
-----------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/espressif8266/d1_mini.html
PLATFORM: Espressif 8266 (4.2.1) > WeMos D1 R2 and mini
HARDWARE: ESP8266 80MHz, 80KB RAM, 4MB Flash
PACKAGES: 
 - framework-esp8266-rtos-sdk @ 1.5.0-beta.5 
 - tool-esptool @ 1.413.0 (4.13) 
 - tool-esptoolpy @ 1.30000.201119 (3.0.0) 
 - toolchain-xtensa @ 1.40802.0 (4.8.2)
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 0 compatible libraries
Scanning dependencies...
No dependencies
Building in release mode
Compiling .pio/build/d1_mini/src/hello_world_main.o
Compiling .pio/build/d1_mini/src/my_gpio.o
Compiling /home/hbarta/.platformio/packages/framework-esp8266-rtos-sdk/lib/driver/driver/hw_timer.o
Compiling /home/hbarta/.platformio/packages/framework-esp8266-rtos-sdk/lib/driver/driver/i2c_master.o
src/my_gpio.c:6:25: fatal error: driver/gpio.h: No such file or directory
 #include "driver/gpio.h"
                         ^
compilation terminated.
Compiling /home/hbarta/.platformio/packages/framework-esp8266-rtos-sdk/lib/driver/driver/spi_interface.o
src/hello_world_main.c:13:27: fatal error: esp_spi_flash.h: No such file or directory

***********************************************************************
* Looking for esp_spi_flash.h dependency? Check our library registry!
*
* CLI  > platformio lib search "header:esp_spi_flash.h"
* Web  > https://registry.platformio.org/search?q=header:esp_spi_flash.h
*
***********************************************************************

 #include "esp_spi_flash.h"
                           ^
compilation terminated.
*** [.pio/build/d1_mini/src/my_gpio.o] Error 1
*** [.pio/build/d1_mini/src/hello_world_main.o] Error 1
==================================== [FAILED] Took 0.25 seconds ====================================
```

I did some ssearching and found <https://esp32.com/viewtopic.php?t=27115> which seems to imply a change in the library. There was "a fix":

```text
idf_component_register(SRC_DIRS "."
    REQUIRES driver
    INCLUDE_DIRS "."
    "include")
```

This looks like something from `cmake` but this is not a `cmake` project. Setting this aside for now. I saved the output so I coiuld compare versions against what is found in the `SDK_bare`.
