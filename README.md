# Traffic Light Simulator

## Description
This project simulates a traffic light system using a finite state machine (FSM) in C.

I implemented this project to be cross platform, supporting both Windows and Linux by using conditional compilation (#ifdef) to handle system specific functions such as "sleep" and screen clearing ("cls" / "clear").

## Features
- Three states: RED, GREEN and YELLOW
- Time-based transitions
- Continuous simulation loop
- This simulator includes a pedestrian crossing feature. When the user presses **P**, a request is registered and the system transitions to a pedestrian state at the appropriate time, allowing safe crossing.

## How to Run
gcc traffic-simulator.c -o traffic

./traffic
