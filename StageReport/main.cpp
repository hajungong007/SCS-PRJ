#include "functions.h"
#include "iostream"
using namespace std;

int main()
{	
	//PicShot();
	PicAdj();	
	PicProcessing();
	Painting();
	MixPics();	
	LinearFilter();
	cout << "end" << endl;
	return 0;
}