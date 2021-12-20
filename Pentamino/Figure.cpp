#include "Figure.h"


//���������� ������ ������
int figure::lenX(vector<int> f) {
    int x = 0, flag = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 25; j += 5) {
            if (f[j]) flag = 1;
        }
        if (flag) x++;
        flag = 0;
    }
    return x;
}

//���������� ������ ������
int figure::lenY(vector<int> f) {
    int y = 0, flag = 0;
    for (int i = 0; i < 25; i += 5) {
        for (int j = i; j < i + 5; j++) {
            if (f[j]) flag = 1;
        }
        if (flag) y++;
        flag = 0;
    }
    return y;
}



//������� �������������� ������
vector<int> fig::mirror(vector<int> f) {
    vector<int> tmp;
    for (int j = 0; j < 25; j++) {
        tmp.push_back(0);
    }
    for (int i = ((int)f.size() - 1), j = 0; j < 25; i--, j++) {
        tmp[j] = f[i];
    }
    return update(tmp);
}

//����������� ������ � ������ ����
vector<int> fig::update(vector<int> f) {
    vector<int> tmp1;
    vector<int> tmp2;
    int flag = 0;
    //���������
    int i = 0;
    for (i = 0; i < 25; i += 5) {
        for (int j = i; j < i + 5; j++) {
            if (f[j] == 1) flag = 1;
        }
        if (flag) {
            break;
        }
    }
    for (int j = i; j < 25; j++) {
        tmp1.push_back(f[j]);
    }
    flag = 0;
    for (int i = (int)tmp1.size(); i < 25; i++) tmp1.push_back(0);
    //� ������ ����
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < ((int)tmp1.size() - 1); j += 5) {
            if (tmp1[j] == 1) {
                flag = 1;
            }
        }
        if (flag) {
            int j = 0;
            for (int k = i; k < ((int)tmp1.size() - 1); k += 5) {
                for (j = k; j < k + 5; j++) {
                    if (j > ((int)tmp1.size() - 1)) break;
                    tmp2.push_back(tmp1[j]);
                }
                if (j == 24)  tmp2.push_back(tmp1[j]);
            }

            flag = 0;
            break;
        }
    }
    for (int i = (int)tmp2.size(); i < 25; i++) tmp2.push_back(0);

    return tmp2;
}

//������� ���������� ������
vector<int> fig::turn_figure(vector<int> f, int n) {
    vector<int> tmp;
    for (int j = 0; j < 25; j++) {
        tmp.push_back(0);
    }
    //�� ������� ���� �����
    if (n == 1) return f;
    else if (n == 2) {
        for (int i = 0, j = 0; i <= 4; i++) {
            for (int k = 20 + i; k >= 0; k -= 5, j++) {
                tmp[j] = f[k];
            }
        }
    }
    //�� ���������� �����
    else if (n == 3) {
        for (int i = 4, j = 0; i >= 0; i--) {
            for (int k = 20 + i; k >= 0; k -= 5, j++) {
                tmp[j] = f[k];
            }
        }
    }
    //������� � ������
    else if (n == 4) {
        for (int i = 20, j = 0; i >= 0; i -= 5) {
            for (int k = i; k <= i + 4; k++, j++) {
                tmp[j] = f[k];
            }
        }
    }
    return update(tmp);
}
