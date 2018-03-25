
#include "StringLibrary.h"

using namespace std;

int main()
{
	char source[] = "wordl how are you World hello hello hello aaaaaa what hello";

	char  needdelete[] = "hello you how what";

	StrDel(source, needdelete);
	
	SortByAlphabet(source);

	cout << source;

	system("pause");

	return 0;
}