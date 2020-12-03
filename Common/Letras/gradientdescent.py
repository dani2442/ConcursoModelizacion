from mykernel import *
def derivative1(p,letras="abcdefghijklmnñopqrstuvwxyz"):
    return conteo_numero2(p+1,letras)-conteo_numero2(p,letras)

def derivative2(p,letras="abcdefghijklmnñopqrstuvwxyz"):
    if p==0: return derivative1(p)
    else: return (conteo_numero2(p+1,letras)-conteo_numero2(p-1,letras))/2

class LetterDescent(object):
    def __init__(self,mensaje):
        self.letras=""
        self.mensaje=mensaje
        self.error=0
        self.output=float(0)
        self.P=0
        self.dP=0
        self.alpha=1
        

    def forward(self):
        self.error=vec_to_mat(calcular_error2(self.mensaje,self.P,self.letras))
        print(self.error.shape)
        self.output=norm2(self.error)
        return self.output

    def backward(self):
        grad2=np.zeros((len(self.letras),len(self.letras)))
        for i in range(len(self.letras)):
            grad2[i]=derivative1(self.P[i],self.letras)
        grad2-=np.identity(len(self.letras))
        self.dP=np.dot(self.error.T,grad2.T)

    def update(self):
        self.P-=self.alpha*self.dP

    def train(self,iter=1,letras="abcdefghijklmnñopqrstuvwxyz",p=None):
        self.letras=letras
        if p==None: self.P=[20]*len(letras)
        else: self.P=p

        for _ in range(iter):
            self.forward()
            self.backward()
            self.update()

        print(self.P)

mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
model=LetterDescent(mensaje_global)
model.train(letras="ab")


