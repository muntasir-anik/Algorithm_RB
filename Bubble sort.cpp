#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n , arr[100] , i , j ;

    cin >> n ;
    for(int i=1;i<=n;i++)
        cin >> arr[i] ;

    for(i=1;i<=n-1;i=i+1)
    {
        for(j=1;j<=n-i;j=j+1)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }

    for(int i=1;i<=n;i++)
        cout << arr[i] << " ";
    return 0;
}
