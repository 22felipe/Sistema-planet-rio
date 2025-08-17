#include <GL/glut.h> 

// Variáveis globais de rotação
static int year_sun = 0;
static int year_planet1 = 0;
static int year_planet2 = 0;
static int year_moons = 0;
static int day = 0;

// Inicializa parâmetros de rendering
void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

// Função callback chamada para fazer o desenho
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//iniciando a cor de fundo e profundidade
    
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0); //cor das linhas do objeto
        glRotatef((GLfloat) year_sun, 0.0, 1.0, 0.0);
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(1.0, 20, 16);   /* desenha o sol */
    glPopMatrix();

    /*
        para que as luas girem em volta do planeta precisamos coloca-las dentro
        da matriz de transformação do planeta desejado
    */
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);//cor das linhas do objeto
        glRotatef((GLfloat) year_planet1, 0.0, 1.0, 0.0);
        glTranslatef(2.0, 0.0, 0.0); //Translada após a rotação
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);   /* desenha o planeta 1*/

        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);//cor das linhas do objeto
        glRotatef((GLfloat) year_moons, 0.0, 1.0, 0.0);
        glTranslatef(0.5, 0.0, 0.0); //Translada após a rotação
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.1, 10, 8);   // desenha lua 1
        glPopMatrix();  

        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);//cor das linhas do objeto
        glRotatef((GLfloat) year_moons, 1.0, 1.0, 0.0);
        glTranslatef(-0.5, 0.0, 0.0); //Translada após a rotação
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.1, 10, 8);   // desenha lua 2
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);//cor das linhas do objeto
        glRotatef((GLfloat) year_planet2, 0.0, 1.0, 0.0);
        glTranslatef(4.0, 0.0, 0.0); //Translada após a rotação
        glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);   /* desenha o planeta 2 */
    glPopMatrix();

    glutSwapBuffers(); // usado quando GLUT_DOUBLE está ativo
}

/*
// Função de ajuste de viewport (visão de cima)
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    
    // Câmera de cima olhando para o sol
    gluLookAt(0.0, 8.0, 0.0,   // posição da câmera (x, y, z)
              0.0, 0.0, 0.0,   // ponto para onde a câmera está olhando (alvo)
              0.0, 0.0, -1.0); // vetor "up" (qual direção é considerada para cima)
    glMatrixMode(GL_MODELVIEW);
}*/


// Função de ajuste de viewport (visão frontal)
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    gluLookAt(0.0, 0.0, 8.0, // posição da câmera (x, y, z)
              0.0, 0.0, 0.0, // ponto para onde a câmera está olhando (alvo)
              0.0, 1.0, 0.0); // vetor "up" (qual direção é considerada para cima)
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
            year_sun = (year_sun + 5) % 360;
            year_moons = (year_moons + 5) % 360;
            year_planet1 = (year_planet1 + 5) % 360;
            year_planet2 = (year_planet2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            year_sun = (year_sun - 5) % 360;
            year_moons = (year_moons - 5) % 360;
            year_planet1 = (year_planet1 - 5) % 360;
            year_planet2 = (year_planet2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

// Função principal
int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotacao de Planetas");
    //glutFullScreen();

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
