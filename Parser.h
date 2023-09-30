#pragma once
#include <fstream>
#include <string>

using namespace std;
class Parser
{
	int countofrowsreturned;
	int countforsplitter;
public:
	int getlastrows() { return countofrowsreturned; }
	int getCountLastSplitter() {
		return countforsplitter;
	}
	string** pars(string path);
	string* pars(string str, char ch);
	void deleateString(string**& str);
	
};

