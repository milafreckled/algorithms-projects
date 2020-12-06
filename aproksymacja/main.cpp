//
//  main.cpp
//  aproksymacja
//
//  Created by Людмила Маломуж on 20/11/2020.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#define pi 3.14159
#define e 2.71828
using namespace std;
void trapezy(double, double, int, int);
void simpsona(double, double, int, int);
int main(int argc, const char * argv[]) {
    int wyb1, m;
    char wyb2;
    while (wyb1!=3){
        cout<<"Wybierz całkę do aproksymacji: \n";
        cout<<"1. (sin(x))^2+2 na [0, 2pi]\n";
        cout<<"2. e^x + 2*x^3 na [0, 2]\n";
        cout<<"3. Wyjscie.\n";
        cin>>wyb1;
        if (wyb1!=3){
        cout<<"Wybierz wzor: \n";
        cout<<"T - Wzor zlozonych trapezow\n";
        cout<<"S - Wzor Simpsona\n";
        cin>>wyb2;
        cout<<"Liczba podprzedzialow: ";
        cin>>m;
        }
        system("cls");
        switch(wyb1){
            case(1):if (wyb2=='T'){
                trapezy(0, 2*pi, m, 1);
            }else if(wyb2=='S'){
                simpsona(0, 2*pi, m, 1);
            }else{
                cout<<"Podanao złą wartość..."<<endl;
            }
                break;
            case(2): if (wyb2=='T'){
                trapezy(0, 2, m, 2);
            }else if(wyb2=='S'){
                simpsona(0, 2, m, 2);
            }else{
                cout<<"Podanao złą wartość..."<<endl;
            }
                break;
            case(3): cout<<"Dziekuje za skorzystanie z programu!";
                break;
            default: cout<<"Podano złą wartość..."<<endl;
                break;
        }
    }
    return 0;
}
void trapezy(double a, double b, int m, int wyb){
    double h = (b-a)/m;
    double x = 0;
    double sum=0;
    if (wyb==1){
        for (int i=0; i<=m; i++){
            if (i==0 || i==m){
                sum+=0.5*((sin(x)*sin(x))+2);
            }else{
                sum+=sin(x)*sin(x)+2;
            }
            x+=h;
        }
        sum*=h;
    }else{
        for (int i=0; i<=m; i++){
            if (i==0 || i==m){
                sum+=0.5*(pow(e, x)*2*pow(x, 3));
            }else{
                    sum+=pow(e, x)*2*pow(x, 3);
            }
                x+=h;
            }
            sum*=h;
    }
    cout<<"Aproksymowana wartość: "<<sum<<endl;
}
void simpsona(double a, double b, int m, int wyb){
    if (m%2==0){
    double h = (b-a)/m;
    double x = 0;
    double sum=0;
    if (wyb==1){
        for (int i=0; i<=m; i++){
            if (i==0 || i==m){
                sum+=sin(x)*sin(x)+2;
            }else if (i%2==1){
                sum+=4*(sin(x)*sin(x)+2);
            }else{
                sum+=2*(sin(x)*sin(x)+2);
            }
            x+=h;
        }
        sum*=h/3;
    }else{
        for (int i=0; i<=m; i++){
            if (i==0 || i==m){
                sum+=pow(e, x)*2*pow(x, 3);
            }else if (i%2==1){
                    sum+=4*(pow(e, x)*2*pow(x, 3));
            }else{
                sum+=2*(pow(e, x)*2*pow(x, 3));
            }
                x+=h;
        }
        sum*=h/3;
    }
        cout<<"Aproksymowana wartość: "<<sum<<endl;}else{
        cout<<"Liczba podprzedziałów musi być parzysta!"<<endl;
    }
}
