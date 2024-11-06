#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread> // For sleep
#include <chrono> // For time durations

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
bool gameover;
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100];
int tail_len;

void setup();
void draw();
void input();
void logic();

int main() {
    char start;
    cout << "\t-------------------------------------------" << endl;
    cout << "\t\t\t : Snake King :" << endl;
    cout << "\t-------------------------------------------" << endl;
    cout << "\tPress 's' to Start : ";
    cin >> start;

    if (start == 's') {
        setup();
        while (!gameover) {
            draw();
            input();
            logic();
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust speed
        }
    }
    return 0;
}

void setup() {
    gameover = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tail_len = 0;
}

void draw() {
    system("clear"); // Use "cls" on Windows
    cout << "\t\t";
    for (int i = 0; i < width; i++) cout << "##";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "\t\t##";
            if (i == headY && j == headX) cout << 'O';
            else if (i == fruitY && j == fruitX) cout << '*';
            else {
                bool print = false;
                for (int k = 0; k < tail_len; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << 'o';
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }
            if (j == width - 1) cout << "##";
        }
        cout << endl;
    }

    cout << "\t\t";
    for (int i = 0; i < width; i++) cout << "##";
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}

void input() {
    char input;
    cout << "Enter direction (w=up, s=down, a=left, d=right, x=exit): ";
    cin >> input;
    switch (input) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
    }
}

void logic() {
    int prevX = tailx[0];
    int prevY = taily[0];
    int prev2X, prev2Y;
    tailx[0] = headX;
    taily[0] = headY;

    for (int i = 1; i < tail_len; i++) {
        prev2X = tailx[i];
        prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
    }

    if (headX >= width) headX = 0; else if (headX < 0) headX = width - 1;
    if (headY >= height) headY = 0; else if (headY < 0) headY = height - 1;

    for (int i = 0; i < tail_len; i++) {
        if (tailx[i] == headX && taily[i] == headY) gameover = true;
    }

    if (headX == fruitX && headY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail_len++;
    }
}
