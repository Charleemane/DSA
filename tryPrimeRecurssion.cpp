//Create a program which will dosplay all the prime factors of a given number. Use recursion.

#include <iostream>

using namespace std;

//prime --> x = x % 3

void FactorsPrime(int x) {
	if (x < 0) {
		return;
	}
	for (int i = 1; i<=x; ++i)
	if (i % 3){
		return FactorsPrime(x);
	}
	
	cout << FactorsPrime(x);
} 

int main {
	int num;
	cin >>num;
	FactorsPrime(num);
}
