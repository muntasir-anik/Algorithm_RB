
#include <bits/stdc++.h>
using namespace std;
int arr[1000];

void Merge(int lo,int mid,int hi)
{
    int i , j , k = 1 , temp[10000];
    i = lo ;
    j = mid + 1 ;

    while( i<=mid && j<=hi )
    {
        if(arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while( i<=mid )
    {
        temp[k] = arr[i];
        k++;i++;
    }

    while( j<=hi )
    {
        temp[k] = arr[j];
        k++;j++;
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
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> arr[i];

    divide(1,n);

    for(int i=1;i<=n;i++) cout << arr[i] << endl;
    return 0;
}
