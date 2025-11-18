// Implement Heapsort (Increasing/Decreasing order).

// Time:  O(n log n)
// Space: O(1)

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
        int index = ++size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }


    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest])
            largest = left;

        if (right <= n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }



    void heapifymin(int arr[], int n, int i)
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] < arr[smallest])
            smallest = left;
        if (right <= n && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapifymin(arr, n, smallest);
        }
    }


    void heapsort(int arr[], int n)
    {
        int size = n;
        while (size > 1)
        {
            swap(arr[1], arr[size]);
            size--;

            heapify(arr, size, 1);
        }
    }


     void heapsortmin(int arr[], int n)
    {
        int size = n;
        while (size >1)
        {
            swap(arr[1], arr[size]);
            size--;

            heapifymin(arr, size, 1);
        }
    }


    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    cout << "max heap ";
    for (int i = (n / 2); i > 0; i--)
    {
        h.heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    cout << "min heap ";
    for (int i = (n / 2); i > 0; i--)
    {
        h.heapifymin(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    cout << "heap sort ascending ";

    int arr2[6]={-1,70,60,55,45,50};

    h.heapsort(arr2,n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;



    cout << "heap sort descending ";

    int arr3[6]={-1,50 ,52 ,54, 55 ,53 };

    h.heapsortmin(arr3,n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;


    return 0;
}