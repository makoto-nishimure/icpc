#include <iostream>

using namespace std;

int
main (void)
{
	/*
	double a = 1.5;
	double b = 2.0;
	if (a % 2 == 0)
		cout << "dame" <<endl;
	else
		cout << "OK" << endl;
	if (b % 2 == 0)
		cout << "OK" <<endl;
	else
		cout << "dame" << endl;
	*/
	double a = 0.5;
	double t = 0.5;
	a -= t;
	if (a < 0.0)
		cout << "nogood" << endl;
	else if (a == 0.0)
		cout << "OK" << endl;

	a -= t;
	if (a < 0.0)
		cout << "nogood" << endl;
	else
		cout << "OK" << endl;

	return 0;
}
