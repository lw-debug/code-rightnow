#include "test_array.h"
using namespace std;
using std::cin;
using std::cout;
using std::endl;
// using std::string;
int main() {
	srand((unsigned)time(0));
	long num, value;
	cout << "please choose your select :";
	cin >> num;
	if (num != 1) {
	   cout << "How many elements :";
	   cin >> value;
	}
	if (num == 1)
		jj01::test_array();
	else if (num == 2)
		jj02::test_vector(value);
	else if (num == 3)
		jj03::test_list(value);
	else if (num == 4)
		jj04::test_forward_list(value);
	else if (num == 5)
		jj05::test_deque(value);
	else if (num == 6)
		jj06::test_multiset(value);
	else if (num == 7)
		jj07::test_multimap(value);
	else if (num == 8)
		jj08::test_unordered_multiset(value);
	return 0;
}
