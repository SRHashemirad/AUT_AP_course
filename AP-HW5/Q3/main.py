# -*- coding: utf-8 -*-
"""
Created on Thu May 30 01:20:48 2019

@author: SeyedReza
"""

A0 = dict(zip(('a', 'b', 'c', 'd', 'e'), ('1', '2', '3', '4', '5')))
A1 = range(10)
A2 = [i for i in A1 if str(i) in A0.values()]
A3 = sorted(int(A0[i]) for i in A0)
A4 = [[i, i*i] for i in A1]

my_keys = list(A0.keys())

for i in A1:
    ### A1 ###
    print(f'iter = {i}', end = '\t')
    
    ### A0 ###
    if str(i) in A0.values():
        print (f'{my_keys[i-1]}: {A0[my_keys[i-1]]}', end = '\t')
    
    ### A2 ###
    if i in A2:
        print(f'A2 list data is: {i}', end = '\t')
    
    ### A3 ###
    if i in A3:
        print(f'A3 list data is: {i}', end = '\t')
        
    ### A4 ###
    if i in A4[i]:
         print(f'A4 list data is: {A4[i][0]} and {A4[i][1]}')