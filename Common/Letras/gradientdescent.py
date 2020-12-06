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
		self.alpha=0.6
        

	def forward(self):
		self.error=vec_to_mat(calcular_error2(self.mensaje,self.P.astype(int),self.letras))
		self.output=norm2(self.error)
		print(self.output)
		return self.output

	def backward(self):
		grad2=np.zeros((len(self.letras),len(self.letras)))
		for i in range(len(self.letras)):
			grad2[i]=derivative2(self.P.astype(int)[i],self.letras)
		grad2-=np.identity(len(self.letras))
		self.dP=np.dot(grad2,self.error)

	def update(self):
		self.P-=self.alpha*np.concatenate(self.dP)
		print(self.P)

	def train(self,iter=20,letras="abcdefghijklmnñopqrstuvwxyz",p=None):
		self.letras=letras
		if p==None: self.P=np.array([20]*len(letras),dtype=float) #self.P=[39,4]
		else: self.P=p

		for _ in range(iter):
			self.forward()
			self.backward()
			self.update()

		print(self.P)

mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
model=LetterDescent(mensaje_global)
model.train(letras="ab")


