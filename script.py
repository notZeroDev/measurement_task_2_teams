import serial
import time

# configuration variables
serial_port = 'COM5'  # Change this to your port
baud_rate = 115200 # change this to your Serial port
i = 0
TRIES = 20

# Create a serial connection
try:
    ser = serial.Serial(serial_port, baud_rate)
    time.sleep(2)  # Wait for the connection to establish
except serial.SerialException:
    print(f"Could not open serial port {serial_port}. Please check the port.")
    exit()

def output(line):
    global i, file, TRIES
    mode, value = line.split(); # convert the line into mode and value
    if mode == 's':
        # tries data
        print('/'*50)
        TRIES = int(value)
        print(f'You Will Read {TRIES} Tries')
        print('To cahnge the number change the LOOPCOUNT variable int the first line in arduino sketch to the desird number')
    elif mode == 't':
        # time data
        print('/'*50)
        print(f'The Cycle Time will be: {value} millis')
        print(f'To Change The Time of Eacg Cycle Change the CYCLE_TIME_MILLIS on The second Line')
        print('/'*50)
    elif mode == 'c':
        # calibraion mode
        print(f'Calibrating: {value} cm')
    elif mode == 'r':
        # recording mode
        if i == 0:
            file = open('results.csv', 'w')
            file.write("i,value\n")
        i += 1
        print(f'{i} Recorded: {value} cm')
        file.write(f"{i},{value}\n")

        # ending of recording data and close the file
        if i == TRIES:
            file.close()
            print('results.csv is created')
            print('to reset the file press reset button on the board')
            
# Function to read data from the serial port
def read_serial():
    global file
    while True:
        try:
            if ser.in_waiting > 0:  # Check if data is available to read
                line = ser.readline().decode('utf-8').rstrip()  # Read a line and decode it
                output(line)
        except KeyboardInterrupt:
            print("Exiting...")
            file.close()
            break
        except Exception as e:
            print(f"Error: {e}")
# Call the function
read_serial()

# Close the serial connection
ser.close()
