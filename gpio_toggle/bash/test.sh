#!/bin/bash

while (true)
do
gpioset gpiochip4 26=0
sleep 1
gpioset gpiochip4 26=1
sleep 1
done
