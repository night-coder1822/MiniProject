from gpiozero import Servo
from time import sleep

# Connect the signal wire of the servo to GPIO pin 18 (BCM numbering)
servo = Servo(18)

while True:
    # Move the servo to the minimum angle (usually -90 degrees)
    servo.min()
    print("Set to minimum angle")
    sleep(1)
    
    # Move the servo to the center position (usually 0 degrees)
    servo.mid()
    print("Set to center position")
    sleep(1)
    
    # Move the servo to the maximum angle (usually +90 degrees)
    servo.max()
    print("Set to maximum angle")
    sleep(1)
