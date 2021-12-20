#include "Pentamino.h"
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "error" << std::endl;

		return -1;
	}
	int xy[2] = { 0 };
	string buf;
	ifstream fin(argv[1]);
	
	if (!fin.is_open()) 
	{
		cout << "Файл не может быть открыт или создан\n"; 
		return -1; 
	}
	for ( int i = 0;i<2;i++) {
		fin >> buf;
		xy[i] = stoi(buf);
	}
	pentamino A(xy[0], xy[1]);
	A.search();
}