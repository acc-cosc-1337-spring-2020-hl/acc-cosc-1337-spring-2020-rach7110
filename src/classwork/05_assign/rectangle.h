/*
Create the interface for a Rectangle class with one constructor that accepts 
two int parameters (width, height),
has one public function area that returns the area of the rectangle, 
and one private function calculate_area
that calculates area of the rectangle.  
The class has 3 int private variables area, width, and height.
*/
class Rect
{
	public:
		Rect(int width, int height);
		int get_area()const { return area;  };
		friend std::ostream & operator<< (std::ostream& out, const Rect& r);

	private:
		void calculate_area();
		int width;
		int height;
		int area;
};

