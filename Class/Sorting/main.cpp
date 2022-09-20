#include <iostream>
#include "sorting.h"
#include <conio.h>
using namespace std;

int main()
{
     Sorting list;
     //list.random();
    int ch,elm;
    do{
            cout << endl;

            //menu
            cout << "----------------------- Menu ---------------------\n";
            cout << "1. Selection Sort\n";
            cout << "2. Insertion Sort\n";
            cout << "3. Bubble Sort\n";
            cout << "4. Shell Sort\n";
            cout << "5. Merge Sort\n";
            cout << "6. Quick Sort\n";
            cout << "7. Clear List\n";
            cout << "8. Sorting Conparison\n";
            cout << "0. Exit program\n";
            cout << "----------------------------------------------------\n";

            cout << "Choose:";
            cin >> ch;

            switch (ch) {
            case 1: // Selection Sort
                list.clear();
                list.random();
                list.display();
                list.selection(true);

                break;
            case 2: // Insertion Sort
                list.clear();
                list.random();
                list.display();
                list.insertion(true);
                break;
            case 3: // Bubble Sort
                list.clear();
                list.random();
                list.display();
                list.bubble(true);
                break;
            case 4: // Shell Sort
                list.clear();
                list.random();
                list.display();
                list.shell(true);
                break;
            case 5: // Merge Sort
                list.clear();
                list.random();
                list.display();
                list.merge();
                list.display();
                break;
            case 6:// Quick Sort
                list.clear();
                list.random();
                list.display();
                list.quick();
                list.display();
                break;
            case 7:// Clear List
                list.clear();
                cout << "List is cleared!!\n";
                break;
            case 8:// Sorting Conparison
                cout << "type number of data:";cin >> elm;
                list.sixEfficiencySortingComparison(elm);
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
               // list.clrsc();
    }while(true);


    return 0;
}
