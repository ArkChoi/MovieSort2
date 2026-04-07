#include "Movie.h"
#include <iostream>


Movie::Movie()
{
	MoveName = "None";
	MovieDirector = "None";
	Year = 0;
	Admissions = 0;
}

Movie::Movie(std::string InMoveName, std::string InMovieDirector, int InYear, int InAdmissions)
{
	MoveName = InMoveName;
	MovieDirector = InMovieDirector;
	Year = InYear;
	Admissions = InAdmissions;
}

void Movie::Print()
{
	std::cout << Year;
	std::cout << " | ";
	std::cout << Admissions;
	std::cout << " | ";
	std::cout << MoveName;
	std::cout << std::endl;
}

Movie::~Movie()
{

}

std::string Movie::GetMoveName()
{
	return MoveName;
}

int Movie::GetAdmissions()
{
	return Admissions;
}

int Movie::GetYear()
{
	return Year;
}

