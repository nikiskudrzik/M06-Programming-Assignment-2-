#include "BTree.h"

int main() {
    int degree;
    int choice;
    int value;

    cout << "B-Tree Insert Program" << endl;
    cout << "Enter the minimum degree of the B-Tree: ";
    cin >> degree;

    BTree tree(degree);

    do {
        cout << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Display B-Tree" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << value << " was inserted." << endl;
        } else if (choice == 2) {
            cout << endl;
            cout << "Current B-Tree:" << endl;
            tree.display();
        } else if (choice == 3) {
            cout << "Program ended." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 3);

    return 0;
}