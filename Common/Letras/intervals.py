import numpy as np
from mykernel import conteo_numero2,conteos_mensaje2,firmar_mensaje_fija

maximum_global={'a': 10, 'b': 0, 'c': 13, 'd': 4, 'e': 15, 'f': 0, 'g': 0, 'h': 6, 'i': 11, 'j': 0, 'k': 0, 'l': 1, 'm': 1, 'n': 10, 'ñ': 0, 'o': 10, 'p': 0, 'q': 4, 'r': 6, 's': 15, 't': 10, 'u': 6, 'v': 6, 'w': 0, 'x': 0, 'y': 2, 'z': 2}
minimum_global= {'a': 0, 'b': 0, 'c': 0, 'd': 0, 'e': 0, 'f': 0, 'g': 0, 'h': 0, 'i': 0, 'j': 0, 'k': 0, 'l': 0, 'm': 0, 'n': 0, 'ñ': 0, 'o': 0, 'p': 0, 'q': 0, 'r': 0, 's': 0, 't': 0, 'u': 0, 'v': 0, 'w': 0, 'x': 0, 'y': 0, 'z': 0}

mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
#mensaje_global=""

def calculate_maximum_minimum(a,b,letras="abcdefghijklmnñopqrstuvwxyz"):
    minimum,maximum=[999]*len(letras),[-1]*len(letras)
    for i in range(a,b+1):
        vec=conteo_numero2(i,letras)
        for j in range(len(letras)):
            if minimum[j]>vec[j]:
                minimum[j]=vec[j]
            if maximum[j]<vec[j]:
                maximum[j]=vec[j]
    return np.array(maximum),np.array(minimum)


def reduccion_intervalos(mensaje,letras="abcdefghijklmnñopqrstuvwxyz"):
    longitud=len(letras)
    kappa=conteos_mensaje2(firmar_mensaje_fija(mensaje,letras),letras)
    
    intervals=[]
    for i in range(longitud):
        intervals+=[[kappa[i]+longitud*minimum_global[letras[i]],kappa[i]+longitud*maximum_global[letras[i]]]]
    print(intervals)
    for i in range(10):
        new_maximum,new_minimum=np.zeros(longitud,dtype=int),np.zeros(longitud,dtype=int)
        for j in intervals:
            max_inter,min_inter=calculate_maximum_minimum(j[0],j[1],letras)
            new_maximum+=max_inter
            new_minimum+=min_inter
        intervals=[]
        for j in range(longitud):
            intervals+=[[kappa[j]+new_minimum[j],kappa[j]+new_maximum[j]]]
    return intervals

print("\nIntervalo previo: ")
sol=reduccion_intervalos(mensaje_global)
print("\nSolucion Reduccion: \n"+str(sol))