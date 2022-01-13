void merge(vector < int > & arr, int s,int e){
   
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int* first=new int[len1];
    int* second=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
    
    int index1=0,index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
        
    }
     while(index1 < len1) {
        arr[k++] = first[index1++];
    }
    while(index2<len2){
        arr[k++]=second[index2++];
    }
    delete []first;
    delete []second;
    
}



void solve(vector < int > & arr, int s,int e){
    int mid=(s+e)/2;
    if(s>=e){
        return;
    }
    solve(arr,s,mid);
    solve(arr,mid+1,e);
    merge(arr,s,e);
}



void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr,0,n-1);
}







class Solution{
    long long merge(long long arr[], long long s,long long mid, long long e){
    long long inv=0;
    long long len1=mid-s+1;
    long long len2=e-mid;
    long long first[len1];
    long long second[len2];
    //copying elements to the dynamic array
    int mainarrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainarrayindex++];
        }
    mainarrayindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainarrayindex++];
        }
    //merge two sorted array
    long long index1=0;
    long long index2=0;
    mainarrayindex=s;
    
    while(index1<len1 && index2<len2){
        if(first[index1]<=second[index2]){
            arr[mainarrayindex++]=first[index1++];
        }
        else{
            arr[mainarrayindex++]=second[index2++];
            inv+=len1-index1;
        }
    }
    while(index1<len1){
        arr[mainarrayindex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainarrayindex++]=second[index2++];
    }
    return inv;
}
long long mergesort(long long arr[], long long s, long long e){
    // base case
     long long inv=0;
   
   if(s<e){
    long long mid=(e+s)/2;
   inv += mergesort(arr,s,mid);
   inv += mergesort(arr,mid+1,e);
    
   inv += merge(arr,s,mid,e);
   }
    return inv;
}
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans=mergesort(arr,0,N-1);
        return ans;
    }

};

