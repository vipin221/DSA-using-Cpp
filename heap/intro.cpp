#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }

    void deleteFromHeap()
    {

        if (size == 0)
            return;

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if ((leftIndex < size) && (arr[leftIndex] > arr[i]))
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if ((rightIndex < size) && (arr[rightIndex] > arr[i]))
            {
                swap(arr[i], arr[rightIndex] );
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int *arr, int n , int i){

    int largest = i;
    int leftInd = 2*i;
    int rightInd = 2*i + 1;

    if(leftInd <= n && arr[largest] < arr[leftInd]){
        largest = leftInd;
    }
    if(rightInd <= n && arr[largest] < arr[rightInd]){
        largest = rightInd;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }


}
void HeapSort( int arr[], int n){
    int size = n;

    while(size > 1){

        // step 1
        swap(arr[size], arr[1]);
        size--;

        // step 2 
        heapify(arr, size , 1);
    }
}

int main()
{

    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    // h.deleteFromHeap();
    // cout <<" after deleting "<<endl;
    // h.print();




    int arrr[9]= {-1, 50, 55,  53, 52,  30, 10, 20, 54};
    int n =8;
    for(int i=n/2; i>0; i--){
        heapify(arrr,n, i);
    }

    cout<<" Printing the hepaify "<< endl;
    for(int i=1; i<=n; i++ ){
        cout << arrr[i] << " ";
    }
    cout << endl;

    HeapSort(arrr, n);

    cout << "Printing sorted heap  " << endl;
    
    for(int i=1; i<=n; i++ ){
        cout << arrr[i] << " ";
    }
    cout << endl;

    return 0;
}