import mykernel
import numpy as np
def derivative1(p,letras="abcdefghijklmnñopqrstuvwxyz"):
    return mykernel.conteo_numero2(p+1,letras)-mykernel.conteo_numero2(p,letras)

def derivative2(p,letras="abcdefghijklmnñopqrstuvwxyz"):
    if p==0: return derivative1(p,letras)
    else: return (mykernel.conteo_numero2(p+1,letras)-mykernel.conteo_numero2(p-1,letras))/2

class LetterDescent(object):
	def __init__(self,letras="abcdefghijklmnñopqrstuvwxyz"):
		self.letras=letras
		self.error=0
		self.output=float(0)
		self.P=0
		self.dP=0
		self.alpha=0.001
		self.min=999999999
		self.value_min=[]
        
	# Convertimos el mensaje en un vector que representa el conjunto de letras fijas
	def set_message(self,mensaje):
		self.mensaje=mensaje
		self.kappa=mykernel.conteos_mensaje2(mykernel.firmar_mensaje_fija(mensaje,self.letras),self.letras)

	# Inicializamos kappa
	def set_messagefixed(self,kappa):
		self.kappa=kappa

	# Calculamos el error
	def forward(self,b=False):
		self.error=mykernel.vec_to_mat(mykernel.calcular_error_kappa(self.kappa,self.P.astype(int),self.letras))
		self.output=mykernel.norm2(self.error)
		if b: # Printear resultados 
			print(self.output)
			print(self.P)
		if(self.output<self.min):
			self.min=self.output
			self.value_min=self.P

		return self.output

	# Calculamos las derivadas
	def backward(self): 
		grad2=np.zeros((len(self.letras),len(self.letras)))
		for i in range(len(self.letras)):
			grad2[i]=derivative2(self.P.astype(int)[i],self.letras)
		grad2-=np.identity(len(self.letras))
		self.dP=np.dot(grad2,self.error)

	# Actualizamos los resultados
	def update(self):
		self.P-=self.alpha*np.concatenate(self.dP)

	# Entrenamos
	def train(self,iter=10000,p=None):
		if p==None: self.P=np.array(self.kappa,dtype=float) 
		else: self.P=p

		for i in range(iter):
			self.forward(i%100==0)
			self.backward()
			self.update()
		
		# Imprimimos el menor valor
		print(self.value_min)
		print(self.min)


	# Optener el error del resultado
	def get_output(self):
		return self.P.astype(int)

#mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
#model=LetterDescent(letras="ab")
#model.set_message(mensaje_global)
#model.train()


