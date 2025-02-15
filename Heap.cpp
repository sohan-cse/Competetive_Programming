#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>&A,int i){

    int l=2*i+1;
    int r=2*i+2;
    int largest;
    if(l<A.size()&&A[l]>A[i])largest=l;
    else largest=i;
    if(r<A.size()&&A[r]>A[largest])largest=r;

    if(largest!=i){
        swap(A[largest],A[i]);
        Heapify(A,largest);
    }
}



void Delete(vector<int>&A){
    if(A.empty())return;

    int maxVal=A[0];
    int sz=A.size()-1;
    swap(A[0],A[sz]);
    A.pop_back();
    Heapify(A,0);
    cout<<"\nDeleted element : "<<maxVal<<endl;
}

void increaseKey(vector<int>&A,int i,int key){
    if(A[i]>key)cout<<"Error"<<endl;
    else{
        A[i]=key;
        while(i>0&&A[(i-1)/2]<A[i]){
            swap(A[(i-1)/2],A[i]);
            i=(i-1)/2;
        }
    }
}
void Insert(vector<int>&A){
    A.push_back(INT_MIN);
    int sz=A.size()-1;
    int ele;
    cout<<"Enter element : ";
    cin>>ele;
    increaseKey(A,sz,ele);
}

int main(){
    vector<int>A={5,2,9,7,1,6,3,8,4};
    for(int i=A.size()/2-1;i>=0;i--)Heapify(A,i);
    for(auto&i:A)cout<<i<<" ";
    Delete(A);
    for(auto&i:A)cout<<i<<" ";
    Delete(A);
    for(auto&i:A)cout<<i<<" ";
    Delete(A);
    for(auto&i:A)cout<<i<<" ";
    cout<<endl;
    increaseKey(A,2,20);
    for(auto&i:A)cout<<i<<" ";
    Insert(A);
    for(auto&i:A)cout<<i<<" ";

    return 0;
}