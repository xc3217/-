#include<iostream>
using namespace std;
struct Polynode
{
	int coef;
	int exp;
	Polynode* next;
};
class Poly
{
	Polynode* head;
public:
	Poly()
	{
		Polynode* r ,* s ;
		head = new Polynode;
		r = head;
		int coef, exp;
		while (1)
		{
			cout << "请输入系数和指数：";
			cin >> coef >> exp;
			if (coef == 0 && exp == 0)
				break;
			s = new Polynode;
			s->coef = coef;
			s->exp = exp;
			r->next = s;
			r = s;
		}
		r->next = NULL;
		cout << endl;
	}
	void Polyadd(Poly LB)
	{
		float sum;
		Polynode* pa, * pb, * qa, * qb;
		pa = head;
		qa = pa->next;
		pb = LB.head;
		qb = pb->next;
		while (qa != NULL && qb != NULL)
		{
			if (qa->exp < qb->exp)
			{
				pa = qa; qa = qa->next;
			}
			else if (qa->exp > qb->exp)
			{
				pb->next = qb->next;
				pb->next = qa;
				pa->next = qb;
				pa = qb;
				pb = pb->next;
			}
			else {
				sum = qa->coef + qb->coef;
				if (sum == 0)
				{
					pa->next = qa->next;
					delete qa;
					qa = pa->next;
					pb->next = qb->next;
					delete qb;
					qb = pb->next;
				}
				else
				{
					qa->coef = sum;
					pa = qa; qa = qa->next;
					pb->next = qb->next;
					delete qb;
					qb = pb->next;
				}
			}
		}
		if (qb != NULL)
		{
			pa->next = qb;
		}
	}
	void Print()
	{
		Polynode* s, * t;
		t = head;
		s = t->next;
		cout << "多项式为：" << s->coef << "x^" << s->exp << ' ';
		s = s->next;
		while (s != NULL)
		{
			if (s->exp != 0)
			{
				if (s->coef > 0)
					cout << '+' << s->coef << "x^" << s->exp << ' ';
				else
					cout << s->coef << "x^" << s->exp << ' ';
			}
			else {
				if (s->coef > 0)
					cout << '+' << s->coef << ' ';
				else
					cout << s->coef;
			}
			s = s->next;
		}
		cout << endl;
	}
};
int main()
{
	Poly A;
	A.Print();
	Poly B;
	B.Print();
	A.Polyadd(B);
	A.Print();
	return 0;
}
