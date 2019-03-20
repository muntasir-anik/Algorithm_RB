#include <bits/stdc++.h>
using namespace std;
int arr[1000];

void Merge(int lo,int mid,int hi)
{
    int i , j , k = 1 , temp[10000];
    i = lo ;
    j = mid + 1 ;

    while( i<=mid || j<=hi )
    {
        if(i>mid) temp[k++] = arr[j++];
        else if(j>hi) temp[k++] = arr[i++];
        else if(arr[i]<arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    k=1;
    for(i=lo;i<=hi;i=i+1,k=k+1)
    {
        arr[i] = temp[k];
    }
}

void divide(int lo,int hi)
{
    if(lo<hi)
    {
        int mid = (lo+hi)/2;
        divide(lo,mid);
        divide(mid+1,hi);
        Merge(lo,mid,hi);
    }
}


int main()
{
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        cin >> arr[i];
        cin >> arr[i];

    }
    divide(1,n);

    for(int i=0;i<=n;i++) {
        cout << arr[i] << " ";
        cout<<endl;
    }
    return 0;
}
