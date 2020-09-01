//============================================================================
// Name        : FibonacciNumber.cpp
// Author      : Andrew Sears
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int fib(int n)
{
  if(n == 1 || n == 2)
      return 1;
  else
      return fib(n-1) + fib(n-2);
}

int main(int argc, char *argv[])
{
	if(argc == 1){
		ofstream outfile ("cache.txt");
		for(int i=1; i<41; i++)
		{
			cout << fib(i) << endl;

			outfile << fib(i) << endl;
		}
		outfile.close();
	}
	else if (atoi(argv[1]) <= 40 && atoi(argv[1]) > 0){
		ifstream infile ("cache.txt");
		vector <string> fibs;
		string somethingcool;
		while(getline(infile,somethingcool))
			fibs.push_back(somethingcool);
		infile.close();
		cout << "The " << argv[1]  << "th Fibonacci number is " << fibs[atoi(argv[1])-1] << endl;
		int numholder = 0;
		while(true){
			cout << "nextFibonacci Number?(up to 40)" << endl;
			cin >> numholder;
			if(numholder > 40 || numholder < 1)
				break;
			cout << "The " << numholder  << "th Fibonacci number is " << fibs[numholder-1] << endl;
		}
	}
    return 0;
}
