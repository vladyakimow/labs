#include <iostream>
using namespace std;
int main () {
        double xn,xk,dx;
        cout <<"Enter xn,xk,dx";
        cin >> xn >> xk >> dx;
        double a,b,c;
        cout <<"Enter a,b,c";
        cin >> a >> b >> c;
        double f;
        for(double x = xn; x <=xk; x+=dx) {
            if(x < 0 && b!=0){
                f= -(2*x-c)/(c*x-a);
            }
            else if(x > 0 && b==0){
                f=(x-a)/(x-c);
            }
            else{
            f = -(x/c)+(-c/2*x);
            }
            
            if((int(a) | int(b)) & (int(a)|int(c)) == 0){
                f = int(f);
            }
            
            cout << "x =" <<x << "\tf = " << f << endl;
       }
       
       return 0;
}      
