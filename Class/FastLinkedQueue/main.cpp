#include <iostream>
#include "fastlinkedqueue.h"
#include <conio.h>
using namespace std;

int main()
{
    FastLinkedQueue list;

    int ch,elm;
    do{
            list.display();
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Add new queue\n";
            cout << "2. Remove queue\n";
            cout << "3. Queue size\n";
            cout << "4. Get Front Queue\n";
            cout << "5. Get Rear Queue\n";
            cout << "6. Display queue status\n";
            cout << "7. Clear queue\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Add new queue
                cout << "Enter element:"; cin >> elm;
                list.enQueue(elm);

                break;
            case 2: // Remove queue
                elm = list.remove();
                if(elm != -1)cout << "Remove number ["<<elm<<"]\n";
                break;
            case 3: // Queue size
                cout << "curSize: "<<list.size()<<endl;
                break;
            case 4: // Get Front Queue
                cout << "Front: "<<list.front()<<endl;
                break;
            case 5: // Get Rear Queue
                cout << "Rear: "<<list.rear()<<endl;
                break;
            case 6:// Display queue status
                list.display();
                break;
            case 7:// Clear queue
                list.clear();
                cout << "Queue is cleared!!\n";

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
