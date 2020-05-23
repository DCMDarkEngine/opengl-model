#include <GL/glut.h>

void init(void)
{
	glClearColor(0.3, 0.3, 0.3, 1.0);

	static float light0_ambient[] =
	{ 0.1, 0.1, 0.1, 1.0 };
	static float light0_diffuse[] =
	{ 1.0, 1.0, 1.0, 0.0 };
	static float light0_position[] =
	{ 3.0, 1.0, 5.0, 0.0 };
	static float light0_specular[] =
	{ 0.0, 0.0, 0.0, 0.0 };

	static float lmodel_ambient[] =
	{ 0.0, 0.0, 0.0, 0.0 };
	static float lmodel_twoside[] =
	{ GL_FALSE };
	static float lmodel_local[] =
	{ GL_FALSE };

	static float bevel_mat_ambient[] =
	{ 0.0, 0.0, 0.0, 1.0 };
	static float bevel_mat_shininess[] =
	{ 40.0 };
	static float bevel_mat_specular[] =
	{ 0.0, 0.0, 0.0, 0.0 };
	static float bevel_mat_diffuse[] =
	{ 1.0, 0.0, 0.0, 0.0 };

	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glEnable(GL_LIGHT0);

	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_local);
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glEnable(GL_LIGHTING);

	glMaterialfv(GL_FRONT, GL_AMBIENT, bevel_mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, bevel_mat_shininess);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bevel_mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bevel_mat_diffuse);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(45.0, 0.0, 1.0, 0.0);
	glRotatef(20.0, 1.0, 0.0, 1.0);

	// Вид сверху
	/*glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);*/

	// Основа
	glPushMatrix();
	glColor3f(0.0, 0.1, 0.0);
	glScalef(2.0, 0.3, 1.0);
	glutSolidCube(2.0);
	glPopMatrix();

	// Кабина
	glPushMatrix();
	glColor3f(0.0, 0.1, 0.0);
	glScalef(0.8, 0.7, 0.8);
	glTranslatef(1.5, 1, 0);
	glutSolidCube(2.0);
	glPopMatrix();

	// Крыша
	glPushMatrix();
	glColor3f(0.0, 0.1, 0.0);
	glTranslatef(1.25, 1.4, 0);
	glScalef(0.9, 0.1, 0.9);
	glutSolidCube(2.0);
	glPopMatrix();

	// Окно
	glPushMatrix();
	glTranslatef(1.2, 0.9, 0.8);
	glColor3f(0.0, 0.0, 0.9);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.05, 0.4);
	glutSolidCube(2.0);
	glPopMatrix();

	// Колеса
	{
		glPushMatrix();
		glColor3f(0.5, 0.0, 0.0);
		glTranslatef(1, 0, 1.24);
		glutSolidTorus(0.25, 0.35, 10, 30);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.0, 0.0);
		glTranslatef(1, 0, -1.24);
		glutSolidTorus(0.25, 0.35, 10, 30);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.0, 0.0);
		glTranslatef(-1.25, -0.1, 1.19);
		glutSolidTorus(0.21, 0.31, 10, 30);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.0, 0.0);
		glTranslatef(-1.25, -0.1, -1.19);
		glutSolidTorus(0.21, 0.31, 10, 30);
		glPopMatrix();
	};

	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();

	// Корпус
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.75, -2.0);
	gluCylinder(quadratic, 0.45, 0.45, 3.0, 32, 32);
	glPopMatrix();

	// Большая труба
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(-1.4, 0.75, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.25, 0.25, 1.0, 32, 32);
	glPopMatrix();

	// Затычка большой трубы
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(0.6, 0.0, 0.0);
	glTranslatef(0, 0.75, -1.9);
	glutSolidTorus(0.22, 0.22, 10, 30);
	glPopMatrix();

	// Труба поменьше
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(-0.4, 0.6, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.16, 0.16, 1.0, 32, 32);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w,
			2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.5 * (GLfloat)w / (GLfloat)h,
			2.5 * (GLfloat)w / (GLfloat)h, -2.5, 2.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}