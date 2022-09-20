#include <iostream>

using namespace std;

int main(){
    int min,max;

    cout << "************************\n";
    cout << "*****StarMinMax*****\n";
    cout << "************************\n";

    cout << "Min:";cin >> min;
    cout << "Max:";cin >> max;

    for(int i=1;i<=max-min+1;i++){
        for(int j=1;j<=min+i-1;j++){
            cout << '*';

        }
        cout << endl;
    }
    return 0;
}

