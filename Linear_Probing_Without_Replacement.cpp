#include <iostream>
using namespace std;

class HashTable
{
    int hash[10];
    int size;

public:
    HashTable()
    {
        size = 10;
        for(int i = 0; i < size; i++)
        {
            hash[i] = -1;
        }
    }

    void insert(int key)
    {
        int index = key % size;
        int start = index;

        while(hash[index] != -1)
        {
            index = (index + 1) % size;

            if(index == start)
            {
                cout << "Hash Table is Full!" << endl;
                return;
            }
        }

        hash[index] = key;
        cout << key << " inserted at index "
             << index << endl;
    }

    void display()
    {
        cout << "\nIndex\tValue\n";

        for(int i = 0; i < size; i++)
        {
            cout << i << "\t";

            if(hash[i] == -1)
                cout << "Empty";
            else
                cout << hash[i];

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;
    int n, key;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> key;
        h.insert(key);
    }

    h.display();

    return 0;
}