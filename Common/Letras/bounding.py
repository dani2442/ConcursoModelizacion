from mykernel import conteo_numero

def cota(letras="abcdefghijklmnñopqrstuvwxyz"):
    minimum,maximum=conteo_numero(0,letras),conteo_numero(0,letras)
    for i in range(1000000):
        vec=conteo_numero(i,letras)
        for j in vec:
            if minimum[j]>vec[j]:
                minimum[j]=vec[j]
            if maximum[j]<vec[j]:
                maximum[j]=vec[j]
    return maximum,minimum

#print(cota())