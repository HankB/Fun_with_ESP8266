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

