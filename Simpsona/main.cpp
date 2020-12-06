//
//  main.cpp
//  Simpsona
//
//  Created by Людмила Маломуж on 04/12/2020.
//

#include <iostream>
using namespace std;
float simpson(int a, int b, int w){
    float h = (b - a)/(w*1.0);
    float xi = a+h;
    float res = (1/(2*a))+(1/(2*b));
    for (int i = 1; i<w; i++){
        if (i%2!=0){
            res += 4 * (1/(2*xi));
        }else{
            res += 2 *(1/(2*xi));
        }
        xi += h;
    }
    res *= h/3;
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 2;
    int b  = 4;
    int w = 4;
    cout << "Wartosc calki od 2 do 4: "<<simpson(a, b, w)<<endl;
    return 0;
}
