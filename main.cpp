// lab6 - task 1 //

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
void insertSort(T arr[], int size) {
    T x;
    int i, j;

    for (i = 0; i < size; i++) // pass cycle, i - pass number
    {
        x = arr[i];

        // finding the place of an element in a given sequence
        for (j = i - 1; j >= 0 && arr[j] > x; j--)
            arr[j + 1] = arr[j]; // shift the element to the right until we reach

    // place found, insert element
        arr[j + 1] = x;
    }
}

int main()
{
    srand(time(NULL));

    int size;

    cout << "Enter the size of the array >> ";
    cin >> size;
    cout << "\n";

    int* array = new int[size];

    // before sort
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
        cout << array[i] << "\t";
    }
    cout << "\n\n";
    insertSort(array, size);

    // after sorted
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    cout << "\n\n";

    delete[] array;

    return 0;
}

// lab6 - task 2 //

#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
template<class T>
class MyArr
{
    T* arr;
    int len;
public:
    MyArr()
    {
        len = 1;
        arr = nullptr;
    }
    MyArr(int size)
    {
        len = size;
        arr = new T[len];
    }
    ~MyArr()
    {
        if (arr != nullptr)
        {
            delete[] arr;
        }
    }

    void setArr()
    {
        if (typeid(arr[0]) == typeid(int))
        {
            cout << "int\n";
            for (int i = 0; i < len; i++)
            {
                arr[i] = rand() % 100;
            }
        }
        if (typeid(arr[0]) == typeid(float))
        {
            cout << "float\n";
            for (int i = 0; i < len; i++)
            {
                arr[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100));
            }
        }
        if (typeid(arr[0]) == typeid(long))
        {
            cout << "long\n";
            for (int i = 0; i < len; i++)
            {
                arr[i] = static_cast <long> (rand()) / (static_cast <long> (RAND_MAX / 100));
            }
        }

    }
    void printArr()
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    T const operator [](int i)
    {
        return arr[i];
    }
};

int main()
{
    MyArr <int> a(10);
    a.setArr();
    a.printArr();
    MyArr <float> a(10);
    a.setArr();
    a.printArr();
    MyArr <long> a(10);
    a.setArr();
    a.printArr();

    return 0;
}