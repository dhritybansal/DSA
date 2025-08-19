#include<iostream>
using namespace std;
class diagonal{
  int* a;
    int n;
    public:
    diagonal(int n){
        this->n=n;
        a=new int[3*n-2];
    }
    void set(int i,int j,int num){
if((i-j)==1){
    a[i-2]=num;
}
else if((i-j)==0){
a[n+i-2]=num;
}
else if((i-j)==-1){
a[2*n-2+i]=num;
}
    }
    int get(int i,int j){
     if((i-j)==1){
    return a[i-2];
}
else if((i-j)==0){
return a[n+i-2];
}
else if((i-j)==-1){
return a[2*n-2+i];
}
else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++)  {
              if((i-j)==1){
    cout<<a[i-2]<<" ";
}
else if((i-j)==0){
cout<<a[n+i-2]<<" ";
}
else if((i-j)==-1){
cout<<a[2*n-2+i]<<" ";
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
         for(int j=1;j<=n;j++){
           cout << "Enter element for position (" << i << "," << j << "): ";
            cin>>x;
           d.set(i,j,x);
}}
d.display();
}