
#include <iostream>
#include "Parser.h"
#include "ui.h"
void persertest() {
    setlocale(LC_ALL, "");
    string torses = "torses.csv";
    Parser pars;
    string** test = pars.pars("torses.csv");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << test[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    ui user;
    Hero* myhero = user.createhero();
    myhero->show();
    delete myhero;
    
}
