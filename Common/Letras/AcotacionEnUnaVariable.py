from mykernel import *
from math import log

def n(letra,m):
    if(m==0):
        return 0
    elif(m==2):
        n0=n(letra,m-1)
        max=0
        min=10
        for i in range(10,20):
            compara=conteo_numero(i,letra)[letra]
            
            if(letra=='i' and i>15 and i<30):compara+=1
            
            if(compara>max):
                max=compara
            if(compara<min):
                min=compara
        for i in range(2,10):
            compara=conteo_numero((10)*i,letra)[letra]
            
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
            compara=conteo_numero((10**(m-1))*i,letra)[letra]
            
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

def resolver(mensaje, letra):
    n0=firmar_mensaje_fija(estandarizar_mensaje(mensaje),'e').count(letra)
    n1=n0+n(letra, int(log(n0,10)+1) )
    cota=n(letra,int(log(n1,10)+1))
    for i in range(cota+1):
        if(-i+conteo_numero(n0+i)[letra]==0):
            fin='ces'
            if(n0+i==1):fin='z'
            return f"En este mensaje aparece {n0+i} ve{fin} la letra e"
    return "No hay solucion"