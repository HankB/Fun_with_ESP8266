# PlatformIO extension for VS Code

This has been previously installed so steps to get it working are not included here. Perhaps if this can be included in testing on the headless server...

## 2025-04-04 Create a project

These things can be a bit tricky as they have opinion on where to store the project that differ from mine.

```text
deactivate # make sure we're not in a venv.
mkdir PlatformIO
cd PlatformIO
code -n .
```

Click PlatformIO to open the extension's left side bar and click the "Create New Project" button. And follow through:

* Enter `PIO_demo` for the project name.
* Selected "WeMos D1 Mini Lite" for the device <https://www.wemos.cc/en/latest/d1/d1_mini_lite.html>
* Only available framework is "Arduino".
* Unchecked "Location [] Use default location" and navigated to this directory.
* Clicked the "Finish" button.

Result is:

```text
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/PlatformIO$ tree
.
├── PIO_Demo
│   ├── include
│   │   └── README
│   ├── lib
│   │   └── README
│   ├── platformio.ini
│   ├── src
│   │   └── main.cpp
│   └── test
│       └── README
└── README.md

6 directories, 6 files
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/PlatformIO$ 
```

I'll `git commit` these as a starting point amd make it easier to `.gitignore` build artifacts later. Hit the check mark in the bottom tray to build and the right arrow to flash. Here I get the warning:

```text
Warning! Please install `99-platformio-udev.rules`. 
More details: https://docs.platformio.org/en/latest/core/installation/udev-rules.html
```

The flash is successful so I do not bother. I might have done something years ago that managed this. On my laptop/Trixie install I did need to run this.

## Add some I/O 

Serial outpout and blinking the built in LED. Blinking works. Needed to change the code to set the baud rate to 9600 as that's what the terminal came up as. That worked. Changed the baud rate (in the code) back to 115200 and added `monitor_speed = 115200` to `platformio.ini`, rebuilt and flashed. The monitor screen was then filled with garbage and then started working. And then stopped working. I fiddled a bit with this and then just left it. I don;t have much patience for this kind of crap. The LED is blinking as desired and I'm moving on.
