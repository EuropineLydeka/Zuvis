#include <iostream>
#include <fstream>
using namespace std;

void eilutes(int&);
void irasymas(char masyvas[], ifstream&, int& sk);
void skaiciavimas(int eil, int simboliai[], ifstream&, char masyvas[], int sk);
void daugiausiai(int eil, int simboliai[], int& eilute);
void spausdinimas(int did);


int main()
{
	ifstream duom("duomenys.txt");
	int eil = 0;
	int sk = 0;
	int simboliai[100];
	char masyvas[100];
	int eilute = 0;
	eilutes(eil);
	skaiciavimas(eil, simboliai, duom, masyvas, sk);
	daugiausiai(eil, simboliai, eilute);
	spausdinimas(eilute);
	system("PAUSE");
}
void eilutes(int& eil)
{
	ifstream duom("duomenys.txt");
	char c;
	while (!duom.eof())
	{
		while (!duom.eof())
		{
			duom.get(c);
			if (c == '\n' || duom.eof())
			{
				eil++;
				break;
			}

		}
	}
}

void irasymas(char masyvas[], ifstream& duom, int& sk)
{
	char c;
	while (!duom.eof())
	{
		duom.get(c);
		if (c == '\n' || duom.eof())
		{
			break;
		}
		masyvas[sk] = c;
		sk++;
	}
}

void skaiciavimas(int eil, int simboliai[], ifstream& duom, char masyvas[], int sk)
{

	int a = 0;
	char c;
	for(int i = 0; i < eil; i++)
	{
		irasymas(masyvas, duom, sk);
		cout << sk << endl;
		for (int i = 0; i < sk; i++)
		{
			c = masyvas[i];
			if (c == '\n')
			{
				break;
			}
			if (c == '.')
			{
				a++;
			}
			if (c == ',')
			{
				a++;
			}
		}
		simboliai[i] = a;
		a = 0;
		sk = 0;
	}
}

void daugiausiai(int eil, int simboliai[], int& eilute)
{
	int did = -1;
	for (int i = 0; i < eil; i++)
	{
		if (simboliai[i] > did)
		{
			did = simboliai[i];
			eilute = i+1;
		}
	}
}

void spausdinimas(int eilute)
{
	ofstream rez("rezultatai.txt");
	rez << eilute << " eiluteje yra daugiausiai simboliu" << endl;
}
