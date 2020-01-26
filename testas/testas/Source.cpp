#include <iostream>
#include <fstream>
using namespace std;

void Eilutes(int&);
void Skaiciuoti(int eil, int simboliai[], ifstream&, char masyvas[], int sk);
void daugiausiai(int eil, int simboliai[], int& eilute);
void Spausdinti(int did);


int main() {
    int eil = 0, sk = 0, eilute = 0;
    int simboliai[100];
    char masyvas[100];
	ifstream duom("duomenys.txt");
	eilutes(eil);
	skaiciavimas(eil, simboliai, duom, masyvas, sk);
	daugiausiai(eil, simboliai, eilute);
	Spausdinti(eilute);
	return 0;
}

void Eilutes(int& eil) {
	ifstream fin("duomenys.txt");
	char character;
	while (!fin.eof()) {
		while (!fin.eof()) {
			fin.get(character);
			if (character == '\n' || fin.eof()) {
				eil++;
				break;
			}
		}
	}
}


void Skaiciuoti(int eilutes, int simboliai[], ifstream& fin, char masyvas[], int index){
	int a = 0;
	char character;
	for(int i = 0; i < eilutes; i++) {
		irasymas(masyvas, fin, index);
		cout << index << endl;
		for (int i = 0; i < sk; i++) {
			character = masyvas[i];
			if (character == '\n') {
				break;
			}
			if (character == '.') {
				counter++;
			}
			if (character == ',') {
				counter++;
			}
		}
		simboliai[i] = counter;
		counter = 0;
		index = 0;
	}
}

void daugiausiai(int eil, int simboliai[], int& eilute) {
	int did = -1;
	for (int i = 0; i < eil; i++) {
		if (simboliai[i] > did) {
			did = simboliai[i];
			eilute = i+1;
		}
	}
}

void Spausdinti(int eilute) {
	ofstream rez("rezultatai.txt");
	rez << eilute << " eiluteje yra daugiausiai simboliu" << endl;
}
