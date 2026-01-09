🔹 LED loop  

Connect GPIO2 to the long leg of the LED (anode +).  

Connect the short leg of the LED (cathode -) to one side of the resistor.  

Connect the other side of the resistor to GND rail.  

✅ This completes the LED loop — ESP32 can turn it ON/OFF via GPIO2.  

🔹 Button loop  

Connect GPIO4 to one pin of the button.  

Connect the opposite pin of the button to the same GND rail you used for the LED.  

When you press the button: GPIO4 reads LOW  

When released: GPIO4 reads HIGH (thanks to INPUT_PULLUP)  
