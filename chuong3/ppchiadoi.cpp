#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double cs[6]={};
void fx(){
    int bac;
    cout<<"Phuong trinh bac(chi tinh duoc tu phuong trinh bac 5 do ve): ";cin>>bac;
    switch (bac)
    {
    case 5:
        cout<<"_x^5 + _x^4 + _x^3 + _x^2 + _x + c\n";
        for (int i=5;i>=0;i--){
            cin>>cs[i];
        }
        break;
    case 4:
        cout<<"_x^4 + _x^3 + _x^2 + _x + c\n";
        for (int i=4;i>=0;i--){
                cin>>cs[i];
        }
        break;
    case 3:
        cout<<"_x^3 + _x^2 + _x + c\n";
        for (int i=3;i>=0;i--){
            cin>>cs[i];
        }
        break;
    case 2:
        cout<<"_x^2 + _x + c\n";
        for (int i=2;i>=0;i--){
            cin>>cs[i];
        }
    }
}
double f(double x){
    return cs[5]*pow(x,5) +  cs[4]*pow(x,4) +  cs[3]*pow(x,3) + cs[2]*pow(x,2) + cs[1]*x +cs[0];
}
void slove(){
    double a,b,ss;
    cout<<"Nhap doan lien tuc a b: ";cin>>a>>b;
    cout<<"Nhap sai so: ";cin>>ss;
    double c=(a+b)/2;
    fx();
    while (abs(b-a)>=ss)
    {
        if (f(c)*f(a)<0){
            a=a;b=c;
        }
        elif (f(c)*f(b)<0){
            a=c;b=b;
        }
        c=(a+b)/2;
    }
    cout<<c;
}
main(){//phuong phap chia doi
    slove();
    cerr<<endl<<"Time: "<<TIME;
}