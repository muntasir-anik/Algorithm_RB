#include<bits/stdc++.h>
using namespace std;

int Partition(int a[], int p, int q)
{
    int pivot = a[q];
    int j = p;

    for (int i=p; i<q; i++)
    {
        if (a[i] < pivot)
        {
            swap (a[i],a[j]);
            j++;
        }
    }
    swap (a[j],a[q]);
    return j;

}
void quickSort(int a[], int p, int q)
{
    if(p<q)
    {
        int j= Partition(a, p, q);
        quickSort(a, p, j - 1);
        quickSort(a, j+ 1, q);
    }

}

int main()
{
    int arr[100];
    int n, i;

    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    for (i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
