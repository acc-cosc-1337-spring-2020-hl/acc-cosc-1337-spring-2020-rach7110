#include "vector.h"
#include<iostream>

Vector::Vector(size_t sz) : size{sz}, nums{ new int[sz] }
{
    std::cout << "allocate memory\n\n";
    
    for (size_t i = 0; i < sz; ++i)
    {
        nums[i] = 0;
    }
}

// Copy Constructor
Vector::Vector(const Vector &v) : size{v.size}, nums{ new int[v.size] }
{

    
    for (size_t i = 0; i < size; ++i)
    {
        nums[i] = v[i];
    }
}

Vector::~Vector() {
    std::cout << "released memory\n\n";
    delete[] nums;
}


void use_vect()
{
    Vector *v = new Vector(3);  // does not call the destructor.
    // If you allocate dynamic memory, you should release the moemery manually.
    
}
