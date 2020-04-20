//
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
    // Class copy
    
    // For stack variables
//    public:
//        Vector(size_t sz);
//        size_t Size()const { return size; }
//        void set_size(size_t s) { size = s; }
//
//    private:
//        size_t size;
    
    // For heap variables (Dynamic memory):
    public:
        Vector(size_t sz);
        Vector(const Vector &v);  // copy constructor
        size_t Size()const { return size; }
        int &operator[](int i)  { return nums[i]; }       // Overloading [] operator to assign value
        int &operator[](int i) const { return nums[i]; }  // Overloading [] operator to get value

    private:
        size_t size;
        int *nums;
};

#endif



