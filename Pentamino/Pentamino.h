
#ifndef PENT
#define PENT
#include "Figure.h"
#include <fstream>

//—труктура дл€ хождени€ по клеткам.
typedef struct Point {
	int x; int y;
	Point(int a, int b) {
		y = a;
		x = b;
	}
} Point;


class pentamino {
private:
	int a = 0, //высота
		b = 0; //ширина
	vector<vector<int>> field;
	void creature();
	vector<fig> counter;
	int Solution = 0;
	int visited[12] = {0};
	int check_visited(int i);
	
public:
	void test_turn();
	friend class fig;
	Point check_field(vector<vector<int>> v, Point st, Point end);
	Point check_figure(vector<int> v);
	int CountEmpty(int y, int x, int Count);
	void output(vector<vector<int>> v);
	void search();
	void delete_figure(Point pt, Point f, int i, int j);
	char transfer(int i);
	
	pentamino(pentamino& obj) {
		this->counter = obj.counter;
		this->field = obj.field;
	};
	pentamino(int y, int x) {
		if (y * x != 60) { cout << "error";exit(1); }
		creature();
		a = y;
		b = x;
		vector<int> tmp;
		for (int j = 0; j < x; j++) {
			tmp.push_back(0);
		}
		for (int i = 0; i < y; i++) {
			field.push_back(tmp);
		}
	};
};
#endif PENT

