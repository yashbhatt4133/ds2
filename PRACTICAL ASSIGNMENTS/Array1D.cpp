#include<iostream>
using namespace std;
class Array1D{
    int size;
    int *arr;
    public :
    //constructor
    Array1D(int size = 0){
        if (size < 0) throw "Bad Initialisation";
        this->size = size;
        arr = new int[size];
    }
    void setall(int x = 0){
        for(int i =0;i<size;i++)
            arr[i] = x;
    }
    int getSize() const{return size;}
    //resize and copy initial elements 
    void reSize(int s){
        if (s < 0) throw "Bad thing";
        if (size !=s){
            int n = (s>size)?size:s;
            int* tarr = new int[s];
            for(int i =0;i<n;i++){
                tarr[i] = arr[i];
            }
            delete[] arr;
            arr = tarr;//reassign pointer
            size = s;
        }
    }
    //copy-constructor
    Array1D(const Array1D& a){
        size = a.getSize();
        arr = new int[size];
        for(int i =0;i<size;i++){
            arr[i] = a.arr[i];
        }
    }
    //destructor
    ~Array1D(){
        delete []arr;
    }
    //safe-array-accessor
    int &operator[](int i) const{
        if(i<0||i>=size){
            throw "Invalid Index";
        }
        return arr[i];
    }
    //a = Array1d(5);
    //a.arr[3];
    //a[3];
    //input->>
    friend istream &operator>>(istream &in,Array1D &a){
        cout<<"Enter "<<a.getSize()<<" elements : ";
        for(int i = 0;i<a.getSize();i++){
            in>>a[i];
        }
        return in;
    }
    //output-<<
    friend ostream &operator<<(ostream &out,Array1D &a){
        out<<"[ ";
        for(int i = 0;i<a.getSize();i++){
            out<<a[i]<<" ";
        }
        out<<"]\n";
        return out;
    }
    //arithmetic-operations
    Array1D operator+(const Array1D& obj);
    Array1D operator-(const Array1D& obj);
    Array1D operator*(const Array1D& obj);
    Array1D operator/(const Array1D& obj);
    Array1D operator*(int n){
        Array1D temp(this->getSize());
        for(int i=0;i < this->getSize();i++){
            temp[i] = ((*this)[i]*n);
        }
        return temp;
    }
    // void operator=(const Array1D& a){
    //     size = a.getSize();
    //     delete [] arr;
    //     arr = new int[size];
    //     for(int i =0;i<size;i++){
    //         arr[i] = a.arr[i];
    //     }
    // }
    Array1D operator=(const Array1D& a){
        size = a.getSize();
        delete [] arr;
        arr = new int[size];
        for(int i =0;i<size;i++){
            arr[i] = a.arr[i];
        }
        return (*this);
    }
};
Array1D Array1D::operator+(const Array1D& obj){
    if(this->getSize()!=obj.getSize()){
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for(int i=0;i < this->getSize();i++){
        temp[i] = ((*this)[i]+obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator-(const Array1D& obj){
    if(this->getSize()!=obj.getSize()){
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for(int i=0;i < this->getSize();i++){
        temp[i] = ((*this)[i]-obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator*(const Array1D& obj){
    if(this->getSize()!=obj.getSize()){
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for(int i=0;i < this->getSize();i++){
        temp[i] = ((*this)[i]*obj.arr[i]);
    }
    return temp;
}
Array1D Array1D::operator/(const Array1D& obj){
    if(this->getSize()!=obj.getSize()){
        throw "Unequal Sized Arrays";
    }
    Array1D temp(this->getSize());
    for(int i=0;i < this->getSize();i++){
        temp[i] = ((*this)[i]/obj.arr[i]);
    }
    return temp;
}

int main(){
    int n = 5;
    Array1D a(n);
    cin>>a;
    cout<<"A :"<<a;
    Array1D b;
    b = a+a;
    cout<<"B :"<<b;
    b.setall(100);
    cout<<"A :"<<a;
    cout<<"B :"<<b;
    a[2] = 10;
    b[1] = 1000;
    cout<<"A :"<<a;
    cout<<"B :"<<b;
    return 0;
}
