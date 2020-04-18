#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
    int r = 0, p = 0;
    int* p_ptr = &p;
    
    cout << "Address of p: "<< &p << "\n";
    cout << "Address of p_ptr: "<< &p_ptr << "\n";
    cout << "Address p_ptr points to: " << p_ptr << " value pointed to: " << *p_ptr << "\n";
    
    // Address of p_ptr: 0x7ffeefbff544 value pointed to: 0
    
	return 0;
}
