#include <agar/core.h>
#include <agar/gui.h>
#include <GL/glut.h>

void desenharTriangulo(AG_Event *evento) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();
}

int main(int argc, char *argv[]) {
    AG_Window *janela;
    AG_GLView *glView;

    if (AG_InitCore("exemplo", 0) == -1) {
        return 1;
    }

    if (AG_InitGraphics(NULL) == -1) {
        AG_Destroy();
        return 1;
    }

    janela = AG_WindowNew(0);
    glView = AG_GLViewNew(janela, AG_GLVIEW_EXPAND);

    AG_SetEvent(glView, "window-paint", desenharTriangulo, NULL);

    AG_WindowShow(janela);

    AG_EventLoop();

    AG_Destroy();

    return 0;
}
