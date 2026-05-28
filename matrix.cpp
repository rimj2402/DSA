// #include<bits/stdc++.h>
// using namespace std;
// // matrix addition
// int main(){
//     int m,n;
//     cin>>m>>n;
//    vector<vector<int>> a(m,vector<int>(n,0));
//     vector<vector<int>> b(m,vector<int>(n,0));
//     vector<vector<int>> sum(m,vector<int>(n,0));
//     int count_add=0;
//     // cout<<"enter elements of first matrix"<<endl;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>a[i][j];
//         }
//     }
//     // cout<<"enter elements of second matrix"<<endl;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>b[i][j];
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             sum[i][j]=a[i][j]+b[i][j];
//                count_add++;
//         }
//     }
//     // cout<<"sum of two matrix is "<<endl;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout<<sum[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<"number of addition "<<count_add<<endl;
// }

// matrix multiplication
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int m,n,p,q;
//     cin>>m>>n>>p>>q;
//     int count_mul=0;
//     int count_add=0;
//     vector<vector<int>> a(m,vector<int>(n,0));
//     vector<vector<int>> b(p,vector<int>(q,0));
//     vector<vector<int>> result(m,vector<int>(q,0));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>a[i][j];
//         }
//     }
//     for(int i=0;i<p;i++){
//         for(int j=0;j<q;j++){
//             cin>>b[i][j];
//         }
//     }
//     if(n!=p){
//         cout<<"multiplication not possible"<<endl;
//         return 0;
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<q;j++){
//             result[i][j]=0;
//             for(int k=0;k<n;k++){
//                 result[i][j]=result[i][j]+a[i][k]+b[k][j];
//                 count_mul++;
//                 if(k>0){
//                     count_add++;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<m;i++){
//         for(int j=0;j<q;j++){
//             cout<<result[i][j]<<" ";
//         }cout<<endl;
//     }
//     cout<<"number of multiplication "<<count_mul<<endl;
//     cout<<"number of addition "<<count_add<<endl;
    
// }

#include <bits/stdc++.h>
using namespace std;

// multiplication using strassen's algorithm

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n,0));
    vector<vector<int>> b(m,vector<int>(n,0));
    vector<vector<int>> result(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    int count_mul=0;
    int count_add=0;
    int p1=a[0][1]*(b[1][0]-b[1][1]);
    int p2=(a[0][0]+a[0][1])*b[1][1];
    int p3=(a[1][0]+a[1][1])*b[0][0];
    int p4=a[1][1]*(b[0][0]-b[0][1]);
    int p5=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    int p6=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
    int p7=(a[0][0]-a[1][0])*(b[0][0]+b[0][1]);
    result[0][0]=p5+p4-p2+p6;
    result[0][1]=p1+p2;
    result[1][0]=p3+p4;
    result[1][1]=p1+p5-p3-p7;


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
}
