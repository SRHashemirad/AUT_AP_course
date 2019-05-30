# -*- coding: utf-8 -*-
"""
Created on Thu May 30 02:43:04 2019

@author: SeyedReza
"""

import os

def create_dir(name, address):
    dirAddress = os.path.abspath(address)
    dirPath = os.path.join(dirAddress, name)
    print(f'You have entered -> {dirPath}')
    if (os.path.exists(dirPath)):
        print("This directory already exists... try another!")
    else:    
        os.mkdir(dirPath)
        print("The directory created successfully")
 
    
def create_file(name, address):
    fileAddress = os.path.abspath(address)
    if (os.path.exists(fileAddress)):    
        filePath = os.path.join(fileAddress, name)
        if (os.path.isfile(filePath)):
            print("This file already exists... try another!")
        else:    
            f = open(filePath, 'w')
            print("The file created successfully")
            f.close()
    else:
        print("Directory not found")
        
def delete(name, address):
    fileAddress = os.path.abspath(address)
    if (os.path.exists(fileAddress)):    
        filePath = os.path.join(fileAddress, name)
        if (os.path.isfile(filePath)):
            inp = input(f"Are you sure?? (to remove {filePath}) (y/n)")
            if inp == 'y':
                os.remove(filePath)
                print("The file was deleted successfully")
            elif inp == 'n':
                print("The file was not deleted")
            else:
                print("Sorry! Only 'y' or 'n'!")
        else:    
            print("File not found")
    else:
        print("Directory not found")

def find(name, address):
    dirAddress = os.path.abspath(address)
    #### os.walker ####
    files = []

    # r=root, d=directories, f = files
    for r, d, f in os.walk(dirAddress):
        for file in f:
            if name in file:
               files.append(os.path.join(r, file)) 

    for f in files:
        print(f)

    return files
    
    
if __name__=='__main__':
    inp = input("""What do you want to do?
                CD (create dir)
                CF (create file)
                D (delete file)
                F (fine file)\n""")
    print(f'You have entered -> {inp}')
    name = input("Enter name: ")
    address = input("Enter address: ")
    
    if inp == 'CD':
        create_dir(name, address)
    elif inp == 'CF':
        create_file(name, address)
    elif inp == 'D':
        delete(name, address)
    elif inp == 'F':
        my_files = find(name, address)
        print(my_files)
        print(f'Files count is: {len(my_files)}')
    else:
        print("Sorry! Only 'CD' or 'CF' or 'D' or 'F'!")
    
    
    #create_dir('sreza',"E:/")
    #create_file('hi_reza.txt', 'E:/sreza')
    #delete('hi_reza.txt', 'E:/sreza')
    #my_files = find('.hpp', 'E:/')
    #print(my_files)
    #print(f'Files count is: {len(my_files)}')