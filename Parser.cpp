#include "Parser.h"

string** Parser::pars(string path)
{
	
	string buf;
	ifstream in(path);
	if (in.is_open()) {
		int countofrows = 1;
		int countOfCollums = 1;
		getline(in, buf);
		for (auto el : buf) {
			if (el == ';')countOfCollums++;
		}
		while (getline(in, buf)) {
			countofrows++;
		}
		countofrowsreturned = countofrows;
		in.close();
		string** strToReturn = new string * [countofrows];
		for (int i = 0; i < countofrows; i++) {
			strToReturn[i] = new string[countOfCollums];
		}
		in.open(path);
		string bufferword = "";
		int x = 0, y = 0;
		while (getline(in, buf)) {
			for (int i = 0; i < buf.size(); i++) {
				if (buf[i] != ';') { 
					bufferword += buf[i];
				}
				else {
					strToReturn[x][y] = bufferword;
					bufferword = "";
					y++;
				}
			}
			strToReturn[x][y] = bufferword;
			bufferword = "";
			y = 0;
			x++;
		}
		return strToReturn;
	}
	throw"file not found";
	
}

string* Parser::pars(string str,char ch)
{
	int num = 1;
	for (auto el : str)if (el == ch)num++;
	string* toreturn = new string[num];
	for (int i = 0; i < num; i++) {
		toreturn[i] = "";
	}
	countforsplitter = num;
	num = 0;
	for (auto el : str) {
		if (el == ch) {
			num++;
		}
		else {
			toreturn[num] += el;
		}
	}
	return toreturn;
}

void Parser::deleateString(string**& str)
{
	for (int i = 0; i < countofrowsreturned; i++)delete[]str[i];
	delete[]str;
}





