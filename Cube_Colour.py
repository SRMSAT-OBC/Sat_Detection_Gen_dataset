import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
from math import *


a=[[cos(0.5*pi/180),sin(0.5*pi/180),0],
       [-sin(0.5*pi/180),cos(0.5*pi/180),0],
       [0,0,1]]
def zarb_matris(p,b): 
         c=[b[0][0]*p[0][0]+b[0][1]*p[1][0]+b[0][2]*p[2][0], 
            b[1][0]*p[0][0]+b[1][1]*p[1][0]+b[1][2]*p[2][0], 
            b[2][0]*p[0][0]+b[2][1]*p[1][0]+b[2][2]*p[2][0]] 
         return c 
          
verticies= [ 
         [1, -1, -1], 
         [1, 1, -1], 
         [-1, 1, -1], 
         [-1, -1, -1], 
         [1, -1, 1], 
         [1, 1, 1], 
         [-1, -1, 1], 
         [-1, 1, 1] 
         ] 
      
      
edges = ( 
         (0,1), 
         (0,3), 
         (0,4), 
         (2,1), 
         (2,3), 
         (2,7), 
         (6,3), 
         (6,4), 
         (6,7), 
         (5,1), 
         (5,4), 
         (5,7), 
         ) 
      
surfaces= ( 
         (0,1,2,3), 
         (3,2,7,6), 
         (6,7,5,4), 
         (4,5,1,0), 
         (1,5,7,2), 
         (4,0,3,6) 
         ) 
      
colors = ( 
         (0.9,0,0), 
         (0,1,0), 
         (0.75,0.38,0), 
         (0,0,1), 
         (1,1,0), 
         (1,1,1),    
         (1,0,0), 
         (0,1,0), 
         (0.75,0.38,0), 
         (0,0,1), 
         (1,1,0), 
         (0.9,1,1) 
         ) 
      
      
def Cube(): 
    global verticies 
    glBegin(GL_QUADS) 
    x = 0 
    for surface in surfaces: 
        x+=1 
      
        for vertex in surface: 
            glColor3fv(colors[x]) 
            glVertex3fv(verticies[vertex]) 
    glEnd() 
    glBegin(GL_LINES) 
    glColor3fv((1,1,1)) 
    for edge in edges: 
        for vertex in edge: 
            glVertex3fv(verticies[vertex]) 
    glEnd() 
      
      
def main(): 
    global s 
    pygame.init() 
    display = (800,600) 
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL) 
    glEnable(GL_DEPTH_TEST) 
    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0) 
      
    glTranslatef(1,1, -10) 
      
    while True: 
        for event in pygame.event.get(): 
            if event.type == pygame.QUIT: 
                pygame.quit() 
                quit() 
        glRotatef(1, 12, 0,55115 ) 
        for i in range(8): 
            s=[] 
            for j in verticies[i]: 
                s.append([j]) 
            k=zarb_matris(s,a) 
            verticies[i]=k 
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) 
        Cube() 
        pygame.display.flip() 
        pygame.time.wait(10) 
        
main()
