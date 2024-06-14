#include <bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int long long
#define endl "\n"
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double  x[100000],x_,n,y[100000];
double L(double xi){
    double t1=1,t2=1;
    for (int i=0;i<=n;i++){
        if (xi!=x[i]) {
            t1*=(x_-x[i]);
            t2*=(xi-x[i]);
        }
    }
    return t1/t2;
}
void inplagrange(){
    cin>>n>>x_;
    for (int i=0;i<=n;i++) cin>>x[i];
     for (int i=0;i<=n;i++) cin>>y[i];
}
void slove(){
    inplagrange();
    double p=0;
    for (int i=0;i<=n;i++){
        p+=y[i]*L(x[i]);
    }
    cout<<p<<endl;
}
main(){
    flash;
    slove();
    cout<<endl;
    cerr<<endl<<TIME;
}