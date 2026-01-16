# DJI-S1-EP-Battery-status-
DJI S1/EP battery read paramter script 

This repo is how to connect dji S1/EP battery and read it parametr.
1. Connect Uno to battery 

PCAK- = BAT-<br>
SDA<br>
SCL<br>
PCAK+ = BAT+<br>

![alt text](https://github.com/Franek211/DJI-S1-EP-Battery-status-/blob/main/image/1000001580.jpg?raw=true)
![alt text](https://github.com/Franek211/DJI-S1-EP-Battery-status-/blob/main/image/1000001581.jpg?raw=true)
![alt text](https://github.com/Franek211/DJI-S1-EP-Battery-status-/blob/main/image/1000001582.jpg?raw=true)
^
Green SDA<br>
Blue SCL<br>
Black GND<br>
Red 3S volatge<br>

2. Upload Script Battery-status.ino in fw folder
3.a IF not work serach in google "I2C addres scanner", next upload it to UNO and watch console
3.b next change "#define BATTERY_ADDR YOUR_ADDRESS" <- change that to your addres
3.c re-flash Battery-status.ino
4. Look into the console and watch your battery par