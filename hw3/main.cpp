#include <iostream>
#include <vector>

using namespace std;

vector <vector <char> > friends;
vector <char> que;

bool check(char x, char y){
    for(int i = 0; i<friends.size(); i++){
        bool x1= false, y1 = false;
        for(int j =0; j<friends[i].size(); j++){
            if(friends[i][j] ==x) x1= true;
            if(friends[i][j] == y) y1 =true;
        }
        if(x1 && y1){
            return true;
        }
    }
    return false;
}

void AddFriend(char a)
{
    for(int i = 0 ; i< que.size(); i++){
        if(check(que[i],a)){
            que.insert(que.begin()+i, a);
            return;
        }
    }
    que.push_back(a);
}


int main()
{
    vector <char> store;
    int n;

    cin >> n;
    friends.resize(n);
    for(int i = 0, m; i< n; i++){
        cin >> m;
        for(int j = 0; j<m; j++){
            char x;
            cin >> x;
            friends[i].push_back(x);
        }
    }

    string input;

    while(cin >> input){
        if(input[0] == 'E'){
            char M;
            cin>>M;
            AddFriend(M);
        }
        else if (input[0] == 'D'){
            //cout << que[0] << "\n";
            store.push_back(que[0]);
            que.erase(que.begin(), que.begin()+1);
        }
    }
    for (char i : store)
    {
        cout << i << endl;
    }
}
