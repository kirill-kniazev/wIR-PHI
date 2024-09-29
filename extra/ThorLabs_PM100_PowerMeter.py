import serial
import time
from time import sleep


class power_meter():
    def __init__(self, serial_port = '1', baudrate = 38400, timeout = 0.5):
        # open and initialize port
        self.ser = serial.Serial(port="COM"+serial_port, baudrate = baudrate, timeout=timeout,  bytesize=8, parity='N', stopbits=1)
        self.ser.flushInput()

        # check if port is open
        if self.ser.isOpen():
            print(self.ser.name + " for power meter is open")


    def read_value(self):
        cmd_str = ':POWER?'
        cmd = bytes(cmd_str,'UTF-8')
        self.ser.write(cmd)#+'\n') # query the last power value in Watts
        try:
            received_string = self.ser.read(1024)
            self.data = received_string
        except serial.SerialException:
            print("SerialException...")
            received_string = self.ser.read(1024)
            print (received_string)
            self.data = float(received_string)
        self.ser.flushInput()
        self.ser.flushOutput()


    def disconnect(self):
        self.ser.flushInput()
        self.ser.flushOutput()
        if self.ser: self.ser.close()
        print ("Lockin disconnected.")

    #def time_constant(self,target):
    #    self.ser.write('OFLT'+str(target)+'\n')

# The following is used if we want to use this script as a standalone to read the lockin. It is not implemented if this module is imported in another script.
if __name__ == '__main__':
    meter = power_meter(serial_port='1')
    #meter.read_value()
    #data = meter.data
    #print data
    #lockin.time_constant(7)  # 7 is 30ms; 8 is 100 ms

    for i in range(20):
        t1 = time.time()
        sleep(0.03)
        t2 = time.time()
        meter.read_value()
        #sleep(0.03)
        t3 = time.time()


        try:
            print (i, float(meter.data))
        except ValueError:
            print (i, 'Value error. Lockin reading = ', meter.data)

    print ("Disconnecting...")
    meter.disconnect()
