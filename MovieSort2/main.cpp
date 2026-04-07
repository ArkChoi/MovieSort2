#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Movie.h"

std::vector<Movie>* FileOpen(std::string InFileName, std::vector<Movie>* InMovies);
int CutString(std::string InLine, std::string* ResultStr, std::string* TempStr);

bool SizeStrName(Movie InMovie1, Movie InMovie2);
bool SizeIntAdm(Movie InMovie1, Movie InMovie2);
bool SizeLenName(Movie InMovie1, Movie InMovie2);

int main()
{
	std::vector<Movie> Movies;
	FileOpen("movie.txt", &Movies);

	std::sort(Movies.begin(), Movies.end(), SizeLenName);

	for (int i = 0; i < Movies.size(); i++)
	{
		Movies[i].Print();
	}

	return 0;
}

std::vector<Movie>* FileOpen(std::string InFileName, std::vector<Movie>* InMovies)
{
	std::ifstream ReadFile;
	ReadFile.open(InFileName);

	char Buffer[1024] = { 0, };
	Movie* TempMovie;

	if (ReadFile.is_open())
	{
		while (ReadFile.getline(Buffer, 255))
		{
			std::string Line = Buffer;
			int Cheak = 1;
			int Count = 0;

			std::string MoveName;
			std::string MovieDirector;
			int Year;
			int Admissions;

			while (Cheak)
			{
				std::string* Result = new std::string;
				std::string* Temp = new std::string;
				Cheak = CutString(Line, Result, Temp);

				switch (Count)
				{
				case 0:
					MoveName = *Result;
					break;

				case 1:
					MovieDirector = *Result;
					break;

				case 2:
					Year = std::stoi(*Result);
					break;

				case 3:
					Admissions = std::stoi(*Result);
					break;

				default:
					break;
				}

				Line = *Temp;
				Count++;

				delete Result;
				delete Temp;
			}

			TempMovie = new Movie(MoveName, MovieDirector, Year, Admissions);

			InMovies->push_back(*TempMovie);
		}
	}
	ReadFile.close();

	return nullptr;
}

int CutString(std::string InLine, std::string* ResultStr, std::string* TempStr)
{
	size_t pos = InLine.find('|'); // '|' 위치 찾기

	std::string Result;
	std::string Temp;

	if (pos != std::string::npos) {
		Result = InLine.substr(0, pos);
		Temp = InLine.substr(pos + 1);

		*(ResultStr) = Result;
		*(TempStr) = Temp;

		return 1;
	}
	else
	{
		*(ResultStr) = InLine;

		return 0;
	}
}

// a)영화제목 기준으로 오름차순 정렬하여, 영화제목과 관람객 수 출력하기 sort 조건식
bool SizeStrName(Movie InMovie1, Movie InMovie2)
{
	if (InMovie1.GetMoveName() < InMovie2.GetMoveName())
	{
		return true;
	}
	return false;
}

// b) 관람객 수 기준으로 내림차순 정렬하여, 영화제목과 관람객 수 출력하기 sort 조건식
bool SizeIntAdm(Movie InMovie1, Movie InMovie2)
{
	if (InMovie1.GetAdmissions() > InMovie2.GetAdmissions())
	{
		return true;
	}
	return false;
}

//c) 영화제목의 길이를 기준으로 오름차순 정렬하여, 영화제목 출력하기 sort 조건식
bool SizeLenName(Movie InMovie1, Movie InMovie2)
{
	if (InMovie1.GetMoveName().length() < InMovie2.GetMoveName().length())
	{
		return true;
	}
	return false;
}

