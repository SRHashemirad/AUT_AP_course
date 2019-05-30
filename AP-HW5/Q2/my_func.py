def my_func(name, phone, *args, **keywords):
    print (f'The name is {name} and the phone is {phone}!')
    
    for i in range(len(args)):
        print (f'arg{i} = {args[i]}')
        
    for key in keywords:
        print (f'{key}: {keywords[key]}')
        

if (__name__=='__main__'):
    my_func("SReza", 9353624314, 123, 321, 456, 654,
            Familiy = "Hashemirad",
            City = "Tehran",
            University = "AUT")