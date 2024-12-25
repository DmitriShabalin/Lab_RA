#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arabicToRoman(int arabic) {
    string roman = "";
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; ++i) {
        while (arabic >= values[i]) {
            roman += symbols[i];
            arabic -= values[i];
        }
    }

    return roman;
}

int romanToArabic(string roman) {
    int arabic = 0;
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; ++i) {
        while (roman.find(symbols[i], 0) == 0) {
            arabic += values[i];
            roman.erase(0, symbols[i].length());
        }
    }

    if (!roman.empty()) {
        return -1;
    }

    return arabic;
}

int main() {
    setlocale(LC_ALL, "ru");

    int choice;
    bool proga = true;

    while (proga == true) {

        cout << "�������� ��������:" << endl;
        cout << "1) ������� �� ��������� � �������." << endl;
        cout << "2) ������� �� �������� � ��������." << endl;
        cout << endl;
        cout << "��� �����: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            int arabicNum;
            cout << "������� �������� �����: ";
            cin >> arabicNum;
            string romanNum = arabicToRoman(arabicNum);
            cout << "������� �����: " << romanNum << endl;
            cout << endl;
            break;
        }
        case 2: {
            string romanNum;
            cout << "������� ������� �����: ";
            cin >> romanNum;
            int arabicNum = romanToArabic(romanNum);
            if (arabicNum != -1) {
                cout << "�������� �����: " << arabicNum << endl;
            }
            cout << endl;
            break;
        }
        }
    }
}