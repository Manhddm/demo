#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
double c[100][100],a[100][100],d[100],x[100];
int n;
void out(double a[][100],int n){
      for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void xuly();
void jacobi(){
    for (int i=0;i<n;i++){
        d[i]=d[i]/a[i][i];
        for (int j=0;j<n;j++){
            if (i==j) c[i][j]=0;
            else{
                c[i][j]=-1*a[i][j]/a[i][i];
            }
        }
    }
    double xx[100];
    double maxx=0;
    for (int i=0;i<n;i++) xx[i]=d[i];
    while(1){
      for (int i=0;i<n;i++){
        double s=0;
        for (int j=0;j<n;j++){
          s+=c[i][j]*xx[j] ;
        }
        for (int i=0;i<n;i++) x[i]=s;
      }
      for (int i=0;i<n;i++){xx[i]=x[i];maxx=max(maxx,x[i]-x[i-1])};//fix tiep doan nay
  }
}
int ktct(int n,double a[][100])
{
    float t;
    for(int i=1;i<=n;i++)
    {
        t=0;
        for(int j=1;j<=n;j++) t+=fabs(a[i][j]);
        if(t >= 2*fabs(a[i][i])) return 0;
    }
    return 1;
}
void slove(){
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (j==n-1) {
                cin>>a[i][j];
                cin>>d[i];
            }
            else cin>>a[i][j];
        }
    }
    jacobi();
}
main(){
    slove();
    cerr<<endl<<"Time: "<<TIME;
}