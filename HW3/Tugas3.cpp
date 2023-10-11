#include <iostream>
#include <cmath>

using namespace std;

void drawDDALine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = x1, y = y1;

    cout << "Coordinates on the line:" << endl;

    for (int i = 0; i <= steps; i++) {
        cout << "(" << round(x) << ", " << round(y) << ")" << endl;
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the starting point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the ending point (x2 y2): ";
    cin >> x2 >> y2;

    drawDDALine(x1, y1, x2, y2);

    return 0;
}
