import numpy as np
from mykernel import *
import pickle

def array_to_string(arr):
    s=""
    for i in arr:
        s+=str(i)+","
    return s

#Genera casos de prueba como se indica en el apartado 4 y los guarda en el documento dataset.csv
def create_dataset(size=100):
    np.random.seed(1)
    letras="abcdefghijklmnñopqrstuvwxyz"
    with open("dataset.csv","w") as f:
        for _ in range(size):
            sol=np.random.randint(405,900,len(letras))
            numeros=np.zeros(len(letras),dtype=int)
            for i in range(len(letras)):
                numeros+=conteo_numero2(sol[i],letras)
            kappa=sol-numeros
            f.write("{}\t{}\n".format(array_to_string(kappa),array_to_string(sol)))

#Lee dataset.csv para devolver un array de diccionarios con claves kappa (array con numero de apariciones de cada letra en la parte fija) y solution (array de numeros que indican el numero de veces que aparecen las letras en el mensaje y postdata)
def load_dataset(path="dataset.csv"):
    f=open(path)
    f2=f.readlines()
    dataset=[[]]*len(f2)
    for i in range(len(f2)):
        [kappa,solution]=f2[i].split('\t')
        dataset[i]={'kappa':eval(kappa),'solution':eval(solution)}
    f.close()
    return dataset


#create_dataset()
#dataset=load_dataset()