//
//  main.cpp
//  newtonInterpolation
//
//  Created by Людмила Маломуж on 20/11/2020.
//

/***************** Newtons interpolation **************/
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,i,j;
    float x[10],f[10],a,sum,mult;
    //sys("cls");
    cout<<"No of sample points ? ";
    cin>>n;
    cout<<"\nAll x with corresponding f(x) ";
    for(i=0;i<n;i++)
    cin>>x[i]>>f[i];
    cout<<"\nEnter x for calculation ";
    cin>>a;
    sum=f[0];
    for(j=0;j<n-1;j++)
    {
        for(i=n-1;i>j;i--){
            f[i]=(f[i]-f[i-1])/(x[i]-x[i-j-1]);
            cout<<f[i]<<" ";
        }
        cout<<endl;
    }
    for(i=n-1;i>=1;i--)
    {
        mult=1;
        for(j=0;j<i;j++)
            mult*=(a-x[j]);
            
        mult*=f[i];
        sum+=mult;
    }
    cout<<"The result is: "<<sum<<endl;;
    //getch();
    return 0;
}
