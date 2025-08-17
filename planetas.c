//
//  main.cpp
//  TransformacaoPlanetas
//
//  Adaptado para Windows
//

#include <GL/glut.h>  // no Windows é <GL/glut.h>

// Variáveis globais de rotação
static int year = 0, day = 0;

// Inicializa parâmetros de rendering
void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Função callback chamada para fazer o desenho
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);//cor de fundo
    glColor3f(1.0, 1.0, 1.0);//cor das linhas dos objetos

    glPushMatrix();
        glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
        glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
        glutWireSphere(1.0, 20, 16);   /* desenha o sol */
    glPopMatrix();

    glPushMatrix();
        glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
        glTranslatef(2.0, 0.0, 0.0); //Translada após a rotação
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);   /* desenha o planeta */
    glPopMatrix();

    glutSwapBuffers(); // usado quando GLUT_DOUBLE está ativo
}

// Função de ajuste de viewport
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
}

// Função para capturar teclado
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'd':
            day = (day + 10) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            day = (day - 10) % 360;
            glutPostRedisplay();
            break;
        case 'y':
            year = (year + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            year = (year - 5) % 360;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

// Função principal
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotacao de Planetas");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
