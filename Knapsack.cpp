#include<bits/stdc++.h>
using namespace std;

struct Item
{
    double value,weight;
    Item(int v,int w):value(v),weight(w){}//Initializer list
};

bool cmp(Item a,Item b){//custom comparision
    double r1=a.value/a.weight;
    double r2=b.value/b.weight;
    return r1>r2;
}

double fracktional_Knapsack(vector<Item>&items,int capacity){
    sort(items.begin(),items.end(),cmp);
    double total_cost=0;
    if(capacity==0)return 0;
    for(auto&item:items){
        if(capacity==0)return total_cost;
        if(capacity>=item.weight){
            total_cost+=item.value;
            capacity-=item.weight;
        }else{
            total_cost+=capacity*item.value/item.weight;
            capacity=0;
        }
    }
    return total_cost;  
}


int main(){
    int n,capacity;
    cout<<"Enter number of items :";
    cin>>n;
    vector<Item>items;
    for(int i=0;i<n;i++){
        int value,weight;
        cout<<"Enter value of item "<<i+1<<" :";
        cin>>value;
        cout<<"Enter weight of item "<<i+1 <<" :";
        cin>>weight;
        items.emplace_back(value,weight);//c++ 11 feature
    }
    cout<<"Enter capacity of knapsack : ";
    cin>>capacity;
    cout<<"Maximum value of knapsack : "<<fracktional_Knapsack(items,capacity);

    return 0;
}