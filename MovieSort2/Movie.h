#pragma once
#include <iostream>

class Movie
{
protected:
	std::string MoveName;
	std::string MovieDirector;
	int Year;
	int Admissions;

public:
	Movie();

	Movie(std::string InMoveName, std::string InMovieDirector, int InYear, int InAdmissions);

	~Movie();

	std::string GetMoveName();
	int GetAdmissions();
	int GetYear();

	void Print();

public:
	Movie& operator=(const Movie& InMovie)
	{
		this->MoveName = InMovie.MoveName;
		this->MovieDirector = InMovie.MovieDirector;
		this->Year = InMovie.Year;
		this->Admissions = InMovie.Admissions;

		return *this;
	}
};

