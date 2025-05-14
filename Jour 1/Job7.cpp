#include <iostream>
using namespace std;
int main() {
    int n ;
    cout<<" Entrer un entier:";
    cin>> n ;
    if (n % 2 ==  0)
        cout<<n<<" est pair";
    else
        cout<<n<<" est impair";
    return 0;
}
