
libposjs is a Qt plugin that provide functionalities to access hardware-specific 
features like printing and scan text codes with HID USB devices.

See [LICENSE](LICENSE).

## Building

### Requirements

* Linux based OS with 64-bit or 32-bit architecture. 
* C++ toolchain.
* libusb-0.1-4.
* [Git](http://git-scm.com/).
* [Qt5.3.0](http://qt-project.org/downloads).

### Build and run

1. Open your command prompt and download the latest [libposjs](https://github.com/Zimtronic/libposjs.git).

 ```sh
  git clone https://github.com/Zimtronic/libposjs.git
  cd libposjs
  ```
  
2. Execute `qmake` to create Makefile. 
3. Execute `make` to compile.

When finished you will see a "lib" directory that contain a shared library called "libposjs.so".

## Supported devices

Theoretically we support any ESC/POS based printer and compatible cash drawers. ESC/POS protocol was designed by EPSON 
and is widely used by many other printer brands mainly on POS. Additionally, we support access
to USB HID barcode scanners and magnetic card readers.

Default devices:

* Printer EPSON TM-T20II
* Barcode scanner MJ_tech V3.00
* Magnetic card reader model MSR100 
* Cash drawers, as the cash drawers are connected to the printer all Epson compatible cash drawers should work. 


