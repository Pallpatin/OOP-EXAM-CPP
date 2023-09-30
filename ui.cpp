#include "ui.h"
#include "Parser.h"
using namespace std;



Hero* ui::createhero()
{
	setlocale(LC_ALL, "");
	HeroToCreate = new Hero;
	{
		char ge;
		do {
			cout << "input gender of charracrer m/f :";
			cin >> ge;
			system("cls");
		} while (ge != 'm' && ge != 'f');
		if (ge == 'm') {
			HeroToCreate->gender = 1;
		}
		else HeroToCreate->gender = 0;
	}
	Parser myparser;
	{
		string** bodyes = myparser.pars(torsespath);
		HeroToCreate->body = (HeroToCreate->gender ? bodyes[1][1] : bodyes[2][1]);
		myparser.deleateString(bodyes);
	}
	system("cls");
	cout << "select hairstyle :";
	string gen = (HeroToCreate->gender ? "m" : "f");
	{
		int num = 1;
		string** hairs = myparser.pars(hairstylespath);
		for (int i = 0; i < myparser.getlastrows(); i++) {
			if (hairs[i][1] == "a"||(hairs[i][1]==gen)) {
				cout << endl << num++ <<'\t' << hairs[i][0];
			}
		}
		cout << endl;
		int selected;
		do {
			cin >> selected;
		} while (selected<=0||selected>num);
		for (int i = 0; i < myparser.getlastrows(); i++) {
			if (hairs[i][1] == "a" || (hairs[i][1] == gen)) {
				selected--;
				if (!selected) {
					HeroToCreate->hairstyle = hairs[i][2];
					break;
				}
			}
		}
		myparser.deleateString(hairs);
	}



	return HeroToCreate;
}
