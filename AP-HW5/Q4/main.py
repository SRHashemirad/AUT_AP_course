# -*- coding: utf-8 -*-
"""
Created on Fri May 31 20:08:48 2019

@author: SeyedReza
"""
from random import random as rand
from math import pi as myPi


def isInCircle(x, y):
    return x**2 + y**2 < 1


def piCal(num):
    inCir = 0
    outCir = 0
    for i in range(num):
        if isInCircle(rand(), rand()):
            inCir += 1
        else:
            outCir += 1
    
    result = 4*inCir/(outCir + inCir)
    return result


def find():
    i = 1
    err = 1
    
    while (err > 0.01):
        estimatedPi = piCal(i)
        err = abs(estimatedPi - myPi)
        i += 1

    return estimatedPi


def meanFilter():
    count = int(input("Enter number of find() executions: "))
    s = 0
    for i in range(count):
        s += find()
    
    return round(s/count,5)

if __name__ == '__main__':
    
    result = meanFilter()
    print(f"Pi is around: {result}")
    
    #i = find()
    #print (i)
    
    #res = piCal(100)
    #print(f"Pi is around: {res}")