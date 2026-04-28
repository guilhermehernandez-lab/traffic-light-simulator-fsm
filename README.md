# Traffic Light Simulator

## Description
This project simulates a traffic light system using a finite state machine (FSM) in C.
I implemented this project to be cross platform, supporting both Windows and Linux by using conditional compilation (#ifdef) to handle system specific functions such as "sleep" and screen clearing ("cls" / "clear").
## Features
- Three states: RED, GREEN and YELLOW
- Time-based transitions
- Continuous simulation loop

## How to Run
gcc traffic-simulator.c -o traffic

./traffic
