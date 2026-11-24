#include <iostream>
using namespace std;

class HeapSort
{
    int a[50];
    int n;

public:
    void read()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void heapify(int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && a[left] > a[largest])
        {
            largest = left;
        }

        if(right < n && a[right] > a[largest])
        {
            largest = right;
        }

        if(largest != i)
        {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            heapify(n, largest);
        }
    }

    void sort()
    {
        // Build Max Heap
        for(int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(n, i);
        }

        // Extract maximum element
        for(int i = n - 1; i > 0; i--)
        {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            heapify(i, 0);
        }
    }

    void display()
    {
        cout << "\nSorted elements in Ascending Order:\n";

        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    HeapSort h;

    h.read();
    h.sort();
    h.display();

    return 0;
}