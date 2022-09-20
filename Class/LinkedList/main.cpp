#include <iostream>
#include <conio.h>
#include "linkedlist.h"
using namespace std;

int main()
{
  /*  LinkedList list; //L: []
    list.add(0,25); //L: [25]
    list.add(1,20); //L: [25,20]
    list.add(2,30); //L: [25,20,30]
    list.add(3,30);
    list.add(4,30);
    list.add(5,30);
    list.display();
    list.clear();
    list.display();*/


    LinkedList list;
    int ch,index,elm;
    float n;
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
            cout << "9. Odd Count\n";
            cout << "10. Even Count\n";
            cout << "11. Sum\n";
            cout << "12. Mean\n";
            cout << "13. Sorting (ascending order)\n";
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
            case 9://Odd Count
                elm = list.oddCount();
                cout << "Odd Count: " << elm << endl;
                break;
            case 10://Even Count
                elm = list.evenCount();
                cout << "Even Count: " << elm << endl;
                break;
            case 11://Sum All
                n = list.sum();
                cout << "Sum: " << n << endl;
                break;
            case 12://Mean
                n = list.mean();
                cout << "Mean: " << n << endl;
                break;
            case 13://Sorting (ascending order)
                list.sort();
                break;
            case 0: // Exit
                cout << "ThankYou for using my program BYEBYE!\n";
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

