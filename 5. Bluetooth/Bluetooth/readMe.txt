For HC-05: (38400?) 115200

Here you can find sketch and wiring diagram for programming your BT module with Arduino Nano:

1. Upload the sketch HC05_BT_config.ino to your Nano first, then disconnect Nano from USB.

2. Now connect BT to Nano as shown in diagram but do not connect VCC.

3. Plug in the USB to Nano and then connect VCC so BT enters AT mode. LED on BT should start to blink slower, about once every 2 seconds. (If this doesn't work, try holding the button on BT module while connecting VCC).

Open serial monitor in IDE, set baud-rate to 9600 and line ending to Both NL & CR.

Type AT then press enter; (if everything is right, BT should respond with OK and then enter following commands:

AT+NAME=Zowi "setting the name"

AT+PSWD=1234 "pairing password"

AT+UART=115200,1,0 "baud rate"

AT+POLAR=1,0 "enabling STATE pin to be used as reset for programming arduino over BT"



Install and open Zowi app for android, pair the device and ignore the warning message that says the code is modified or something.