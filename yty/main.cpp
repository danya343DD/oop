#include "MathTemplates.h"
#include "ArrayTemplate.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Meeting 11: Function Templates" << endl;

    int intArr[] = { 1, 2, 3, 4, 5 };
    cout << getAverage(intArr, 5) << endl;

    findRoots(2.0, -4.0);
    findRoots(1.0, -5.0, 6.0);
    findRoots(1.0, 2.0, 1.0);
    findRoots(1.0, 0.0, 4.0);

    cout << getMax(10, 20) << endl;
    cout << getMin(10.5, 5.2) << endl;

    cout << "\nMeeting 12: Class Templates" << endl;

    Array<int> arr;
    arr.SetSize(3, 2);

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);

    for (int i = 0; i <= arr.GetUpperBound(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.InsertAt(1, 15);
    for (int i = 0; i <= arr.GetUpperBound(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAt(2);
    for (int i = 0; i <= arr.GetUpperBound(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Array<int> arr2;
    arr2.Add(100);
    arr2.Add(200);

    arr.Append(arr2);
    for (int i = 0; i <= arr.GetUpperBound(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.FreeExtra();
    cout << arr.GetSize() << endl;

    arr.RemoveAll();
    cout << arr.IsEmpty() << endl;

    return 0;
}