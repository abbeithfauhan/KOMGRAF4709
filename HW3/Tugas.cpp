#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float startX, endX, startY, endY;

void display(void) {
  float deltaY, deltaX, step, currentX, currentY, k, XIncrement, YIncrement;
  deltaX = endX - startX;
  deltaY = endY - startY;
  if (abs(deltaX) > abs(deltaY)) {
    step = abs(deltaX);
  } else {
    step = abs(deltaY);
  }
  XIncrement = deltaX / step;
  YIncrement = deltaY / step;
  currentX = startX;
  currentY = startY;
  glBegin(GL_POINTS);
  glVertex2i(currentX, currentY);
  glEnd();
  for (k = 1; k <= step; k++) {
    currentX = currentX + XIncrement;
    currentY = currentY + YIncrement;
    glBegin(GL_POINTS);
    glVertex2i(currentX, currentY);
    glEnd();
  }
  glFlush();
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char **argv) {
  printf("Enter the value of startX: ");
  scanf("%f", &startX);
  printf("Enter the value of startY: ");
  scanf("%f", &startY);
  printf("Enter the value of endX: ");
  scanf("%f", &endX);
  printf("Enter the value of endY: ");
  scanf("%f", &endY);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}
