#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Actor {
	string Name;
	float Reting;
};

struct Film {
	string FilmName;
	Actor* actors;
	int countActors;
};

void addFilm();
void showAllFilms();