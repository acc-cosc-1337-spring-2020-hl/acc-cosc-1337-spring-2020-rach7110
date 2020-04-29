#include "vector.h"
#include<iostream>


int main() 
{
//    L-values and R-values:
//    int a =1, b=5, c;
//    c = a * b;  // R-Value: (a*b)
//    int &c_ref = c;   // Can reference an L-value
//    int &ab_ref =&(a*b);  // Cannot reference an R-Value.
    
    
    // L-value
    Vector v1(3);
    v1 = get_vector();
    
	return 0;
}
