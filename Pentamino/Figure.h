#ifndef IF
#define IF
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Структура для хранения фигур с габаритами.
typedef struct figure {
	int lenx, leny; //размер фигуры
	vector<int> main_figure;
	figure(vector<int> f) {
		lenx = lenX(f);
		leny = lenY(f);
		main_figure = f;
	}
private:
	int lenX(vector<int> f);
	int lenY(vector<int> f);

} figure;

//Класс создания всех фигур, с поворотами и зеркальным отражением.
class fig {
private:
	int n_turn;
	vector<figure> turns;
public:
	friend class pentamino;
	fig() {
		n_turn = 0;
	};
	fig(int n, vector<int> t) {
		//Запись всех видов фигур в вектор векторов turns.
		if (n == -1) { turns.push_back(figure(t)); n_turn = 1; }
		else if (n == -2) {
			turns.push_back(figure(t));
			turns.push_back(figure(turn_figure(t, 2))); n_turn = 2;
		}
		else if (n == -3) {
			turns.push_back(figure(t));
			turns.push_back(figure(turn_figure(t, 4)));
			turns.push_back(figure(turn_figure(t, 2)));
			turns.push_back(figure(turn_figure(turn_figure(t, 4), 2))); n_turn = 4;
		}
		else {
			n_turn = n * 2;
			for (int i = 1; i <= n; i++) {
				turns.push_back(figure(turn_figure(t, i)));
				turns.push_back(figure(mirror(turn_figure(t, i))));
			}
		}
	}
	vector<int> turn_figure(vector<int> f, int n);
	vector<int> mirror(vector<int> f);
	vector<int> update(vector<int> f);
};



#endif IF
