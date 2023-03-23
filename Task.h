#pragma once
#include <vector>
#include <string>
using namespace std;
class Task
{
private:
	int id;
	string descriere;
	vector<string>prog;
	string stare;

public:
	Task(int id,string descriere,vector<string>prog,string stare):id{id},descriere{descriere},prog{prog},stare{stare}{}
	//returneaza id
	int getID() {
		return id;
	}
	//returneaza descriere
	string getDescriere()
	{
		return descriere;
	}
	//returneaza programatori
	vector<string> getProg()
	{
		return prog;
	}
	//returneaza stare
	string getStare()
	{
		return stare;
	}
	//seteaza Stare
	void setStare(string st)
	{
		stare = st;
	}
};
