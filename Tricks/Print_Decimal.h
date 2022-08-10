#include<bits/stdc++.h>
using namespace std;
int main(){
    double x=123.456789012345678;

    //  printing the value without any specification. The number of digits in output may not be adequate enough.
    cout << x << '\n';                          // 123.457

    // specifying to output 12 significant digits.
    cout << std::setprecision(12) << fixed << x << '\n'; // 123.456789012

    // specifying to output 12 digits after the decimal point.
    printf("%.12lf\n",x);                       // 123.456789012346
}