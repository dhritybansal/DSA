#include<iostream>
using namespace std;
class lowtriangle{
  int* a;
    int n;
    public:
  lowtriangle(int n){
        this->n=n;
        a=new int[(n*(n+1))/2];
    }
    void set(int i,int j,int num){
if(i<=j){
    a[(j*(j-1))/2+i-1]=num;
}
    }
    int get(int i,int j){
        if(i<=j){
    return a[(j*(j-1))/2+i-1];
}
else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++)  {
                 if(i<=j){
    cout<<get(i,j)<<" ";
           }
           else cout<<"0 ";
        }
        cout<<endl;
    }}
~lowtriangle(){delete[]a;}
};
int main(){
    int n;
    cout<<"enter size of matrix"<<endl;
    cin>>n;
   lowtriangle d(n);
     int x;
     for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
           cout << "Enter element for position (" << i << "," << j << "): ";
            cin>>x;
           d.set(i,j,x);
}}
d.display();
}