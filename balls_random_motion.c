#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<GL/glu.h>
#include<stdlib.h>

void init();
void display();

int LEFT=-10,RIGHT=10,TOP=10,BOTTOM=-10,NEAR=10,FAR=-10;
float RADIUS=1.5;

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
   glutInitWindowSize(800,720);
   glutInitWindowPosition(10,10);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Programming Techniques - 3D Spheres"); 
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 1;
}

void init(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,10,-10);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glutSwapBuffers();
}



const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

float x1=7,x2=-10,x3=10,y11=-10,y2=3,y3=-5;
int flag1x=1,flag1y=1,flag2x=1,flag2y=1,flag3x=1,flag3y=1;
float speedx1=0.1,speedy1=0.1,speedx2=0.1,speedy2=0.1,speedx3=0.1,speedy3=0.1;

void display(){
while(1){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,1);


	 glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 


	if((x1-x2)<=1.25*RADIUS & (x1-x2)>=-1.25*RADIUS & (y11-y2)<=1.25*RADIUS & (y11-y2)>=-1.25*RADIUS){			//collision between ball1 and ball2
		printf("yolo");
		flag1x=flag1x*(-1);
		flag1y=flag1y*(-1);
		flag2x=flag2x*(-1);
		flag2y=flag2y*(-1);
	}

	if((x3-x2)<=1.25*RADIUS & (x3-x2)>=-1.25*RADIUS & (y3-y2)<=1.25*RADIUS & (y3-y2)>=-1.25*RADIUS){			//collision between ball2 and ball3
		printf("yolo");
		flag3x=flag3x*(-1);
		flag3y=flag3y*(-1);
		flag2x=flag2x*(-1);
		flag2y=flag2y*(-1);
	}

	if((x1-x3)<=1.25*RADIUS & (x1-x3)>=-1.25*RADIUS & (y11-y3)<=1.25*RADIUS & (y11-y3)>=-1.25*RADIUS){			//collision between ball1 and ball3
		printf("yolo");
		flag1x=flag1x*(-1);
		flag1y=flag1y*(-1);
		flag3x=flag3x*(-1);
		flag3y=flag3y*(-1);
	}

	if((x1-RIGHT)<=RADIUS & (x1-RIGHT)>=-RADIUS){			//boundary conditon for ball1
		flag1x=-1;
		speedx1=(rand()%10)/(float)(100);
	}
	if((x1-LEFT)<=RADIUS & (x1-LEFT)>=-RADIUS){
		flag1x=1;
		speedx1=(rand()%10)/(float)(100);
	}

	if((y11-TOP)<=RADIUS & (y11-TOP)>=-RADIUS){			//boundary conditon for ball1
		flag1y=-1;
		speedy1=(rand()%10)/(float)(100);
	}
	if((y11-BOTTOM)<=RADIUS & (y11-BOTTOM)>=-RADIUS){
		flag1y=1;
		speedy1=(rand()%10)/(float)(100);
	}


	x1=x1+speedx1*flag1x;
	y11=y11+speedy1*flag1y;
	glPushMatrix();										//ball1
	glLoadIdentity();
	glColor3f(1,0,0);
	glTranslatef(x1,y11,0);
	glRotatef(100,1,1,0);
	glutSolidSphere(RADIUS,100,100);
	glPopMatrix();	

		
	if((x2-RIGHT)<=RADIUS & (x2-RIGHT)>=-RADIUS){			//boundary conditon for ball2
		flag2x=-1;
		speedx2=(rand()%10)/(float)(100);
	}
	if((x2-LEFT)<=RADIUS & (x2-LEFT)>=-RADIUS){
		flag2x=1;
		speedx2=(rand()%10)/(float)(100);
		printf("so %f",speedx2);
	}

	if((y2-TOP)<=RADIUS & (y2-TOP)>=-RADIUS){			//boundary conditon for ball2
		flag2y=-1;
		speedy2=(rand()%10)/(float)(100);
	}
	if((y2-BOTTOM)<=RADIUS & (y2-BOTTOM)>=-RADIUS){
		flag2y=1;
		speedy2=(rand()%10)/(float)(100);
	}

	x2=x2+speedx2*flag2x;
	y2=y2+speedy2*flag2y;
	glPushMatrix();											//ball2
	glLoadIdentity();
	glColor3f(0,1,0);
	glTranslatef(x2,y2,0);
	glRotatef(100,1,1,0);
	glutSolidSphere(RADIUS,100,100);
	glPopMatrix();


	if((x3-RIGHT)<=RADIUS & (x3-RIGHT)>=-RADIUS){			//boundary conditon for ball3
		flag3x=-1;
		speedx3=(rand()%10)/(float)(100);
	}
	if((x3-LEFT)<=RADIUS & (x3-LEFT)>=-RADIUS){
		flag3x=1;
		speedx3=(rand()%10)/(float)(100);
	}

	if((y3-TOP)<=RADIUS & (y3-TOP)>=-RADIUS){			//boundary conditon for ball3
		flag3y=-1;
		speedy3=(rand()%10)/(float)(100);
	}
	if((y3-BOTTOM)<=RADIUS & (y3-BOTTOM)>=-RADIUS){
		flag3y=1;
		speedy3=(rand()%10)/(float)(100);
	}


	x3=x3+speedx3*flag3x;
	y3=y3+speedy3*flag3y;
	glPushMatrix();										//ball3
	glLoadIdentity();
	glColor3f(0,0,1);
	glTranslatef(x3,y3,0);
	glRotatef(100,1,1,0);
	glutSolidSphere(RADIUS,100,100);
	glPopMatrix();	


	glutSwapBuffers();
	}
}
