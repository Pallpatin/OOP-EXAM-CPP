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

	system("cls");
	cout << "select shoes :";
	{
		int num = 1;
		string** shoes = myparser.pars(shoespath);
		for (int i = 0; i < myparser.getlastrows(); i++) {
			if (shoes[i][1] == "a" || (shoes[i][1] == gen)) {
				cout << endl << num++ << '\t' << shoes[i][0];
			}
		}
		cout << endl;
		int selected;
		do {
			cin >> selected;
		} while (selected <= 0 || selected > num);
		for (int i = 0; i < myparser.getlastrows(); i++) {
			if (shoes[i][1] == "a" || (shoes[i][1] == gen)) {
				selected--;
				if (!selected) {
					HeroToCreate->shoes = shoes[i][2];
					break;
				}
			}
		}
		myparser.deleateString(shoes);
	}

	{
		string** clothes = myparser.pars(clothpath);
		int num = 1;
		int celected = 0;
		bool flag;
		do{
			num = 1;
			system("cls");
			cout << "\tselect clothes, 0 - to confirm\n";
			for (int i = 1; i < myparser.getlastrows(); i++) {
				if (clothes[i][1] == "a" || (clothes[i][1] == gen)) {
					string* bodyparts = myparser.pars(clothes[i][2], ',');
					flag = 1;
					for (int i = 0; i < myparser.getCountLastSplitter(); i++) {
						if (!(bodyparts[i] == "0" && HeroToCreate->head0 || bodyparts[i] == "1" && HeroToCreate->up1 || bodyparts[i] == "2" && HeroToCreate->up2 || bodyparts[i] == "3" && HeroToCreate->doun3 || bodyparts[i] == "4" && HeroToCreate->doun4))flag = 0;
					}
					if (flag)cout << endl << num++ << '\t' << clothes[i][0];
					delete[]bodyparts;
				}
			}
			if (num == 1)break;
			cout << endl;
			do {
				cin >> celected;
			} while (celected<0 || celected>num);
			num = 0;
			for (int i = 1; i < myparser.getlastrows(); i++) {
				if (clothes[i][1] == "a" || (clothes[i][1] == gen)) {
					string* bodyparts = myparser.pars(clothes[i][2], ',');
					flag = 1;
					for (int i = 0; i < myparser.getCountLastSplitter(); i++) {
						if (!(bodyparts[i] == "0" && HeroToCreate->head0 || bodyparts[i] == "1" && HeroToCreate->up1 || bodyparts[i] == "2" && HeroToCreate->up2 || bodyparts[i] == "3" && HeroToCreate->doun3 || bodyparts[i] == "4" && HeroToCreate->doun4)) {
							flag = 0;
						}
						else num++;
					}
					if (flag&&(celected==num)) {
						HeroToCreate->clothes.push_back(clothes[i][3]);
						for (int i = 0; i < myparser.getCountLastSplitter(); i++) {
							if (bodyparts[i] == "0") { HeroToCreate->head0 = 0; continue; }
							if (bodyparts[i] == "1") { HeroToCreate->up1 = 0; continue; }
							if (bodyparts[i] == "2") { HeroToCreate->up2 = 0; continue; }
							if (bodyparts[i] == "3") { HeroToCreate->doun3 = 0; continue; }
							if (bodyparts[i] == "4") { HeroToCreate->doun4 = 0; continue; }
						}
					}
					delete[]bodyparts;
				}
			}
			
		} while (celected != 0);

		myparser.deleateString(clothes);
	}



	return HeroToCreate;
}
