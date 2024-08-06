#include<bits/stdc++.h>
using namespace std;

void extractDigits(int n){
    while(n>0){
        int lastdigit = n%10;
        n = n/10;
        cout << lastdigit << endl;
    }
}
// TC -> O(log10(n))
void countDigits(int n){
    int cnt = 0;
    while(n>0){
        n = n/10;
        cnt += 1;
    }
    cout << cnt << endl;
}
// TC -> O(1)
void countDigits1(int n){
    int cnt = log10(n) + 1;
    cout << cnt;
}
void revNumber(int n){
    int revn = 0;
    while(n!=0){
        int lastdigit = n%10;
        n = n/10;
        if ((revn > INT_MAX/10) || (revn < INT_MIN/10)) 
                cout << 0;
        revn = ((revn*10) + lastdigit);
    }
    cout << revn << endl;
}
bool palindrome(int n){
    if (n < 0)
        return false;
    int revn = 0;
    int temp = n;

    while (temp != 0) {
        int lastdigit = temp % 10;
        revn = revn * 10 + lastdigit;
        temp = temp/10;
    }
    return (revn == n);
    
}
bool armstrongNum(int n){
    int temp = n;
    int temp1 = n;
    int sum = 0;
    int cnt = 0;
    while (temp1 > 0){
        temp1 = temp1 / 10;
        cnt+=1;
    }

    while(temp > 0){
        int lastdigit = temp % 10;
        temp = temp / 10;
        sum = sum + pow(lastdigit,cnt);
    }
    return(sum == n);
}
// TC -> O(n) takes more time for large no.
void alldivisors(int n){
    for(int i=1; i<=n; i++){
        if(n%i == 0)
            cout << i << " ";
    }
}
// TC -> O(sqrt(n))
void alldivisors1(int n){
    vector<int> ls;
    for(int i=1; i*i<=n; i++){   // i*i <= n is same as i <= sqrt(n)
        if(n%i == 0){
            ls.push_back(i);
            if(n/i != i)
                ls.push_back(n/i);
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it : ls) cout << it << " ";
}
// TC -> O(n)
void primecheck(int n){
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(n%i == 0)
            cnt++;
    }
    if(cnt == 2) cout << "Prime";
    else cout << "Not Prime";
}
// TC -> O(sqrt(n))
void primecheck1(int n){
    int cnt = 0;
    for(int i = 1; i*i<=n; i++){   // i*i <= n is same as i <= sqrt(n)
        if(n%i == 0){
            cnt++;
            if(n/i != i)
                cnt++;
        }
    }
    if(cnt == 2) cout << "Prime" << endl;
    else cout << "Not Prime" << endl;
}
// TC -> O(min(n1, n2))
void gcd(int n1, int n2){
    for(int i = min(n1,n2); i>=1; i--){  // Loop in reverse since we need Greatest value
        if(n1%i == 0 && n2%i == 0){
            cout << i;
            break;
        }
    }
} // but if n1 and n2 are 11 and 13 it'll take more time since it has to loop from 11 to 1
// TC -> O(log phi(min(n1, n2))) Euclidean Algorithm
void gcd1(int n1, int n2){
    while(n1 > 0 && n2 > 0){
        if(n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1; 
    }
    if (n1 == 0) cout << n2;
    else cout << n1;
}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n1, n2;
        cin >> n1 >> n2;
        gcd1(n1, n2);
    }
    return 0;
}