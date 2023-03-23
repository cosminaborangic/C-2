#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include "qdebug.h"
class Repo
{
private:
	vector<Task>v;
	string fName;
	//adaugare din fisier
	void loadFromFile() {
		ifstream fin(fName);
		int id,nr,i;
		string descriere;
		vector<string> prog;
		string stare;
		string proge;
		while (fin >> id)
		{
			prog.clear();
			fin >> descriere;
			fin >> nr;
			for (i = 0; i < nr; i++)
			{
				fin >> proge;
				prog.push_back(proge);
			}
			fin >> stare;
			Task a(id, descriere, prog, stare);
			v.push_back(a);
		}
		fin.close();
	}
	//adaugare in fisier
	void writeToFile()
	{
		ofstream fout(fName);
		for (auto i : v)
		{
			fout << i.getID() << '\n' << i.getDescriere() << '\n';
			vector<string> a = i.getProg();
			fout << a.size() << '\n';
			for (auto j: a)
			{
				fout << j << '\n';
			}
			fout << i.getStare() << '\n';
		}
		fout.close();
	}

public:
	Repo(string fName) :fName(fName) {
		loadFromFile();
	}
	//adaugare 
	void add(Task a)
	{	
		for (auto j : v)
		{
			if (j.getID() == a.getID())
				throw exception();
		}
		v.push_back(a);
		writeToFile();
	}
	//modificare
	void update(Task a)
	{
		for (auto& j : v)
		{
			if (j.getID() == a.getID())
			{	

				j.setStare(a.getStare());
				return;
			}
		}

	}
	//returneaza elementele
	vector<Task> getAll()
	{
		return v;
	}
};
