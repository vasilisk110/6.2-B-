#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
class Childrens {
protected:
	int n;
	bool* visit;
	string* str;
	int* count;
	int* days;
	bool* oplacheno;
	bool* sestra;
public:
	void setN(int _n) { n = _n; };
	void cilcist() {
		str = new string[n]; visit = new bool[n]; count = new int[n]; days = new int[n]; oplacheno = new bool[n]; sestra = new bool[n];
	};
	void set() {
		for (int i = 0; i < n; i++) {
			count[i] = 0;
			days[i] = 0;
			
	} }
	void full();
	void visited();
	void spravka();
	void input();
};
class Zavuch :public Childrens {
protected:
	float* money;
public:
	void Money();

};
class Vospitatil :public Zavuch {
public:
	float givepaper();
	

};
class Parent :public Vospitatil {
protected:
	float* kvitancia;
	float* zarobitok;
	int tendays = 10;
public:
	void Work();
	void GetKvit();
	void oplata();
};
class Medrabotnic :public Childrens {
public:
	void show();
	
};


int main()
{
	setlocale(LC_ALL, "Russian");
	Childrens kids;
	Zavuch zav;
	Vospitatil vosp;
	Parent mom;
	Medrabotnic med;
	int n;
	int choise;
	cout << "Введите 1 если хотите заполнить список самостоятильно, 2 - если с файла - "; cin >> choise;
	if (choise == 1) {
		cout << "Введите количество детей - "; cin >> n;
		med.setN(n);
		med.cilcist();
		med.set();
		med.input();
		for (int i = 0; i < 30; i++) {
			med.visited();
		}
		zav.Money();
		mom.Work();
		vosp.givepaper();
		mom.GetKvit();
		mom.oplata();
		med.spravka();
	}
	else if (choise == 2) {
		cout << "Введите количество детей (до 30) - "; cin >> n;
		med.setN(n);
		med.cilcist();
		med.set();
		med.full();
		for (int i = 0; i < 30; i++) {
			med.visited();
		}
		zav.Money();
		mom.Work();
		vosp.givepaper();
		mom.GetKvit();
		mom.oplata();
		med.spravka();
	}
	else cout << "Not correct";
	
	
	
}

void Childrens::full()
{
	fstream file("Data.txt");
	for (int i = 0; i < n; i++) {
		file >> str[i];
	}
	file.close();
}

void Childrens::visited()
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int k = 1 + rand() % 2;
		
		if (k == 1) {
			visit[i] = true;
			count[i] += 1;
		}
		else { visit[i] = false; 
		days[i] += 1;
		
		}
	}
}

void Childrens::spravka()
{
	srand(time(NULL));
	
	for (int i = 0; i < n; i++) {
		if (days[i] >= 3) {
			cout << str[i] << " - нужна справка" << endl;
			int k = 1 + rand() % 2;
			if (k == 1) {
				sestra[i] = true;
			}
			else sestra[i] = false;
		}
	}
}

void Childrens::input()
{
	cout << "Введите фамилии\n";
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
}

void Zavuch::Money()
{
	
	
	int day = 50;
	for (int i = 0; i < n; i++) {
		if (visit[i] == true) {
			money[i] = count[i] * day;
		}
	}
}


void Parent::Work()
{
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		zarobitok[i] = rand() % 100;
	}
}

void Parent::GetKvit()
{
	for (int i = 0; i < n; i++) {
		kvitancia[i] = givepaper();
	}
}

void Parent::oplata()
{
	for (int i = 0; i < n; i++) {
		zarobitok[i] *= 10;
		if (zarobitok[i] > kvitancia[i] || zarobitok[i] == kvitancia[i]) {
			oplacheno[i] = true;
		}
		else { oplacheno[i] = false; }
	}
	

}

float Vospitatil::givepaper()
{
	for (int i = 0; i < n; i++) {
		return money[i];
	}
}

void Medrabotnic::show()
{
	Childrens kids;
	kids.spravka();
}
