int partition(vector<int>& arr,int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pindex=s+cnt;
    swap(arr[pindex],arr[s]);
    int i=s;
    int j=e;
    while(i<pindex && j>pindex){
        while(arr[i]<=arr[pindex]){
            i++;
        }
         while(arr[j]>arr[pindex]){
            j--;
        }
        if(i<pindex && j>pindex){
            swap(arr[i++],arr[j--]);
        }
        
    }
    return pindex;
}




void solve(vector<int>& arr,int s,int e){
    if(s>=e){
        return ;
    }
    int p=partition(arr,s,e);
    solve(arr,s,p-1);
    solve(arr,p+1,e);
}



vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    solve(arr,0,arr.size()-1);
    return arr;
}
