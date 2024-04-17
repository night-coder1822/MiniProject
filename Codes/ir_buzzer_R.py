import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)

GPIO.setup(3, GPIO.IN)
GPIO.setup(5, GPIO.OUT)

try:
    while True:
        val = GPIO.input(3)
        if val == 1:
            #buzzer off
            GPIO.output(5, False)
        else:
            #buzzer on
            GPIO.output(5, True)
        print(val)
        
except KeyboardInterrupt:
    GPIO.cleanup()