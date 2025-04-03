# SDK bare

No plugins - Use any editor and run the commands via CLI.

Follow the instructions at <https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html>

## 2025-04-03 Setup toolchain 

Instructions at <https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/linux-setup.html> and I have a few deviations that are probably specific to Debian (Bookworm, Trixie.) I add the package `python-is-python3` which is the easiest way to get Python3 when typing `python` at the command line. Also select Python3 versions of Python packages.

```text
sudo apt-get install -y gcc git wget make libncurses-dev flex bison gperf python-is-python3 python3-serial
```

Next download and extract the ESP8266 toolchain as indicated.

```text
cd ~/Downloads
wget https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz
mkdir -p ~/esp
cd ~/esp
tar -xzf ~/Downloads/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz
```

Add the path to my `~/.profile` (or I will forever be forgetting to add this.) These instructions are for `bash` and may differ for other shells.

```text
export PATH="$PATH:$HOME/esp/xtensa-lx106-elf/bin"
```

I did not need to mess with device permissions on my Bookworm host but it was necessary to add `udev` rules on Trixie. The process will remind you of that at some point and I'll add that to my notes when I get there.

## 2025-04-03 Get ESP8266_RTOS_SDK

* <https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#get-esp8266-rtos-sdk>

```text
cd ~/esp
git clone --recursive https://github.com/espressif/ESP8266_RTOS_SDK.git
```

Cloning took about half a minute on my workstation. Then setup the path to the SDK. This went into my `~/.profile` too.

```text
export IDF_PATH=/home/hbarta/esp/ESP8266_RTOS_SDK
```

## 2025-04-03 Install the Required Python Packages

* <https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#install-the-required-python-packages>

Here I deviated in a couple ways. First, I'm using Python3. Second, it is no longer accepted practice to install Python modules globally, they should go into a virtual environment and for this I used `venv`. I have included the directory for the virtual environment in this project.

```text
cd path/to/project/dir # ~/Programming/ESP8266/Fun_with_ESP8266 for me.
python -m venv esp-idf
cd esp-idf
. bin/activate
```

The last two commands need to be repeated before doing anything that involves the SDK. I suppose `. path/to/venv/dir/bin/activate` could work from anywhere in the directory tree. In my case this would be `. ~/Programming/ESP8266/Fun_with_ESP8266/esp-idf/bin/activate` I just realized that naming that dir `.../esp-idf`may not have been wise as 1) Python can have difficulty with things that have a '-' character as it thinks that means subtraction (*) and 2) this is not an intuitively recognixable name.

Next, install the Python packages. I'm not sure if that needs to be done in the `venv` directory but will do so just in case. (I am not an expert Python dev.) Also note that `pip` rejects the `--user` option when run inside a virtual environment.

```text
(esp-idf) hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/esp-idf$ python -m pip install --user -r $IDF_PATH/requirements.txt
ERROR: Can not perform a '--user' install. User site-packages are not visible in this virtualenv.
(esp-idf) hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/esp-idf$ python -m pip install -r $IDF_PATH/requirements.txt
Requirement already satisfied: setuptools in ./lib/python3.11/site-packages (from -r /home/hbarta/esp/ESP8266_RTOS_SDK/requirements.txt (line 4)) (66.1.1)
Collecting click>=5.0
  Using cached click-8.1.8-py3-none-any.whl (98 kB)
Collecting pyserial>=3.0
  Using cached pyserial-3.5-py2.py3-none-any.whl (90 kB)
Collecting future>=0.15.2
  Using cached future-1.0.0-py3-none-any.whl (491 kB)
Collecting cryptography<35,>=2.1.4
  Using cached cryptography-3.4.8-cp36-abi3-manylinux_2_24_x86_64.whl (3.0 MB)
Collecting pyparsing<2.4.0,>=2.0.3
  Using cached pyparsing-2.3.1-py2.py3-none-any.whl (61 kB)
Collecting pyelftools>=0.22
  Using cached pyelftools-0.32-py3-none-any.whl (188 kB)
Collecting cffi>=1.12
  Using cached cffi-1.17.1-cp311-cp311-manylinux_2_17_x86_64.manylinux2014_x86_64.whl (467 kB)
Collecting pycparser
  Using cached pycparser-2.22-py3-none-any.whl (117 kB)
Installing collected packages: pyserial, pyparsing, pyelftools, pycparser, future, click, cffi, cryptography
Successfully installed cffi-1.17.1 click-8.1.8 cryptography-3.4.8 future-1.0.0 pycparser-2.22 pyelftools-0.32 pyparsing-2.3.1 pyserial-3.5
(esp-idf) hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/esp-idf$ 
```

As far as I know, this Python virtual environment can be used for any project that uses this tool chain.

## 2025-04-03 Start a Project

* https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#start-a-project>

Finally! The fun part.

```text
cd ../SDK_bare/ # Or from wherever you wound up
cp -r $IDF_PATH/examples/get-started/hello_world .
cd hello_world
make menuconfig
```

I did not change anything in `make menuconfig`. Plug in the ESP8266 (WEMOS D1 mini), ccross my fingers and:

```text
make flash monitor
```

It's alive! Time to commit and push.

NB: The information produced by `esp_chip_info()` can be misleading. In particular, it reports 2MB flash and the board I'm using advertises 4MB. `esptool.py` (included with the ESP_RTOS_SDK) reports the correct infmrmation.

```text
(esp-idf) hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/SDK_bare/hello_world$ $IDF_PATH/components/esptool_py/esptool/esptool.py --port /dev/ttyUSB0 flash_id
esptool.py v2.4.0
Connecting....
Detecting chip type... ESP8266
Chip is ESP8266EX
Features: WiFi
MAC: 48:e7:29:53:3b:e6
Uploading stub...
Running stub...
Stub running...
Manufacturer: 5e
Device: 4016
Detected flash size: 4MB
Hard resetting via RTS pin...
(esp-idf) hbarta@olive:~/Programming/ESP8266/Fun_with_ESP8266/SDK_bare/hello_world$ 
```

The `esp_chip_info()` reports the external flash configured by `make menuconfig`. It also reports 2MB on the ESP-01 I tried and that only has 512KB.

The monitor prints some gibberish when the chip resets. The boot loader (or whatever initializes the device) prints messages at a different baud rate than the application. It shoule be possible to set a matching baud rate but I have not done so here. And I just noticed that `make monitor` takes me out of the virtual environment.

## 2025-04-03 But Wait! There's more

The traditional embedded "hello world" in the embedded realm is to blink an LED. I'll do that before moving on. From the directory where we copied hello_wqorld there should be a blinky example. But I cannot find one. :-/ I'll fall back to other projects. I cheated and copied `my_gpio.c` and `my_gpio.h` from <https://github.com/HankB/ESP8266_RTOS_Start/tree/main> and then added the include and call to `init_gpio()` to `app_main()` and had a flashing blue LED. And at this time became confused about the virtual env. It looked like `. ~/.profile` to get the tools back in my `$PATH` took me out of the ENV, but I think it just changed the `PS1` back so it just looked like it was gone.