//
//  main.cpp
//  kwadratury
//
//  Created by Людмила Маломуж on 23/11/2020.
//

#include <iostream>
#include <cmath>
#define pi 3.14159
#define e 2.71828
using namespace std;
void GaussaChebysheva();
void GaussLegendre();
void GaussHermite();
void GaussLaguerre();
int main(int argc, const char * argv[]) {
    int wyb=0;
    while (wyb!=5){
        cout<<"Wybierz kwadrature:\n";
        cout<<"1. f(x)=x/sqrt(1-x^2) na [-1;1], Gaussa-Chebysheva \n";
        cout<<"2. f(x)=1/sqrt(1-x^2) na [-1;1], Gaussa-Legendre'a \n";
        cout<<"3. f(x)=exp(-x^2)*cos(x) ma [-niesk; +niesk], Gaussa-Hermite'a \n";
        cout<<"4. f(x)=exp(-2x)*(sin(x)/(x)) na [0; +niesk], Gaussa-Laguerre'a \n";
        cout<<"5. Wyjscie.\n";
        cin>>wyb;
        switch(wyb){
            case(1): GaussaChebysheva();
                break;
            case (2) : GaussLegendre();
                break;
            case(3): GaussHermite();
                break;
            case(4): GaussLaguerre();
                break;
            default: cout<<"Podano niepoprawna wartosc...";
                break;
        }
    }
    return 0;
}
void GaussaChebysheva(){
    
    double res = 0;
    double x;
    for (int j = 0; j<=3; j++){
        x = cos(((2*j+1)*pi)/(2*(3+1)));
        res += x*x;
    }
    double H = pi/(3+1);
    res *= H;

    cout<<"przyblizona wartosc calki metoda Gaussa-Chebysheva wynosi: "<<res<<endl;
}
void GaussLegendre(){
    double h0 = 0.236927;
    double h1 = 0.478629;
    double h2 = 0.568889;
    double h4 = h0;
    double h3 = h1;
    double x0 = -0.90618;
    double x1 = -0.538469;
    double x2 = 0;
    double x4 = -x0;
    double x3 = -x1;
    double res = (1/sqrt(1+x0*x0)*h0)+ (1/sqrt(1+x1*x1)*h1) + (1/sqrt(1+x2*x2)*h2) + (1/sqrt(1+x3*x3)*h3) + (1/sqrt(1+x4*x4)*h4);
    cout<<"Przyblizona wartosc calki metoda Gaussa-Legendre'a wynosi: "<<res<<endl;
}
void GaussHermite(){
    double h0 = 0.019953;
    double h1 = 0.393619;
    double h2 = 0.945309;
    double h4 = h0;
    double h3 = h1;
    double x0 = -2.020183;
    double x1 = -0.958572;
    double x2 = 0;
    double x4 = -x0;
    double x3 = -x1;
    double res = (cos(x0)*h0)+ (cos(x1)*h1) + (cos(x2)*h2) + (cos(x3)*h3) + (cos(x4)*h4);
    cout<<"Przyblizona wartosc calki metoda GaussaHermite'a wynosi: "<<res<<endl;
}
void GaussLaguerre(){
    double h0 = 0.603154;
    double h1 = 0.357419;
    double h2 = 0.038888;
    double h3 = 0.000539;
    double x0 = 0.322548;
    double x1 = 1.745761;
    double x2 = 4.53662;
    double x3 = 9.395071;
    double res = (exp(-x0)*(sin(x0)/x0)*h0)+ (exp(-x1)*(sin(x1)/x1)*h1) + (exp(-x2)*(sin(x2)/x2)*h2) + (exp(-x3)*(sin(x3)/x3)*h3);
    cout<<"Przyblizona wartosc calki metoda GaussLaguerre'a wynosi: "<<res<<endl;
}
