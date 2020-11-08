#include <iostream>
#include <vector>
#include <math.h>

class Tensor{
protected:
    std::vector<Tensor> capas;
    double valor=0.0;
    bool fin=1;
    unsigned short longitud=1;

public:

    Tensor(){
        valor=0.0;
        fin= 1;
        longitud= 1;
        capas=std::vector<Tensor>();
    }

    Tensor(double x){
        fin=1;
        valor=x;
        longitud=1;
        capas=std::vector<Tensor>();
    }

    Tensor(std::initializer_list<Tensor> v):capas(v){
        fin=0;
        valor=0.0;
        longitud=v.size();
    }

    ~Tensor(){
        if(!fin){
            capas.clear();
        }
    }

    operator double(){if(fin)return valor; else exit(3);}

    operator int(){if(fin)return (int)valor; else exit(3);}

    Tensor& operator<<(int capa){
        if(fin){
            fin=0;
            longitud=capa;
            for(int i=0;i<capa;i++)capas.push_back(Tensor());
        }
        else for(int i=0;i<this->longitud;i++){capas[i]<<capa;}
        return *this;
    }

    void operator=(double val){
        if(!fin)exit(1);
        (*this).valor=val;
    }

    void operator=(Tensor tensor){
        if(&tensor==NULL)printf("\nOye, aqui tenemos un null, creo que se llama... tenor? no, tensor");
        valor=tensor.valor;
        fin=tensor.fin;
        longitud=tensor.longitud;
        capas.clear();
        if(!fin)for(int i=0;i<tensor.longitud;i++)capas.push_back(tensor.capas[i]);
    }

    Tensor& operator[](int i){
        if(fin && i==0){
            Tensor *out= new Tensor(valor);
            return *out;
        }
        return capas[i];
    }

    /*
    Tensor& subTensor(std::initializer_list<int> t){

    }
    */

    Tensor& nindex(int i){
        if(fin)return *this;
        int modulo=nelementos()/longitud;
        return capas[(i-i%modulo)/modulo].nindex(i%modulo);
    }

    char* show(){
        char* out;
        out=(char*)malloc(600);
        if(fin){
            sprintf(out,"%f",(*this).valor);
        }
        else{
            sprintf(out,"{");
            for(int i=0;i<longitud-1;i++){
                sprintf(out,"%s%s,",out,capas[i].show());
            }
            sprintf(out,"%s%s}",out,capas[longitud-1].show());
        }
        return out;
    }

