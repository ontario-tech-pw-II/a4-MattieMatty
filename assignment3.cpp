#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;
	
	void setX(int n);
	void setY(int n);
	void setR(double n);
    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
	setX(x);
	setY(y);
	setR(r);
}

void Circle::setX(int n)
{
	x = n;
}

void Circle::setY(int n)
{
	y = n;
}

void Circle::setR(double n)
{
	r = n;
}

double Circle::area() const 
{
	return (3.14*pow(r,2.0));
}

double Circle::operator+(const Circle & c) const
{
	double a;
	a = c.area() + area(); //was not sure if this meant area of a plus area of b or add values of a and b then find the area
	return a;
   // + Return the area of two circles  
}

Circle & Circle::operator++()
{
	r++;
	return *this;
	//incremented radius by 1
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  r++;
  return temp;
  //increment the radius by 1
}

ostream & operator<<(ostream &out, const Circle &c)
{
	out << "\tx: " << c.x << endl;
	out << "\ty: " << c.y << endl;
	out << "\tr: " << c.r << endl;
	return out;
  // print a circle in the out stream (the format is the same as print())
}

istream & operator>>(istream &in, Circle &c)
{
	int temp_x, temp_y;
	double temp_r;
	
	cout << "\tx: ";
	in >> temp_x;
	
	cout << "\ty: ";
	in >> temp_y;
	
	cout << "\tr: ";
	in >> temp_r;
	
	c = Circle(temp_x, temp_y, temp_r);
	return in;
 // Read a circle information form the in stream

}


void Circle::print() const
{
  cout << "Circle = (" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
	Circle a;
	Circle b(2,3,3.0);

	a.print();
	b.print();
  
	cout << "The area a + b is: " << a+b << endl;
	cout << "\nResult of ++a overload: ";
	++a;
	a.print();
	
	cout << "Result of a++ overload while being immediately printed: ";
	(a++).print();
	cout << "Result of a++ overload not immediately print: ";
	a.print();

	cout << "\ncout << a" << endl;
	cout << a;	

	cout << "cin >> a" << endl;
	cin >> a;
	
	cout << "cout << a" << endl;
	cout << a;

  return 0;

}