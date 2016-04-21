#include <iostream>
#include <string>
#include <math.h>

#define PI 3.14159265

using namespace std;

struct circle{
	double x,y,r;
};

double chordLength (circle c, double k){
	return 2*sprt(c.r*c.r-pow(k*c.x+c.y/(sqrt(k*k+1)),2));
}






int main(){
	int n_circle;
	circle cs[200];

	for (int i = 0; i < n_circle; ++i)
	{
		circle c;
		cin>>c.x>>c.y>>c.r;
		cs[i] = c;
	}

	double max = 0;

	for (int i = 0; i < 360; ++i)
	{
		k = tan ( i * PI / 180.0 );
		double totalLength = 0;
		for (int j = 0; j < n_circle; ++j)
			totalLength += chordLength (cs[j], k);

		if (totalLength>max)
			max = totalLength;
	}


	cout<<max;
	



	




}