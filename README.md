# Arc-Reactor
LED animation for Iron Man Arc Reactor using FastLED library


This project is using an Adafruit Trinket to control two LED rings.
cycles through various shades of blue but this can be changed
Also uses a potentiomer to adjust LED brigtness

Video demo - https://photos.app.goo.gl/IQGxQgxycCgzlA3E3


Google Photos Album - https://photos.app.goo.gl/7kJDe2Sk65IBUcs42

Parts List

Adafruit Trinket - Mini Microcontroller - 5V Logic-https://www.adafruit.com/product/1501

Neo pixel rize amount/size would vary depending on the size desired the original STL file can fit the 24 LED ring while the 4-inch model can only fit the 16 LED
NeoPixel Ring - 12 - https://www.adafruit.com/product/1643
NeoPixel Ring - 16 - https://www.adafruit.com/product/1463
NeoPixel Ring - 24 - https://www.adafruit.com/product/1586

You may want to add a 0.1 µF capacitor between the + and – pins of EACH PIXEL. Individual pixels may misbehave without this “decoupling cap. Also adding a ~470 ohm resistor between the microcontroller's data pin and the data input on the NeoPixels can help prevent spikes on the data line that can damage your first pixel. 

A potentiomer can also be used to adjust brightness
