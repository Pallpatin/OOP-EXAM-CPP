#include "Hero.h"

void Hero::show()
{
	std::cout << "\n your heto is ";
	std::cout << (gender ? "male" : "female");
	std::cout << "\n your hero has\n" << "\n body : " << body;
	for (auto el : clothes) {
		std::cout << "\n clothes : " << el;
	}
	std::cout<< "\n shoes : " << shoes << "\n hairstyle : " << hairstyle;
}


void Hero::test()
{
	gender = 1;
	body = "test male";
	for (int i = 1; i < 11; i++) {
		clothes.push_back("test clothes " + std::to_string(i));
	}
	shoes = "test nice shoes";
	hairstyle = "test hair";
}
