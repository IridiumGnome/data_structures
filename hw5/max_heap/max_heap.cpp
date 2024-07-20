#include <iostream>

using namespace std;

void MaxHeap(int *arr, int m, int n)
{
   int child, parent;

   parent = arr[m];
   child = 2 * m;

   while (child <= n) {
      if (child < n && arr[child+1] > arr[child])
         child = child + 1;
      if (parent > arr[child])
         break;
      else if (parent <= arr[child]) {
         arr[child / 2] = arr[child];
         child = 2 * child;
      }
   }

   arr[child/2] = parent;
   return;
}

void CreateHeap(int *arr, int n)
{
   int k;

   for(k = n/2; k >= 1; k--)
      MaxHeap(arr, k, n);
}

int main()
{
    int T, M, N;
    int * arr;

    cin >> T; // # of cases

    for(int i =0; i < T; i++){

        int price = 0;

        cin >> M; // # of rows
        cin >> N; // # of fans

        arr = new int [M];

        for(int j = 1; j <= M; j++)
            cin >> arr[j];

        CreateHeap(arr, M);

        int f = 1;

        for(int k = 0; k < N; k++){

            int largest = arr[1];

            for(int i = 2; i <= M; i++) {
                if(largest < arr[i]){
                    largest = arr[i];
                    f = i;
                }
            }

            price +=  largest;
            arr[f] = largest - 1;

            CreateHeap(arr, M);
        }
        cout << price << "\n";
        delete[] arr;
    }
}
