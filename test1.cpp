#include <iostream>
#include <conio.h> 

using namespace std;

int round=1,n,sum=0; 
std::string ch;
int main () {
	//Title for decoration
	cout << "Created By ModelZ 63002115\n";
   	cout << "**********************\n";
	cout << "*    Plus 1-9 only   *\n";
	cout << "**********************\n";
	cout << "Type 1-9 Only then sum all of them\n";
	cout << "Type 0 for stop and see the result\n";
	cout << "----------------------\n";
   do{
   		//Input with String
   		cout << "Type Number[" << round << "]:"; 
   		ch = getche();
   		cout << "\n";
   		// string -> integer
        sscanf(ch.c_str(), "%d", &n);
        //Process
        sum += n;
        round++;
   }while(n!=0); // If user choose 0 show result and exit program
    //Output
    cout << "Sum is [" << sum << "]\n";
 	getch();
   return 0;
}
