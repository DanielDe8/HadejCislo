#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
using namespace std;

string HISCORE_CESTA = "hiscore.txt";

int nactiHiScore() {
	fstream hiscoreSoubor(HISCORE_CESTA);
	string scoreStr;
	int scoreInt;
	hiscoreSoubor >> scoreStr;
	try {
		scoreInt = stoi(scoreStr);
	} catch(exception _) {
		throw scoreStr;
	}
	hiscoreSoubor.close();
	return scoreInt;
}

void vytvorHiScore(int score) {
	fstream hiscoreSoubor(HISCORE_CESTA);
	hiscoreSoubor << score << endl;
	hiscoreSoubor.close();
}

bool noveHiScore(int score) {
	int stareHiScore = nactiHiScore();
	return score > stareHiScore;
}

void vyhra(int score) {
	string plusZprava = "";
	string hiscoreZprava = " a dokonce jsi prekonal hi-score";
	string konecZpravy = "!!!";
	// try {
	// 	if (noveHiScore(score)) {
	// 		plusZprava = hiscoreZprava;
	// 		vytvorHiScore(score);
	// 	}
	// } catch(string i) {
	// 	plusZprava = ", ale nekde se stala chyba a pokud jsi prekonal hi-score, nemuzeme ho ulozit" + i;
	// 	konecZpravy = ".";
	// }
	cout << "Gratuluji, vyhral jsi" << plusZprava << konecZpravy << endl;
}

int main(void) {
	srand(time(NULL));

	int score = 0;
	int cislo = rand() % 101;

	cout << "Vitejte ve hre HadejCislo!!!" << endl;
	cout << "Stisknutim klavesy ENTER muzete zacit hrat." << endl;
	cin.get();

	while(true) {
		score++;
		string jehoinput;
		cout << "Typuj cislo: " << endl;
		cin >> jehoinput;
		int jehocislo = 0;
		try {
			jehocislo = stoi(jehoinput);
		}
		catch(exception _) {
			cout << "Zadej CISLO." << endl;	
			continue;
		}

		if (cislo == jehocislo) {
			vyhra(score);
			break;
		} else if (cislo < jehocislo) {
			cout << "Prave cislo je mensi." << endl;
		} else if (cislo > jehocislo) {
			cout << "Prave cislo je vetsi." << endl;
		}
	}

	cout << "Stisknutim klavesy ENTER ukoncite program." << endl;
	cin.get();cin.get();
	return 0;
}
