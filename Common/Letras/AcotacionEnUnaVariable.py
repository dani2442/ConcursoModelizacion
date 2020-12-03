from mykernel import *

def n(letra,m):
    if(m==0):
        return 0
    elif(m==2):
        n0=n(letra,m-1)
        max=0
        min=10
        for i in range(10,20):
            compara=numero_a_letras((10**m)*i).count(letra)
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        n1=(max-min)
        max=0
        min=100
        for i in range(2,10):
            compara=numero_a_letras((10)*i).count(letra)
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        if(n1>(max-min)+n0):
            return n1+1
        return max-min+n0+1
    else:
        n0=n(letra,m-1)
        max=0
        min=10**m
        for i in range(10):
            compara=numero_a_letras((10**(m-1))*i).count(letra)
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        return (max-min)+n0+1
        