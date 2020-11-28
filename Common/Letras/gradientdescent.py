from mykernel import *
def derivative1():
    pass

def derivative2():
    pass

class LetterDescent(object):
    def __init__(self,mensaje):
        self.letras=""
        self.mensaje=mensaje
        self.error=0
        self.output=float(0)

    def forward(self,p):
        self.error=vec_to_mat(calcular_error2(self.mensaje,p,self.letras))
        print(self.error.shape)
        self.output=norm2(self.error)
        return self.output

    def backward(self,p):
        self.error.T

    def update(self):
        pass

    def train(self,iter=1,letras="abcdefghijklmnñopqrstuvwxyz",p=None):
        self.letras=letras
        if p==None: p=[20]*len(letras)

        for _ in range(iter):
            self.forward(p)
            self.backward(p)
            self.update()

        print(p)

mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
model=LetterDescent(mensaje_global)
model.train()


