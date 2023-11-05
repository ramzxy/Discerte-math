#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    srand(time(0));

    unordered_map<bool, string> myanswer{ {true, "yes"}, {false, "no"} };
    char L[] = { 'b', 's', 'b' };
    char Location[] = { 'L', 'M', 'R' };
    unordered_map<char, char> Place;
    set<int> index1, index2;

    while (index1.size() < 3 && index2.size() < 3) {
        int temp1 = rand() % 3;
        int temp2 = rand() % 3;
        if (index1.find(temp1) == index1.end() && index2.find(temp2) == index2.end()) {
            index1.insert(temp1);
            index2.insert(temp2);
            Place[Location[temp2]] = L[temp1];
        }
    }

    char pl;
    cout << "Which room you pointed (L/M/R)? ";
    cin >> pl;

    cout << "Your question:" << endl;
    char p;
    cout << "Which one (b:brother / s:sister)? ";
    cin >> p;

    char loc;
    cout << "In which place (L/M/R)? ";
    cin >> loc;

    if (Place[pl] == 'b') {
        cout << "Your question: Is " << p << " in " << loc << "?" << endl;
        cout << "My answer: " << myanswer[Place[loc] == p] << endl;
    }
    else {
        cout << "My answer: " << myanswer[rand() % 2] << endl;
    }

    cout << "Now you must say! Which room any of your brothers is in? ";
    char brother_room;
    cin >> brother_room;

    if (Place[brother_room] == 'b') {
        cout << "Your answer is correct!" << endl;
    }
    else {
        cout << "Your answer is incorrect." << endl;
    }

    cout << "Initial placement:" << endl;
    for (char room : {'L', 'M', 'R'}) {
        cout << room << ": " << Place[room] << endl;
    }

    return 0;
}
