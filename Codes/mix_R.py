import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Set pin 32 as an output, and set servo1 as pin 32 as PWM
GPIO.setup(32, GPIO.OUT)
servo1 = GPIO.PWM(32, 50) # Note 32 is pin, 50 = 50Hz pulse

# Define the ultrasonic sensor pins
TRIG = 40
ECHO = 38

# Set up the ultrasonic sensor pins
GPIO.setup(TRIG, GPIO.OUT)
GPIO.setup(ECHO, GPIO.IN)

# Start PWM running, but with value of 0 (pulse off)
servo1.start(0)

def get_distance():
    # Send a pulse on the TRIG pin
    GPIO.output(TRIG, True)
    time.sleep(0.00001)
    GPIO.output(TRIG, False)

    # While the ECHO pin is low, record the start time
    while GPIO.input(ECHO) == 0:
        start_time = time.time()

    # While the ECHO pin is high, record the end time
    while GPIO.input(ECHO) == 1:
        end_time = time.time()

    # Calculate the distance
    distance = (end_time - start_time) * 34300 / 2
    return distance

try:
    while True:
        distance = get_distance()
        print("Distance: %0.1f cm" % distance)

        # If an obstacle is detected, rotate the servo
        if distance < 20:
            servo1.ChangeDutyCycle(7)
        else:
            servo1.ChangeDutyCycle(0)

        time.sleep(0.1)

except KeyboardInterrupt:
    print("Measurement stopped by user")
    servo1.stop()
    GPIO.cleanup()