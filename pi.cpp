#include <cmath>
#include <iostream>

using namespace std;

double min(double a, double b){
    if(a < b){
        return a;
    }
    return b;
}

int main(){

    double num = 3.0;
    double denom = 1.0;
    const double pi = 3.1415926535;

    //could probably have better memory effeciency here
    double saveN10;
    double saveD10;
    double saveN100;
    double saveD100;
    double saveN1k;
    double saveD1k;

    //something nowhere close to the best to get the initIal min(a,b) calculation going
    double bestdiff = 10.0;

    //holds the value of the num over the denom
    double calc;

    //10
    for(denom = 1.0; denom < 10; denom += 1.0){
        for(num = denom * 3.0; num < 31.5; num += 1.0){
            calc = num/denom * 1.0;
            calc = abs(calc - pi);
            bestdiff = min(bestdiff, calc);
            if(bestdiff == calc){
                saveN10 = num;
                saveD10 = denom;
            }
        }
    }

    //100
    for(denom = 1.0; denom < 100; denom += 1.0){
        for(num = denom * 3.0; num < 315; num += 1.0){
            calc = num/denom * 1.0;
            calc = abs(calc - pi);
            bestdiff = min(bestdiff, calc);
            if(bestdiff == calc){
                saveN100 = num;
                saveD100 = denom;
            }
        }
    }

    //1000
    for(denom = 1.0; denom < 1000; denom += 1.0){
        for(num = denom * 3.0; num < 3150; num += 1.0){
            calc = num/denom * 1.0;
            calc = abs(calc - pi);
            bestdiff = min(bestdiff, calc);
            if(bestdiff == calc){
                saveN1k = num;
                saveD1k = denom;
            }
        }
    }

    cout << "For 10: " << saveN10 << " over " << saveD10 << ": " << (saveN10/saveD10) << ". Is only " << (saveN10/saveD10)-pi << " far off." << "\n";
    cout << "For 100: " << saveN100 << " over " << saveD100 << ": " << (saveN100/saveD100) << ". Is only " << (saveN100/saveD100)-pi << " far off."  << "\n";
    cout << "For 1000: " << saveN1k << " over " << saveD1k << ": " << (saveN1k/saveD1k) << ". Is only " << (saveN1k/saveD1k)-pi << " far off."  << "\n"; 

    return 0;
}