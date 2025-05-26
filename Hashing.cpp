#include <iostream>
#include <climits>
using namespace std;

#define hashMod 20
#define deleted INT_MAX
#define empty -1

class Hashing 
{
int hashArr[hashMod];

public:
    Hashing() 
    {
        fill_n(hashArr, hashMod, empty);
}

    int hashIndex(int value) 
    {
        return value % hashMod;
}

    bool linearProbing(int value) 
    {
        int start = hashIndex(value);
        int i = start, h = 1;

        do {
            if (hashArr[i] == empty || hashArr[i] == deleted) 
            {
                hashArr[i] = value;
                return true;
            }

            i = (start + h) % hashMod;
            h++;
        } 
        


        while (i != start);
        return false;
}
    bool quadraticProbing(int value) 
    {
        int start = hashIndex(value);
        int i = start, h = 1;

        do 
        {
            if (hashArr[i] == empty || hashArr[i] == deleted) 
            {
                hashArr[i] = value;
                return true;
            }

            i = (start + h * h) % hashMod;
            h++;
        } 
        
        while (i != start);
        return false;
}

    bool search(int value) 
    {
        int start = hashIndex(value);
        int i = start, h = 1;

        do {
            if (hashArr[i] == value) 
            {
                return true;
            }

            if (hashArr[i] == empty) 
            {
                return false;
            }


            i = (start + h) % hashMod;
            h++;
        } 
        
        while (i != start);
        return false;
    }
    bool deleteValue(int value) 
    {
        int start = hashIndex(value);

        int i = start, h = 1;
        do {
            if (hashArr[i] == value) 
            {
                hashArr[i] = deleted;
                return true;
            }

            if (hashArr[i] == empty) 
            {
                return false;
            }

            i = (start + h) % hashMod;
            h++;
        } 
        
        while (i != start);
        return false;
}

    void display() 
    {
        cout << "Current Hash Table: ";

        for (int i = 0; i < hashMod; i++) 
        {
            if (hashArr[i] == empty)
                cout << "_ ";
            else if (hashArr[i] == deleted)
                cout << "X ";

            else
                cout << hashArr[i] << " ";
        }
        cout << endl;
    }
};

void menu() {
    Hashing hashTable;
    int choice, value;
bool result;

    cout << "Hash Table Operations:\n";
    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Choose method [1: Linear Probing, 2: Quadratic Probing]: ";
            cin >> result;
            if (result == 1)
                hashTable.linearProbing(value);
            else
                hashTable.quadraticProbing(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            result = hashTable.search(value);
            cout << "Value " << (result ? "found" : "not found") << " in the table." << endl;
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            result = hashTable.deleteValue(value);
            cout << "Value " << (result ? "deleted" : "not found") << " from the table." << endl;
            break;
        case 4:
            hashTable.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
