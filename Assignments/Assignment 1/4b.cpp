#include<iostream>
using namespace std;
int main(){
  int a1[10][10], a2[10][10], res[10][10]={0};
   int r1, c1, r2, c2;
   cout << "Enter number of rows for 1st matrix: ";
   cin >> r1;
   cout << "Enter number of columns for 1st matrix: ";
   cin >> c1;
   cout << "Enter number of rows for 2nd matrix: ";
   cin >> r2;
   cout << "Enter number of columns for 2nd matrix: ";
   cin >> c2;
   if (c1 != r2) {
       cout << "Matrix multiplication not possible!" << endl;
       return 0;  // exit the program
   }
   cout << "Enter elements of 1st matrix:\n";
   for (int i = 0; i < r1; i++) {
       for (int j = 0; j < c1; j++) {
           cin >> a1[i][j];
       }
   }
   cout << "Enter elements of 2nd matrix:\n";
   for (int i = 0; i < r2; i++) {
       for (int j = 0; j < c2; j++) {
           cin >> a2[i][j];
       }
   }
  
int rc=r2;
        for(int i=0;i<r1;i++){
             for(int j=0;j<c2;j++){
       res[i][j]=0;
       for(int k=0;k<rc;k++){
res[i][j]=   res[i][j]+(a1[i][k]*a2[k][j]);
       }
    }}
    cout<<endl;
        for(int i=0;i<r1;i++){
             for(int j=0;j<c2;j++){
        cout<<res[i][j]<<" ";
    }
cout<<endl;}
return 0;
}