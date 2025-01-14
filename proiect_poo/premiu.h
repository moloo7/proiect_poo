#pragma once

#include <iostream>
#include <string>

using namespace std;

class Premiu
{

public:
	string premiu1;
	string premiu2;
	string premiu3;
	string mentiuni;

	Premiu(string premiu1, string premiu2, string premiu3, string mentiuni)
	{
		this->premiu1 = premiu1;
		this->premiu2 = premiu2;
		this->premiu3 = premiu3;
		this->mentiuni = mentiuni;
	}
};

static ostream& operator<<(ostream& os, const Premiu& premiu)
{
	os << "Premiul 1: " << premiu.premiu1;
	os << "Premiul 2: " << premiu.premiu2;
	os << "Premiul 3: " << premiu.premiu3;
	os << premiu.mentiuni;
	return os;
}