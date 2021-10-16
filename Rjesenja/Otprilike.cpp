#include <iostream>
#include <cstdio>

using namespace std;

int main(void){

    int n, m, k;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);

    cout << (n * m * k) + 1;

    return 0;
}