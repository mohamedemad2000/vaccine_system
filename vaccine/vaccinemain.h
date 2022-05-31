#include "vaccine.cpp"
#include <iostream>
#include <string>
using namespace std;

class person
{
public:
	string fullname;
	long long nationalid;
	string password;
	char gender;
	int age;
	string country;
	string governorate;
	bool waitinglist;
	bool onedose;
	bool twodose;
	friend ostream& operator << (ostream& output, person& p);
}p[100];
ostream& operator << (ostream& output, person& p)
{
	cout << "your name is : " << p.fullname << endl;
	cout << "your id is : " << p.nationalid << endl;
	cout << "your password is : " << p.password << endl;
	cout << "your gender is :" << p.gender << endl;
	cout << "your age is :" << p.age << endl;
	cout << "your country is : " << p.country << endl;
	cout << "your governorate is : " << p.governorate << endl;
	if (p.waitinglist == true)
		cout << "you are in waiting list" << endl;
	if (p.onedose == true)
		cout << "you take one dose" << endl;
	if (p.twodose == true)
		cout << "you take two dose" << endl;
	return output;
}
person edit()
{
	person pu;
	cout << "enter the new name : " << endl;
	cin >> pu.fullname;
	cout << "enter the new id : " << endl;
	while (true) { // validation on user choise
		long long flag1 = 1000000000000;
		if (!(cin >> pu.nationalid) || pu.nationalid < 0 || pu.nationalid / flag1 < 1 || pu.nationalid / flag1 > 10)
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Enter a valid number \n";
			cout << "National ID :";
		}
		else
		{
			break;
		}
	}
	cout << "enter the new password : " << endl;
	cin >> pu.password;
	cout << "enter the new gender : " << endl;
	cin >> pu.gender;
	cout << "enter the new age : " << endl;
	cin >> pu.age;
	cout << "enter the new country : " << endl;
	cin >> pu.country;
	cout << "enter the new governorate : " << endl;
	cin >> pu.governorate;
	return pu;
}
person update()
{
	person pu;
	cout << "enter the new name : " << endl;
	cin >> pu.fullname;
	cout << "enter the new id : " << endl;
	while (true) { // validation on user choise
		long long flag1 = 1000000000000;
		if (!(cin >> pu.nationalid) || pu.nationalid < 0 || pu.nationalid / flag1 < 1 || pu.nationalid / flag1 > 10)
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Enter a valid number \n";
			cout << "National ID :";
		}
		else
		{
			break;
		}
	}
	cout << "enter the new password : " << endl;
	cin >> pu.password;
	cout << "enter the new gender : " << endl;
	cin >> pu.gender;
	cout << "enter the new age : " << endl;
	cin >> pu.age;
	cout << "enter the new country : " << endl;
	cin >> pu.country;
	cout << "enter the new governorate : " << endl;
	cin >> pu.governorate;
	return pu;
}
void deleteperson(int position)
{
	for (int i = position; i < 100; i++)
		p[i] = p[i + 1];
}
int main()
{
	vaccine <person> people(100);
	int i = 1;
	float egypopulation = 101674434;
	int g;
	string Gov[] = { "Cairo","Alexandria","Giza","Aswan","Luxor","Monufia","North Sinai","South Sinai","Red Sea","Qena","Qalyubia","Port Said","Suez","Sohag","Sharqia","New Valley","Minya","Matruh","Kafr El Sheikh","Ismailia","Gharbia","Faiyum","Damietta","Dakahlia","Beni Suef","Beheira","Asyut" };
	float waitinglist = 1;
	float onedose = 1;
	float twodose = 0;
	p[0].fullname = "mohamed";
	p[0].nationalid = 3000503010554;
	p[0].password = "23456";
	p[0].gender = 'm';
	p[0].age = 21;
	p[0].country = "egypt";
	p[0].governorate = "cairo";
	p[0].waitinglist = true;
	people.Append(p[0]);
	p[1].fullname = "ahmed";
	p[1].nationalid = 3001090950142;
	p[1].password = "352000";
	p[1].gender = 'm';
	p[1].age = 26;
	p[1].country = "egypt";
	p[1].governorate = "alexandria";
	p[1].onedose = true;
	people.Append(p[1]);
	cout << "                                 welcome to Vaccine Tracking System  " << endl;
	while (true)
	{
		cout << "1-log in" << endl;
		cout << "2-Sign up " << endl;
		long long ID;
		string password;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "1.Admin" << endl;
			cout << "2.User" << endl;
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			
			case 1:
				cout << "please enter password : " << endl;
				cin >> password;
				if (password == "Admin")
				{
					cout << "1.Show statistics of the Vaccination system in Egypt" << endl;
					cout << "2.Search for a user" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:

						cout << "1.People have received one dose of the vaccine in Vaccination system :  " << endl;
						cout << (onedose / (waitinglist + onedose + twodose)) * 100 << "%" << endl;
						cout << "2.People have received two doses of the vaccine in Vaccination system  : " << endl;
						cout << (twodose / (waitinglist + onedose + twodose)) * 100 << "%" << endl;
						cout << "3.People have received one dose or two doses of the vaccine in Vaccination system  : " << endl;
						cout << ((onedose + twodose) / (waitinglist + onedose + twodose)) * 100 << "%" << endl;
						cout << "4.People have applied for vaccination in Vaccination system  :  " << endl;
						cout << (waitinglist / (waitinglist + onedose + twodose)) * 100 << "%" << endl;
						cout << "5.People have applied for vaccination in Egypt  :  " << endl;
						cout << ((waitinglist + onedose + twodose) / egypopulation) * 100 << "%" << endl;
						cout << "6.People have not applied for vaccination in Egypt  :  " << endl;
						cout << ((egypopulation - (waitinglist + onedose + twodose)) / egypopulation) * 100 << "%" << endl;

						break;
					case 2:
						cout << "please enter user's National ID :" << endl;
						cin >> ID;
						for (int j = 0; j < 100; j++)
							if (ID == p[j].nationalid)
							{
								people.AT(j);
								cout << endl;
								cout << "do you want to delete this record ??" << endl;
								char confirm;
								cin >> confirm;
								if (confirm == 'y' || confirm == 'Y')
								{
									people.deleteat(j);
									deleteperson(j);
									people.Display();
									break;
								}
								else
								{
									break;
								}
							}
							else
							{
								cout << "this id is not in the system" << endl;
								break;
							}
					}

				}
				else
				{
					cout << "please enter the right password" << endl;
				}
				break;
			case 2:
				cout << "Please enter your National ID" << endl;
				cin >> ID;
				cout << "Please enter your Password" << endl;
				cin >> password;
				for (int i = 0; i < 100; i++)
					if (ID == p[i].nationalid && password == p[i].password)
					{
						people.AT(i);
						cout << "1.Edit or update my information" << endl;
						cout << "2.Delete my record" << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:
							int eou;
							cout << "1-edit" << endl;
							cout << "2-update" << endl;
							cin >> eou;
							switch (eou)
							{
							case 1:
								people.update(i, edit());
								people.AT(i);
								break;
							case 2:
								people.update(i, update());
								people.AT(i);
								break;
							default:
								break;
							}
							break;
						case 2:
							people.deleteat(i);
							deleteperson(i);
							people.Display();
							break;
						default:
							break;
						}

					}


				break;
			}
		}
		else if (choice == 2)
		{
			i++;
			cout << "Please enter your :" << endl;
			cout << "Name :";
			cin >> p[i].fullname;
			cout << "National ID :";
			while (true) { // validation on user choise
				long long flag1 = 1000000000000;
				if (!(cin >> p[i].nationalid) || p[i].nationalid < 0 || p[i].nationalid / flag1 < 1 || p[i].nationalid / flag1 > 10)
				{
					cin.clear();
					cin.ignore(123, '\n');
					cout << "Enter a valid number \n";
					cout << "National ID :";
				}
				else
				{
					break;
				}
			}
			cout << "Password :";
			cin >> p[i].password;
			cout << "Gender :" << endl << "type m for male or f for female" << endl;
			cin >> p[i].gender;
			cout << "Age :";
			cin >> p[i].age;
			cout << "your country ??" << endl << "1-egypt" << endl << "2-another country" << endl;
			int countryy;
			cin >> countryy;
			if (countryy == 1)
				p[i].country = "egypt";
			if (countryy == 2)
			{
				cout << "sorry you cant apply to vaccine....";
				break;
			}
			cout << "Please pick your governorate  " << endl;
			for (int k = 0; k < 27; k++)
			{
				cout << k + 1 << ":" << Gov[k] << "   ";
			}
			cout << endl;
			cout << "the number of your governorate is :  "; cin >> g;
			p[i].governorate = Gov[g];
			cout << "1-applying for vaccination" << endl;
			cout << "2-already vaccinated for one dose" << endl;
			cout << "3-already vaccinated for two doses" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "you are in waiting list......" << endl;
				p[i].waitinglist == true;
				waitinglist++;
				break;
			case 2:
				p[i].onedose == true;
				onedose++;
				cout << "we will send you a message in the date of the next dose" << endl;
				break;
			case 3:
				p[i].twodose == true;
				twodose++;
				cout << "you are vaccined so you don't need any dose , thank you" << endl;
				break;

			default:
				break;
			}


			people.Append(p[i]);


		}
		else
		{
			cout << "please choose 1 or 2 only" << endl;
		}
		char con;
		cout << "do you want to continue : " << endl;
		cin >> con;
		if (con == 'y')
		{
			continue;
		}
		if (con == 'n')
		{
			break;
		}
	}
}