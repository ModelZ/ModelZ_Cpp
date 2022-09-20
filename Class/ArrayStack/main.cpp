#include <iostream>
#include <conio.h>
#include "arraystack.h"
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
    ArrayStack stack;
    int ch,elm;
    do{
            stack.display();
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Push Element\n";
            cout << "2. Pop element\n";
            cout << "3. Peek element\n";
            cout << "4. Is Stack Empty?\n";
            cout << "5. Is Stack Full?\n";
            cout << "6. Stack size\n";
            cout << "7. Display Stack status\n";
            cout << "8. Clear Stack\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Push new element
                cout << "Enter element:"; cin >> elm;
                stack.push(elm);

                break;
            case 2: // Pop element
                elm = stack.pop();
                if(elm != -1)cout << "Pop out number ["<<elm<<"]\n";
                break;
            case 3: // Peek element value
                cout << "Peek Element: " << stack.peek() << endl;
                break;
            case 4: // Is stack empty?
                cout << "Status: "<< stack.isEmpty() << endl;

                break;
            case 5: // Is Stack Full?
                cout << "Status: "<< stack.isFull() << endl;
                break;
            case 6:// Stack size
                cout << "Stack size is ["<<stack.size()<<"]\n";

                break;
            case 7:// Display Stack status
                stack.display();

                break;
            case 8:// Clear Stack
                stack.clear();

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
                stack.clrsc();
    }while(true);


    return 0;
}

