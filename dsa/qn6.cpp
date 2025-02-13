//Program-4: Program to implement Tower of Hanoi (TOH).
#include <iostream>
using namespace std;

void THanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move Disk 1 from " << from << " to " << to << endl;
        return;
    }
    THanoi(n - 1, from, aux, to);
    cout << "Move Disk " << n << " from " << from << " to " << to << endl;
    THanoi(n - 1, aux, to, from);
}

int main() {
    int no_of_discs;
    cout << "Enter number of discs: ";
    cin >> no_of_discs;
    cout << endl;
    THanoi(no_of_discs, 'A', 'C', 'B');
    return 0;
}
