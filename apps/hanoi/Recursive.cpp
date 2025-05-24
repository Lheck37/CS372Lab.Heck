#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int, int, int);

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num > 0) {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int disk, int fromPeg, int toPeg) {
    // Disabled to avoid console slow-down during timing
    // cout << "Move disk " << disk << " from peg " << fromPeg << " to peg " << toPeg << endl;
}

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;

    for (int numdisks : {5, 10, 15, 20, 25, 30, 35}) {
        cout << "Numdisks: " << numdisks << endl;

        auto start = chrono::high_resolution_clock::now();
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Time taken: " << elapsed.count() << " seconds" << endl;
        cout << "Moved " << numdisks << " disks from peg "
             << FROMPEG << " to peg " << TOPEG << "\n\n";
    }

    return 0;
}
