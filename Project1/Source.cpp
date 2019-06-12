#include <Windows.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	double x, Val, xnorm;
	char sw, save;
	bool resr;
	long factval;
	ofstream fout("bin.txt", ios::out | ios::binary);
	ifstream fin("bin.txt", ios::in | ios::binary);
	HINSTANCE hmodule = NULL;
	hmodule = LoadLibrary(L"Dll1.dll");
	if (hmodule == NULL) { cout << "No" << endl; }
	else { cout << "File or Input ? " << endl; }	
	typedef bool(*CheckFact)(double val, long fact);
	CheckFact checkf = (CheckFact)GetProcAddress(hmodule, "ccheck");
	typedef bool(*CheckRand)(double Val, double x);
	CheckRand checkr = (CheckRand)GetProcAddress(hmodule, "ccout");
	cin >> sw;
	switch (sw)
	{
	case 'f':
	{
		/*fin.read((char*)&x, sizeof(x));
		cout << "X is " << x << endl;
		Val = Valfunc(x);
		factval = fact(x);
		cout << "Rand is " << Val << endl;
		resr = checkr(Val, x);*/
		typedef long(*Fact)(long x);
		Fact fact = (Fact)GetProcAddress(hmodule, "factorial");
		cout << "X is ";
		cin >> x;
		factval = fact(x);
		cout << "Rand is " << factval << endl;
		resr = checkr(x, factval);
		break;
	}
	case 'i':
	{
		typedef double(*Value)(double x);
		Value Valfunc = (Value)GetProcAddress(hmodule, "Val");
		cout << "X is ";
		cin >> x;
		Val = Valfunc(x);
		cout << "Rand is " << Val << endl;
		resr = checkr(Val, x);
		break;
	}
	default:
		cout << "No" << endl;
		break;
	}	
	if (resr == 1) { cout << "Same" << endl; }
	else { cout << "Different" << endl; }
	cout << "Save?" << endl;
	cin >> save;
	if (save == 'y') { fout.write((char*)&x, sizeof(x)); fout.close(); }
	FreeLibrary(hmodule);
	system("pause");
	return 0;
}
