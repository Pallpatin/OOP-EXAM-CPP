#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
class ui
{
	std::string clothpath = "clothes.csv";
	std::string hairstylespath = "hairstyles.csv";
	std::string shoespath = "shoes.csv";
	std::string torsespath = "torses.csv";
	Hero* HeroToCreate = nullptr;
public:
	Hero* createhero();
};

