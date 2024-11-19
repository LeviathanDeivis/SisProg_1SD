#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::setprecision;
using std::fixed;
using std::setw;
using std::right;
using std::left;


class Studentas {
public:
	string vardas, pavarde;
	vector <int> namuDarbai;
	int egzaminas;
	double galutinis;
public:
	Studentas() {             // default konstruktorius;
		vardas = "nera";
		pavarde = "nera";
		galutinis = 0.0;
	}
	Studentas(string vard, string pav, vector <int> nd, int egz, double gal) { // konstruktorius su parametrais
		vardas = vard;
		pavarde = pav;
		namuDarbai = nd;
		egzaminas = egz;
		galutinis = gal;
	}
	Studentas(const Studentas& kopija) { // kopijavimo konstruktorius
		vardas = kopija.vardas;
		pavarde = kopija.pavarde;
		namuDarbai = kopija.namuDarbai;
		egzaminas = kopija.egzaminas;
		galutinis = kopija.galutinis;
	}
	Studentas& operator=(const Studentas& kopija) { // priskyrimo/kopijavimo konstruktorius
		if (this == &kopija) return *this; 
		vardas = kopija.vardas;
		pavarde = kopija.pavarde;
		namuDarbai = kopija.namuDarbai;
		egzaminas = kopija.egzaminas;
		galutinis = kopija.galutinis;
		return *this;
	}

	~Studentas() {} // destruktorius

	double skaiciuotiGalutini() {
		double suma = 0.0;
		for (int nd : namuDarbai) {
			suma = nd + suma;
		}
		double vidurkis = 0.0;
		if (!namuDarbai.empty()) {
			vidurkis = suma / namuDarbai.size(); 
		}
		return  0.4 * vidurkis + 0.6 * egzaminas;
	}

	friend istream& operator >> (istream&, Studentas& studentas) { // ivesties operatoriaus perdengimas
		cout << "Iveskite studento varda: " << endl;
		cin >> studentas.vardas;
		cout << "Iveskite studento pavarde: " << endl;
		cin >> studentas.pavarde;
		cout << "Iveskite namu darbu pazymius (noredami baigti, irasykite 0): ";
		int pazymys;
		while (cin >> pazymys && pazymys != 0) {
			studentas.namuDarbai.push_back(pazymys);
		}
		cout << "Iveskite egzamino ivertinima: ";
		cin >> studentas.egzaminas;
		studentas.galutinis = studentas.skaiciuotiGalutini();
		return cin;
	}

	friend ostream& operator<<(ostream& cout, const Studentas& studentas) {

		cout << left << setw(15) << studentas.pavarde << setw(12) << studentas.vardas << fixed << setprecision(2) << setw(15) << studentas.galutinis << endl;

		return cout;

	}
};


int main() {
	
	vector<Studentas> studentai;  
	string atsakymas;

	do {
		Studentas studentas;
		cin >> studentas;  
		studentai.push_back(studentas); 

		cout << "Ar norite prideti kita studenta? (taip/ne): ";
		cin >> atsakymas;
	} while (atsakymas == "taip");

	cout << endl << left << setw(15) << "Pavarde" << setw(12) << "Vardas" << setw(15) << "Galutinis (Vid.)" << endl;
	cout << "--------------------------------------------------" << endl;

	for (const Studentas& studentas : studentai) {
		cout << studentas;
	}

	return 0;
}

