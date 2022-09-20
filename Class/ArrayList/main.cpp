#include <iostream>
#include <conio.h>
#include "arraylist.h"
using namespace std;

int main()
{
    /*
    int a;
    ArrayList list; // create list with 5 elements (default)
    list.display();
    list.add(0,15); // [15 , - , - , - , - ]
    list.add(0,25); // [25 , 15 , - , - , - ]
    list.add(3,99); // [25 , 15 , 99 , - , - ]
    list.add(-9,53); // [ 53 , 25, 15 , 99 , - ]
    list.display();  // [ 53 , 25, 15 , 99 , - ]
    a = list.remove(3);
    cout << "Num Remove: " << a << endl;
    list.display();
    list.clear();
    list.display();
    */
    ArrayList list;
    int ch,index,elm;
    do{
            list.display();
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Add new element\n";
            cout << "2. Remove element\n";
            cout << "3. Set element value\n";
            cout << "4. Get element value from index\n";
            cout << "5. Find index from element value\n";
            cout << "6. List size\n";
            cout << "7. Display list status\n";
            cout << "8. Clear list\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Add new element
                cout << "Enter index:"; cin >> index;
                cout << "Enter element:"; cin >> elm;
                list.add(index,elm);

                break;
            case 2: // Remove element
                cout << "Enter index to remove:"; cin >> index;
                elm = list.remove(index);
                if(elm != -1)cout << "Remove number ["<<elm<<"]\n";
                break;
            case 3: // Set element value
                cout << "Enter index to set:"; cin >> index;
                cout << "Set number:"; cin >> elm;
                list.set(index,elm);
                break;
            case 4: // Get element from index
                cout << "Enter index value:"; cin >> elm;
                index = list.get(elm);
                cout << "Element Value: "<<index<<endl;

                break;
            case 5: // Find element from index
                cout << "Enter value to find:"; cin >> elm;
                index = list.indexOf(elm);
                if(index != -1)cout << "Is in index ["<<index<<"]\n";
                break;
            case 6:// List size
                cout << "List size is ["<<list.size()<<"]\n";

                break;
            case 7:// Display list status
                list.display();

                break;
            case 8:// Clear list
                list.clear();

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

