#include <iostream>
#include "chainnode.h"
using namespace std;

int main()
{
    ChainNode a,b(10,&a),c(20,&b);

    c.next->next->element = 99;
    cout <<"a.element: "<<a.element <<endl;
    return 0;
}

