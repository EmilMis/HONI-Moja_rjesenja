#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool is_mm(char digit){
    if (digit == '0' || digit == '6' || digit == '9' || digit == '8'){
        return true;
    }
    return false;
}

int main(void){
    string broj;
    cin >> broj;
    cout << broj;

    for (char letter : broj){
        if (!is_mm(letter)){
            cout << "NE";
            return 0;
        }
    }

    if (broj[broj.size() - 1] == '0'){
        cout << "NE";
        return 0;
    }

    cout << "DA";
    return 0;

}