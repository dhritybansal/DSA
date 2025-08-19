#include<iostream>
using namespace std;
class diagonal{
  int* a;
    int n;
    public:
    diagonal(int n){
        this->n=n;
        a=new int[n];
    }
    void set(int i,int j,int num){
if(i==j){
    a[i-1]=num;
}
    }
    int get(int i,int j){
        if(i==j){
    return a[i-1];
}
else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++)  {
                 if(i==j){
    cout<<a[i-1]<<" ";
           }
           else cout<<"0 ";
        }
        cout<<endl;
    }}
~diagonal(){delete[]a;}
};
int main(){
    int n;
    cout<<"enter size of matrix"<<endl;
    cin>>n;
    diagonal d(n);
     int x;
     for(int i=1;i<=n;i++){
           cout << "Enter element for position (" << i << "," << i << "): ";
            cin>>x;
           d.set(i,i,x);
}
d.display();
}