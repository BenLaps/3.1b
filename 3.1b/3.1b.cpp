
#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <Windows.h> 

using namespace std;

enum Cours { I = 1, II, III, IV, V, VI };
string CoursStr[] = {
	"I", "II", "III", "IV", "V", "VI"
};

enum Spec { KN, INF, MATHandECONOM};
string SpecStr[] = {
	"Комп.і науки",
	"Інформ.",
	"Матем. та еконо.",
};

struct Student
{
	string prizv;
	Cours cours;
	Spec spec;
	int physic;
	int math;
	union {
		int prog;
		int numM;
		int ped;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double Excellent(Student* s, const int N);
void Count(Student* s, const int N);


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Обчислити процент студентів,  " << endl;
		cout << " у яких середній бал більший за 4,5" << endl;
		cout << " [4] - Вивести прізвища студентів, які вчаться на “відмінно”" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;


		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			cout << "Процент студентів що має середній бал >4.5 ="
				<< Excellent(s, N) << " % " << endl;
			break;
		case 4:
			Count(s, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Create(Student* s, const int N)
{
	int cours, spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище: "; cin >> s[i].prizv;
		cout << " Курс: "; cin >> cours;
			s[i].cours = (Cours)cours;
		cout << "Спеціальність: 0 - Комп’ютерні науки,  1 - Інформатика, \n 2 - Математика та економіка, "
				<< endl << "Введіть спеціальність: ";
			cin >> spec;        
			s[i].spec = (Spec)spec;
		cout << " Оцінка з фізики: "; cin >> s[i].physic;
		cout << " Оцінка з математики: "; cin >> s[i].math;
		switch (s[i].spec) {
		case KN:
			cout << "Оцінка з програмування:"; cin >> s[i].prog;
			break;
		case INF:
			cout << "Оцінка з чисельних методів:"; cin >> s[i].numM;
			break;
		case MATHandECONOM:
			cout << "Оцінка з педагогіки:"; cin >> s[i].ped;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{

	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Матемa | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].prizv << " "
			<< "| " << setw(4) << right << s[i].cours << " "
			<< "| " << setw(11) << left << s[i].spec << " "
			<< "| " << setw(6) << right << s[i].physic << " "
			<< "| " << setw(6) << left << s[i].math << " ";
			switch (s[i].spec) {
			case KN:
				cout << "| " << setw(8) << right
					<< s[i].prog << " | " << setw(12) << right
					<< " | " << setw(12) << right << " |" << endl;
				break;
			case INF:
				cout << "| " << setw(11) << right
					<< " | " << setw(9) << right << s[i].numM
					<< " | " << setw(12) << right << " |" << endl;
				break;
			case MATHandECONOM:
				cout << "| " << setw(11) << right
					<< " | " << setw(12) << right
					<< " | " << setw(10) << right << s[i].ped << " |" << endl;
				break;
			}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

double Excellent(Student* s, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (((double)(s[i].prog + s[i].math + s[i].physic) / 3) >= (double)4.5)
			count++;
	}
	if (count != (int)0)
		return (double)(N * count) / 100;
	else
		return 0;
}

void Count(Student* s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if ((s[i].prog == 5) && (s[i].math == 5) && (s[i].physic == 5))
		{
			cout << "# " << s[i].prizv << endl;
		}
	}
}