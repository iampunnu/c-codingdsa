#include<bits/stdc++.h>
#include <vector> 

using namespace std;

void swap(int * a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
    cout<<*a<<" "<<*b<<endl;
}

void set1(int  marks[1]){
        cout<<marks[0]<<" "<<marks<<endl;

    marks[0]=10;
}

void updateVector(vector<int> &  v){
    v.insert(v.begin(),100);
}

int main(){
    int marks[]={1,2,3,4};
    cout<< sizeof(marks)/sizeof(int)<<endl;
 //   cout<<marks[0]<<" "<<marks<<endl;
    //set1(marks);
    //cout<<marks[0]<<" "<<marks<<endl;
        vector<int> g1; 
g1.push_back(10);
g1.push_back(12);
g1.push_back(13);
  for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
updateVector(g1);   
cout<<endl;
  for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " ";      
    return 0;

}