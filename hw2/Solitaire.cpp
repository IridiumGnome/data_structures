#include <iostream>
//#include <vector>
#include <stdlib.h>
//#include <algorithm>
#include <time.h>

using namespace std;

int deleteElement(string arr[], int count, string x, string arr2[]){

    string tmp;
    int num1 = count-1;

    while(arr[0]!=x){
        tmp = arr[0];
            for(int k = 0; k<count-1; k++){
                arr[k] = arr[k+1];
            }
        arr[count-1] = tmp;
        for(int i = 0; i< count; i++){
            cout<< arr[i]<< " ";
        }
        cout<<"\n";
    }
        if(arr[0] == x){
            for(int i = 0; i<num1; i++){
                arr2[i]=arr[i+1];
            }
        }

    count-=1;

    for(int i = 0; i< num1; i++){
        cout << arr2[i]<< " ";
    }
    cout<<"\n";

    return count;
}

void change(string *x, string*y){
    string tmp = *x;
    *x=*y;
    *y=tmp;
}

void shuffle(string arr[], int count){
    //to prevent sequence repetition between runs
    srand(time(NULL));
    for(int i = count -1; i>0; i--){
        int j =rand()%(i+1);
        change(&arr[i], &arr[j]);
    }
}

int main()
{
    string arr[13] = {"K","Q","J","10","9","8","7","6","5","4","3","2","A"};
    //vector<string> symb{"K","Q","J","10","9","8","7","6","5","4","3","2","A"};
    int count = 13;
    //vector <string>check = symb;
    //random_shuffle(symb.begin(), symb.end());
    shuffle(arr, count);

    for(int i = 0; i< count; i++){
        //arr[i] = symb[i];
        cout << arr[i]<< " ";
    }
    cout<< "\n";

    int num = count -1;
    string arr2[num];

    count = deleteElement(arr, count, "K", arr2);
    num = count -1;
    string arr3[num];
    count = deleteElement(arr2, count, "Q", arr3);
    num = count -1;
    string arr4[num];
    count = deleteElement(arr3, count, "J", arr4);
    num = count -1;
    string arr5[num];
    count = deleteElement(arr4, count, "10", arr5);
    num = count -1;
    string arr6[num];
    count = deleteElement(arr5, count, "9", arr6);
    num = count -1;
    string arr7[num];
    count = deleteElement(arr6, count, "8", arr7);
    num = count -1;
    string arr8[num];
    count = deleteElement(arr7, count, "7", arr8);
    num = count -1;
    string arr9[num];
    count = deleteElement(arr8, count, "6", arr9);
    num = count -1;
    string arr10[num];
    count = deleteElement(arr9, count, "5", arr10);
    num = count -1;
    string arr11[num];
    count = deleteElement(arr10, count, "4", arr11);
    num = count -1;
    string arr12[num];
    count = deleteElement(arr11, count, "3", arr12);
    num = count -1;
    string arr13[num];
    count = deleteElement(arr12, count, "2", arr13);
    num = count -1;
    string arr14[num];
    count = deleteElement(arr13, count, "A", arr14);
    num = count -1;
}
