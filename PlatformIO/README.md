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

I'll `git commit` these as a starting point amd make it easier to `.gitignore` build artifacts later.