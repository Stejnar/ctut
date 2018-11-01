#include <iostream>

#include "../list.h"

using namespace std;

const int two = 2;

string displayNumber(int value, int index)
{
    return to_string(value);
};

bool findNumberTwo(int value, int index)
{
    return two == value;
};

class TestConsumer : public Observer<int>
{
  public:
    TestConsumer(){};
    ~TestConsumer(){};
    void next(int value, int index)
    {
        cout << "next: " << value << endl;
    };
};

int main()
{

    List<int> list(0);

    list.append(1);
    list.append(two);
    list.append(3);
    list.prepend(-1);

    cout << "shift: " << *list.shift() << endl;
    cout << "pop: " << *list.pop() << endl;

    list.display(displayNumber);

    TestConsumer consumer;

    list.forEach(&consumer);

    int res;
    if (list.find(&res, findNumberTwo))
    {
        cout << "res: " << res << endl;
    }

    return 0;
}