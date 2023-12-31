import serial
import time
from utils import recvFromArduino, sendToArduino, waitForArduino, list_to_bytearray, bytearray_to_int

if __name__ == "__main__":
    port_name = "/dev/ttyACM1"
    baud_rate = 9600
    serial_port = serial.Serial(port_name, baud_rate)
    print(f"Serial port opened {port_name} with baud rate {baud_rate}")

    start_marker = 60
    end_marker = 62
    
    waitForArduino(serial_port)
    
    send_data = b"<test>"
    
    mode = "w" # or "r"
    
    if mode == "w":
        print("Sending data to Arduino")
        sendToArduino(serial_port, send_data)
        print("Data sent")
        mode = "r"
        
    if mode == "r":
        while True:
            if serial_port.in_waiting > 0:
                # print("Available byte count: ", serial_port.in_waiting)
                data, byte_received = recvFromArduino(serial_port, start_marker, end_marker)
                breakpoint()
                result = bytearray_to_int(list_to_bytearray(data))
                print("Message received:", result)
                
                if result == 3152:
                    break
                    
    
