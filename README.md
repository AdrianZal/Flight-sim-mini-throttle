# This throttle is designed to be portable and fit next to the keyboard on the desk and costs almost nothing if you own a 3D printer

## What you need to make one
- Thin hookup wire
- 12 × Kailh mechanical switches (regular size)
- 1 × Waveshare RP2040-Tiny microcontroller
- 1 × DFRobot DFR0053 potentiometer
- 10 × 2mm screws or glue
## Assembly
- 3D print the case and keycaps from the 3dModels folder.
- Install the switches.
- Install the potentiometer and screw it in.
- Wire the switches and potentiometer to the RP2040-Tiny.
- Flash the firmware from the CodeForArduinoIDE folder.
- Update the BUTTON_PINS array in the code to match your wiring.

## Notes
- The case is modeled specifically for the **Waveshare RP2040-Tiny** and **DFRobot DFR0053**.  
- Printing recommendation: PLA, 0.2 mm layer height.

![miniThrottle](https://github.com/user-attachments/assets/4515d31d-3a41-4808-95ef-1713ce090da2)
