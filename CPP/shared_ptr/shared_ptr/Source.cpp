#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class A 
{
private:
	string m_str;
	weak_ptr<A> m_other;

public:
	A(const string& str) : m_str(str) {
		cout << "call copy constructor" << endl;
	}

	~A() {
		cout << "call destructor" << endl;
	}

	void set_other(weak_ptr<A> other) {
		m_other = other;
	}

	void access_other() {
		shared_ptr<A> access = m_other.lock();

		if (access) {
			cout << "access!" << endl;
		}
		else {
			cout << "failed!" << endl;
		}
	}

	string name() {
		return m_str;
	}

};

int main()
{
	vector<shared_ptr<A>> vec;
	vec.push_back(make_shared<A>("resource 1"));
	vec.push_back(make_shared<A>("resource 2"));

	vec[0]->set_other(vec[1]);
	vec[1]->set_other(vec[0]);

	cout << "vec[0] ref count : " << vec[0].use_count() << endl;
	cout << "vec[1] ref count : " << vec[1].use_count() << endl;

	vec[0]->access_other();
	
	vec.pop_back();

	vec[0]->access_other();

	return 0;
}