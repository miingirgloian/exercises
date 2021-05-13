#!/usr/bin/python
# Number guessing

value = 25
running = True

while running:
    num = int(raw_input('Input a number:'))
    if num > value:
        print 'Too large!'
    elif num < value:
        print 'Too small!'
    else:
        print 'Congratulations,you guessed it!'
        running = False
else:
    print 'Loop is over.'

print 'Done.'
