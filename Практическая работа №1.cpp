#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string name, cena, kolvo;
    cout << "Введите наименование товара: ";
    getline(cin, name);
    int flag1 = 1;
    while (flag1 == 1) {
        try {
            cout << "Введите цену товара: ";
            int flag2 = 0;
            int flag3 = 0;
            getline(cin, cena);
            for (int i = 0; i < cena.length(); i++) {
                if (i == 0 && cena[i] == '-') {
                    if(flag2==1)
                        throw invalid_argument("некорректное значение (несколько минусов).");
                    flag2 = 1;
                }
                else if (cena[i] == '.') {
                    if (flag3 == 1)
                        throw invalid_argument("некорректное значение (несколько точек).");
                    flag3 = 1;
                }
                else if(cena[i] != '0' && cena[i] != '1' && cena[i] != '2' && cena[i] != '3' && cena[i] != '4' && cena[i] != '5' && cena[i] != '6' && cena[i] != '7' && cena[i] != '8' && cena[i] != '9')
                    throw invalid_argument("некорректное значение (неправильное расположение минуса или символы, не являющиеся цифрами или точкой).");
            }
            if(cena == "-" || cena == "." || cena =="-." || cena == "")
                throw invalid_argument("некорректное значение (отсутствуют цифры).");
            cout << "Введите количество товара: ";
            getline(cin, kolvo);
            flag2 = 0;
            flag3 = 0;
            for (int i = 0; i < kolvo.length(); i++) {
                if (i == 0 && kolvo[i] == '-') {
                    if (flag2 == 1)
                        throw invalid_argument("некорректное значение (несколько минусов).");
                    flag2 = 1;
                }
                else if (kolvo[i] != '0' && kolvo[i] != '1' && kolvo[i] != '2' && kolvo[i] != '3' && kolvo[i] != '4' && kolvo[i] != '5' && kolvo[i] != '6' && kolvo[i] != '7' && kolvo[i] != '8' && kolvo[i] != '9')
                    throw invalid_argument("некорректное значение (неправильное расположение минуса или символы, не являющиеся цифрами).");
            }
            if (kolvo == "-" || kolvo == "")
                throw invalid_argument("некорректное значение (отсутствуют цифры).");
            float floatcena = stof(cena);
            int intkolvo = stoi(kolvo);
            if (floatcena < 0 || intkolvo < 0)
                throw domain_error("отрицательные значения.");
            flag1 = 0;
            cout << "Данные успешно введены.\n";
            cout << "Наименование товара: "<<name<<"; цена: "<<floatcena<<"; количество: "<<intkolvo<<".";
        }
        catch (domain_error& ex) {
            cout << "domain_error: " << ex.what() << endl;
        }
        catch (invalid_argument& ex) {
            cout << "invalid_argument: " << ex.what() << endl;
        }
    }
    return 0; 
}
