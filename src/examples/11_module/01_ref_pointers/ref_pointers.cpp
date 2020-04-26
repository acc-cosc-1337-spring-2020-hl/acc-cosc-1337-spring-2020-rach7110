#include "ref_pointers.h"


void ref_point(int &int1, int * int2)
{
    // int &int1 = r;
    // int *int2 = &p;
    
    //Modify a ref variable.
    int1 = 66;
    
    // Modify varibale that pointer is pointing to.
    *int2 = 100;
}
