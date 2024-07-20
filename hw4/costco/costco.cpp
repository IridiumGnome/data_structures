#include <iostream>
#include <vector>

using namespace std;

vector <vector <char>> groups;

struct que
{
    char data;
    que *right, *left;
};

bool check(char x, char y){
    for(int i = 0; i<groups.size(); i++){
        bool x1= false, y1 = false;
        for(int j =0; j<groups[i].size(); j++){
            if(groups[i][j] ==x) x1= true;
            if(groups[i][j] == y) y1 =true;
        }
        if(x1 && y1){
            return true;
        }
    }
    return false;
}

void add(que **last, char customer)
{
    que *v = new que;
    v->right = NULL;
    v->data = customer;
    v->left = *last;

    if (*last)
        (*last)->right = v;

    *last = v;

}

void insert_in(char x, que *elem, char y, que **start)
{
    que *v = new que;
    while (elem)
    {
        if (elem->data == x)
        {
            v->data = y;
            v->right = elem;
            v->left = elem->left;
            if (elem->left)
            {
                (elem->left)->right = v;
            }
            else
            {
                *start = v;
            }
            elem->left = v;
            break;
        }
        elem = elem->right;
    }
}

void print(que *elem)
{
    while(elem)
    {
        cout << elem->data << endl;
        elem = elem->right;
    }
}

int main()
{
    que *first, * last;

    first = NULL;
    last = NULL;

    int n, m;

    cin >> n;
    groups.resize(n);

    for (int i = 0; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            char A;
            cin >> A;
            groups[i].push_back(A);

        }
    }

    string input;
    char customer;

    while(cin >> input){
        if (input[0] == 'E'){
            cin >> customer;
            if (first == NULL){
                add(&first, customer);
                last = first;
                //print(first);
            }
            else {
                que *current = new que;
                current = first;
                bool checkif = false;
                while(current){
                    char word = current -> data;
                    if(check(customer, word)){
                        //cout << "same";
                        insert_in(word, first, customer, &first);
                        //print(first);
                        checkif = true;
                        break;
                    }
                    current = current -> right;
                }
                if(!checkif){
                    add(&last, customer);
                    //print(first);
                }
            }
        }
        else if (input[0] == 'D'){
            if (first != NULL){
                que *temp = first;
                cout << temp -> data << "\n";
                (first->right)->left = NULL;
                first = first->right;
                delete temp;
                //print(first);
            }
        }
    }
}
