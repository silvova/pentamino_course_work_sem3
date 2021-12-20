#include "Pentamino.h"

//������� ������ ���� ����� � ������ counter.
void pentamino::creature() {
    vector<int> t = { 0, 1, 0, 0, 0,
                         0, 1, 0, 0, 0,
                         1, 1, 1, 0, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0
    };
    vector<int> u = { 1, 1, 0, 0, 0,
                      1, 0, 0, 0, 0,
                      1, 1, 0, 0, 0,
                      0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0
    };
    vector<int> l = { 1, 0, 0, 0, 0,
                       1, 1, 1, 1, 0,
                       0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0
    };
    vector<int> w = { 1,0,0,0,0,
                        1,1,0,0,0,
                        0,1,1,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> x = { 0,1,0,0,0,
                        1,1,1,0,0,
                        0,1,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> y = { 1,1,1,1,0,
                        0,1,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> z = { 0,0,1,0,0,
                        1,1,1,0,0,
                        1,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> f = { 0,0,1,0,0,
                        1,1,1,0,0,
                        0,1,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> i = { 1,1,1,1,1,
                        0,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> v = { 0,0,1,0,0,
                        0,0,1,0,0,
                        1,1,1,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> p = { 0,1,1,0,0,
                        1,1,1,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    vector<int> n = { 0,1,1,1,0,
                        1,1,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0,
                        0,0,0,0,0
    };
    fig X(-1, x);//��� ���������
    fig I(-2, i);//��� �������
    fig T(2, t);
    fig U(2, u);
    fig W(2, w);
    fig L(4, l);
    fig Y(4, y);
    fig Z(-3, z);//���������
    fig F(4, f);
    fig V(2, v);
    fig P(4, p);
    fig N(4, n);
    counter.push_back(U);
    counter.push_back(X);
    counter.push_back(I);
    counter.push_back(N);
    counter.push_back(F);
    counter.push_back(T);
    counter.push_back(W);
    counter.push_back(Y);
    counter.push_back(Z);
    counter.push_back(V);
    counter.push_back(P);
    counter.push_back(L);

}

//���������� ��������� ��������� ����� � ����
Point pentamino::check_field(vector<vector<int>> v, Point st, Point end) {
    for (; st.y < end.y; st.y++) {
        for (; st.x < end.x; st.x++) {
            if (v[st.y][st.x] == 0) {
                return st;
            }
        }
        st.x = 0;
    }
    return st;
}

//���������� ��������� ������� ����� � ������
Point pentamino::check_figure(vector<int> v) {
    for (int i = 0; i < 25; i++) {
        if (v[i] == 1) {
            Point st(i / 5, i % 5);
            return st;
        }
    }
    return Point(0, 0);
}

//��������� ������� ��������� ������ ��� ��������� ������
int pentamino::CountEmpty(int y, int x, int Count) {
    //���� ����� �� ��������, �� �������
    if ((y < 0) || (x < 0) || ((y >= a) || (x >= b))) return Count - 1;

    //���� ������ ������
    if (field[y][x] == 0)
    {
        
        //��� ����� 4-�, ������ ��� ����� � �������
        if (Count == 4) return 5;

        //���������, ��� ��� ������ ���������
        field[y][x] = -1;

        //��������� �� ��������
        Count = CountEmpty(y, x + 1, Count + 1);
        //���� �� ����� ����, �� ���� ������
        if (Count < 5)
        {
            //��������� �� ��������
            Count = CountEmpty(y + 1, x, Count + 1);
            //���� �� ����� ����, �� ���� ������
            if (Count < 5)
            {
                //��������� �� ��������
                Count = CountEmpty(y, x - 1, Count + 1);
                //���� �� ����� ����, �� ���� ������
                if (Count < 5)
                {
                    //��������� �� ��������
                    Count = CountEmpty(y - 1, x, Count + 1);
                    
                }
            }
        }
        //�� ������ ������� ������� �������� ������
        field[y][x] = 0;
        
    }
    else return Count - 1;

    return Count;
}

//������� ������ ������������ ����.
ofstream fout("output.txt");
void pentamino::output(vector<vector<int>> v) {
   
    fout << "Solution " << Solution << " :\n";
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            fout << transfer(v[i][j]) << " ";
        }
        fout << '\n';
    }
}

//������� �������� ������ ������ � �����.
char pentamino::transfer(int i) {
    switch (i) {
    case 0: return 'O';
    case 1: return 'U';
    case 2: return 'X';
    case 3: return 'I';
    case 4: return 'N';
    case 5: return 'F';
    case 6: return 'T';
    case 7: return 'W';
    case 8: return 'Y';
    case 9: return 'Z';
    case 10: return 'V';
    case 11: return 'P';
    case 12: return 'L';
    }
        
}

//�������� ��������� �����
void pentamino::test_turn() {
    for (int i = 0; i < 12; i++) {
        cout << "   ALLAX" << endl;
        for (int j = 0; j <= (int)(counter[i].turns.size() - 1); j++) {

            for (int k = 0; k < 25; k++) {
                cout << counter[i].turns[j].main_figure[k] << " ";
                if (((k + 1) % 5) == 0) cout << "\n";
            }
            cout << endl;
        }
    }
};

//�������� ������ �� ����.
void pentamino::delete_figure(Point pt, Point f, int i, int j) {
    for (int y = 0; y < counter[i].turns[j].leny; y++)
    {
        for (int x = 0; x < counter[i].turns[j].lenx; x++)
        {
           if(field[pt.y + y][pt.x - f.x + x]==(i+1)) field[pt.y + y][pt.x - f.x + x] = 0;
        }
    }
    visited[i] = 0;
}

//�������� ������� ��������� �����
int pentamino::check_visited(int i) {
    int ex = i;
    while (visited[(i%=12)]) {        
        i++;
        if (i == ex) return -1;
    }
    return i;
}

//������� ��������� ������� ��������� � ������� ���� ����������
void pentamino::search() {
    Point pt(0, 0);
        for (int i = 0;i <= 11;i++) {
            if (visited[i]) continue;

            

            pt = check_field(field, pt, Point(a, b));
            if (pt.y == a)
            {
                break;
            }
            // ���� �� ����������� ��� �������� � ���������
            for (int j = 0; j < counter[i].n_turn;j++){
                //����� ������ �������� ������ � ������ �� �����������
                Point f = check_figure(counter[i].turns[j].main_figure);

                //������� ���������, ���� ����������� �������, ��������� ����� ������
                if (pt.x - f.x >= 0 && (pt.x - f.x) + counter[i].turns[j].lenx <= b && pt.y + counter[i].turns[j].leny <= a){
                    //�������, ���� ������ � �������
                    bool s = true;
                    int d = f.x;

                    //�������� ����� �� ��������
                    for (int y = 0; y < counter[i].turns[j].leny; y++){
                        for (int x = 0; x < counter[i].turns[j].lenx; x++){
                            if (counter[i].turns[j].main_figure[(y * 5 + x)] == 1){
                                if (field[pt.y + y][pt.x - f.x + x] != 0) {
                                    s = false;
                                    x = counter[i].turns[j].lenx; //������� �� ������
                                    y = counter[i].turns[j].leny;
                                }
                            }
                        }
                    }
                    //���������
                    if (s){
                        for (int y = 0; y < counter[i].turns[j].leny; y++){
                            for (int x = 0; x < counter[i].turns[j].lenx; x++){
                                if (!field[pt.y + y][pt.x - f.x + x] && counter[i].turns[j].main_figure[(y * 5 + x)] != 0)
                                    field[pt.y + y][pt.x - f.x + x] += (counter[i].turns[j].main_figure[(y * 5 + x)]+ i);
                            }
                        }
                        
                        //������� ��������� ����� ��� �������� �� ���������
                        int y1 = pt.y - 1;
                        int x1 = pt.x - f.x - 1;

                        //���������, ����� �� ������� �� ��������
                        if (y1 < 0) y1 = 0;
                        if (x1 < 0) x1 = 0;

                        //�������� ������� ������
                        for (int y = y1; y < y1 + counter[i].turns[j].leny + 1 && y < a; y++){
                            for (int x = x1; x < x1 + counter[i].turns[j].lenx + 1 && x < b; x++){
                                if (field[y][x] == 0){
                                    if (CountEmpty(y, x, 0) < 5){ //���� �������� ������ ������ 5-�, ��
                                        s = false;
                                        y = a; //������� �� �����, ��� ��� ����� �����, ������� ������ ��� �� ��� ���������
                                        x = b;
                                    }
                                }
                            }
                        }

                        if (s){
                            visited[i] = 1;
                            //���� �� ��� ������ �����������, �� ���������� ������
                            if (check_visited(i) != -1){
                                search();
                                delete_figure(pt, f, i, j);
                            }

                            else{
                                //�������� ������� �� ����������
                                Point pr = pt;
                                pt = check_field(field, Point(0, 0), Point(a, b));

                                if (pt.x == 0 && pt.y == a)
                                {
                                    Solution++;
                                    
                                    //����� ���� � ������ � ����
                                    output(field);
                                }
                                pt = pr;
                                delete_figure(pt, f, i, j);
                            }
                        }
                        else { //������
                             delete_figure(pt, f, i, j);
                        }
                    }
                }
            }
            
             
            if (pt.x == b) {
                pt.x = 0;pt.y++;
                if (pt.y >= a) {
                    break;
                }
            }
        }
}