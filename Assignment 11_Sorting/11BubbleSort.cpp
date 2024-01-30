#include <iostream>
using namespace std;
class BubbleSort
{
    int a[20], i, n, j, temp;

public:
    void get()
    {
        cout << "ENTER THE NUMBER OF ELEMENTS IN THE ARRAY: " << endl;
        cin >> n;
        cout << "ENTER THE ARRAY ELEMENTS: " << endl;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

public:
    void display()
    {
        cout << "UNSORTED ARRAY ELEMENTS ARE: " << endl;
        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }

public:
    void sort()
    {
        cout << "\nSORTED ELEMENTS ARE: " << endl;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            cout << a[i]<<" ";
        }
    }
};
int main()
{
    BubbleSort b;
    b.get();
    b.display();
    b.sort();
}