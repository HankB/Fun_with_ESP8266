# Arduino

This is probably where most people get their start with microcontrollers. In my case it was with an Uno R3 and the Arduino IDE (and probably on Windows at that time.) I had already worked with embedded systems and microcontrollers professionally. This was my first foray into that realm as a hobbyist. And it didn't need thousands of dollars worth of hardware and software to do. The Arduino line of boards has expanded and the IDE itself has grown beyond that and now supports the ESP chips. This is probably where most users should start.

## 2025-04-05 Getting started

There are a couple ways to install on Linux and I chose the native Debian package. That's tweaked a bit from the Arduino release (and probably versions behind) but I prefer that packaging method. Here's a list of packages it pulls in.

```text
The following additional packages will be installed:
  arduino-builder arduino-core-avr arduino-ctags avr-libc avrdude binutils-avr extra-xdg-menus gcc-avr java-wrappers libastylej-jni libbatik-java
  libbcpg-java libcommons-exec-java libcommons-net-java libftdi1 libgoogle-gson-java libhidapi-libusb0 libjackson2-annotations-java
  libjackson2-core-java libjackson2-databind-java libjaxp1.3-java libjmdns-java libjna-java libjna-jni libjna-platform-java libjsch-java
  libjssc-java libjzlib-java liblightcouch-java liblistserialsj-dev liblistserialsj1 liblog4j2-java libmongodb-java librsyntaxtextarea-java
  librxtx-java libsemver-java libserialport0 libxalan2-java libxmlgraphics-commons-java
Suggested packages:
  dfu-programmer avrdude-doc gcc-doc librhino-java libbcpg-java-doc libcommons-net-java-doc libgoogle-gson-java-doc
  libjackson2-annotations-java-doc libjackson2-core-java-doc libjackson2-databind-java-doc libjna-java-doc libgeronimo-jms-1.1-spec-java
  librsyntaxtextarea-java-doc libsemver-java-doc libxalan2-java-doc libbsf-java libxsltc-java libxmlgraphics-commons-java-doc
The following NEW packages will be installed:
  arduino arduino-builder arduino-core-avr arduino-ctags avr-libc avrdude binutils-avr extra-xdg-menus gcc-avr java-wrappers libastylej-jni
  libbatik-java libbcpg-java libcommons-exec-java libcommons-net-java libftdi1 libgoogle-gson-java libhidapi-libusb0 libjackson2-annotations-java
  libjackson2-core-java libjackson2-databind-java libjaxp1.3-java libjmdns-java libjna-java libjna-jni libjna-platform-java libjsch-java
  libjssc-java libjzlib-java liblightcouch-java liblistserialsj-dev liblistserialsj1 liblog4j2-java libmongodb-java librsyntaxtextarea-java
  librxtx-java libsemver-java libserialport0 libxalan2-java libxmlgraphics-commons-java
0 upgraded, 40 newly installed, 0 to remove and 0 not upgraded.
Need to get 47.9 MB of archives.
After this operation, 175 MB of additional disk space will be used.
```

This gets me `Arduino: 1.8.19`. Listed as "Legacy" at <https://www.arduino.cc/en/software>. I'm not seeing anything newer in backports or the next Debian release so I suppose I would need to use the Appimage or Zip file to get the current Arduino release. I'm setting that upgrade aside for now.

## 2025-04-05 Start a Project

```text
cd Arduino
arduino
```

The IDE opens with the most recent sketch I worked on. I click "File > New" and a new edit window opens with a skeleton code and named `sketch_apr05s`. next I click "File > Examples" there are numerous ESP8266 entries so I click on ESP8266WiFi and another drop down opens with a list of specific projects. I chose NTPClient since that's something I usually incorporate in my ESP projects. Yet another IDE window opens (and I close the previous ones.) I click "File > Save As", navigate to the `.../Arduino` directory and click "Save". The result is

```text
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/Arduino$ tree -a
.
├── NTPClient
│   └── NTPClient.ino
└── README.md

2 directories, 2 files
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/Arduino$ 
```

The `README.md` is created by me and is this file. I click the check mark to build and a while later it reports

```text
. Variables and constants in RAM (global, static), used 28460 / 80192 bytes (35%)
║   SEGMENT  BYTES    DESCRIPTION
╠══ DATA     1512     initialized variables
╠══ RODATA   1148     constants       
╚══ BSS      25800    zeroed variables
. Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
║   SEGMENT  BYTES    DESCRIPTION
╠══ ICACHE   32768    reserved space for flash instruction cache
╚══ IRAM     26979    code in IRAM    
. Code in flash (default, ICACHE_FLASH_ATTR), used 242324 / 1048576 bytes (23%)
║   SEGMENT  BYTES    DESCRIPTION
╚══ IROM     242324   code in flash   
```

(It builds - ship it!) It flashes w/out issue and I see output. Of course it fails to connect since I've not put my credentials in. Time to commit before moving on.

## 2025-04-05 an actual connection

I've added my creds and also switched the baud rate in the sketch to 74880 which seems to be what the boot loader uses. It did not go well. I see messages in the "black window" (and terminal window) 

```text
Error while setting serial port parameters: 74,880 N 8 1
```

The serial monitor shows gibberish. Closing and reopening the monitor produces the same result and repeats the same error message. I'm switching the sketch back to 115200 baud. (`Serial.begin(115200);`) And build/flash. Interesting. The sketch output in the monitor window is correct but the setting still shows 74880. I guess the error message indicates it did not change from the default/previous 115200. (I won;t count that against Arduino since I'm using a legacy version of the tools.) The ESP connected and is getting time from ""ime.nist.gov". The next test is to see if it still connects w/out providing SSID and password. ... It does not. I'm not sur if that's an Arduino thing or an ESP8266 thing. The ESP32 I've worked with saves the most recently used credentials and I can delete them from my code to avoid committing them to Github. I'll use the other strategy of putting them in `secrets.h` and adding to .gitignore. Sadly I seem unable to open `secrets.h` in the Arduino IDE. (Legacy issue?)

## 2025-04-05 make it blink

Open the blink example. Now add a my_blink.ino to the NTPClient directory and copy the contents from the example. Build. It should fail with symbol conflicts with `setup()` and `loop()` and it does. Now to fix this up by renaming setup and providing `my_led_on()` and `my_led_off()` functions and a header to tie them to the main sketch. Can't open `my_led.h` :-/ Configure code to turn the LED on while processing the NTP packet. That code is a little awkward as it sends the request and waits a second before checking for a reply. And it seems to miss a lot of replies:

```text
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
packet received, length=48
Seconds since Jan 1 1900 = 0
Unix time = 2085978496
The UTC time is 6:28:16
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
no packet yet
sending NTP packet...
packet received, length=48
Seconds since Jan 1 1900 = 0
Unix time = 2085978496
The UTC time is 6:28:16
sending NTP packet...
```

Every fifth query gets a reply. Is my NTP server throttling? Ah... Go back to 10s delay. Yes, it gets a reply to ewach query at 10s delay.
