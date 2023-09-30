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
	bool head0;
	bool up1;
	bool up2;
	bool doun3;
	bool doun4;
	friend class ui;
public:
	void show();
	void test();
};

