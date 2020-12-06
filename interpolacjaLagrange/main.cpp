//
//  main.cpp
//  interpolacjaLagrange
//
//  Created by Людмила Маломуж on 29/11/2020.
//

#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
     float x[100], y[100], xp, yp=0, p;
     int i,j,n;

     /* Input Section */
     cout<<"Enter number of data: ";
     cin>>n;
     cout<<"Enter data:"<< endl;
     for(i=1;i<=n;i++)
     {
          cout<<"x["<< i<<"] = ";
          cin>>x[i];
          cout<<"y["<< i<<"] = ";
          cin>>y[i];
     }
     cout<<"Enter interpolation point: ";
     cin>>xp;

     /* Implementing Lagrange Interpolation */
     for(i=1;i<=n;i++)
     {
          p=1;
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    p = p* (xp - x[j])/(x[i] - x[j]);
                   //cout<<p<<" ";
               }
             
          }
          yp = yp + p * y[i];
         cout<<"l"<<i<<" = "<<p<<endl;
     }
     cout<< endl<<"Interpolated value at "<< xp<< " is "<< yp<<endl;

     return 0;
}
