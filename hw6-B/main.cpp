#include <iostream>
#include <vector>
#include "Student.h"
#include "select.h"
using namespace std;

int main() {
	int n, tmp;
	cin >> n;
    vector<int> credit;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        credit.push_back(tmp);
    }
    int m;
    cin >> m;
	for (int i = 0; i < m; ++ i) {
		char type;
		vector<int> interest;
        int l, r;
        cin >> type >> l >> r;

		Student* student;

		if (type == 'A')
            student = new StudentTypeA();
        else if (type == 'B')
            student = new StudentTypeB();
        else if (type == 'C')
            student = new StudentTypeC();
		else {
			cout << "Student type error." << endl;
			exit(1);
		}

		vector<int> result = select(credit, l, r, student);
        for (vector<int>::iterator it = result.begin(); it < result.end(); ++ it){
            if (it != result.begin())
                cout << ' ';
            cout << *it;
        }
		cout << endl;
	}

	return 0;
}