/*

sa se implementeze o clasa Spital, conform urmatoarelor cerinte :
clasa are cel putin urmatoarele atribute private
- cif(cod de identificare fiscala) - sir de caractere, se atribuie valoare la crearea obiectului si apoi nu mai poate fi modificata
- nume - sir de caractere
- adresa - sir de caractere
- medici - vector de valori string, dinamic
- nrMedici - int
- nrSpitale - static int va retine nr de spitale - obiecte de tip spital - instantiate vreodata

- cel putin un atribut sir caract e char*

- constructor fara parametri
- constructor cu toti parametrii necesari instantierii unui obiect complet
- constructor de copiere
- destructor

- metode get set

- suprainc operator =
-suprainc operatori de citire si de scriere din / in consola >> <<
-suprainc operator[] - returneaza medicul de pe o pozitie data - atat in mod scriere cat si in mod citire
- suprainc operator!
- cast explicit int - ret numarul de spitale instantiate

*/

#include <iostream>
#include <string>

using namespace std;

class Spital 
{
private:
	const string cif;
	char* nume;
	string adresa;
	string* medici;
	int nrMedici;
	static int nrSpitale;

public:

	Spital() : cif("")
	{
		this->nume = nullptr;
		this->adresa = "";
		this->medici = nullptr;
		this->nrMedici = 0;

		Spital::nrSpitale++;
	}

	Spital(string cif, const char* nume, string adresa, const string* medici, int nrMedici) : cif(cif)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
			this->nume = nullptr;

		this->adresa = adresa;

		if (medici != nullptr && nrMedici > 0)
		{
			this->nrMedici = nrMedici;
			this->medici = new string[nrMedici];
			for (int i = 0; i < nrMedici; i++)
				this->medici[i] = medici[i];
		}
		else
		{
			this->nrMedici = 0;
			this->medici = nullptr;
		}

		Spital::nrSpitale++;
	}

	Spital(const Spital& s) : cif(s.cif)
	{
		if (s.nume != nullptr)
		{
			this->nume = new char[strlen(s.nume) + 1];
			strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		}
		else
			this->nume = nullptr;

		this->adresa = s.adresa;

		if (s.medici != nullptr && s.nrMedici > 0)
		{
			this->nrMedici = s.nrMedici;
			this->medici = new string[s.nrMedici];
			for (int i = 0; i < s.nrMedici; i++)
				this->medici[i] = s.medici[i];
		}
		else
		{
			this->nrMedici = 0;
			this->medici = nullptr;
		}
	}

	~Spital()
	{
		delete[] this->nume;
		this->nume = nullptr;
		delete[] this->medici;
		this->medici = nullptr;

		Spital::nrSpitale--;
	}

	string getCif()
	{
		return this->cif;
	}

	char* getNume()
	{
		char* temp = new char[strlen(this->nume)+1];
		strcpy_s(temp, strlen(this->nume)+1, this->nume);
		return temp;
	}

	string getAdresa()
	{
		return this->adresa;
	}

	int getNrMedici()
	{
		return this->nrMedici;
	}

	string* getMedici()
	{
		string* temp = new string[this->nrMedici];
		for (int i = 0; i < this->nrMedici; i++)
			temp[i] = this->medici[i];
		return temp;
	}

	void setNume(const char* nume)
	{
		if (nume != nullptr)
		{
			delete[] this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
			this->nume = nullptr;
	}

	void setAdresa(string adresa)
	{
		this->adresa = adresa;
	}

	void setMedici(string* medici, int nrMedici)
	{
		if (medici != nullptr && nrMedici > 0)
		{
			delete[] this->medici;
			this->medici = new string[nrMedici];
			for (int i = 0; i < nrMedici; i++)
				this->medici[i] = medici[i];
			this->nrMedici = nrMedici;
		}
		else
		{
			this->medici = nullptr;
			this->nrMedici = 0;
		}
	}

	Spital& operator=(const Spital& s)
	{
		if (this == &s)
			return *this;

		delete[] this->nume;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		this->adresa = s.adresa;
		this->nrMedici = s.nrMedici;
		delete[] this->medici;
		this->medici = new string[s.nrMedici];
		for (int i = 0; i < s.nrMedici; i++)
			this->medici[i] = s.medici[i];

		return *this;
	}

	friend ostream& operator<<(ostream& out, Spital& s);

	friend istream& operator>>(istream& in, Spital& s);

	string& operator[](int i)
	{
		if (i >= 0 && i < nrMedici)
			return this->medici[i];
	}

	bool operator!()
	{
		return this->nrMedici > 0;
	}

	explicit operator int()
	{
		return Spital::nrSpitale;
	}

};

int Spital::nrSpitale = 0;

ostream& operator<<(ostream& out, Spital& s)
{
	out << "CIF: " << s.cif << "\n";
	out << "Nume: " << s.nume << "\n";
	out << "Adresa: " << s.adresa << "\n";
	out << "Nr medici: " << s.nrMedici << "\n";
	out << "Nume medici: ";
	for (int i = 0; i < s.nrMedici; i++)
		out << s.medici[i] << "\n";

	return out;
}

istream& operator>>(istream& in, Spital& s)
{
	char* temp = new char[256];
	cout << "Nume: ";
	in.getline(temp, 256);
	s.setNume(temp);
	
	delete[] temp;
	temp = new char[256];
	cout << "Adresa: ";
	in.getline(temp, 256);
	s.setAdresa(temp);

	int tempnr;
	cout << "Nr medici: ";
	in >> tempnr;
	
	in.getline(temp, 256);

	string* tempnume = new string[tempnr];
	cout << "Nume medici: ";
	for (int i = 0; i < tempnr; i++)
	{
		delete[] temp;
		temp = new char[256];
		in.getline(temp, 256);
		tempnume[i] = temp;
	}

	s.setMedici(tempnume, tempnr);

	return in;
}

int main()
{
	Spital s;

	string* medici = new string[3];
	medici[0] = "Medic 1";
	medici[1] = "Medic 2";
	medici[2] = "Medic 3";


	Spital s1, s2("RO1234", "Floreasca", "Bucuresti", medici, 3);
	s2 = s2;
	s1 = s2;

	cout << s2;

	Spital s3;
	cin >> s3;

	cout << s3;

	Spital s4 = s2;

	return 0;
}
