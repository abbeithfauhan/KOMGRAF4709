#include <GL/glut.h>
#include <cmath>

int x1 = 3, y = 3;
int x2 = 9, y2 = 7;

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int twody = 2 * dy;
    int twodx = 2 * dx;
    int p;

    if (dx >= dy) {
        int slope = (y2 > y1) ? 1 : -1;
        int x, y, xe;

        if (x1 > x2) {
            x = x2;
            y = y2;
            xe = x1;
        } else {
            x = x1;
            y = y1;
            xe = x2;
        }

        setPixel(x, y);
        p = twody - dx;

        while (x < xe) {
            x++;
            if (p < 0)
                p += twody;
            else {
                y += slope;
                p += twody - twodx;
            }
            setPixel(x, y);
        }
    } else {
        int slope = (x2 > x1) ? 1 : -1;
        int x, y, ye;

        if (y1 > y2) {
            x = x2;
            y = y2;
            ye = y1;
        } else {
            x = x1;
            y = y1;
            ye = y2;
        }

        setPixel(x, y);
        p = twodx - dy;

        while (y < ye) {
            y++;
            if (p < 0)
                p += twodx;
            else {
                x += slope;
                p += twodx - twody;
            }
            setPixel(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set line color to white

    void bresenhamLine(int x1, int y1, int x2, int y2);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
