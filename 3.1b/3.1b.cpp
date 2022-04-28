
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
	"����.� �����",
	"������.",
	"�����. �� �����.",
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
	cout << "������ N: "; cin >> N;

	Student* s = new Student[N];

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ��������� ������� ��������,  " << endl;
		cout << " � ���� ������� ��� ������ �� 4,5" << endl;
		cout << " [4] - ������� ������� ��������, �� ������� �� �������" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "������� �������� �� �� ������� ��� >4.5 ="
				<< Excellent(s, N) << " % " << endl;
			break;
		case 4:
			Count(s, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Create(Student* s, const int N)
{
	int cours, spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; cin >> s[i].prizv;
		cout << " ����: "; cin >> cours;
			s[i].cours = (Cours)cours;
		cout << "������������: 0 - ��������� �����,  1 - �����������, \n 2 - ���������� �� ��������, "
				<< endl << "������ ������������: ";
			cin >> spec;        
			s[i].spec = (Spec)spec;
		cout << " ������ � ������: "; cin >> s[i].physic;
		cout << " ������ � ����������: "; cin >> s[i].math;
		switch (s[i].spec) {
		case KN:
			cout << "������ � �������������:"; cin >> s[i].prog;
			break;
		case INF:
			cout << "������ � ��������� ������:"; cin >> s[i].numM;
			break;
		case MATHandECONOM:
			cout << "������ � ���������:"; cin >> s[i].ped;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{

	cout << "========================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | �����a | �������. | ���. ���. | ��������� |"
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