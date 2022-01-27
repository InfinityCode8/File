#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
//#include <ctime>

using namespace std;

class Customers
{
public:
	string name;
	string surname;
	string midllename;
	string date_of_birth;
	string position;
	int number_of_purchases;
	float amount_spent;



	Customers()
	{
		name = "";
		surname = "";
		midllename = "";
		date_of_birth = "";
		position = "";
		number_of_purchases = 0;
		amount_spent = 0;
	}
	Customers(string namew, string surnamew, string midllenamew, string date_of_birthw, string positionw, int number_of_purchasesw, float amount_spentw)
	{
		this-> name = namew;
		this->surname = surnamew;
		this->midllename = midllenamew;
		this->date_of_birth = date_of_birthw;
		this->position = positionw;
		this->number_of_purchases = number_of_purchasesw;
		this->amount_spent = amount_spentw;
	}

	void info()
	{
		cout << name << "\t    " << surname << "\t    " << midllename << "\t  " << date_of_birth << "\t "
		<< position << " \t" << number_of_purchases << "\t" << amount_spent << endl;
	}

	
};


ostream& operator<<(ostream& os, const Customers& a)
{
	os << a.name << "\t\t" << a.surname << "\t\t" << a.midllename << "\t" << a.date_of_birth 
	<< "\t" << a.position << "\t\t   " << a.number_of_purchases << "\t" << a.amount_spent;
	return os;
}

istream& operator>>(istream& is, Customers& a)
{
	is >> a.name >> a.surname >> a.midllename >> a.date_of_birth
	>> a.position >> a.number_of_purchases >> a.amount_spent;
	return is;
}


void addobj()
{
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if(!fs.is_open())
	{
		cout << "Помилка відкриття файлу" << endl;
	}
	else
	{
		string name, surname, midllename, date_of_birth, position;
		int number_of_purchases;
		float amout_spent;
		cout << "\nФайл вікрито" << endl;
		cout << "Введіть відповідні дані клієнта" << endl;
		cout << "Ім'я: ";
		cin >> name;
		cout << "Прізвище: ";
		cin >> surname;
		cout << "По-батькові: ";
		cin >> midllename;
		cout << "Дата народження (приклад 22.12.2000): ";
		cin >> date_of_birth;
		cout << "Посада: ";
		cin >> position;
		cout << "Кількість покупок: ";
		cin >> number_of_purchases;
		cout << "Витрачена сума: ";
		cin >> amout_spent;
		Customers a(name, surname, midllename, date_of_birth, position, number_of_purchases, amout_spent);
		fs << a << '\n';
		a.info();
	}
	fs.close();
}

void customer_list()
{
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Помилка відкриття файлу" << endl;
	}
	else
	{

		cout << "\nФайл вікрито " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		while (true)
		{
			Customers a;
			fs >> a;
			if (fs.eof())
			{
				break;
			}
			a.info();
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	}
	fs.close();
}


void average_size_of_purchases()
{
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Помилка відкриття файлу" << endl;
	}
	else
	{
		cout << "\nФайл вікрито " << endl;
		int i = 0;
		int sum = 0;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		while (!fs.eof())
		{
			
			Customers a;
			fs >> a;
			string foo = a.date_of_birth;
			foo.erase(0, 6);
			int f = atoi(foo.c_str());
			if (f <= 1956)
			{
				i++;
				sum += a.number_of_purchases;
				if (f == 0)
				{
					cout << "Середній розмір покупок для клієнтів пенсійного віку (старше 65): " << (sum / i) << endl;
					break;
				}
			}
			/*else
			{
				cout << "Середній розмір покупок для клієнтів пенсійного віку (старше 65): " << (sum / i) << endl;
				break;
			}*/
			

		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
	}
	fs.close();
}


void special_сustomer_list()
{
	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Помилка відкриття файлу" << endl;
	}
	else
	{
		cout << "\nФайл вікрито " << endl;
		int x ;
		cout << "Введіть Х: ";
		cin >> x;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		int i = 0;
		while (!fs.eof())
		{
			
			Customers a;
			fs >> a;
			int foo = a.number_of_purchases;
			
			if (x < foo)
			{
				i++;
				a.info();
				if(fs.eof())
				{
					break;
				}
	
			}
			else if (fs.eof() and i == 0)
			{
				cout << "Немає клієнтів у яких кількість покупок більша ніж Х" << endl;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
	}
	fs.close();
}



void birthday_check()
{
	/*int month, day, border;
	time_t now = time(0);
	char* dt = ctime(&now);
	tm* ltm = localtime(&now);
	month = 1 + ltm->tm_mon;
	day = ltm->tm_mday;
	border = day + 7; 
	cout << day << endl;*/

	fstream fs;
	fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Помилка відкриття файлу" << endl;
	}
	else
	{
		cout << "\nФайл вікрито " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	
		while (!fs.eof())
		{
			Customers a;
			fs >> a;
			if (a.date_of_birth != "" and a.date_of_birth != "\n")
			{
				string birthday_day = a.date_of_birth;
				string birthday_month = a.date_of_birth;
				string birthday = birthday_day.erase(birthday_day.size() - 8);
				birthday_month = birthday_month.erase(birthday_month.size() - 5);
				birthday_month = birthday_month.erase(0, 3);
				//int birthday_dayf = atoi(birthday_day.c_str());
				//int birthday_monthf = atoi(birthday_month.c_str());
				if (birthday >= "16" and birthday <= "23" and birthday_month == "12")
				{
					a.info();
				}
				if (fs.eof())
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
	}
	fs.close();
}

void Menu()
{
	string str;
	cout << "\n************************************************************************************************************************" << endl;
	cout << "Введіть назву функції для відповідної дії" << endl;
	cout << "\"addobj\" - додати об'єкт" << endl;
	cout << "\"custlist\" - виводить список всіх клієнтів" << endl;
	cout << "\"aver\" - виводить середній розмір покупок для клієнтів пенсійного віку (старше 65)" << endl;
	cout << "\"purch\" - виводить список клієнтів, у яких покупок більше ніж певне Х" << endl;
	cout << "\"birth\" - виводить список клієнтів, у яких на цьому тижні день народження" << endl;
	cout << "\"exit\" - вийти з програми" << endl;
	cout << "************************************************************************************************************************" << endl;
	cin >> str;
	if (str == "addobj")
	{
		addobj();
	}
	else if (str == "custlist")
	{
		customer_list();
	}
	else if(str == "aver")
	{
		average_size_of_purchases();
	}
	else if (str == "purch")
	{
		special_сustomer_list();
	}
	else if (str == "birth")
	{
		birthday_check();
	}
	else if (str == "exit")
	{
		exit(0);
	}
	else
	{
		cout << "Не вірна команда" << endl;
	}
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	while (true)
	{
		Menu();
	}

	return 0;
}