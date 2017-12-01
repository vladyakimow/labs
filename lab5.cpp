#include <iostream>
#include <stdlib.h>
using namespace std;
struct ORDER
{
	int Platelshik;
	int Poluchatel;
	int Summa;
} ;




int main()
{
	const int ORDER_COUNT = 8;

	ORDER array[ORDER_COUNT];
	for (int i = 0; i < ORDER_COUNT; i++) {
		cout << "Platelshik[" << i << "]: ";
		cin >> array[i].Platelshik;

		cout << "Poluchatel[" << i << "]: ";
		cin >> array[i].Poluchatel;

		cout << "Summa[" << i << "]: ";
		cin >> array[i].Summa;
	}


	int min;
	for (int i = 0; i < ORDER_COUNT - 1; i++) {
		min = i;

		for (int j = i + 1; j < ORDER_COUNT; j++) {
			if (array[min].Platelshik > array[j].Platelshik) {
				min = j;
			}
		}

		if (min != i) {
			std::swap(array[min], array[i]);
		}
	}


	cout << "  Platelshik \t|  Poluchatel \t|  Summa" << endl;
	for (int i = 0; i < ORDER_COUNT; i++) {
		cout << "  " << array[i].Platelshik << " \t\t|  " << array[i].Poluchatel << " \t\t|  " << array[i].Summa << endl;
	}


	while (true) {
		cout << "Vvedite schet platelshika : ";

		char vhodnoy_platej[20];
		cin >> vhodnoy_platej;

		if (vhodnoy_platej[0] == 'q' && vhodnoy_platej[1] == '\0') {
			return 0;
		}


		int is_valid = 1;
		for (int i = 0; i < 20; i++) {
			if (vhodnoy_platej[i] == '\0') {
				break;
			}
			if (!isdigit(vhodnoy_platej[i])) {
				cout << "Platelshik " << vhodnoy_platej << " ne naiden" << endl;
				is_valid = 0;
				break;
			}
		}
		if (is_valid == 0) {
			continue;
		}


		int is_nahodka= 0;
		for (int i = 0; i < ORDER_COUNT; i++) {
			if (atoi(vhodnoy_platej) == array[i].Platelshik) {
				is_nahodka = 1;
				cout << "Platelshik " << vhodnoy_platej << " otpravil " << array[i].Summa << " rubles" << endl;
				break;
			}
		}
		if (is_nahodka == 0) {
			cout << "Platelshik " << vhodnoy_platej << " ne naiden" << endl;
		}
	}
	return 0;
}
