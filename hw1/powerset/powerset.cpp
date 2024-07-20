#include <iostream>
#include <vector>

using namespace std;

void Function(vector <string> ourVector, int j, string a){
    cout << ("{" + a.substr(0, a.size() - 1) + "}"); 
    for (int i = j + 1; i < ourVector.size(); i++) 
    { 
        Function(ourVector, i, a + ourVector[i] + " ");
    }
}

int main(void){

    string input; 
    while(getline(cin, input))
    {
        vector <string> ourVector;
        string space = "";  
        for (int i = 0; i < input.size(); i++)  
        {
            if (input[i] != ' ') 
            {
                space += input[i];
            }
            if (input[i] == ' ' || i == input.size() - 1)
            {
                ourVector.push_back(space);
                space = "";
            }
        }
        Function(ourVector, -1, ""); 
        cout << endl;
    }
}


