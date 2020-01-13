# Python 3.3.3 and 2.7.6
# python fo.py

from threading import Thread

i = 0

def incrementingFunction():
    global i
    for j in range(1000000):
        i = i + 1

def decrementingFunction():
    global i
    for j in range(1000000):
        i = i - 1

def main():
    global i
    "This works basically for the same reasons as the two others"

    incrementing = Thread(target = incrementingFunction, args = (),)
    decrementing = Thread(target = decrementingFunction, args = (),)
    
    incrementing.start()
    incrementing.join()

    decrementing.start()
    decrementing.join(100)    
    
    print("The magic number is %d" % (i))


main()
