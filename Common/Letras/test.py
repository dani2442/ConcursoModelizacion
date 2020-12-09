import dataset
from gradientdescent import LetterDescent
import numpy as np
from mykernel import norm2

class Test(object):
    def __init__(self,path="dataset.csv"):
        self.data=dataset.load_dataset(path)
        self.fnc=[self.test_gradientdescent]

    def test_gradientdescent(self,iter):
        print("Testing Gradient Descent: ")
        count=0
        for i in range(iter):
            model=LetterDescent()
            model.set_messagefixed(self.data[i]["kappa"])
            model.train()
            if (norm2(model.get_output()-np.array(self.data[i]["solution"]))==0):
                count+=1
        return count

    def test(self,iter=1):
        for f in self.fnc:
            print("{} / {} acertados".format(f(iter),iter))


testing=Test()
testing.test(1)
