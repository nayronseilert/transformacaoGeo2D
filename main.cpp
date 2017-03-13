/*
  programa que faz operações de rotação, escala e translação
  autor Náyron dos Anjos Seilert
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



float angulo = 0, escala = 18.0;
float pos_X = 0, pos_Y = 0;


void MenuPrincipal()
{
    int op;
    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t|------------------------------------|"<<endl;
    cout<<"\t\t| UNIVERSIDADE FEDERAL DO TOCANTINS  |"<<endl;
    cout<<"\t\t|  FACULDADE CIENCIAS DA COMPUTACAO  |"<<endl;
    cout<<"\t\t|  DISC.: COMPUTACAO GRAFICA 2016-2  |"<<endl;
    cout<<"\t\t|    NAYRON DOS ANJOS SEILERT        |"<<endl;
    cout<<"\t\t|------------------------------------|"<<endl;
    cout<<"\t\t|------------------------------------|"<<endl;
    cout<<"\t\t|--------- MENU DE OPCOES -----------|"<<endl;
    cout<<"\t\t|-----DIGITE [1] P/ ROTACAO----------|"<<endl;
    cout<<"\t\t|-----DIGITE [2] P/ ESCALA-----------|"<<endl;
    cout<<"\t\t|-----DIGITE [3] P/ TRANSLACAO-------|"<<endl;
    cout<<"\t\t|-----DIGITE [4] P/ SAIR-------------|"<<endl;
    cout<<"\t\t|------------------------------------|"<<endl;
    cout<<"\t\t|-ESCOLHA UMA OPCAO: ";
    cin>>op;

    if(op == 1)
    {
        cout<<"\n\n\t\tDIGITE O GRAU QUE DESEJA FAZER A ROTACAO: ";
        cin>>angulo;

    }
    else if(op == 2)
    {
        cout<<"\n\n\t\tDIGITE A ESCALA: ";
        cin>>escala;
    }
    else if(op == 3)
    {
        cout<<"\n\n\t\tVALORES PARA VETOR DE TRANSLACAO=[-100 E 100]"<<endl;
        cout<<"\n\n\t\tDIGITE VALOR P/ X : ";
        cin>>pos_X;
        cout<<"\n\n\t\tDIGITE VALOR P/ Y : ";
        cin>>pos_Y;
    }
    else if(op == 4)
    {
        exit(1);
    }
    else
    {
        cout<<"\nOPCAO INVALIDA"<<endl;
        system("pause");
    }

}

void MostrarEixoXY()//função que mostra os eixos x e y na tela opengl
{
    glLineWidth(3);
    glColor3f (0.0, 0.0, 0.0);//cor das linhas
    glBegin(GL_LINES);
    glVertex2f (0.0, -100.0);
    glVertex2f (0.0, 100.0);
    glVertex2f (-100.0, 0.0);
    glVertex2f (100.0, 0.0);
    glEnd();
}
void TransformarGeom(){

    glColor3f (0.0, 0.0, 255.0);//cor do objeto
    glPushMatrix();
    glTranslatef(pos_X, pos_Y, 0.0);
    glRotatef(angulo, 0.0, 0.0, 1.0);
    glScalef(escala, escala, escala);

    // glutWireCube(10);
    //glutWireCone(10.0, 20.0, 5.0,1.0);

    glutWireIcosahedron();
    glPopMatrix();

}

void display(void)
{
    // Limpar todos os pixels
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // Inicializa com matriz identidade

    MostrarEixoXY();
    TransformarGeom();

    glutSwapBuffers ();
    glutPostRedisplay();

    MenuPrincipal();
}

void init (void)
{
    // selecionar cor de fundo
    glClearColor (255.0, 255.0, 255.0, 255.0);

    // inicializar sistema de viz.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutInitWindowSize (500, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Tela principal");


    init ();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
