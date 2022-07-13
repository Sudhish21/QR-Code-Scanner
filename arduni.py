import serial
import time
import numpy as np
from PIL import Image

image = Image.open("image_280.bmp")
array_im = np.array(image, dtype=int)
array_im = array_im.flatten()


scaled_arr = []
k = 0
m = 8
for i in range(9800):
    imd = ''
    for i in range(k, m):
        imd += str(array_im[i])

    k+=8
    m+=8
    scaled_arr.append(imd)

print(len(scaled_arr))

arduino = serial.Serial(port='COM6', baudrate=9600, timeout=1)


def write_read(x):
    arduino.write(bytes(x,'utf-8'))
    time.sleep(0.005)


# inp = input("Enter a String: ")  # Enter 5 as an input to send a bit string
# if inp == 'y':
for val in scaled_arr:
    write_read(val)
