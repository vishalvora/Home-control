# Home-control
Project for controlling home appliance using MQTT and NodeMcu.

For Controling your home appliance through NodeMcu and MQTT protocol.

Step 1: Load home control.ino in NodeMcu firmware using Arduino IDE. -- No Changes required.

Step 2: Restart your NodeMcu module.

Step 3: Your modeule will run in AP mode with ssid: Espadmin and pass: espadmin. Connect to Module using your mobile.

Step 4: Open .apk android app and go to NodeMcu Tab and enter ssid and pass of the wifi network you want to connect.

Step 5: Go to MQTT Tab in app and enter your MQTT broker name and port you wish to connect. Port should be WebSocket suported. e.g. For mosquitto broker Host: test.mosquitto.org and port:8080
Step 6: For adding device go to Device tab and select new device. add topic room/switch/cmd (you can change topic in node Mcu) On command: pin no=on e.g. if you want to control D0 add D0=on and off command D0=off
Step 7: Go to Dashboard tab you can see your added device and a toggle button. On/off your device by this toggle button.



For Controlling NodeMcu GPIO without internet(MQTT)

Follow Step 1 and 2 as above.
Step 3: go to NodeMcu tab and go to NodeMcu button.
Step 4: Control any GPIO by toggling circles with mentioned pin no..


