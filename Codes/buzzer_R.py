import RPi.GPIO as GPIO
from time import sleep
#Disable warnings (optional)
GPIO.setwarnings(False)
#Select GPIO mode
GPIO.setmode(GPIO.BOARD)
#Set buzzer - pin 16 as output on board pin diagram
buzzer=16
GPIO.setup(buzzer,GPIO.OUT)
#Run forever loop
try:
    while True:
        GPIO.output(buzzer,GPIO.HIGH)
        print ("Beep")
        sleep(0.5) # Delay in seconds
        GPIO.output(buzzer,GPIO.LOW)
        print ("No Beep")
        sleep(0.5)
        
except KeyboardInterrupt:
    GPIO.cleanup()
