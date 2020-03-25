#include "Films.h"
#include<fstream>

Film* films;
int countFilms = 0;

void addFilm()
{
	ofstream fout;
	fout.open("Films.txt",fstream::app);
	bool isOpen = fout.is_open();

	if (isOpen == true) {
		Film* temp = new Film[countFilms + 1];
		for (int i = 0; i < countFilms; i++) {
			temp[i] = films[i];
		}

		int countActors = 0;
		cout << "Enter name for new fiml->_";
		cin >> temp[countFilms].FilmName;

		cout << "Enter count actors for this film ->_";
		cin >> countActors;
		temp[countFilms].countActors = countActors;

		temp[countFilms].actors = new Actor[countActors];
		for (int i = 0; i < countActors; i++) {
			cout << "Enter actor name ->_";
			cin >> temp[countFilms].actors[i].Name;

			cout << "Enter rating for this actor (1 - 5) ->_";
			cin >> temp[countFilms].actors[i].Reting;
		}

		//Тут зробилю запис у файл
		fout << temp[countFilms].FilmName <<endl;
		fout << temp[countFilms].countActors << endl;
		for (int i = 0; i < countActors; i++) {
			fout << temp[countFilms].actors[i].Name << endl;
			fout << temp[countFilms].actors[i].Reting << endl;
		}

		countFilms++;
		delete films;
		films = temp;
	}
	else {
		cout << "Error: file was not opend!" << endl;
	}
	//cout << films << endl;
}

void showAllFilms()
{
	for (int i = 0; i < countFilms; i++) {
		cout << "Name film: " << films[i].FilmName << endl;
		for (int j = 0; j < films[i].countActors; j++) {
			cout << "\t" <<
			films[i].actors[j].Name
			<< " -> " <<
			films[i].actors[j].Reting
			<< "/5" << endl;
		}
	}
}