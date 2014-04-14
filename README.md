usb-joystick
============

Soo.. I ordered a couple of Atari 2600 joysticks from Ebay (all genuine and Atari sanctioned I'm sure :)),
so I could use them with the [FPGA VCS project](https://github.com/elpuri/argh2600). I thought it would be cool
to retrofit the other one with a microcontroller that acts as like a USB keyboard, sending arrow key and space presses
when when wiggling the stick and hitting that fire so I can use the joystick with the plethora of emulators out there.

After a bit of googling I found  [Teensy](http://pjrc.com/store/teensy.html) which is a small footprint USB capable AVR microcontroller board. The small bootloader on the AVR lets you program the flash memory inside the chip using the USB if you press the small button on the board and during normal operation the microcontroller acts as a USB device. A perfect fit for our task.

HOWTO (with no eggs smashing)
--------------------

#### Step 1: Observe the carefully crafted pristine control device
![](https://github.com/elpuri/usb-joystick/blob/master/photos/1.jpg?raw=true)
- - - 

#### Step 2: Unscrew the shit out of it and expose the innards
![](https://github.com/elpuri/usb-joystick/blob/master/photos/2.jpg?raw=true)
- - - 

#### Step 3: Detach the PCB from the top cover of the joystick
![](https://github.com/elpuri/usb-joystick/blob/master/photos/3.jpg?raw=true)
- - -

#### Step 4: Marvel the operating principle of the hi-tech control device
So in all it's glory the story is pretty much such that the conductive pads (part of the actual stick assembly)
press down on the squiggly patterns and short the circuit connecting one of the colored wires to the black one
(the left most pad). We will be connecting the black wire to the ground and the rest of the wires to the I/O pins
of the micro controller. The pins have internal pull-ups which means that they will sense '1' (the operating voltage)
when the circuit connected to the pin is open. When the squiggly thing is shorted the pin gets shorted to the ground
and it senses '0'. The internal pull-up resistor limits the current so things don't fry. Awesome.

![](https://github.com/elpuri/usb-joystick/blob/master/photos/4.jpg?raw=true)
- - -

#### Step 5: Prep the patient for surgery
Liberate the wires from the opression of the DB-9 connector, strip, twist and prepare to solder them to the
F port pins of the AVR.

![](https://github.com/elpuri/usb-joystick/blob/master/photos/5.jpg?raw=true)
- - - 

#### Step 6: Solder and trim.
![](https://github.com/elpuri/usb-joystick/blob/master/photos/6.jpg?raw=true)
- - - 

#### Step 7: Reattach the PCB to the top cover
![](https://github.com/elpuri/usb-joystick/blob/master/photos/7.jpg?raw=true)
- - -

#### Step 8: Find a cozy place for the Teensy to sit in
Also now would be a perfect time to flash the firmware on the chip, because you need to be able to press that tiny button to do so.
![](https://github.com/elpuri/usb-joystick/blob/master/photos/8.jpg?raw=true)
- - -

#### Step 9: Congratulate yourself on a job well done and indulge in emulated classic gaming
Turns out the strain relief on the random USB cable I picked is a snug fit with the hole in the casing of the joystick. Perfect. 

![](https://github.com/elpuri/usb-joystick/blob/master/photos/9.jpg?raw=true)