    Tensor operator+(Tensor tensor){
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin && tensor.fin){
            nuevo->valor+=tensor.valor;
        }
        else if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else{
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i]+tensor.capas[i];
        }
        return *nuevo;
    }

    Tensor operator+=(Tensor tensor){
        *this=*this+tensor;
        return *this;
    }

    /*
    -------------------------
    En construcción
    -------------------------
    */

    Tensor suma(Tensor tensor, std::initializer_list<int> t1, std::initializer_list<int> t2){
        int* v1=new int[t1.size()];
        std::copy(t1.begin(), t1.end(), v1);
        int* v2=new int[t1.size()];
        std::copy(t2.begin(), t2.end(), v2);
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else if(v1[0]==-1 && v2[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i].suma(tensor.capas[i],v1+1,v2+1);
        }
        else if(v1[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i].suma(tensor.capas[v2[0]],v1+1,v2+1);
        }
        else if(v2[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[v1[0]]=nuevo->capas[v1[0]].suma(tensor.capas[i],v1+1,v2+1);
        }
        else if(nuevo->fin && tensor.fin){
            nuevo->valor+=tensor.valor;
        }
        else{
            nuevo->capas[v1[0]]=nuevo->capas[v1[0]].suma(tensor.capas[v2[0]],v1+1,v2+1);
        }
        return *nuevo;
    }

    Tensor suma(Tensor tensor, int* v1, int* v2){
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else if(v1[0]==-1 && v2[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i].suma(tensor.capas[i],v1+1,v2+1);
        }
        else if(v1[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i].suma(tensor.capas[v2[0]],v1+1,v2+1);
        }
        else if(v2[0]==-1){
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[v1[0]]=nuevo->capas[v1[0]].suma(tensor.capas[i],v1+1,v2+1);
        }
        else if(nuevo->fin && tensor.fin){
            nuevo->valor+=tensor.valor;
        }
        else{
            nuevo->capas[v1[0]]=nuevo->capas[v1[0]].suma(tensor.capas[v2[0]],v1+1,v2+1);
        }
        return *nuevo;
    }

    /*
    -------------------------
    En construcción
    -------------------------
    */

    Tensor operator-(Tensor tensor){
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin && tensor.fin){
            nuevo->valor-=tensor.valor;
        }
        else if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else{
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i]-tensor.capas[i];
        }
        return *nuevo;
    }

    Tensor operator-=(Tensor tensor){
        *this=*this-tensor;
        return *this;
    }

    Tensor externo(Tensor tensor){
        if(fin && tensor.fin){
            return Tensor(valor*tensor.valor);
        }
        else if(fin){
            return tensor.externo(Tensor(valor));
        }
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i].externo(tensor);
        return *nuevo;
    }

    int orden(){
        int out=0;
        Tensor* sigue=this;
        while(!sigue->fin){
            out++;
            sigue=&sigue->capas[0];
        }
        return out;
    }

    int nelementos(){
        int i=0;
        int out= 1;
        Tensor *sigue=this;
        while(!sigue->fin){
            out*=sigue->longitud;
            sigue=&sigue->capas[0];
        }
        return out;
    }

    int* dimensiones(){
        int i=0;
        int* out= new int[orden()+1];
        Tensor *sigue=this;
        while(!sigue->fin){
            out[i++]=sigue->longitud;
            sigue=&sigue->capas[0];
        }
        out[i]=-1;
        return out;
    }

    Tensor kronecker(Tensor tensor){
        if(fin && tensor.fin){Tensor* nuevo=new Tensor(valor*tensor.valor);return *nuevo;}
        Tensor* nuevo=new Tensor();
        *nuevo<<longitud*tensor.longitud;
        if(fin) for(int j=0;j<tensor.longitud;j++)nuevo->capas[j]=(*this).kronecker(tensor.capas[j]);
        else if(tensor.fin) for(int i=0;i<longitud;i++)nuevo->capas[i]=(*this).capas[i].kronecker(tensor);
        else for(int i=0;i<longitud;i++)for(int j=0;j<tensor.longitud;j++)nuevo->capas[i*tensor.longitud+j]=(*this).capas[i].kronecker(tensor[j]);
        return *nuevo;
    }

    Tensor escalar(Tensor tensor){
        double out=0;
        if(fin && tensor.fin)return Tensor(valor*tensor.valor);
        else if(fin) for(int j=0;j<tensor.longitud;j++)out+=(double)(*this).escalar(tensor.capas[j]);
        else if(tensor.fin) for(int i=0;i<longitud;i++)out+=(double)capas[i].escalar(tensor);
        else for(int i=0;i<longitud;i++)for(int j=0;j<tensor.longitud;j++)out+=(double)capas[i].escalar(tensor.capas[j]);
        return Tensor(out);
    }

    Tensor productoModoN(int n, Tensor tensor, int iteracion=1){
        Tensor* nuevo=new Tensor();
        if(iteracion!=n){
            *nuevo<<longitud;
            for(int i=0;i<longitud;i++)nuevo->capas[i]=capas[i].productoModoN(n,tensor,iteracion+1);
        }
        else{
            if(tensor.orden()<2){
                if(!fin){
                    *nuevo=capas[0].kronecker(Tensor(tensor[0]));
                    for(int i=1;i<longitud;i++)*nuevo+=capas[i].kronecker(Tensor(tensor[i]));
                }
                else *nuevo=Tensor(tensor.valor);
            }
            else{
                *nuevo<<tensor.longitud;
                for(int j=0;j<tensor.longitud;j++)nuevo->capas[j]=this->productoModoN(n,tensor[j],iteracion);
            }
        }
        return *nuevo;
    }

    Tensor dot(Tensor tensor){
        if(tensor.orden()<2)return tensor.productoModoN(1,*this);
        return tensor.productoModoN(tensor.orden()-1,*this);
    }

    Tensor operator*(Tensor tensor){
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin && tensor.fin){
            nuevo->valor*=tensor.valor;
        }
        else if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else{
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i]*tensor.capas[i];
        }
        return *nuevo;
    }

    Tensor operator*=(Tensor tensor){
        *this=(*this)*tensor;
        return *this;
    }

    Tensor operator/(Tensor tensor){
        Tensor* nuevo=new Tensor();
        *nuevo=*this;
        if(nuevo->fin && tensor.fin){
            nuevo->valor/=tensor.valor;
        }
        else if(nuevo->fin!=tensor.fin || nuevo->longitud!=tensor.longitud)exit(2);
        else{
            for(int i=0;i<nuevo->longitud;i++)nuevo->capas[i]=nuevo->capas[i]/tensor.capas[i];
        }
        return *nuevo;
    }

    Tensor operator/=(Tensor tensor){
        *this=(*this)/tensor;
        return *this;
    }

    Tensor normaF(){
        return Tensor(sqrt((double)escalar(*this)));
    }

    Tensor normaL1(){
        Tensor out;
        if(fin)return *this;
        else for(int i=0;i<longitud;i++)out+=abs((double)capas[i].normaL1());
        return out;
    }

    bool operator<(Tensor tensor){
        return normaL1().valor<tensor.normaL1().valor;
    }

    bool operator<=(Tensor tensor){
        return normaL1().valor<=tensor.normaL1().valor;
    }

    bool operator>(Tensor tensor){
        return normaL1().valor>tensor.normaL1().valor;
    }

    bool operator>=(Tensor tensor){
        return normaL1().valor>=tensor.normaL1().valor;
    }

    bool operator==(Tensor tensor){
        if(fin && tensor.fin)return valor==tensor.valor;
        else if(!fin && ! tensor.fin && longitud==tensor.longitud){
            bool out=1;
            for(int i=0;i<longitud;i++)out=out&&capas[i]==tensor[i];
            return out;
        }
        return 0;
    }

    Tensor reduce_min(){
        if(fin)return Tensor(valor);
        else{
            Tensor maxi=capas[0].reduce_max();
            for(int i=1;i<longitud;i++){
                double val=capas[i].reduce_max().valor;
                if(maxi.valor>val)maxi.valor=val;
            }
            return maxi;
        }
    }

    Tensor reduce_max(){
        if(fin)return Tensor(valor);
        else{
            Tensor maxi=capas[0].reduce_max();
            for(int i=1;i<longitud;i++){
                double val=capas[i].reduce_max().valor;
                if(maxi.valor<val)maxi.valor=val;
            }
            return maxi;
        }
    }

    Tensor argmin(int prin=1){
        Tensor* nuevo=new Tensor;
        if(prin==0){
            if(fin) return Tensor(valor);
            Tensor *cosa= new Tensor();
            *cosa=capas[0].reduce_max();
            double maxi=(*cosa).valor;
            *nuevo<<(*cosa).longitud+1;
            for(int i=0;i<longitud;i++){
                delete cosa;
                cosa= new Tensor();
                *cosa=capas[i].reduce_max();
                if((*cosa)[0].valor<maxi){
                    maxi=(*cosa)[0].valor;
                    if(!(*cosa).fin)for(int i=1;i<nuevo->longitud;i++)(*nuevo)[i]=(*cosa)[i-1];
                    nuevo[0].valor=maxi;
                    nuevo[1].valor=i;
                }
            }
        }
        else if(fin)return Tensor(0);
        else{
            Tensor *cosa= new Tensor();
            *cosa=capas[0].reduce_max();
            double maxi=(*cosa).valor;
            *nuevo<<(*cosa).longitud;
            for(int i=0;i<longitud;i++){
                delete cosa;
                cosa= new Tensor();
                *cosa=capas[i].reduce_max();
                if((*cosa)[0].valor<maxi){
                    maxi=(*cosa)[0].valor;
                    if(!(*cosa).fin)for(int i=0;i<nuevo->longitud;i++)(*nuevo)[i]=(*cosa)[i];
                    nuevo[0].valor=i;
                }
            }
        }
        return *nuevo;
    }

        Tensor argmax(int prin=1){
        Tensor* nuevo=new Tensor;
        if(prin==0){
            if(fin) return Tensor(valor);
            Tensor *cosa= new Tensor();
            *cosa=capas[0].reduce_max();
            double maxi=(*cosa).valor;
            *nuevo<<(*cosa).longitud+1;
            for(int i=0;i<longitud;i++){
                delete cosa;
                cosa= new Tensor();
                *cosa=capas[i].reduce_max();
                if((*cosa)[0].valor>maxi){
                    maxi=(*cosa)[0].valor;
                    if(!(*cosa).fin)for(int i=1;i<nuevo->longitud;i++)(*nuevo)[i]=(*cosa)[i-1];
                    nuevo[0].valor=maxi;
                    nuevo[1].valor=i;
                }
            }
        }
        else if(fin)return Tensor(0);
        else{
            Tensor *cosa= new Tensor();
            *cosa=capas[0].reduce_max();
            double maxi=(*cosa).valor;
            *nuevo<<(*cosa).longitud;
            for(int i=0;i<longitud;i++){
                delete cosa;
                cosa= new Tensor();
                *cosa=capas[i].reduce_max();
                if((*cosa)[0].valor>maxi){
                    maxi=(*cosa)[0].valor;
                    if(!(*cosa).fin)for(int i=0;i<nuevo->longitud;i++)(*nuevo)[i]=(*cosa)[i];
                    nuevo[0].valor=i;
                }
            }
        }
        return *nuevo;
    }

    Tensor reshape(int* nuevas){
        Tensor *nuevo=new Tensor();
        int contador=1;
        int numero_elementos=nelementos();
        while(contador<numero_elementos){
            contador*=(*nuevas);
            *nuevo<<(*nuevas);
            nuevas=nuevas+1;
        }
        if(contador!=numero_elementos){
            delete nuevo;
            exit(5);
        }
        for(int i=0;i<numero_elementos;i++)nuevo->nindex(i)=this->nindex(i);
        return *nuevo;
    }

    Tensor reshape(std::initializer_list<int> dim){
        std::vector<int> nuevas=dim;
        Tensor *nuevo=new Tensor();
        int contador=1;
        int numero_elementos=nelementos();
        int i=0;
        while(contador<numero_elementos && i<nuevas.size()){
            contador*=nuevas[i];
            *nuevo<<nuevas[i++];
        }
        if(contador!=numero_elementos){
            delete nuevo;
            exit(5);
        }
        for(int i=0;i<numero_elementos;i++)nuevo->nindex(i)=this->nindex(i);
        return *nuevo;
    }

    Tensor traspuesta(int* param=NULL, int* indices=NULL, int len=0){
        int rango=orden();
        if(len==rango){
            Tensor* tensor=this;
            int e=0;
            while(!tensor->fin){
                tensor=&tensor->capas[indices[param[e++]]];
            }
            return *tensor;
        }
        Tensor* nuevo=new Tensor();
        int* numeros=dimensiones();
        if(param==NULL){
            param=new int[rango];
            param[0]=rango-1;
            param[rango-1]=0;
            for(int i=1;i<rango-1;i++)param[i]=i;
        }
        *nuevo<<numeros[param[len]];
        int* indices2=new int[len+1];
        for(int i=0;i<len;i++)indices2[i]=indices[i];
        for(int i=0;i<nuevo->longitud;i++){
            indices2[len]=i;
            nuevo->capas[i]=traspuesta(param,indices2,len+1);
        }
        return *nuevo;
    }

    Tensor traspuesta(std::initializer_list<int> perm, int* indices=NULL, int len=0){
        std::vector<int> v=perm;
        int rango=orden();
        int* param=new int[rango];
        for(int i=0;i<rango;i++)param[i]=v[i];
        if(perm.size()<rango)exit(6);
        if(len==rango){
            Tensor* tensor=this;
            int e=0;
            while(!tensor->fin){
                tensor=&tensor->capas[indices[param[e++]]];
            }
            return *tensor;
        }
        Tensor* nuevo=new Tensor();
        int* numeros=dimensiones();
        if(param==NULL){
            param=new int[rango];
            param[0]=rango-1;
            param[rango-1]=0;
            for(int i=1;i<rango-1;i++)param[i]=i;
        }
        *nuevo<<numeros[param[len]];
        int* indices2=new int[len+1];
        for(int i=0;i<len;i++)indices2[i]=indices[i];
        for(int i=0;i<nuevo->longitud;i++){
            indices2[len]=i;
            nuevo->capas[i]=traspuesta(param,indices2,len+1);
        }
        return *nuevo;
    }

    Tensor junta(Tensor tensor, unsigned short direccion){
        if(direccion==0){
            Tensor* nuevo=new Tensor();
            (*nuevo)<<longitud+tensor.longitud;
            for(int i=0;i<longitud;i++)nuevo->capas[i]=capas[i];
            for(int i=longitud;i<longitud+tensor.longitud;i++)nuevo->capas[i]=tensor.capas[i-longitud];
            return *nuevo;
        }
        else{
            if(longitud!=tensor.longitud)exit(7);
            Tensor* nuevo=new Tensor();
            (*nuevo)<<longitud;
            for(int i=0;i<longitud;i++)nuevo->capas[i]=capas[i].junta(tensor[i],direccion-1);
            return *nuevo;
        }
    }

    Tensor ravel(){
        Tensor* nuevo=new Tensor();
        int nelem=nelementos();
        (*nuevo)<<nelem;
        for(int i=0;i<nelem;i++)nuevo->capas[i].valor=nindex(i).valor;
        return *nuevo;
    }

    Tensor apply(double (*func)(double)){
        if(fin)return Tensor((*func)(valor));
        Tensor* nuevo=new Tensor();
        (*nuevo)<<longitud;
        for(int i=0;i<longitud;i++)nuevo->capas[i]=capas[i].apply(func);
        return *nuevo;
    }

};
