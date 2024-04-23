#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void update(vector<int>& v){
    v.insert(v.begin()+1,2);
}
int main(){

    int arr [5]={1,2,3,4,5};

    vector<int> v={1,2,3,4};

    for(auto i=v.begin();i<v.end();i++){
        cout<<*i<<" ";
    }
 

     
    cout<< "" <<endl;

    update(v);
    for(auto i=v.begin();i<v.end();i++){
        cout<<*i<<" ";
    }



    return 0;
}