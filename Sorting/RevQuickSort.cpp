#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>&a, int low,int high){

 int pivot=a[high];
 int i=low-1;

 for(int j=low;j<high;j++){
    if(a[j]>pivot){
        i++;
        swap(a[i],a[j]);
    }
 }
 swap(a[i+1],a[high]);
 cout<<endl;
 return i+1;
}


void quicksort(vector<int>& a,int low, int high){
   if(low<high){
   int p = partition(a,low,high);

     for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }

    quicksort(a,low,p-1);
    quicksort(a,p+1,high);
   }

}

int main(){

cout<<"ENTER ARRAY SIZE: ";
int n;
cin>>n;

vector<int> a(n);

cout<<"ENTER ARRAY INPUTS: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}

quicksort(a,0,n-1);

 cout<<endl;
 cout<<"SORTED ARRAY: ";
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
 }

}
