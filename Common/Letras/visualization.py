from intervals import *
from mykernel import *

from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

def example1(mensaje):
    x_size,y_size=10,50

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    x=np.arange(0,x_size,1)
    y=np.arange(30,y_size,1)
    X,Y=np.meshgrid(x,y)
    Z=np.zeros((y_size-30,x_size))
    x_min,y_min=0,0
    min_val=100000
    for i in range(len(y)):
        for j in range(len(x)):
            Z[i,j]=norm2(calcular_error2(mensaje,[y[i],x[j]],"ab"))
            if(Z[i,j]<min_val):
                if(Z[i,j]==0):
                    print("[{}, {}]".format(x[j],y[i]))
                x_min=x[j]
                y_min=y[i]
                min_val=Z[i,j]
    
    ax.plot_wireframe(X,Y,Z,zorder=2)
    ax.scatter([x_min],[y_min],[min_val+0.5],c="r",s=100,zorder=1)
    #ax.plot_surface(X,Y,Z,zorder=2)
    ax.set_xlabel('\'b\'')
    ax.set_ylabel('\'a\'')
    ax.set_zlabel('error')
    plt.show()

            

example1(mensaje_global)
print(norm2(calcular_error2(mensaje_global,[20,20],"ab")))