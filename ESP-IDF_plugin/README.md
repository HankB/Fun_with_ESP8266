# ESP-IDF Extension for VSCode

* <https://docs.espressif.com/projects/vscode-esp-idf-extension/en/latest/>
* <https://docs.espressif.com/projects/esp-idf/en/v4.2.3/esp32/get-started/vscode-setup.html> For ESP32 but likely relevant for ESP8266.

## 2025-04-03 Prerequisites

* VS Code previously installed.
* Install Debian packages

```text
sudo apt-get install git wget flex bison gperf python3 python3-pip python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```

* Install the extension (previously installed.)
* Configure = "View > Command Palette" and type ESP-IDF and select `ESP-IDF: Configure ESP-IDF Extension`. May need to "Enable" the extension on the ESP-IDF page that comes up when clicking on the extension in the extension marketplace. This brings up the configuration page. I skipped `Select download server:` and `Select ESP-IDF version:` and entered `/home/hbarta/esp/ESP8266_RTOS_SDK` for `Enter ESP-IDF directory (IDF_PATH):`. I had a 2 or three year old `~/.espressif` directory and I ignored that, creating a new directory under `~/esp` so the path for `Enter ESP-IDF Tools directory (IDF_TOOLS_PATH):` is entered as `/home/hbarta/esp/.espressif`. For `Select Python version:` I entered `which python` in the (venv) command line and got

```text
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266$ which python
/home/hbarta/Programming/ESP8266/Fun_with_ESP8266/esp-idf/bin/python
hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266$ 
```

 and used that. Then clicked the "Install" button. There was a progress monitor and then a warning popped up

 ```text
 OPENOCD_SCRIPTS environment variables is not defined
```

I also confirmed that this plugin installed the same package I had already installed (`xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz`). If I redo this, I'll look for an option to use the existing install.

I exited and restarted VS Code and the conmfiguration page came up again. I clicked the install button again. I saw two warnnings. The one about `OPENOCD_SCRIPTS` was repeated and now I see ...

```text
pkg_resources cannot be imported probably because the pip package is not installed and/or using a legacy Python interpreter. Please refer to the Get Started section of the ESP-IDF Programming Guide for setting up the required packages.
Command failed: /home/hbarta/SW/python_env/idf4.4_py3.9_env/bin/python /home/hbarta/esp/ESP8266_RTOS_SDK/tools/check_python_dependencies.py -r /home/hbarta/esp/ESP8266_RTOS_SDK/requirements.txt
/usr/bin/cmake

/usr/bin/ninja

pkg_resources cannot be imported probably because the pip package is not installed and/or using a legacy Python interpreter. Please refer to the Get Started section of the ESP-IDF Programming Guide for setting up the required packages.
Command failed: /home/hbarta/SW/python_env/idf4.4_py3.9_env/bin/python /home/hbarta/esp/ESP8266_RTOS_SDK/tools/check_python_dependencies.py -r /home/hbarta/esp/ESP8266_RTOS_SDK/requirements.txt
Downloading from https://dl.espressif.com/dl/esp-idf/idf_versions.txt
idf_versions.txt has (1) KB
idf_versions.txt progress: 100.00% (0.10 / 0.10) KB
/usr/bin/cmake

/usr/bin/ninja


Downloading Toolchain for Xtensa (ESP8266) based on GCC
Using mirror Github with URL https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz
Found xtensa-lx106-elf in /home/hbarta/esp/.espressif/dist

Using existing Toolchain for Xtensa (ESP8266) based on GCC in /home/hbarta/esp/.espressif/tools/xtensa-lx106-elf/esp-2020r3-49-gd5524c1-8.4.0

Selected python is from a virtual environment. Choose system python
OPENOCD_SCRIPTS environment variables is not defined
pkg_resources cannot be imported probably because the pip package is not installed and/or using a legacy Python interpreter. Please refer to the Get Started section of the ESP-IDF Programming Guide for setting up the required packages.
Command failed: /home/hbarta/SW/python_env/idf4.4_py3.9_env/bin/python /home/hbarta/esp/ESP8266_RTOS_SDK/tools/check_python_dependencies.py -r /home/hbarta/esp/ESP8266_RTOS_SDK/requirements.txt
Downloading from https://dl.espressif.com/dl/esp-idf/idf_versions.txt
idf_versions.txt has (1) KB
idf_versions.txt progress: 100.00% (0.10 / 0.10) KB
/usr/bin/cmake

/usr/bin/ninja
```

In particular

```text
Selected python is from a virtual environment. Choose system python
```

It's not clear that the ESP-IDF plugin is going to be installable on Debian. W/out doing more work to see if I can get it going, I'm not going to file an issue at this time. I'm setting this part of the exploration aside for now.
