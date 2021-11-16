import serial
import time

#Constant Resources
secondsForTimeout = 0.1


def main():
    print("Program Start")
    #Note, the name of the USB connection assigned by the pi may be different
    with serial.Serial("/dev/ttyUSB0", 9600, timeout = 1) as arduino:
        time.sleep(secondsForTimeout)
        
        if arduino.isOpen():
            print("Connection Established")

            while True:
                arduino.write(b"True")
                time.sleep(8)
                arduino.write(b"False")
                time.sleep(8)

if __name__ == "__main__":
    main()