#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *a, int n){
    vector<int> output;
    unordered_map<int, bool> mymap;

    for(int i=0;i<n;i++){
        if(mymap.count(a[i]) == 0){
            output.push_back(a[i]);
            mymap[a[i]] = true;
        }
    }
    return output;
}

int main(){
    int a[] = {1,3,4,3,4,3,4,34,3,4,3,4,3,4,34,3};
    vector<int> output = removeDuplicates(a, 12);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}