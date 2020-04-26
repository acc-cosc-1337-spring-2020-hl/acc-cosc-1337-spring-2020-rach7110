#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
    // References
    int r = 0;
    int p = 0;
    int &ref_r = r;
    
//    cout << "Address of r: " << &r << "\n";
//    cout << "Value of r: " << r << "\n";
//    cout << "Address of ref_r: " << &ref_r << "\n\n";  // References do not get their own allocaiton  in memory.
//
//    // Pointers
//    int *ptr_p =  &p;
//
//    cout << "Address of p: " << &p << "\n";
//    cout << "Value of p: " << p << "\n";
//    cout << "Address of ptr_p: " << &ptr_p << "\n";  // Pointers get their own allocation in memory.
//    cout << "Value of ptr_p: " << ptr_p << "\n";  // Value of pointer is the address of what it points to.
//    cout << "Value of ptr_p points to: " << *ptr_p << "\n";  // Derefernce of pointer is the value of what it points to.
    
    int rainbows = 100;
    int puppies = 200;
    
    int &ref_rainbows = rainbows;
    
    cout << "Address of rainbows: " <<  &rainbows << "\n";
    cout << "Value of rainbows: " << rainbows << "\n";
    cout << "Address of ref_rainbows: " << &ref_rainbows << "\n";
    cout << "Value of ref_rainbows: " << ref_rainbows << "\n";
    
    // Modify the value by reference:
    ref_rainbows = 150;
    cout << "New value of rainbows: " << rainbows << "\n\n";
    
    int *ptr_puppies = &puppies;

    cout << "Address of puppies: " << &puppies << "\n";
    cout << "Value of puppies: " << puppies << "\n";
    cout << "Address of ptr_puppies: " << &ptr_puppies << "\n";
    cout << "Value of ptr_puppies: " << ptr_puppies << "\n";
    cout << "Value of ptr_puppies points to: " <<  *ptr_puppies << "\n\n";
    
    // Modify the value that pointer points at.
    *ptr_puppies = 250;
    cout << "Value of puppies: " << puppies << "\n";
    
    
    // Differences: reference vs pointer.
    // Pointers work like a reference, but get their own address.
    // Pointer is more powerful than reference.
        // - You cannot change the address of a reference after its assignment. Pointer can be assigned different values.
        // - With a pointer, you cna create dynamic memory.
    
	return 0;
}
