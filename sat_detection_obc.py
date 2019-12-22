import pygame,os

pygame.init()

clock=pygame.time.Clock()
display_width=1675
display_height=1050
black=(0,0,0)
white=(255,255,255)
red=(255,0,0)
dark_red=(200,0,0)
green=(0,200,0)
light_green=(0,255,0)
gameDisplay=pygame.display.set_mode((display_width,display_height),pygame.FULLSCREEN)
i=0
image = pygame.image.load(os.path.join("D:","wallpapers","spiderman.jpg"))
def screenshot():
  global i
  rect = pygame.Rect(0, 0, 1675, 1000)
  sub = gameDisplay.subsurface(rect)
  pygame.image.save(sub,"D:\wallpapers\satellite"+str(i)+".jpg")
  i+=1
  print("satellite"+str(i-1)+".jpg")
def text_objects(text,font):
  textSurface=font.render(text,True,black)
  return textSurface,textSurface.get_rect()

def button(msg,x,y,w,h,i,a,action=None):
  
  mouse = pygame.mouse.get_pos()
  click=pygame.mouse.get_pressed()
  
  if x+w > mouse[0] > x and y+h> mouse[1]> y:
    pygame.draw.rect(gameDisplay,a,(x,y,w,h))
    if click[0]==1 and action !=None:
      if action=="screenshot":
        screenshot()
      elif action=="close":
        pygame.quit()
      elif action=="rand":
        pass
  else:
    pygame.draw.rect(gameDisplay,i,(x,y,w,h))
    smalltext=pygame.font.SysFont("arial",10)
    textsurf,textrect=text_objects(msg,smalltext)
    textrect.center=((x+int(w/2)),(y+int(h/2)))
    gameDisplay.blit(textsurf,textrect)
  
intro=True

while intro:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      pygame.quit()
      quit()
  gameDisplay.fill(white)
  
  gameDisplay.blit(pygame.transform.scale(image,(1675,1000)),(0,0))
  button("scrnsht",0,1000,50,50,light_green,green,"screenshot")
  button("X",1620,1000,50,50,dark_red,red,"close")
  button("random",550,1000,500,50,white,black,"rand")
  pygame.display.update()
  clock.tick(15)
  
