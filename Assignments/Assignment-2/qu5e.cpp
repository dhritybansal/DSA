#include<iostream>
using namespace std;
class diagonal{
  int* a;
    int n;
    public:
    diagonal(int n){
        this->n=n;
        a=new int[(n*(n+1))/2];
    }
    void set(int i,int j,int num){
if(i>=j){
    a[(i*(i-1))/2+j-1]=num;
}
    }
    int get(int i,int j){
        if(i>=j){
    return a[(i*(i-1))/2+j-1];
}
else return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++)  {
                 if(i>=j){
    cout<<a[(i*(i-1))/2+j-1]<<" ";
           }
           else cout<<a[(j*(j-1))/2+i-1]<<" ";
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