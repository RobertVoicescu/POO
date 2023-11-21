#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};

//sa se implementeze o clasa care sa transpuna in aplicatie o carte
//se va tine cont de faptul ca o carte este descrisa prin:
//titlu (char*)
//autor (string sau char*)
//nr pagini (int)
//pret (double)
//electronica (bool)
//nr de cuvinte per pagina (int* [nr pag])
//pt clasa carte se vor implementa: 
//constructor cu parametri (pentru toate atributele)
//constructor de copiere
//destructor
//setter si getter pt toate atributele
//toate atributele private

class Carte
{
private:

	//atribute
	char* titlu;
	char* autor;
	int nr_pag;
	int* nr_cuv_pag;
	double pret;
	bool elect;

	//constructor
	Carte(char* _titlu, char* _autor, int _nr_pag, int* _nr_cuv_pag, double _pret, bool _elect)
	{
		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);

		this->autor = new char[strlen(_autor) + 1];
		strcpy_s(this->autor, strlen(_autor) + 1, _autor);

		this->nr_pag = _nr_pag;

		this->nr_cuv_pag = new int[_nr_pag];
		for (int i = 0; i < _nr_pag; i++)
			this->nr_cuv_pag[i] = _nr_cuv_pag[i];

		this->pret = _pret;

		this->elect = _elect;
	}

	//constructor de copiere
	Carte(const Carte& carte)
	{
		this->titlu = new char[strlen(carte.titlu) + 1];
		strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);

		this->autor = new char[strlen(carte.autor) + 1];
		strcpy_s(this->autor, strlen(carte.autor) + 1, carte.autor);

		this->nr_pag = carte.nr_pag;

		this->nr_cuv_pag = new int[carte.nr_pag];
		for (int i = 0; i < carte.nr_pag; i++)
			this->nr_cuv_pag[i] = carte.nr_cuv_pag[i];

		this->pret = carte.pret;

		this->elect = carte.elect;
	}

	//destructor
	~Carte()
	{
		delete[] this->titlu;
		delete[] this->autor;
		delete[] this->nr_cuv_pag;
	}

	//getter
	char* get_titlu()
	{
		return this->titlu;
	}

	char* get_autor()
	{
		return this->autor;
	}

	int get_nr_pag()
	{
		return this->nr_pag;
	}

	int* get_nr_cuv_pag()
	{
		return this->nr_cuv_pag;
	}

	double get_pret()
	{
		return this->pret;
	}

	bool get_elect()
	{
		return this->elect;
	}

	//setter
	void set_titlu(char* _titlu)
	{
		if (this->titlu != nullptr)
			delete[] this->titlu;
		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);
	}

	void set_autor(char* _autor)
	{
		if (this->autor != nullptr)
			delete[] this->autor;
		this->autor = new char[strlen(_autor) + 1];
		strcpy_s(this->autor, strlen(_autor) + 1, _autor);
	}

	void set_nr_cuv_pag(int _nr_pag, int* nr_cuv_pag)
	{
		this->nr_pag = _nr_pag;
		if (this->nr_cuv_pag != nullptr)
			delete[] this->nr_cuv_pag;
		this->nr_cuv_pag = new int[_nr_pag];
		for (int i = 0; i < _nr_pag; i++)
			this->nr_cuv_pag[i] = nr_cuv_pag[i];
	}

	void set_pret(int _pret)
	{
		this->pret = _pret;
	}

	void set_elect(bool _elect)
	{
		this->elect = _elect;
	}

};

class Student
{
public:
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

	//constructori
	Student()
	{

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}
	*/

	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii


	Student(const Student& student)
	{
		this->nume = student.nume;

		this->adresa = new char[strlen(student.adresa) + 1];
		strcpy_s(this->adresa, strlen(student.adresa) + 1, student.adresa);

		this->varsta = student.varsta;

		this->an_studii = student.an_studii;

		this->note = new int[student.numar_materii];
		for (int index = 0; index < student.numar_materii; index++)
		{
			this->note[index] = student.note[index];
		}

		this->numar_materii = student.numar_materii;

		this->numar_matricol = student.numar_matricol;

		this->finantare = student.finantare;
	}

	//setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}
private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0;

	s0.nume = "Anghel Mihai";

	s0.adresa = new char[20];
	strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");

	s0.varsta = 21;
	s0.an_studii = 2;

	//de ce este generata eroarea?
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);


	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	Student s2 = s1;
	s2.nume = "Ionescu C";
}

