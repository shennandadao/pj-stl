#include<iostream>
#include"list.h"
#include"vector.h"
#include"deque.h"
#include"stack.h"
#include"queue.h"
#include"tree.h"
#include"set.h"
#include"map.h"
#include"string.h"
#include"bitset.h"
#include<functional>
using namespace std;

void main()
{
	bitset<10> bt;
	bt.set(3);
	cout<<bt<<endl;
	cout<<bt.at(3)<<endl;
	cout<<bt[3]<<endl;

	bt[2] = 1;
	cout<<bt<<endl;
	//bt[2].flip();
	~bt[2];
	cout<<bt<<endl;
}


/*
void main()
{
	mystring s("Hello");
	mystring s1 = s;
	//mystring s2 = s1;
	s1[0] = 'h'; //255

	mystring s2 = s1;

}

/*
void main()
{
	//mybasic_string<char, char_traits<char>,	allocator<char> > s;
	mystring s("Hello");
	cout<<"length:"<<s.length()<<endl;
	cout<<"size :"<<s.size()<<endl;
	cout<<"capacity:"<<s.capacity()<<endl;

	mystring s1 = s;
	//s1[0] = 'h';
}


/*
void main()
{
	map<int, int> mp;
	multimap<int, int> mup;
}

/*
template<class _Ty>
class KeyOfValue
{
public:
	const _Ty& operator()(const _Ty &_X)const
	{return _X;}
};

void main()
{
	int ar[] = {10, 10, 10, 7, 8, 15, 5, 6, 11, 13, 12};
	int n = sizeof(ar) / sizeof(int);
	//_Tree<int, int, KeyOfValue<int>, less<int>, allocator<int> > tr(less<int>(),true);
	_Tree<int, int, KeyOfValue<int>, less<int>, allocator<int> > tr(less<int>(), false);
	for(int i=0; i<n; ++i)
		tr.insert(ar[i]); //

	_Tree<int, int, KeyOfValue<int>, less<int>, allocator<int> >::iterator it = tr.begin();
	it++;
	it++;
	it++;
	it++;
	it++;

	cout<<*it<<endl;
	tr.erase(it);

	while(it != tr.end())
	{
		cout<<*it<<" ";
		++it; //it++
	}
	cout<<endl;
	return;
}

/*
void main()
{
	stack<int, vector<int> > st;
	st.push(1);
	st.pop();

	queue<int, list<int> > q;
	q.push(1);
	q.pop();

	queue<int, vector<int> >Q;
	Q.push(1);
	Q.pop();
}

/*
void main()
{
	deque<int> de;
	de.push_back(1);
	de.push_back(2);
	de.push_back(3);
	de.push_back(10);
	de.push_back(20);
	de.push_back(30);
	de.push_back(40);
	de.push_back(50);
	de.push_back(60);
	de.push_back(70);
	de.push_back(80);
	de.push_back(90);
	de.push_back(11);
	de.push_back(12);

	de.push_front(4);
	de.push_front(5);
	de.push_front(6);
	de.push_front(7);
	de.push_front(8);

	

	deque<int>::iterator it = de.begin();
	de.insert(it+3, 13);

	//cout<<it[2]<<endl;
	//it += 5;
	//cout<<*it<<endl;
	while(it != de.end())
	{
		cout<<*it<<" "; //it->
		++it; //it++  --it it--
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> v;
	for(int i=1; i<=10; ++i)
		v.push_back(i);
	//v.resize(5);
	cout<<v.size()<<endl;

	for(i=0; i<v.size(); ++i)
		//cout<<v.at(i)<<" ";
		cout<<v[i]<<" ";
	cout<<endl;

	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(20);
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
void main()
{
	vector<int> v;
	for(int i=1; i<=10; ++i)
		v.push_back(i);
	cout<<"capacity = "<<v.capacity()<<endl;

	//v.pop_back();
	v.clear();

	for(i=0; i<v.size(); ++i)
		//cout<<v.at(i)<<" ";
		cout<<v[i]<<" ";
	cout<<endl;

	cout<<"front = "<<v.front()<<endl;
	cout<<"back = "<<v.back()<<endl;

}
	/*
	vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,2,2,2,2,2,2,4,2,5};
	int br[5] = {6,7,8,9,10};

	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar+n);
	list<int> youlist(br, br+5);

	//mylist.splice(mylist.end(), youlist);
	//mylist.remove(2);
	//mylist.unique();
	mylist.reverse();

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
class String
{
public:
	String(const char *str ="")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	~String()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char *m_data;
};

void main()
{
	list<String> mylist;
	String s("abc");

	mylist.insert(mylist.begin(), s);
	mylist.erase(mylist.begin());
}

/*
void main()
{
	list<int> mylist;
	mylist.insert(mylist.begin(), 1);
}

/*
class String
{
public:
	String(const char *str ="")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	~String()
	{
		delete []m_data;
		m_data = NULL;
	}
private:
	char *m_data;
};

void main()
{
	list<String> mylist;
	String s("abc");

	mylist.insert(mylist.begin(), s);
}
/*
void main()
{
	int ar[5] = {1,2,3,4,5};
	list<int> mylist;
	//list<int> youlist(10, 1);

	//mylist.insert(mylist.end(), 10, 2);
	//mylist.insert(mylist.end(), ar, ar+5);
	for(int i=0; i<5; ++i)
		mylist.push_front(ar[i]);

	//mylist.pop_front();
	mylist.clear();

	//mylist.erase(mylist.begin());
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<" ";
		it++; //it++
	}
	cout<<endl;

	//cout<<mylist.front()<<endl;
	//cout<<mylist.back()<<endl;
}
*/
