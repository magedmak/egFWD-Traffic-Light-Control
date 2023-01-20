![Cover](https://github.com/magedmak/egFWD-Traffic-Light-Control/blob/61e3cadeb2547706e1f7a718cb778d279314bdab/Photos/Cover.png)

# On-demand Traffic Light Control
This repository contains the source code and simulation for an **on-demand traffic light control** program. The program simulates a traffic light for cars and pedestrians using LEDs and a button. The program uses 6 LEDs for cars and pedestrians, and uses a timer to control the duration of the different light states (green, yellow, red). The program also has a button that allows the user to switch between normal mode, where the traffic light follows a normal sequence, and pedestrian mode, where the traffic light sequence is adjusted to allow pedestrians to cross the road.

## System Design
The system design of the on-demand traffic light control system is based on an ATMEGA32a microcontroller and utilizes LEDs and a button to simulate a traffic light for cars and pedestrians. The system uses different LEDs for cars and pedestrians, and uses a timer to control the duration of the different light states (green, yellow, red).

![System Circuit](https://github.com/magedmak/egFWD-Traffic-Light-Control/blob/74718f8098579e1568bebd87f2c586a9fd1063c4/Photos/Circuit.SVG)

The system includes several components:
-	6 LEDs: The system uses different LEDs to indicate the different traffic light states for cars and pedestrians. Green LEDs indicate a green light, yellow LEDs indicate a yellow light, and red LEDs indicate a red light.
-	1 Button: The system uses a button to switch between normal mode and pedestrian mode connected to PIN 2 in PORTD.
-	1 Timer: The system uses a timer 0 to control the duration of the different light states (generate 5 seconds delay).
-	1 External Interrupt: The system uses INT0 to sense a rising edge and switch between normal mode and pedestrian mode.


## Features
- Simulates a traffic light for cars and pedestrians using LEDs
- Uses a button to switch between normal mode and pedestrian mode
- Uses a timer to control the duration of the different light states
- Provides flexibility in handling different traffic scenarios
- Can be controlled remotely via a button

## Limitations
- The system is designed to control traffic lights using LEDs and a button, so it may not be suitable for larger scale traffic control systems.
- The system uses a timer to control the duration of the different light states, so it may not be able to handle sudden changes in traffic conditions.
- The system is dependent on the microcontroller platform and the availability of specific ports and pins, so it may not be easily portable to other platforms.
- The system uses a button to switch between normal mode and pedestrian mode, so it may not be suitable for situations where remote control is required.
- The system uses a fixed timer delay of 5 seconds, so it may not be able to handle different traffic scenarios that require different delay times.

## System Layers
The on-demand traffic light control program uses a layered architecture to separate the different tasks and functions of the system. The architecture is divided into three main layers: the application layer (APP), the electronic control unit abstraction layer (ECUAL), and the microcontroller abstraction layer (MCAL).

The application layer is the highest layer in the architecture and it contains the main application code. This layer handles the control of the traffic light sequence, the switch between normal mode and pedestrian mode, and the integration of the different functions and data structures. 

The electronic control unit abstraction layer is the middle layer and it contains the code for the different drivers such as the LED driver, button driver. This layer handles the communication between the application layer and the microcontroller abstraction layer. 

The microcontroller abstraction layer is the lowest layer and it contains the code for the different drivers such as general purpose intput/output driver (GPIO), external interrupt driver (EXTI), and timer driver. This layer handles the communication between the ECU layer and the physical hardware.
The layered architecture allows for a clear separation of concerns and makes it easier to develop, test, and maintain the code. It also improves the flexibility of the system, as it can be easily ported to other microcontroller platforms by only modifying the hardware layer. Furthermore, the layered architecture allows for the easy integration of new features or functions, as they can be added to the appropriate layer without affecting the other layers.

## System Flowchart
![Flowchart](https://github.com/magedmak/egFWD-Traffic-Light-Control/blob/61e3cadeb2547706e1f7a718cb778d279314bdab/Photos/Flowchart.png)

## Timer Configuaration
In order to change the 0.5 second delay, change the initial value and number of overflows in TMR0_Config.h file.
The calculations were as following to generate 0.5 second delay:

![Calculations](https://github.com/magedmak/egFWD-Traffic-Light-Control/blob/fcb74d4e8cac2a6d854619e97d58b7baeb2f1748/Photos/Calculations.png)

## Project Report
A detailed report about the on-demand traffic light control system is provided in this section. The report includes the following sections:
- **System Design and Description**: This section provides a detailed explanation of the overall system design and functionality, including the purpose of the system, the components used, and the different modes of operation.
- **Flowchart**: This section includes a flowchart that illustrates the traffic light sequence in both normal mode and pedestrian mode.
- **System Circuit**: This section provides a detailed diagram of the circuit connections for the LEDs, button, and timer, as well as any additional components used.
- **System Constraints**: This section discusses the limitations of the system and the potential challenges that users may encounter when using the system.
- **Solution Explorer**: This section includes a screenshot of the solution explorer from Microship Studio showing the folders structure of the project. 
- **Future Development**: This section provides suggestions for future development and improvements to the system, including additional features and functionality.

You can read it from here: [On-demand Traffic Light Control.pdf](https://github.com/magedmak/egFWD-Traffic-Light-Control/blob/3e7bf41ce25cd89bc76b484c1547232a111d0319/On-demand%20Traffic%20Light%20Control.pdf)

The report provides an in-depth understanding of the system design, how it works, how to connect the circuit and how to adapt to different traffic scenarios. It also provides insight into the limitations of the system, and potential areas for future development. This report is useful for users who want a more comprehensive understanding of the system, and it can be used as a reference guide when working with the system.

## Demo Video
To better understand the system design and functionality, please refer to the following video which provides an in-depth explanation of the system design, flowchart, circuit, main code, test cases, and different traffic scenarios. The video covers the following topics:

- System description and overall functionality
- Flowchart of the traffic light sequence in normal mode and pedestrian mode
- Circuit diagram and connections of the LEDs, button, and timer
- Walk-through of the main code and different functions
- Test cases and different traffic scenarios with the system

You can see it from here: [On-demand Traffic Light Control.mp4](https://drive.google.com/file/d/1r9sFSSS46DD74uAX_9iSsZO1Jv5bzVvG/view?usp=sharing)

This video will provide a more visual understanding of the system and how it works, and it will help users to better understand the system design, how to connect the circuit, how to run the code, how to test it and how it adapts to different traffic scenarios.

## Conclusion
The on-demand traffic light control program provides a simple and flexible solution for controlling traffic lights. The program can be easily configured to work with different microcontrollers.

## Copyright
This project was developed as part of the egFWD scholarship program. Copyright (c) 2023 Maged Magdy. All rights reserved.

## Contact
For any inquiries or questions about the application, please contact the author at magedmagdy.engr@gmail.com.
