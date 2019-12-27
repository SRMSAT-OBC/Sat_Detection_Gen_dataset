from OpenGL.GL import *
from OpenGL.GLU import *
import pygame
from pygame.locals import *
 
vertices = ((1, -1, -1),(1, 1, -1),(-1, 1, -1),(-1, -1, -1),(1, -1, 1),(1, 1, 1),(-1, -1, 1),(-1, 1, 1))
#coordinates of the vertices
 
edges = ((0, 1),(0, 3),(0, 4),(2, 1),(2, 3),(2, 7),(6, 3),(6, 4),(6, 7),(5, 1),(5, 4),(5, 7))
#these are the index of above vertices
 
def DrawCube(tX, tY, tZ):
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3f(vertices[vertex][0] + tX, vertices[vertex][1] + tY, vertices[vertex][2] + tZ)
    glEnd()
 
def main():
    pygame.init()
    clock = pygame.time.Clock()
    screenSize = (600,600) #number of pixels
    pygame.display.set_mode(screenSize, DOUBLEBUF | OPENGL)
    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (screenSize[0] / screenSize[1]), 0.1, 500.0) #gives step size for angle
    glMatrixMode(GL_MODELVIEW)

    speed = 3
    rot = 0
    sum_rot_updown = 0
    current_mv_mat = (GLfloat * 16)()

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
 
        pressed = pygame.key.get_pressed()
 
        if pressed[pygame.K_ESCAPE]:
            pygame.quit()
            quit()
 
        glGetFloatv(GL_MODELVIEW_MATRIX, current_mv_mat)
        glLoadIdentity()
 
        if pressed[pygame.K_LEFT]:
            glRotatef(speed / 2, 0, -1, 0) # how it will rotate in which axis
            rot += 1
 
        if pressed[pygame.K_RIGHT]:
            glRotatef(speed / 2, 0, 1, 0)
            rot -= 1

        if pressed[pygame.K_w]:
            glTranslate(0, 0, 1 / speed)
        if pressed[pygame.K_s]:
            glTranslate(0, 0, -1 / speed)
        if pressed[pygame.K_a]:
            glTranslate(1 / speed, 0, 0)
        if pressed[pygame.K_d]:
            glTranslate(-1 / speed, 0, 0)
 
        if pressed[pygame.K_SPACE]:
            glTranslate(0, -1 / speed, 0)
        if pressed[pygame.K_LSHIFT]:
            glTranslate(0, 1 / speed, 0)
 
        glMultMatrixf(current_mv_mat)

        if pressed[pygame.K_UP]:
            sum_rot_updown -= speed / 2
        if pressed[pygame.K_DOWN]:
            sum_rot_updown += speed / 2
 
        glPushMatrix()
 
        glGetFloatv(GL_MODELVIEW_MATRIX, current_mv_mat)
        glLoadIdentity()
        glRotatef(sum_rot_updown, 1, 0, 0)
        glMultMatrixf(current_mv_mat)
 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        for i in range(1):
            for j in range(1):
                DrawCube(-i * 2.5, -4, -j * 2.5)
 
        glPopMatrix()
 
        pygame.display.flip()
        clock.tick(60)

main()