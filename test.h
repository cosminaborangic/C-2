
#include "Task.h"
#include <assert.h>
#include "Service.h"

void test_dom()
{	
	vector<string>a = { "a","b" };
	Task b(1, "a", a, "a");
	assert(b.getID() == 1);
	assert(b.getDescriere() == "a");
	assert(b.getProg() == a);
	assert(b.getStare() == "a");
}

void test_repo()
{


}

void test_serv()
{
	Repo r{ "test.txt" };
	Service s{ r };
	vector<Task> a = s.getAll();
	assert(a.size() == 1);
	s.add(2, "a", "a", "", "", "", "open");
	a = s.getAll();
	assert(a.size() == 2);
	a=s.filtrat("a");
	assert(a.size() == 2);
	s.update(2,"open");
	ofstream fout("test.txt");
	fout<<1<<'\n'<<"a"<<'\n'<<1<<'\n'<<"a" << '\n' << "a" << '\n';
	fout.close();
}
void test_all()
{
	test_dom();
	test_repo();
	test_serv();
}