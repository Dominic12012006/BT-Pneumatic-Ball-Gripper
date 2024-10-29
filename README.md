# BT-Pneumatic-Ball-Gripper
# Description
A Bluetooth controlled pneumatic system implemented to hold and lift balls of multiple sizes. The mechanism involves of 2 degrees of freedom: one for the clamping motion to grip the ball and the other to move the ball up and down.

# Construction
The mechanism involves of a 2 jaw gripper and a vertical actuator. The gripper consists of 1 stationary jaw and 1 moving jaw attached to a linear joint. The motion of this linear joint is dependant on a double acting pneumatic cylinder. This creates a opening and closing motion for the claw to pick up balls using. The Vertical actuator consists of a double acting pneumatic cylinder  connected to the top of the claw such that, when the piston is retracted, the claw is in the air.
Both pneumatic cylinders are controlled using 5/2 DCVs that are controlled electronically using solenoids and relays attached to a microcontroller board. These are in turn controlled using bluetooth signals sent from a Bluetooth terminal app downloaded on a mobile phone ("BLUETOOTH ELECTRONICS") to a HC-05 bluetooth module attached to the microcontroller board.

# Working
The Bluetooth terminal app has a remote interface with 4 buttons, namely to "Open claw", "Close claw", "Move up", "Move down". These are used to then grip up the ball and the move it up or down, as required.

# Features
- Bluetooth connectivity for remote control
- Multi-size ball handling capability
- 2 degrees of freedom

# Technologies Used
- Arduino IDE(Arduino UNO R3) / Thonny(Raspberry pi Pico)
- Bluetooth module (HC-05)
- Pneumatic components

# Languages used
- Embedded C/Micropython

# Components:
- Microcontroller (Arduino UNO R3/ Raspberry Pi Pico W)
- Bluetooth Module (HC-05)
- Dotted Solder Board
- 3S battery (12V)
- 2 x 5/2 Direction Control Valves
- 4 x Solenoids
- 2 x double acting pneumatic pistons
- 2 Channel Relay Module
- SPST Switch
- Buck Converter (12V -> 8.3V)
- Air Compressor
- Linear Joint
- Wooden Boards
