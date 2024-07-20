#include <iostream>
#include <time.h>

using namespace std;

struct node
{
    string data;
    node *next;
};

node *first = NULL;
node *last = NULL;

void display()
{
    node *current = first;
    while(current)
    {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << "\n";
}

void searchElement(string element)
{
    node* current = first;
    while(current -> data != element)
    {
        if(first == last) return;
        node *current = first;
        if(current -> data != element)
        {
            first = current -> next;
            current -> next = NULL;
            last -> next = current;
            last = current;
            display();
        }
        else
        {
            node* current = first;
            first = first -> next;
            delete current;
            display();
            return;
        }
    }

    if(current -> data == element)
    {
        node* current = first;
        first = first -> next;
        delete current;
        display();
        return;
    }

}

void insertNode(string element)
{
    node *newNode = new node;
    newNode -> data = element;
    newNode -> next = NULL;
    if(first == NULL)
    {
        first = newNode;
        last = newNode;
        //newNode = NULL;
    }
    else
    {
        last -> next = newNode;
        last = newNode;
    }
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
    int num = 13;
    shuffle(arr, num);
    for(int i =0; i< num; i++)
    {
        insertNode(arr[i]);
    }

    display();

    searchElement("K");
    searchElement("Q");
    searchElement("J");
    searchElement("10");
    searchElement("9");
    searchElement("8");
    searchElement("7");
    searchElement("6");
    searchElement("5");
    searchElement("4");
    searchElement("3");
    searchElement("2");
    searchElement("A");
}
