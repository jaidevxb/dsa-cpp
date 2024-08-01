#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<"* ";
        cout << endl;
    }
}
void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cout<<"* ";
        cout << endl;
    }
}
void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cout<<j<<" ";
        cout << endl;
    }
}
void pattern4(int n){
    for(int i=1; i<=3; i++){
        for(int j=1; j<=i; j++)
            cout<<i<<" ";
        cout << endl;
    }

}
void pattern5(int n){
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--)
            cout<<"* ";
        cout << endl;
    }
}
void pattern6(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++)
            cout<<j<<" ";
        cout << endl;
    }
}
void pattern7(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++)
            cout<<" ";
        for(int j=1; j<=2*i+1; j++)
            cout<<"*";
        for(int j=1; j<n-i; j++)
            cout<<" ";
        cout<<endl;
    }
}
void pattern8(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<2*n-(2*i+1); j++)
            cout<<"*";
        for(int j=0; j<i; j++)
            cout<<" ";
        cout<<endl;
    }
}
void pattern10(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=1; j<=stars; j++)
            cout<<"*";
        cout<<endl;
    }
}
void pattern11(int n){
    for(int i=0; i<n; i++){
        int first=0;
        if(i%2==0) first=1;
        for(int j=0; j<=i; j++){
            cout<<first;
            first = 1 - first;
        }
        cout<<endl;
    }
}
void pattern12(int n){
    int space = 2 * (n-1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cout<<j;
        for(int j=1; j<=space; j++)
            cout<<" ";
        for(int j=i; j>=1; j--)
            cout<<j;
        cout<<endl;
        space -= 2;
    }
}
void pattern13(int n){
    int a=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<a<<" ";
            a += 1;
        }
        cout<<endl;  
    }
    
}
void pattern14(int n){
    for(int i=1; i<=n; i++){
        for(char ch='A'; ch < 'A'+i; ch++)
            cout<<ch<<" ";
        cout<<endl;
    }
}
void pattern15(int n){
    for(int i=0; i<n; i++){
        for(char ch='A'; ch <= 'A'+ (n - i - 1); ch++)
            cout<<ch<<" ";
        cout<<endl;
    }
}
void pattern16(int n){
    for(int i=0; i<n; i++){
        char ch='A'+i;
        for(int j=0; j<=i; j++)
            cout<<ch<<" ";
        cout<<endl;
    }
}
void pattern17(int n){
    for(int i=0; i<n; i++){
        char ch='A';
        int breakpoint =(2*i+1)/2;
        for(int j=1; j<n-i; j++)
            cout<<" ";
        for(int j=1; j<=2*i+1; j++){
            cout<<ch;
            if (j <= breakpoint) ch++;
            else ch--;
        }
        for(int j=1; j<n-i; j++)
            cout<<" ";
        cout<<endl;
    }
}
void pattern18(int n){
    for(int i=0; i<n; i++){
        for(char ch='E'- i; ch<='E'; ch++)
            cout<<ch<<" ";
        cout<<endl;
    }
}
void pattern19(int n){
    int intS=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++)
            cout<<"*";
        for(int j=1; j<=intS; j++)
            cout<<" ";
        for(int j=1; j<=n-i; j++)
            cout<<"*";
        cout<<endl;
        intS += 2;
    }
    intS = 2*n-2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cout<<"*";
        for(int j=1; j<=intS; j++)
            cout<<" ";
        for(int j=1; j<=i; j++)
            cout<<"*";
        cout<<endl;
        intS -= 2;
    }
}
void pattern20(int n){
    int space = 2*n-2;
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=1; j<=stars; j++)
            cout<<"*";
        for(int j=1; j<=space; j++)
            cout<<" ";
        for(int j=1; j<=stars; j++)
            cout<<"*";
        cout<<endl;
        if(i<n) space -= 2;
        else space += 2;
    }
}
void pattern21(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || j==1 || i==n || j==n) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}
void pattern22(int n){
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int top = i;
            int left = j;
            int down = (2*n - 2) - i;
            int right = (2*n - 2) - j;
            cout<< min(min(top,down) , min(right,left))<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        pattern22(n);
    }
    return 0;
}

