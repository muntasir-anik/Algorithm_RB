#include <bits/stdc++.h>
using namespace std;

struct Item
{
    double w , p ;
};

Item arr[100];

bool cmp(Item a,Item b)
{
    return a.p*b.w > b.p*a.w;
}

int main()
{
    double W , P = 0 ;
    int n ;
    cin >> W >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i].w >> arr[i].p ;
    }
    sort(&arr[1],&arr[n+1],cmp);
    for(int i=1;i<=n&&W!=0;i++)
    {
        if(W>=arr[i].w)
        {
            W=W-arr[i].w;
            P=P+arr[i].p;
        }
        else
        {
            P=P+W*(arr[i].p/arr[i].w);
            W = 0 ;
        }
    }
    cout << "Total Profit = " << P << endl ;
    return 0;
}
