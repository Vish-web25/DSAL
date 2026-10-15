#include <iostream>
using namespace std;

class HashTable
{
    int hashTable[20];
    int size;

public:

    void createTable()
    {
        cout << "Enter hash table size: ";
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            hashTable[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insertWithoutReplacement(int key)
    {
        int index = hashFunction(key);

        while (hashTable[index] != -1)
        {
            index = (index + 1) % size;
        }

        hashTable[index] = key;
    }

    void insertWithReplacement(int key)
    {
        int index = hashFunction(key);

        // If location is empty
        if (hashTable[index] == -1)
        {
            hashTable[index] = key;
            return;
        }

        // Check whether existing key belongs to this index
        if (hashFunction(hashTable[index]) != index)
        {
            int temp = hashTable[index];

            hashTable[index] = key;

            // Insert displaced key
            int i = (index + 1) % size;

            while (hashTable[i] != -1)
            {
                i = (i + 1) % size;
            }

            hashTable[i] = temp;
        }
        else
        {
            // Existing key belongs here SYNONYMS
            int i = (index + 1) % size;

            while (hashTable[i] != -1)
            {
                i = (i + 1) % size;
            }

            hashTable[i] = key;
        }
    }

    void display()
    {
        cout << "\nHash Table:\n";

        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";

            if (hashTable[i] == -1)
                cout << "Empty";
            else
                cout << hashTable[i];

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    int choice, key, method;

    do
    {
        cout << "\n===== Hash Table Menu =====";
        cout << "\n1. Create Hash Table";
        cout << "\n2. Insert Key";
        cout << "\n3. Display Hash Table";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.createTable();
            break;

        case 2:
            cout << "\nEnter key: ";
            cin >> key;

            cout << "\n1. Without Replacement";
            cout << "\n2. With Replacement";
            cout << "\nEnter method: ";
            cin >> method;

            if (method == 1)
                h.insertWithoutReplacement(key);
            else if (method == 2)
                h.insertWithReplacement(key);
            else
                cout << "Invalid Method!";

            break;

        case 3:
            h.display();
            break;

        case 4:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
