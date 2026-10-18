#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // For random numbers in Math Game
    int choice;
    bool detectivePlayed = false;
    bool mathPlayed = false;

    cout << "========================================\n";
    cout << "    Welcome to Interactive Dual Adventure System\n";
    cout << "========================================\n\n";

    // Loop until both games are played
    while (!detectivePlayed || !mathPlayed) {
        // Ask user to choose game
        while (true) {
            cout << "Please choose a game to play:\n";
            if (!detectivePlayed) cout << "1. Detective Game\n";
            if (!mathPlayed) cout << "2. Math Game\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if ((choice == 1 && !detectivePlayed) || (choice == 2 && !mathPlayed)) {
                break;
            } else {
                cout << "\nInvalid choice or game already played! Please try again.\n\n";
            }
        }

        // ===========================
        // DETECTIVE GAME
        // ===========================
        if (choice == 1) {
            detectivePlayed = true;
            char playAgain;
            do {
                int lives = 3;
                int subChoice;

                cout << "\nYou selected Detective Game. Let the adventure begin!\n";
                cout << "Welcome Detective Ali!\n";
                cout << "A dead body has been reported in an apartment. Let us take you to the location...\n";
                cout << "A broken window gleams in the morning light, a battered suitcase rests on the floor, "
                     << "the dead body is lying on the ground.\n\n";

                // FIRST QUESTION
                while (true) {
                    cout << "What do you do first?\n";
                    cout << "1. Search the suitcase meticulously\n";
                    cout << "2. Check CCTV footage of the building\n";
                    cout << "3. Search the room for clues\n\n";

                    cin >> subChoice;
                    if (subChoice == 1) {
                        cout << "\nGood choice!\n\n";
                        break;
                    } else {
                        lives--;
                        cout << "Wrong move. Lives left: " << lives << "\n\n";
                        if (lives == 0) goto detective_end;
                    }
                }

                // SECOND QUESTION
                while (true) {
                    cout << "Evidence collected from suitcase:\n";
                    cout << "A USB device, a passport, a diary, some books and men's clothes.\n\n";
                    cout << "What's your next move?\n";
                    cout << "1. Send USB and passport to headquarters\n";
                    cout << "2. Try putting on those clothes\n";
                    cout << "3. Read books\n";

                    cin >> subChoice;
                    if (subChoice == 1) {
                        cout << "\nInformation received.\n\n";
                        break;
                    } else {
                        lives--;
                        cout << "Bad decision. Lives left: " << lives << "\n\n";
                        if (lives == 0) goto detective_end;
                    }
                }

                // THIRD QUESTION
                while (true) {
                    cout << "1. Ask manager to read it aloud\n";
                    cout << "2. Leave it for now\n";
                    cout << "3. Read the information silently\n";

                    cin >> subChoice;
                    if (subChoice == 3) {
                        cout << "\nThe passport is fake. The victim is actually a wanted serial killer.\n\n";
                        break;
                    } else {
                        lives--;
                        cout << "Wrong decision. Lives left: " << lives << "\n\n";
                        if (lives == 0) goto detective_end;
                    }
                }

                // FOURTH QUESTION
                while (true) {
                    cout << "Your next move?\n";
                    cout << "1. Ask manager to order lunch\n";
                    cout << "2. Search the body for weapons & send for forensics\n";
                    cout << "3. Relax on the bed\n";

                    cin >> subChoice;
                    if (subChoice == 2) {
                        cout << "\nNo weapons found.\n\n";
                        break;
                    } else {
                        lives--;
                        cout << "Wrong decision. Lives left: " << lives << "\n\n";
                        if (lives == 0) goto detective_end;
                    }
                }

                // FIFTH QUESTION
                while (true) {
                    cout << "Your next move?\n";
                    cout << "1. Bury the body right away\n";
                    cout << "2. Close the case\n";
                    cout << "3. Send body to forensic & search room for clues\n";

                    cin >> subChoice;
                    if (subChoice == 3) {
                        cout << "\nFingerprints found.\n";
                        cout << "Matched with a man named Basharat.\n";
                        cout << "He killed Taha out of revenge.\n\n";
                        cout << "CASE CLOSED!\n";
                        cout << "Great job Detective Ali! You win!\n";
                        break;
                    } else {
                        lives--;
                        cout << "Wrong decision. Lives left: " << lives << "\n\n";
                        if (lives == 0) goto detective_end;
                    }
                }

            detective_end:
                if (lives == 0) cout << "You lost the game.\n";

                cout << "\nDo you want to replay Detective Game? (Y/N): ";
                cin >> playAgain;

            } while (playAgain == 'Y' || playAgain == 'y');
        }

        // ===========================
        // MATH GAME
        // ===========================
        else if (choice == 2) {
            mathPlayed = true;
            int score = 0, answer;

            cout << "\nYou selected Math Game. Time to test your skills!\n\n";

            // Problem 1
            int apples = 5;
            int moreApples = rand() % 5 + 1;
            cout << "1) Anna has " << apples << " apples. She buys " << moreApples << " more apples.\n";
            cout << "   How many apples does she have now? ";
            cin >> answer;
            if (answer == apples + moreApples) { cout << "Correct!\n\n"; score++; }
            else { cout << "Wrong! Correct answer: " << apples + moreApples << "\n\n"; }

            // Problem 2
            int rows = 4;
            int pencils = rand() % 5 + 2;
            cout << "2) A box has " << rows << " rows of pencils with " << pencils << " pencils in each row.\n";
            cout << "   How many pencils are there in total? ";
            cin >> answer;
            if (answer == rows * pencils) { cout << "Correct!\n\n"; score++; }
            else { cout << "Wrong! Correct answer: " << rows * pencils << "\n\n"; }

            // Problem 3
            int candies = 15;
            int eaten = rand() % 5 + 1;
            cout << "3) There are " << candies << " candies. If you eat " << eaten << " of them,\n";
            cout << "   how many candies are left? ";
            cin >> answer;
            if (answer == candies - eaten) { cout << "Correct!\n\n"; score++; }
            else { cout << "Wrong! Correct answer: " << candies - eaten << "\n\n"; }

            // Problem 4
            int friends = 3;
            int cookies = (rand() % 5 + 2) * friends;
            cout << "4) Ali has " << cookies << " cookies. He shares them equally among " << friends << " friends.\n";
            cout << "   How many cookies does each friend get? ";
            cin >> answer;
            if (answer == cookies / friends) { cout << "Correct!\n\n"; score++; }
            else { cout << "Wrong! Correct answer: " << cookies / friends << "\n\n"; }

            // Problem 5
            int cost = 6;
            int toys = rand() % 4 + 2;
            cout << "5) One toy costs " << cost << " rupees.\n";
            cout << "   How much do " << toys << " toys cost? ";
            cin >> answer;
            if (answer == cost * toys) { cout << "Correct!\n\n"; score++; }
            else { cout << "Wrong! Correct answer: " << cost * toys << "\n\n"; }

            cout << "Game Over!\n";
            cout << "Your score: " << score << " out of 5\n";
        }

        cout << "\n";
    }

    cout << "Thanks for playing! All games completed.\n";
    return 0;
}
