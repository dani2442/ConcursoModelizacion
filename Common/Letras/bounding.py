from mykernel import conteo_numero2,conteo_numero
import numpy as np

# Calcula la cota superior e inferior de f
def cota_f(letras="abcdefghijklmnñopqrstuvwxyz"):
    minimum=conteo_numero(0,letras)
    maximum=minimum
    for i in range(1000000):
        vec=conteo_numero(i,letras)
        for j in vec:
            if minimum[j]>vec[j]:
                minimum[j]=vec[j]
            if maximum[j]<vec[j]:
                maximum[j]=vec[j]
    return maximum,minimum

# Calcula la cota superior e inferior de |f(x+1)-f(x)|
def cota_f_prima(letras="abcdefghijklmnñopqrstuvwxyz"):
    minimum=np.absolute(conteo_numero2(1,letras)-conteo_numero2(0,letras))
    maximum=np.copy(minimum)
    vec_prev=conteo_numero2(1,letras)
    for i in range(2,1000000):
        temp=conteo_numero2(i,letras)
        vec=np.absolute(temp-vec_prev)
        for j in range(len(vec)):
            if minimum[j]>vec[j]:
                minimum[j]=vec[j]
            if maximum[j]<vec[j]:
                maximum[j]=vec[j]
        vec_prev=temp
    return maximum,minimum

#print(cota_f())
#print(cota_f_prima())