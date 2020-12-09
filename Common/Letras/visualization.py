from intervals import *
from mykernel import *
from scipy import ndimage, misc

from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
mensaje_global="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

def example1(mensaje):
    x_size,y_size=10,50

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    #ax=fig.add_subplot()
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
    #ax.contourf(X,Y,Z,25,cmap='RdGy')
    #fig.colorbar()

    plt.show()


def example2(mensaje):
    x_size,y_size=10,50

    fig = plt.figure()
    ax=fig.add_subplot()
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
    
    Z=ndimage.zoom(Z, 3.0)
    X_,Y_=np.meshgrid(np.linspace(0,x_size,Z.shape[1]),np.linspace(30,y_size,Z.shape[0]))
    
    ax.contour(X_,Y_,Z,12)
    #ax.contour(X,Y,Z,25,cmap='RdGy')
    #ax.colorbar()

    plt.show()

def example3(mensaje):
    error=[1453, 293, 205, 68, 10, 2, 1, 1, 1, 0]
    xy=[[1., 1.], [20.,   2.5], [24.25,  7.75], [31.25,  6.25], [35.25, 5.25], [37.5 , 5.5], [38.,    5.25], [38. ,   4.75], [38.5 ,  4.75], [39.,   4.75]]
    x1,y1=[],[]
    for i in xy:
        x1+=[i[1]]
        y1+=[i[0]]

    x_size,y_size=10,50

    fig = plt.figure()
    ax=fig.add_subplot()
    x=np.arange(0,x_size,1)
    y=np.arange(0,y_size,1)
    X,Y=np.meshgrid(x,y)
    Z=np.zeros((y_size,x_size))
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
    
    Z=ndimage.zoom(Z, 3.0)
    X_,Y_=np.meshgrid(np.linspace(0,x_size,Z.shape[1]),np.linspace(0,y_size,Z.shape[0]))
    
    ax.contour(X_,Y_,Z,20)
    #ax.colorbar()
    ax.plot(np.array(x1),np.array(y1),c='r')
    plt.show()


def example4(mensaje):
    error=[1453, 293, 205, 68, 10, 2, 1, 1, 1, 0]
    xy=[[1., 1.], [20.,   2.5], [24.25,  7.75], [31.25,  6.25], [35.25, 5.25], [37.5 , 5.5], [38.,    5.25], [38. ,   4.75], [38.5 ,  4.75], [39.,   4.75]]
    x1,y1=[],[]
    for i in xy:
        x1+=[i[1]]
        y1+=[i[0]]


    x_size,y_size=30,60

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    #ax=fig.add_subplot()
    x=np.arange(0,x_size,2)
    y=np.arange(0,y_size,2)
    X,Y=np.meshgrid(x,y)
    Z=np.zeros((int(y_size/2),int(x_size/2)))
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
    ax.plot(np.array(x1),np.array(y1),np.array(error),c='r')

    #ax.plot_surface(X,Y,Z,zorder=2)
    ax.set_xlabel('\'b\'')
    ax.set_ylabel('\'a\'')
    ax.set_zlabel('error')
    #ax.contourf(X,Y,Z,25,cmap='RdGy')
    #fig.colorbar()

    plt.show()

example4(mensaje_global)