#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hero
{
	bool gender;
	std::string body;
	std::vector<std::string> clothes;
	std::string shoes;
	std::string hairstyle;
	bool head0 = 1;
	bool up1 = 1;
	bool up2 = 1;
	bool doun3 = 1;
	bool doun4 = 1;
	friend class ui;
public:
	void show();
	void test();
};

