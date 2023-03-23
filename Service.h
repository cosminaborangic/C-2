#pragma once
#include "Repo.h"
#include <QtWidgets/QWidget>
#include "qdebug.h"
class Observer {

public:
	virtual void update() = 0;

};

class Observable {
private:
	std::vector<Observer*>observers;
public:

	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs) {
		observers.erase(std::remove(begin(observers), end(observers), obs));
	}
protected:
	void notify()
	{

		for (auto obs : observers)
		{
			obs->update();
		}
	}
};
class Service:public Observable
{
private:
	Repo r;
public:
	Service(Repo r): r{r}{}
	//adaugare 
	void add(int id, string descriere, string prof1, string prof2, string prof3, string prof4, string stare)
	{
		if (descriere == "")
			throw exception();
		vector<string> l;
		if (prof1 != "")
			l.push_back(prof1);
		if (prof2 != "")
			l.push_back(prof2);
		if (prof3 != "")
			l.push_back(prof3);
		if (prof4 != "")
			l.push_back(prof4);
		if (l.size() == 0)
			throw exception();
		if (stare != "open" && stare != "inprogress" && stare != "closed")
			throw exception();
		Task a(id, descriere, l, stare);
		r.add(a);
		notify();
	}
	//modificare stare
	void update(int id, string stare)
	{
		if (stare != "open" && stare != "inprogress" && stare != "closed")
			throw exception();
		vector<string> a;
		Task b(id, "", a, stare);
		r.update(b);
		notify();
	}
	//filtrare
	vector<Task> filtrat(string profesor)
	{	
		vector<Task>a;
		vector<Task>b = getAll();
		for (auto j : b) {
			vector<string>c = j.getProg();
			for (auto d : c) {
				if (profesor.find(d)!=string::npos)
				{	
					a.push_back(j);
					break;
				}
			}
		}
		return a;
	}
	//returneaza tot
	vector<Task> getAll()
	{
		vector<Task> f= r.getAll();
		sort(f.begin(), f.end(), [&](Task a, Task b) {return a.getStare() < b.getStare(); });
		return f;
	}
	vector<Task> filtrats(string stare)
	{
		vector<Task>a;
		vector<Task>b = getAll();
		for (auto j : b) {
			if(j.getStare()==stare)
					a.push_back(j);
		}
		return a;
	}
};

