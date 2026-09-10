
#include <iostream>
using namespace std;

struct Node
{
    int bookID;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:

    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int id)
    {
        Node* newNode = new Node();

        newNode->bookID = id;
        newNode->next = head;

        head = newNode;

        cout << "Book inserted at beginning." << endl;
    }

    // Insert at end
    void insertEnd(int id)
    {
        Node* newNode = new Node();

        newNode->bookID = id;
        newNode->next = NULL;

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            cout << "Book inserted at end." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Book inserted at end." << endl;
    }

    // Delete from beginning
    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        head = head->next;

        cout << "Book ID " << temp->bookID
             << " deleted." << endl;

        delete temp;
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Book IDs: ";

        while (temp != NULL)
        {
            cout << temp->bookID << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int choice;
    int id;

    do
    {
        cout << "\n----- LIBRARY MENU -----" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            list.insertBeginning(id);
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            list.insertEnd(id);
            break;

        case 3:
            list.deleteBeginning();
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
