#pragma once
#include <fstream>
#include <string>
using namespace std;
class Parser
{
	int countofrowsreturned;
public:
	int getlastrows() { return countofrowsreturned; }
	string** pars(string path);

	void deleateString(string**& str);
	
};

