import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setup(40, GPIO.OUT) # Ultra Trig pin
GPIO.setup(38, GPIO.IN) # Ultra Echo pin
GPIO.setup(3, GPIO.OUT) # Buzzer pin

try:
    while True:
        GPIO.output(40, False)
        time.sleep(0.2)
        GPIO.output(40, True)
        time.sleep(0.00001)
        GPIO.output(40, False)
        while GPIO.input(38) == 0:
            pulse_start = time.time()
        while GPIO.input(38) == 1:
            pulse_end = time.time()
    
        pulse_duration = pulse_end - pulse_start
        distance=pulse_duration*17150
        distance=round(distance,2)
        time.sleep(0.00001)
        
    
        if distance <= 20:
            GPIO.output(3, True)
            print("Jaldi Waha Se Hato")
        else:
            GPIO.output(3, False)

except KeyboardInterrupt:
    GPIO.cleanup()