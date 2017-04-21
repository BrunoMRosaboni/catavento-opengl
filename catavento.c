/* Bruno Molina Rosaboni n°USP: 7656533
 * Werik Amaral Fachim n°USP: 7656512
 *
 * Para compilar:
 *		gcc -o catavento catavento.c -lGL -lglut -lm
 */
 
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;
int pos = 1;

int NumeroFrames = 0;

void ChamaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if(state == GLUT_DOWN)
		{
			pos = 1;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			pos = -1;
		}
	}
}

void catavento() {
	int i;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated((pos * (NumeroFrames * (180.0/70))), 0, 0, 1);
	glColor3f(0.2f, 0.7f, 0.2f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

/*
* Essa função é chamada quando a imagem precisa ser redesenhada,
* ela é chamada na main e desenha o "current frame" da animação*
*/
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslated(3.5,-0.7,1);
	glScaled(1.0,1.0,1);
	glutMouseFunc(ChamaMouse);
	catavento();
	glPopMatrix();

	glutSwapBuffers();

}

/*
* Altera os frames por segundo
*/
void doFrame(int v) {
    NumeroFrames++;
    glutPostRedisplay();
    glutTimerFunc(20,doFrame,0);
}

void init() {
	glClearColor(1.0f, 0.6f, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);  
    glutCreateWindow("Catavento");

    init();

    glutDisplayFunc(display);   
    glutTimerFunc(200,doFrame,0);
    

    glutMainLoop(); 
    return 0;
}    

