//
//  main.cpp
//  nevillAlgorytm
//
//  Created by Людмила Маломуж on 01/12/2020.
//
double Nevill(int n, double *x, double *y, double c);
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    double p;
    cout<<"Podaj ilosc wezlow ";
    cin>>n;
    double* x = new double[n];
    double* y = new double[n];
    cout<<"Podaj tablice x: ";
    for (int i = 0; i<n; i++){
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
    }
    cout<<"Podaj tablice y: ";
    for (int i = 0; i<n; i++){
        cout<<"y["<<i<<"]: ";
        cin>>y[i];
    }
    cout<<"Podaj punkt: ";
    cin>>p;
    cout<<"Przyblizona wartosc w punkcie "<<p<<" wynosi: "<<Nevill(n, x, y, p)<<endl;
    return 0;
}
double Nevill(int n, double *x, double *y, double c){
    double* p = new double[n];
    for (int k = 0; k<n; k++)
    {
        p[k]=y[k];
        for(int j=k-1; j>=0; j--)
        {
            p[j]=p[j+1]+(p[j+1]-p[j])*(c-x[k])/(x[k]-x[j]);
            cout<<p[j]<<" ";
        }
    }
    double wynik = p[0];
    delete [] p;
    return wynik;
}
