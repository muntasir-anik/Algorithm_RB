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
void Merge(int day,int month, int year)
{
    int n, d, m, y ,temp[1000];
    d= day;
    m=30*day;
    y=365*day;

    for(d=1;d<=n;d++)
}


int main()
{
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].d;
        cin>>arr[].m;
        cin..arr[].y
    }
    divide(1,n);

    for(int i=0;i<=n;i++) {
        cout << arr[i].d,arr[i].m, arr[i].y,  << " ";
        cout<<endl;
    }
    return 0;
}
