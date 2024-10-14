# measurement_task_2_teams
## Installation
1. install python
2. install pip package manger
3. insatll pyserial
``` 
pip install pyserial
```
## circuit connections

You can see the connection on [Tinkercad](https://www.tinkercad.com/things/fjgFFRaHzuD-measuretask2teams)

![Circuit](https://github.com/user-attachments/assets/2fce0fbf-5783-41cb-9eba-a086e89594ba)
### notice
* the red led will be high to indicate the the board will  start callibration so run [script.py](https://github.com/notZeroDev/measurement_task_2_teams/blob/main/script.py) and use it's output as serial monitor
* once the button is clicked the led will start blinking and on each blynk a row of data is written
* when the led stops blinking it indicates to the end of program and to reset the file again press reset button on the arduino board


## configuration variables
**python:**
  ```python
  serial_port = 'COM5'  # Change this to your port
  ```
 🔴🔴 You must change the value of ```serial_port``` variable to the port that is the board connected to
  
**arduino code:**
  ```cpp
  #define LOOP_COUNT 1000
  #define CYCLE_TIME_MILLIS 100
  ```
  in the [task_2.ino](https://github.com/notZeroDev/measurement_task_2_teams/blob/main/task_2.ino) file you will find the first two defines is to control the skitch :
  1. ```LOOP_COUNT``` to control how many row in results file will be generated
  2. ```CYCLE_TIME_MILLIS``` to control how long the cylce will last in milliseconds
