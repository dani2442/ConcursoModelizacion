import numpy as np
from mykernel import *
import pickle

def array_to_string(arr):
    s=""
    for i in arr:
        s+=str(i)+","
    return s

def create_dataset(size=10000):
    np.random.seed(1)
    letras="abcdefghijklmnñopqrstuvwxyz"
    with open("dataset.csv","w") as f:
        for _ in range(size):
            sol=np.random.randint(405,900000,len(letras))
            numeros=np.zeros(len(letras),dtype=int)
            for i in range(len(letras)):
                numeros+=conteo_numero2(sol[i],letras)
            kappa=sol-numeros
            f.write("{}\t{}\n".format(array_to_string(kappa),array_to_string(sol)))

# Array of dicc: {kappa,solution}
def load_dataset(path="dataset.csv"):
    f=open(path)
    f2=f.readlines()
    dataset=[[]]*len(f2)
    for i in range(len(f2)):
        [kappa,solution]=f2[i].split('\t')
        dataset[i]={'kappa':eval(kappa),'solution':eval(solution)}
    f.close()
    return dataset


create_dataset()
dataset=load_dataset()