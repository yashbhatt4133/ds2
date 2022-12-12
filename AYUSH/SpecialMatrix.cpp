#include <iostream>
#include "Array1D.cpp"
using namespace std;
class Diagnonal{
    public:
    int n;
    Array1D arr;
    Diagnonal(int i=0){
        n=i;
        arr=Array1D(i);
    }
    int get(int i,int j){
        if(i<1 || j<1 || i>n || j>n)
            throw "Out of bounds\n";
        else if(i!=j)
            return 0;
        return arr[i-1];
    }
    void set(int i,int j,int x){
        if(i<1 || j<1 || i>n || j>n)
            throw "Out of bounds";
        else if(i!=j && x!=0)
            throw "Non diagonal elements shouold be zero\n";
        else
            arr[i-1]=x;
    }
};
class Tridiagnonal{
    public:
    Array1D arr;
    int n;
    Tridiagnonal(int i=0){
        n=i;
        arr=Array1D(i*3-2);
    }
    int get(int i,int j){
        if(i<1 || j<1 || i>n || j>n)
            throw "Out of bounds\n";
        else if(abs(i-j)>1)
            return 0;
        return arr[2+3*(i-2)+j-i+1];
    }
    void set(int i,int j,int x){
        if(i<1 || j<1 || i>n || j>n)
            throw "Out of bounds";
        else if(abs(i-j)>1 && x!=0)
            throw "Non diagonal elements should be zero\n";
        else
            arr[2+3*(i-2)+j-i+1]=x;
    }
};
// class Upper{
//     public:
//     Array1D arr;
//     int i,j;
//     Upper(int i=0){
//         n=i;
//         this->j=i;
//         arr.reSize(i);
//     }
//     int get(int i,int j){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds\n";
//         else if(i!=j)
//             return 0;
//         return arr[i-1];
//     }
//     void set(int i,int j,int x){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds";
//         else if(i!=j && x!=0)
//             throw "Non diagonal elements shouold be zero\n";
//         else
//             arr[i-1]=x;
//     }
// };
// class Lower{
//     public:
//     Array1D arr;
//     int i,j;
//     Lower(int i=0){
//         n=i;
//         this->j=i;
//         arr.reSize(i);
//     }
//     int get(int i,int j){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds\n";
//         else if(i!=j)
//             return 0;
//         return arr[2+3*(i-2)+j-i+1];
//     }
//     void set(int i,int j,int x){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds";
//         else if(i!=j && x!=0)
//             throw "Non diagonal elements shouold be zero\n";
//         else
//             arr[i-1]=x;
//     }
// };
// class Symmetric{
//     public:
//     Array1D arr;
//     int i,j;
//     Symmetric(int i=0){
//         n=i;
//         this->j=i;
//         arr.reSize(i);
//     }
//     int get(int i,int j){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds\n";
//         else if(i!=j)
//             return 0;
//         return arr[i-1];
//     }
//     void set(int i,int j,int x){
//         if(i<1 || j<1 || i>n || j>this->j)
//             throw "Out of bounds";
//         else if(i!=j && x!=0)
//             throw "Non diagonal elements shouold be zero\n";
//         else
//             arr[i-1]=x;
//     }
// };
int main(){
    try{
    Diagnonal a(4);
    for (int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 5; j++){
            a.set(i,j,(i==j)?i:0);
        }
    }
    for (int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 5; j++){
            cout<<a.get(i,j);
        }
    }
    }
    catch(char* msg){
        cout<<msg;
    }
}