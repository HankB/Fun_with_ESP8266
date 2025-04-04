# Fun with ESP8266

*ESP8266 development using the ESP-IDF framework*

## Status

* 2025-04-03 This README started.
* 2025-04-03 First cut of first effort (`.../SDK_bare/`) compiles - ship it!
* 2025-04-03 `./SDK_bare/` complete including flashing LED.
* 2025-04-03 Unsuccessful attempt to install the ESP-IDF extension in VS code (`./ESP-IDF_plugin`.)
* 2025-04-04 PlatformIO extension (using Arduino framework) is working except for Serial I/O :-/ Done (`./PlatformIO`)

## 2025-04-03 references

* <https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html>
* <https://github.com/espressif/ESP8266_RTOS_SDK>
* <https://github.com/espressif/ESP8266_NONOS_SDK>
* <https://www.espressif.com/en/news/ESP8266_NonOS_3.0.3>
* <https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html#> Intended for the ESP32 but probably similar to the ESP8266 except perhaps an older version.

## 2025-04-03 Motivation

The ESP8266 from Espressif is cheap and keen to learn (Fawlty Towers reference.) Espressif does a super job of supporting the hobbyist community with easily accessible instructions and tool kits. Development boards using their producte are easy to come by.

However... The ESP8266 is an old product and is not seeing a lot of attention these days. If you're starting your journey with these devices, I highly suggest starting with the ESP32 family. Another option is to use something like ESPhome (with which I have zero experience) that I hear makes it almost trivial to integrate ESP based sensors with Home Assistant. And if you're definition of fun is not like mine, you might prefer the Arduino tool chain which is oriented toward beginners. (I am not a beginner - I used to pay the bills writing S/W for embedded systems.)

My idea of fun is leveraging the best tools to get a job done, though some of these tools may have a big cost in terms of coming up to speed. (Define "best".)

## 2025-04-03 Choices

* `ESP8266_RTOS_SDK` tool chain. The 'NONOS' seems to be light on examples whereas the 'RTOS' documentation seems to not have a lot of information on FreeRTOS itself.
* `ESP-IDF` plugin for VS Code. That's part of the reason I'm documenting this as configuring it appears non-trivial.
* `PlatformIO` plugin for VS Code. I have been told that the ESP8266 libraries are woefully out of date, but the libraries haven't been updated in about 5 years so I'm not sure how that can be true.
* `Arduino`. This is a good starting point for someone who's not a professional programmer. I find some of their choices irksome, but they have made it easy for anyone to get started with embedded systems.

## 2025-04-03 Plan

1. Get the `ESP8266_RTOS_SDK` installed per Espressif's instructions and use it to build a "hello world" style application. There is an example included with the SDK. It's important to do something like this to make sure the tool chain is installed and working. (`./SDK_bare`)
1. Get the `ESP-IDF` plugin working with VS Code per Espressif's instructions, repeating the "hello world" example. (`./ESP-IDF_plugin`) This was actually my original goal, but these things tend to grow.
1. Install the `PlatformIO` plugin in VS Code. It's already there because I've used it for previous projects.
1. Make a "hello world" project using the `Arduino` tool chain.

The instructions for each of these tasks will be found in the README in the corresponding directory.

## 2025-04-03 Dev environment

* X86_64 workstation with 32GB RAM and a Ryzen 7 7700X processor and modern storage running Debian Bookworm.
* X86_64 headless server with ancient Xeon processors and 16GB RAM. (Can't do `Arduino` here but VS Code supports remote so that should work.) This will test that I have the instructions correct. This host also runs Debian Bookworm.
* X86_64 laptop with 16GB RAM and an Intel laptop processor running Debian Trixie.
* "WEMOS D1 mini" - a small 8266 board, not as small as the -01 but not as big as the NodeMCU (of which I have all three.)

I don't generally do Windows but may have access to a laptop running Windows and if time and interest permit, I may try on that.

## Errata

* Typos are my brand! Feel free to submit a PR. It's been done before and you get credit on Github for submitting a PR and I get credit for merging it. :D
