#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
vector<double> x,y,tsp,sp;
int n;
double x_;
void inp(){
    cout<<"Nhap so luong phan tu va x* cab tim: ";
    cin>>n>>x_;
    cout<<"Nhap cac gia tri x: ";
    for (int i=0;i<=n;i++){
        double tmp;
        cin>>tmp;
        x.push_back(tmp);
    }
    cout<<"Nhap cac gia tri y: ";
    for (int i=0;i<=n;i++){
        double tmp;
        cin>>tmp;
        y.push_back(tmp);
    }
}
void SPTIEN(){
    int c=0;
    while (sp.size()<=n){
        sp.push_back(y[0]);
        for (int i=0;i<=n-c;i++){
            y[i]=y[i+1]-y[i];
        }
        c++;
    }
}
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
void SPLUI(){
    int c=0;
    while (sp.size()<=n){
        sp.push_back(y[n-c]);
        for (int i=0;i<=n-c;i++){
            y[i]=y[i+1]-y[i];
        }
        c++;
    }
}
void TSP(){
    int c=0;
    while (tsp.size()<=n){
        tsp.push_back(y[0]);
        for (int i=0;i<=n-c;i++){
            y[i]=(y[i+1]-y[i])/(x[i+c+1]-x[i]);
        }
        c++;
    }
}
void newtontrenluoikhongdeu(){
    inp();
    TSP();
    double tmp=x_-x[0];
    double p=tsp[0];
    for (int i=1;i<=n;i++){
        p+=tsp[i]*tmp;
        tmp*=x_-x[i];
    }
    cout<<"P("<<x_<<")= "<<p<<endl;
}
void newtontien(){
    inp();
    SPTIEN();
    double p=sp[0];
    double t=(x_-x[0])/(x[1]-x[0]),k;k=t;
    int gt=1;
    for (int i=1;i<=n;i++){
        p+=t*sp[i]/gt;
        gt*=i+1;
        t*=k-1;
        k--;
    }
    cout<<"P("<<x_<<")= "<<p<<endl;
}
void newtonlui(){
    inp();
    SPLUI();
    double p=sp[0];
    double t=(x_-x[n])/(x[1]-x[0]),k;k=t;
    int gt=1;
    for (int i=1;i<=n;i++){
        p+=t*sp[i]/gt;
        gt*=i+1;
        t*=k+1;
        k++;
    }
    cout<<"P("<<x_<<")= "<<p<<endl;
}
void lagrange(){
    inp();
    double p=0;
    for (int i=0;i<=n;i++){
        p+=y[i]*L(x[i]);
    }
    cout<<"P("<<x_<<")= "<<p<<endl;
}
main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c=1;
    while(c){cout<<"Chon phep tinh ban muon:\n\t1.Lagrange\n\t2.Newton Tien\n\t3.Newton lui\n\t4.Newton tren luoi khong deu\n(vi du: 1 la Lagrange)\n";
    int pt;
    cin>>pt;
    switch (pt)
    {
    case 1:
        cout<<"Phep tinh lagrange\n";
        lagrange();
        break;
    case 2:
    cout<<"Phep tinh Newton tien\n";
        newtontien();
        break;
    case 3:
    cout<<"Phep tinh Newton lui\n";
        newtonlui();
        break;
    case 4:
    cout<<"Phep tinh Newton tren luoi khong deu\n";
        newtontrenluoikhongdeu();
        break;
    default:
        cout<<"Loi!!!";
        break;
    
    }
    cin>>c;
    }
    cerr<<endl<<"Time: "<<TIME;
}