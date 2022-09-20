#include <iostream>
#include "binarysearchtree.h"
#include <conio.h>
using namespace std;

int main()
{
     BinarySearchTree list;

    int ch,elm;
    ORDER c = IN_ORDER;
    do{
            list.display(c);
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Insert Element\n";
            cout << "2. Remove Element\n";
            cout << "3. Display Mode\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Insert Element
                cout << "Enter element:"; cin >> elm;
                list.insert(elm);

                break;
            case 2: // Remove Element
                cout << "Enter element to remove:";cin >> elm;
                list.remove(elm);
                break;
            case 3: // Display Element
                cout<<"IN_ORDER = 0 ,PRE_ORDER = 1 ,POST_ORDER = 2 "<<endl;
                cout<<"Enter element: ";
                cin>>elm;
                cout<<endl;

                switch (elm) {
                case 0:
                    c = IN_ORDER;

                    break;
                case 1:
                    c = PRE_ORDER;

                    break;
                case 2:
                    c = POST_ORDER;

                    break;
                default:
                    cerr << "Choose wrong number try again......\n";
                    break;
                }

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

