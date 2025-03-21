#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

struct Score {
    int tries;  
    bool used;  

    Score() : tries(0), used(false) {}
};

int main() {
    Score Sc[5];  
    int SC = 0;   

    srand(time(0));  

    while (true) {
        cout << "1. Play  2. Top Scores  3. Exit\n";
        int ch;  
        cin >> ch;
        cin.ignore();

        if (ch == 1) {
            int num = rand() % 100 + 1;  
            int guess;                   
            int t = 0;                   

            cout << "Guess 1-100 (-1 to quit):\n";
            while (true) {
                cin >> guess;
                t++;
                if (guess == -1) {
                    cout << "Quit! Num was " << num << ".\n";
                    break;
                }
                if (guess < 1 || guess > 100) {
                    cout << "1-100 only.\n";
                } else if (guess < num) {
                    cout << "Low! Try:\n";
                } else if (guess > num) {
                    cout << "High! Try:\n";
                } else {
                    cout << "Got it! " << t << " tries.\n";
                    if (SC < 5) {
                        Sc[SC].tries = t;
                        Sc[SC].used = true;
                        SC++;
                    } else {
                        int worst = 0;
                        for (int i = 1; i < 5; i++) {
                            if (Sc[i].tries > Sc[worst].tries) {
                                worst = i;
                            }
                        }
                        if (t < Sc[worst].tries) {
                            Sc[worst].tries = t;
                        }
                    }
                    break;
                }
            }
        } else if (ch == 2) {
            if (SC == 0) {
                cout << "No scores.\n";
            } else {
                cout << "Top Scores (least tries):\n";
                for (int i = 0; i < SC - 1; i++) {
                    for (int j = 0; j < SC - i - 1; j++) {
                        if (Sc[j].tries > Sc[j + 1].tries) {
                            int temp = Sc[j].tries; 
                            Sc[j].tries = Sc[j + 1].tries;
                            Sc[j + 1].tries = temp;
                        }
                    }
                }
                for (int i = 0; i < SC; i++) {
                    cout << i + 1 << ". " << Sc[i].tries << " tries\n";
                }
            }
        } else if (ch == 3) {
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}