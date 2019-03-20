#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[100], int p, int q)
{
    int pivot = arr[q];
    int j = p;

    for (int i=p; i<q; i++)
    {
        if (arr[i] < pivot)
        {
            swap (arr[i],arr[j]);
            j++;
        }
    }
    swap (arr[j],arr[q]);
    return j;

}
void quickSort(int arr[100], int p, int q)
{
    if(p<q)
    {
        int j= Partition(arr, p, q);
        quickSort(arr, p, j - 1);
        quickSort(arr, j+ 1, q);
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

