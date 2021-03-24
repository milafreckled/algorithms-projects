//
//  main.cpp
//  Bisekcja_i_Newtona
//
//  Created by Людмила Маломуж on 15/01/2021.
//

#include <iostream>
#include <cmath>
using namespace std;
void bisekcja(double a, double b){
    int licznik=0;
    double s = (a+b)/2;
    double epsilon = (pow(a, 3)-71)*(pow(b, 3)-71);
    if (epsilon < 0){
        while ((pow(s, 3)-71) >= epsilon){
            s = (a+b)/2;
            epsilon = (pow(a, 3)-71)*(pow(b, 3)-71);
            if (epsilon<0){
                b = s;
            }else{
                a = s;
            }
            licznik++;
        }
        cout<<"Pierwiastkiem jest: "<<(a+b)/2<<"z wartoscia funkcji: "<<pow((a+b)/2, 3)-71<<endl;
        cout<<"Liczba iteracji "<<licznik<<endl;
    }else{
        cout<<"Wartosci funkcji na koncach przedzialu musza miec rozne znaki!";
    }
}
float Newtona(int x0, float eps){
    //f(x) = x^2 - 6
    //f'(x) = 2x
    float x = x0 - (pow(x0, 2)-6)/(2*x0);
    while(abs((pow(x, 2) - 6)) >= eps){
        x = x - (pow(x, 2) - 6)/(2*x);
    }
    //cout<<"Pierwiastkiem jest: "<<x<<" z wartoscia funkcji: "<<pow(x, 3) - 71<<endl;
    //cout<<"Liczba iteracji "<<licznik<<endl;
    return x;
}
int main(int argc, const char * argv[]) {
    //x^3 - 71 = 0;
    //3x^2

    double a = 4;
    double b = 5;
    double x0= 4;
    bisekcja(a, b);
    cout<<Newtona(4, 0.1)<<endl;
    return 0;
}
