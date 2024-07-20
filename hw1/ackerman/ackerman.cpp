#include <iostream>

using namespace std;

int Function(int a, int b){
    if(a == 0){
        return b+1;
    }
    if(b == 0){
       return Function(a-1, 1);
    }
    else{
        return Function(a-1, Function(a, b-1));
    }

}

int main()
{
    int a, b;
    cout << "Please input numbers" << endl;
    while(!cin.eof()){
        cin >> a >> b;
        if(a >= 0 && a<= 5 && b>=0 && b<=5)
            cout << Function(a, b) << "\n";
        else
            cout << "the numbers are too big or too small" << endl;
        cout << "Please input numbers" << endl;
    }
}
