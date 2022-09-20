#include <iostream>
#include <conio.h>
#include "linkedstack.h"
using namespace std;

int main()
{
    LinkedStack stack;
    int ch,elm;
    string cal;
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
            cout << "9. Swap Top Two\n";
            cout << "10. Add Top Two\n";
            cout << "11. Add Top First N stacks\n";
            cout << "12. Advance Calculator\n";
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
            case 9://Swap Top Two
                stack.swapTopTwo();
                cout << "Swap Complete!\n";
                break;
            case 10: //Add Top Two
                stack.addTopTwo();
                break;
            case 11: //Add Top First N Stacks
                cout << "Type Number Of Stacks:";cin >> elm;
                stack.addTop(elm);
                cout << "Add Complete!\n";
                break;
            case 12: //Advance Calculator
                cout << "Type Formula:";cin >> cal;
                cout << "Infix : " <<cal <<endl;
                cout << "Postfix : " <<stack.infixToPostfix(cal) <<endl;
                cout << "Result : " << stack.executePostfix(stack.infixToPostfix(cal)) << endl;
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

