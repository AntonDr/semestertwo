#include "FileSystem.h"
#include "StringLibrary.h"

using namespace std;

int main()
{
	//char source[] = "wordl how are you World hello hello hello aaaaaa what hello";

	char fileName[30] = "text.txt";

	char * source{};

	source = InitArray(fileName);


	char  needdelete[] = "hello you how what";

	StrDel(source, needdelete);
	
	SortByAlphabet(source);

	AddFile(fileName, source);

	system("pause");

	return 0;
}