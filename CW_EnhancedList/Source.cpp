#include "List.h"
//#include "List.cpp"
#include"EnhancedList.h"

int main()
{
	EnhancedList<int> L;
	L.push_back(5);
	L.push_back(12);
	L.push_back(112);
	L.push_back(5);

	for (int i = 0; i < L.size();i++)
		cout << L[i] << endl;


	cout << endl;
	cout << L[2] << endl;
	system("pause");
	return 0;
}