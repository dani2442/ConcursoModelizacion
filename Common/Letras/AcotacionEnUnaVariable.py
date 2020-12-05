from mykernel import *

def n(letra,m):
    if(m==0):
        return 0
    elif(m==2):
        n0=n(letra,m-1)
        max=0
        min=10
        for i in range(10,20):
            compara=numero_a_letras(i).count(letra)
            
            if(letra=='i' and i>15 and i<30):compara+=1
            
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        for i in range(2,10):
            compara=numero_a_letras((10)*i).count(letra)
            
            if(letra=='e' and i>2 and i<3):compara-=1
            if(letra=='i' and i>2 and i<3):compara+=1
            if(letra=='y' and i>3):compara+=1
            
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        return max-min+n0
    else:
        n0=n(letra,m-1)
        max=0
        min=10**m
        for i in range(1,10):
            compara=numero_a_letras((10**(m-1))*i).count(letra)
            
            if( (letra=='t' or letra=='o') and i==1):compara+=1
            
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        return (max-min)+n0
    
def cota(m=6, letras='abcdefghijklmnñopqrstuvwxyz'):
    out=[]
    for i in letras:
        out.append((i,n(i,m)))
    return out
