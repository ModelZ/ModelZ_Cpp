#include <iostream>
#include <conio.h>
#include "hashtable.h"
using namespace std;

int main()
{

    HashTable list;
    int ch,index,key;
    do{
            list.display();
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Add new key\n";
            cout << "2. Search key\n";
            cout << "3. Remove key\n";
            cout << "4. Clear hashtable\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Add new key
                cout << "Enter key:"; cin >> key;
                list.addKey(key);

                break;
            case 2: // Search key
                cout << "Enter Key:"; cin >> key;
                index = list.searchKey(key);
                if(index != -1)cout << "Index of number ["<<key<<"] is ["<<index<<"]\n";
                break;

            case 3: // Remove key
                cout << "Enter index to remove:"; cin >> index;
                key = list.removeKey(index);
                if(key != -1)cout << "Remove number ["<<key<<"]\n";
                break;

            case 4: // Clear hashtable
                list.clearTable();

                break;
            case 0: // Exit
                return 0;
                break;
            default: // choose wrong
                cerr << "Choose wrong number try again......\n";
                break;
            }


                cout << "Enter to continue..........";
                getch();
                list.clrsc();
    }while(true);


    return 0;
}

