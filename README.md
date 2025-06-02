## PyGame: A Brief Overview

**PyGame** is a Python library designed specifically for creating video games. It provides a set of functions and classes that simplify the process of handling graphics, sound, input, and other game-related elements.

PyGame offers a robust set of modules to handle various aspects of game development.

### **General display:**

- pygame.init() and pygame.quit() are the starting point and ending point for any Pygame application. **pygame.init()** initializes all imported pygame modules and **pygame.quit()** end the modules.

```python
pygame.init()
pygame.quit()
```

- The function `display.set_mode()` sets the screen size. It returns a `Surface` object wich we assign to the variable `screen`. This variable will be one of the most used variables. It represents the window we see:

```python
screen = pygame.display.set_mode((x, y))
```

- The function `display.set_caption()` sets the caption that is displayed at the top of the window.

```python
screen = pygame.display.set_caption()
```

- The function `display.set_icon()` sets the icon that is displayed at the top left corner of the window.

```python
screen = pygame.display.set_icon()
```

### **Show the event loop:**

- The most essential part of any interactive application is the **event loop**. Reacting to events allows the user to interact with the application. The following is an infinite loop which prints all events to the console:

```python
**while** **True**:
    **for** event **in** pygame.event.get():
        print(event)
```

### **Quit the event loop properly:**

- In order to quit the application properly, from within the application, by using the window close button (QUIT event), we modify the event loop.

```python
running =True
while running:
	for eventin pygame.event.get():
		if event.type == pygame.QUIT:
            running =False
pygame.quit()
```

### Detecting a keyboard key:

- To detect a pressed key, we use the `KEYDOWN` events. it is written as,

```python
event.type == pygame.KEYDOWN
```

- To detect when the pressed key ifs released, we use the `KEYUP` events. it is written as,

```python
event.type == pygame.KEYUP
```

### **Define colors:**

- Colors in PyGame use the RGB model, defined as tuples of red, green, and blue values (0-255). Each color occupies 1 byte, allowing for 16 million possible combinations.
- Base colors are defined as constant tuples. Black is (0,0,0), white is (255,255,255), and grays use equal values for all components. Primary colors use maximum values for their respective components.

```python
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
```

```python
BLACK = (0, 0, 0)
GRAY = (127, 127, 127)
WHITE = (255, 255, 255)
```

```python
YELLOW = (255, 255, 0)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)
```

- At the end of the event loop, we add the following:

```python
screen.fill(COLOR) # replace COLOR with what you have defined
pygame.display.update() # updates the changes to the display
```

**NOTE : The following  is just an example.**

- Within the event loop we are looking now for `KEYDOWN` events. If found, we check if the R or G keys have been pressed and change the background color to red (R) and green (G). This is the code added in the event loop:

```python
**if** event.type == pygame.KEYDOWN:
    **if** event.key == pygame.K_r:
        background = RED
    **elif** event.key == pygame.K_g:
        background = GREEN
```

- In the drawing section we use now the variable `background` representing the background color:

```python
screen.fill(background)
pygame.display.update()
```

 Pressing the R and G keys allows you to switch the background color.

- The easiest way to decode many keys, is to use a dictionary. Instead of defining many if-else cases, we just create a dictionary with the keyboard key entries.

```python
key_dict = {K_k:BLACK, K_r:RED, K_g:GREEN, K_b:BLUE, K_y:YELLOW, K_c:CYAN, K_m:MAGENTA, K_w:WHITE}

print(key_dict)
```

- So, making the following change in the above mentioned example, we get

```python
if event.type == KEYDOWN:
if event.keyin key_dict:
        background = key_dict[event.key]
```

### **Import pygame.locals:**

- The `pygame.locals` module contains some 280 constants used and defined by pygme. Placing this statement at the beginning of your programm imports them all:

```python
**from** **pygame.locals** **import** *
```

- We find the key modifiers (alt, ctrl, cmd, etc.)

```python
KMOD_ALT, KMOD_CAPS, KMOD_CTRL, KMOD_LALT,
KMOD_LCTRL, KMOD_LMETA, KMOD_LSHIFT, KMOD_META,
KMOD_MODE, KMOD_NONE, KMOD_NUM, KMOD_RALT, KMOD_RCTRL,
KMOD_RMETA, KMOD_RSHIFT, KMOD_SHIFT,

#the number keys:

K_0, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9,

#the special character keys:

K_AMPERSAND, K_ASTERISK, K_AT, K_BACKQUOTE,
K_BACKSLASH, K_BACKSPACE, K_BREAK,

#the letter keys of the alphabet:

K_a, K_b, K_c, K_d, K_e, K_f, K_g, K_h, K_i, K_j, K_k, K_l, K_m,
K_n, K_o, K_p, K_q, K_r, K_s, K_t, K_u, K_v, K_w, K_x, K_y, K_z,

#the arrow keys

K_LEFT, K_RIGHT, K_UP, K_DOWN
```

**NOTE:** Instead of writing `pygame.KEYDOWN` we can now just write `KEYDOWN`

### **Drawing graphics primitives:**

- The `pygame.draw` module allows to draw simple shapes to a surface. This can be the screen surface or any Surface object such as an image or drawing:
    - rectangle
    - polygon
    - circle
    - ellipse
- The functions have in common that they:
    - take a **Surface** object as first argument
    - take a color as second argument
    - take a width parameter as last argument
    - return a **Rect** object which bounds the changed area

the following format:

```python
rect(Surface, color, Rect, width) -> Rect
polygon(Surface, color, pointlist, width) -> Rect
circle(Surface, color, center, radius, width) -> Rect
line(Surface, color, pointlist, width) -> Rect
```

**NOTE:** Most of the functions take a width argument. If the width is 0, the shape is filled.

### **Draw solid and outlined rectangles:**

- The following draws first the background color and then adds three overlapping solid rectangles and next to it three oulined overlapping rectangles with increasing line width:

```python
pygame.draw.rect(screen, RED, (50, 20, 120, 100))
pygame.draw.rect(screen, GREEN, (100, 60, 120, 100))
pygame.draw.rect(screen, BLUE, (150, 100, 120, 100))

pygame.draw.rect(screen, RED, (350, 20, 120, 100), 1)
pygame.draw.rect(screen, GREEN, (400, 60, 120, 100), 4)
pygame.draw.rect(screen, BLUE, (450, 100, 120, 100), 8)
```

### **Draw solid and outlined ellipses:**

- The following code draws first the background color and then adds three overlapping solid ellipses and next to it three outlined overlapping ellipses with increasing line width:

```python
pygame.draw.ellipse(screen, RED, (50, 20, 160, 100))
pygame.draw.ellipse(screen, GREEN, (100, 60, 160, 100))
pygame.draw.ellipse(screen, BLUE, (150, 100, 160, 100))

pygame.draw.ellipse(screen, RED, (350, 20, 160, 100), 1)
pygame.draw.ellipse(screen, GREEN, (400, 60, 160, 100), 4)
pygame.draw.ellipse(screen, BLUE, (450, 100, 160, 100), 8)
```

### **Detect the mouse:**

- Pressing the mouse buttons produces MOUSEBUTTONDOWN and MOUSEBUTTONUP events. The following code in the event loop detects them and writes the event to the console:

```python
**for** event **in** pygame.event.get():
    **if** event.type == QUIT:
        running = **False
    elif** event.type == MOUSEBUTTONDOWN:
        print(event)
    **elif** event.type == MOUSEBUTTONUP:
        print(event)
```

- Just moving the mouse produces a MOUSEMOTION event. The following code detects them an writes the event to the console:

```python
**elif** event.type == MOUSEMOTION:
    print(event)
```

### **Draw a rectangle with the mouse:**

- We can use this three events to draw a rectangle on the screen. We define the rectangle by its diagonal start and end point. We also need a flag which indicates if the mouse button is down and if we are drawing:

```python
start = (0, 0)
size = (0, 0)
drawing = **False**
```

- When the mouse button is pressed, we set start and end to the current mouse position and indciate with the flag that the drawing mode has started:

```python
**elif** event.type == MOUSEBUTTONDOWN:
    start = event.pos
    size = 0, 0
    drawing = **True**
```

- When the mouse button is released, we set the end point and indicate with the flag that the drawing mode has ended:

```python
**elif** event.type == MOUSEBUTTONUP:
    end = event.pos
    size = end[0] - start[0], end[1] - start[1]
    drawing = **False**
```

- When the mouse is moving we have also have to check if we are in drawing mode. If yes, we set the end position to the current mouse position:

```python
**elif** event.type == MOUSEMOTION **and** drawing:
    end = event.pos
    size = end[0] - start[0], end[1] - start[1]
```

**NOTE: this is same for all the shapes.**

### **Draw multiple shapes:**

- To draw multiple shapes, we need to place them into a list. Besides variables for `start`, `end` and `drawing` we add a rectangle list:

```python
start = (0, 0)
size = (0, 0)
drawing = **False**rect_list = []
```

- When drawing of an object (rectangle, circle, etc.) is done, as indicated by a MOUSEBUTTONUP event, we create a rectangle and append it to the rectangle list:

```python
**elif** event.type == MOUSEBUTTONUP:
    end = event.pos
    size = end[0]-start[0], end[1]-start[1]
    rect = pygame.Rect(start, size)
    rect_list.append(rect)
    drawing = **False**
```

- In the drawing code, we iterate through the rectangle list to draw the objects to draw the rectangles

```python
**for** rect **in** rect_list:
    pygame.draw.rect(screen, RED, rect, 3)
```

**NOTE: this is same for all the shapes.**

### **Work with rectangles:**

- The rectangle is a very useful object in graphics programming. It has its own `Rect` class in Pygame and is used to store and manipulate a rectangular area. A `Rect` object can be created by giving:
    - the 4 parameters **left, top, width** and **height**
    - the **position** and **size**
    - an **object** which has a *rect* attribute
    
    ```python
    Rect(left, top, width, height)
    Rect(pos, size)
    Rect(obj)
    ```
    
- A function which expects a `Rect` argument accepts equally one of the three above values. Methods which change the position or size, such as `move()` and `inflate()` leave the original Rect untouched and return a new Rect. They also have the *in place* version `move_ip` and `inflate_ip` which act upon the original Rect.

### **Virtual attributes:**

- The `Rect` object has several virtual attributes which can be used to move and align the Rect. Assignment to these attributes just moves the rectangle without changing its size:

```python
x, y
top, left, bottom, right
topleft, bottomleft, topright, bottomright
midtop, midleft, midbottom, midright
center, centerx, centery
```

- The assignment of these 5 attributes changes the size of the rectangle, by keeping its top left position.

```python
size, width, height, w, h
```

### **Points of interest:**

- The Rect class defines 4 corner points, 4 mid points and 1 center point.

![](https://pygame.readthedocs.io/en/latest/_images/rect2.png)

- These points are used to position the rectangle on the screen at the provided ( X , Y ) coordinates.

### **Move a rectangle with keys:**

- The method `move(v)` creates a new Rect which has moved by a vector `v`. The method `move_ip(v)` moves a Rect **in place**.
- We can use a dictionary to associate a motion vector to each of the 4 arrow keys. for example:

```python
dir = {K_LEFT: (-5, 0), K_RIGHT: (5, 0), K_UP: (0, -5), K_DOWN: (0, 5)}
```

```python
rect.move_ip(v)
```

### **Inflate a rectangle:**

- The method `inflate(v)` grows or shrinks a rectangle by a vector `v` and creates a new Rect. The method `inflate_ip(v)` grows or shrinks a Rect **in place**.

```python
rect.inflate_ip(v)
```

### **Clip a rectangle:**

- We consider `r0` are the coordinates of on rectangle and `r1` are the coordinates of another rectangle.
- The method `r0.clip(r1)` returns a new rectangle which is the intersection of the two rectangles. The method `r0.union(r1)` returns a new rectangle which is the union of the two rectangles.

```python
clip = r0.clip(r1)
union = r0.union(r1)
```

### **Move a rectangle with the mouse:**

- The function `rect.collidepoint(pos)` returns True if the point collides with the rectangle.
- We use it with the mouse position to check if the mouse click has happened inside the rectangle. If that is the case, we move the rectangle by the relative motion of the mouse `event.rel`.
- The boolean variable `moving` is set when the mouse button goes down inside the rectangle. It remains True until the button goes up again.
- The rectangle is only moved when the mouse click has happened inside the rectangle.

```python
elif event.type == MOUSEBUTTONDOWN:
	  if rect.collidepoint(event.pos):
				moving =True
elif event.type == MOUSEBUTTONUP:
    moving = False
elif event.type == MOUSEMOTION and moving:
    rect.move_ip(event.rel)
```

### **A self-moving a rectangle**

- The following code moves a rectangle by the amount `v`:

```python
rect.move_ip(v)
```

- It then checks the 4 borders and inverts the speed component if the rectangle is outside of the application window.

```python
rect = Rect(100, 50, 50, 50) # the dimension of the rectangle
v = [2, 2]  # the speed of the motion
```

```python
if rect.left < 0:
        v[0] *= -1
if rect.right > width:
        v[0] *= -1
if rect.top < 0:
        v[1] *= -1
if rect.bottom > height:
        v[1] *= -1
```

### **Colliding points**

- The method `rect.collidepoint(p)` checks if a rectangle `rect` collides with point `p`. In the following program we create 100 random points and color them red if they fall inside the rectangle.
- Each time the R key is pressed 100 new random points are created.

**NOTE:** The following program is just an example for understanding. 

```python
from rect import *

points = random_points(100)

while running:
			for event in pygame.event.get():
					if event.type == QUIT:
	            running =False
					
					if event.type == KEYDOWN:
							if event.key == K_r:
	                points = random_points(100)
					
	    screen.fill(GRAY)
	    pygame.draw.rect(screen, GREEN, rect, 1)
	    
			for pin points:
					if rect.collidepoint(p):
	            pygame.draw.circle(screen, RED, p, 4, 0)
					else:
	            pygame.draw.circle(screen, BLUE, p, 4, 0)
			
	    pygame.display.flip()

pygame.quit()
```

### **Colliding rectangles**

- The method `rect.colliderect(r)` checks if a rectangle `rect` collides with another rectangle `r`. In the following program we create 50 random rectangles and color them red if they collide with the green rectangle.
- Each time the R key is pressed 50 new random rectangles are created.

**NOTE:** The following program is just an example for understanding. 

```python
from rect import *

n = 50
rects = random_rects(n)

while running:
			for eventin pygame.event.get():
					if event.type == QUIT:
					    running = False
					
					if event.type == KEYDOWN:
							if event.key == K_r:
					        rects = random_rects(n)
			
	    screen.fill(GRAY)
	    pygame.draw.rect(screen, GREEN, rect, 1)

			for rin rects:
					if rect.colliderect(r):
		          pygame.draw.rect(screen, RED, r, 2)
					else:
		          pygame.draw.rect(screen, BLUE, r, 1)

	    pygame.display.flip()

pygame.quit()
```

### **Overlapping rectangles**

- The method `rect.colliderect(r)` checks if a rectangle `rect` collides with another rectangle `r`. If we want to know if there are any two overlapping rectangles, then we have to compare each rectangle with each other one. The number of comparisons increases as power of 2.
- Each time the R key is pressed 20 new random rectangles are created.

**NOTE:** The following program is just an example for understanding. 

```python
from rect import *

n = 30
rects = random_rects(n)

while running:
			for eventin pygame.event.get():
					if event.type == QUIT:
	            running =False
					
					if event.type == KEYDOWN:
							if event.key == K_r:
	                rects = random_rects(n)
					
	    screen.fill(GRAY)
				
	    intersecting = []
			
			for i in range(n-1):
	        r0 = rects[i]
					for j in range(i+1, n):
	            r1 = rects[j]
							if r0.colliderect(r1):
	                intersecting.append(r0)
	                intersecting.append(r1)
									break
			for i, rin enumerate(rects):
	        color = RED if r in intersecting else BLUE
	        pygame.draw.rect(screen, color, r)

		   pygame.display.flip()

pygame.quit()
```

### **Load an image**

- The `pyagme.image` module provides methods for loading and saving images. The method `load()` loads an image from the file system and returns a Surface object. The method `convert()` optimizes the image format and makes drawing faster:

```python
img = pygame.image.load('bird.png')
img.convert()
```

- Download the image `bird.png` to the same folder where your program resides:
- The method `get_rect()` returns a Rect object from an image. At this point only the size is set and position is placed at (0, 0). We set the center of the Rect to the center of the screen:

```python
rect = img.get_rect()
rect.center = w//2, h//2
```

- To recapitulate, we are working with 3 objects:
    - **screen** is the Surface object representing the application window
    - **img** is the Surface object of the image to display
    - **rect** is the Rect object which is the bounding rectangle of the image
- To display the image we fill the screen with a background color (GRAY). Then we blit the image, draw a red rectangle around it and finally update the screen:

```python
screen.fill(GRAY)
screen.blit(img, rect)
pygame.draw.rect(screen, RED, rect, 1)
pygame.display.update()
```

### **Move the image with the mouse**

- At the beginning of the programm we set a boolean variable `moving` to False. Only when the mouse button is pressed, and when the mouse position is within the image (collidepoint) we set it to True:

```python
**elif** event.type == MOUSEBUTTONDOWN:
    **if** rect.collidepoint(event.pos):
        moving = **True**
```

- When the mouse button is released, we set it to False again:

```python
**elif** event.type == MOUSEBUTTONUP:
    moving = **False**
```

- When the mouse moves, and the flag `moving` is True, then we move the image by the amount of relative movement (event.rel):

```python
**elif** event.type == MOUSEMOTION **and** moving:
    rect.move_ip(event.rel)
```

### **Rotate and Scale the image**

- The `pygame.transform` module provides methods for **scaling, rotating and flipping** images. As we are going to modify the image **img** we keep the original image in a variable called **img0**:

```python
img0 = pygame.image.load(path)
img0.convert()
```

- In order to show the image rectangle, we add a green border to the original image:

```python
rect0 = img0.get_rect()
pygame.draw.rect(img0, GREEN, rect0, 1)
```

- Then we place the place the image in the center of the screen:

```python
center = w//2, h//2
img = img0
rect = img.get_rect()
rect.center = center
```

- First we define the global variables **scale** and **angle**:

```python
angle = 0
scale = 1
```

- We use the R key to increment rotation by 10 degrees and (decrement if the SHIFT key is pressed). The function `rotozoom()` allows to combine rotation and scaling. We always transform the orignial image (img0). Repeated rotation or scaling of an image would degrade its quality:

```python
**if** event.type == KEYDOWN:
    **if** event.key == K_r:
        **if** event.mod & KMOD_SHIFT:
            angle -= 10
        **else**:
            angle += 10
        img = pygame.transform.rotozoom(img0, angle, scale)
```

- We use the S key to increment the scale by 10% (decrease if the SHIFT key is pressed):

```python
**elif** event.key == K_s:
        **if** event.mod & KMOD_SHIFT:
            scale /= 1.1
        **else**:
            scale *= 1.1
        img = pygame.transform.rotozoom(img0, angle, scale)
```

- As the image is transformed the bounding rectangle changes size. It must be recalulated and placed at the center again:

```python
rect = img.get_rect()
rect.center = center
```

### **Reset the image to the original**

- We use the O key to reset the image to its original state:

```python
**elif** event.key == K_o:
    img = img0
    angle = 0
    scale = 1
```

### **Flip the image**

- We use the H key to flip the image horizontally:

```python
**elif** event.key == K_h:
    img = pygame.transform.flip(img, **True**, **False**)
```

- and the V key to flip the image vertically:

```python
**elif** event.key == K_v:
    img = pygame.transform.flip(img, **False**, **True**)
```

### **Detect edges with the Laplacian**

- The function `laplacien(img)` allows to detect the outline of the image:

```python
**elif** event.key == K_l:
    img = pygame.transform.laplacian(img)
```

- The function `scale2x(img)` doubles the size of a pixel:

```python
**elif** event.key == K_2:
    img = pygame.transform.scale2x(img)
```

### **Transform the image with the mouse**

- In this section we show how to use the mouse to scale and rotate an image. At the beginning we import the `math` module:

```python
**import** **math**
```

- At the beginning we store the initial mouse position:

```python
mouse = pygame.mouse.get_pos()
```

- When the mouse moves we update the mouse position `mouse` and calculate the **x, y** coordinates from the center of the image. We also calculate the center-mouse distance **d**

```python
**elif** event.type == MOUSEMOTION:
    mouse = event.pos
    x = mouse[0] - center[0]
    y = mouse[1] - center[1]
    d = math.sqrt(x ** 2 + y ** 2)
```

- The `atan2(y, x)` math function allows to find the rotation angle. We need to transform radians in degrees. From the distance mouse-center we calculate the scale argument:

```python
angle = math.degrees(-math.atan2(y, x))
scale = abs(5 * d / w)
img = pygame.transform.rotozoom(img0, angle, scale)
rect = img.get_rect()
rect.center = center
```

- To finally draw the transformed image we first fille the whole screen background (GRAY), blit the transformed image, surround it with a red rectangle.
- In order to give visual feedback for the mouse action when transforming an image, we
    - draw a green line between the center of the image and the mouse position,
    - place two circles on the center and on the mouse position:

```python
screen.fill(GRAY)
screen.blit(img, rect)
pygame.draw.rect(screen, RED, rect, 1)
pygame.draw.line(screen, GREEN, center, mouse, 1)
pygame.draw.circle(screen, RED, center, 6, 1)
pygame.draw.circle(screen, RED, mouse, 6, 1)
pygame.display.update()
```

### **Work with text**

- In pygame, text cannot be written directly to the screen. The first step is to create a `Font` object with a given font size. The second step is to render the text into an image with a given color. The third step is to blit the image to the screen. These are the steps:

```python
font = pygame.font.SysFont(**None**, 24)
img = font.render('hello', **True**, BLUE)
screen.blit(img, (20, 20))
```

- Once the font is created, its size cannot be changed. A `Font` object is used to create a `Surface` object from a string. Pygame does not provide a direct way to write text onto a `Surface` object. The method `render()` must be used to create a Surface object from the text, which then can be blit to the screen. The method `render()` can only render single lines. A newline character is not rendered.
- The function `get_fonts()` returns a list of all installed fonts. The following code checks what fonts are on your system and how many, and prints them to the console:

```python
fonts = pygame.font.get_fonts()
print(len(fonts))
**for** f **in** fonts:
    print(f)
```

### **Render the text**

- The font object can render a given text into an image. In the example below, we place a blue bounding rectangle around that text image:

```python
img = font.render(sysfont, **True**, RED)
rect = img.get_rect()
pygame.draw.rect(img, BLUE, rect, 1)
```

- We then create two more fonts, *Chalkduster* and *Didot* at a size of 72 points. We render a text with both fonts:

```python
font1 = pygame.font.SysFont('chalkduster.ttf', 72)
img1 = font1.render('chalkduster.ttf', **True**, BLUE)

font2 = pygame.font.SysFont('didot.ttc', 72)
img2 = font2.render('didot.ttc', **True**, GREEN)
```

- Finally the text images are blit to the screen like regular images:

```python
screen.fill(background)
screen.blit(img, (20, 20))
screen.blit(img1, (20, 50))
screen.blit(img2, (20, 120))
pygame.display.update()
```

### **Edit text with the keybord**

- The keyboard event can be used to edit a text. First we create a text which we save in a string variable `text` and which we render to an image:

```python
text = 'this text is editable'
font = pygame.font.SysFont(**None**, 48)
img = font.render(text, **True**, RED)
```

- Then we define the bounding rectangle and furthermore a cursor rectangle which is juxtaposed to the text bounding rectangle:

```python
rect = img.get_rect()
rect.topleft = (20, 20)
cursor = Rect(rect.topright, (3, rect.height))
```

- Inside the event loop we watch out for KEYDOWN events. If the key press is a BACKSPACE and the lenght of the string is larger than 0, then we remove the last character, else we append the new character to the text variable:

```python
**if** event.type == KEYDOWN:
    **if** event.key == K_BACKSPACE:
        **if** len(text)>0:
            text = text[:-1]
    **else**:
        text += event.unicode
```

- Then we render the modified text, update the bounding rectangle, and place the cursor box at the end of the updated bounding rectangle:

```python
img = font.render(text, **True**, RED)
rect.size=img.get_size()
cursor.topleft = rect.topright
```

### **Add a blinking cursor**

- In order to make the cursor more visible, we let it blink every 0.5 seconds. We do this using the time.time() floating point value:

```python
screen.fill(background)
screen.blit(img, rect)
**if** time.time() % 1 > 0.5:
    pygame.draw.rect(screen, RED, cursor)
pygame.display.update()
```

### **Create the App class**

- The basis for a game or application is the `App` class. The first thing to do is to import the `pygame` module, as well as a series of useful constants:

```python
**import** **pygamefrom** **pygame.locals** **import** *
```

- Then we create define the App class which initializes Pygame and opens a the app window:

```python
**class** **App**:
    ****def** __init__(self):
				pygame.init()
        flags = RESIZABLE
        App.screen = pygame.display.set_mode((640, 240), flags)

        App.running = **True**
```

- Further we have to define the main event loop:

```python
**def** run(self):
			**while** App.running:
        **for** event **in** pygame.event.get():
            **if** event.type == QUIT:
                App.running = **False**pygame.quit()
```

- At the end of the module we run a demo, if the programm is run directly and not imported as a module:

```python
**if** __name__ == '__main__':
    App().run()
```

### **Add the Text class**

- Now we add some text to the screen. We create a Text class from which we can instantiate text objects:

```python
**class** **Text**:
		  ****def** __init__(self, text, pos, **options):
        self.text = text
        self.pos = pos

        self.fontname = **None**self.fontsize = 72
        self.fontcolor = Color('black')
        self.set_font()
        self.render()
```

- The `Font` object needs to be created initially and everytime the font name or the font size changes:

```python
**def** set_font(self):
				self.font = pygame.font.Font(self.fontname, self.fontsize)
```

- The text needs to be rendered into a surface object, an image. This needs to be done only once, or whenever the text changes:

```python
**def** render(self):
    self.img = self.font.render(self.text, **True**, self.fontcolor)
    self.rect = self.img.get_rect()
    self.rect.topleft = self.pos
```

- Drawing the text means blitting it to the application screen:

```python
**def** draw(self):
    App.screen.blit(self.img, self.rect)
```

### **Shortcut keys**

- Key presses (called shortcuts) can be used to interact with the application and run commands. We can add the following code inside the event loop to intercept the S key and print a message:

```python
**if** event.type == KEYDOWN:
    **if** event.key == K_s:
        print('Key press S')
```

- If the application has many shortcuts, the keys alone may not be enoufht and modifier keys (cmd, ctrl, alt, shift) can be used to increase the number of combinations. The easiest way to represent these shortcuts is under the form of a dictionary, where the key/mod tuples are associated with a command strings. The dictionary has this shape:

```python
self.shortcuts = {
    (K_x, KMOD_LMETA): 'print("cmd+X")',
    (K_x, KMOD_LALT): 'print("alt+X")',
    (K_x, KMOD_LCTRL): 'print("ctrl+X")',
    (K_x, KMOD_LMETA + KMOD_LSHIFT): 'print("cmd+shift+X")',
    (K_x, KMOD_LMETA + KMOD_LALT): 'print("cmd+alt+X")',
    (K_x, KMOD_LMETA + KMOD_LALT + KMOD_LSHIFT): 'print("cmd+alt+shift+X")',
}
```

- Inside the event loop we detect keydown events and call the key handler:

```python
**if** event.type == KEYDOWN:
    self.do_shortcut(event)
```

- The `do_shortcut()` method looks up the shortcut and executes the command string:

```python
**def** do_shortcut(self, event):
		k = event.key
    m = event.mod
    **if** (k, m) **in** self.shortcuts:
        exec(self.shortcuts[k, m])
```

### **Fullscreen, resizable and noframe mode**

- Pygame allows a window to be displayed in 3 different modes:
    - fullscreen mode
    - resizable (a resize edge is displayed)
    - noframe mode (without a window title bar)
- Inside the `App` class `__init__()` method we first define the screen size and the display mode flags, and then create the `screen` surface:

```python
self.flags = RESIZABLE
self.rect = Rect(0, 0, 640, 240)
App.screen = pygame.display.set_mode(self.rect.size, self.flags)
```

- In order to toggle (turn on and off) the three display modes we add these entries to the `shortcuts` dictionary:

```python
(K_f, KMOD_LMETA): 'self.toggle_fullscreen()',
(K_r, KMOD_LMETA): 'self.toggle_resizable()',
(K_g, KMOD_LMETA): 'self.toggle_frame()',
```

- Inside the `App` class we define three methods to toggle the corresponding mode flag, by using the bit-wise XOR operator (`^=`):

```python
**def** toggle_fullscreen(self):
		self.flags ^= FULLSCREEN
    pygame.display.set_mode((0, 0), self.flags)

**def** toggle_resizable(self):
		self.flags ^= RESIZABLE
    pygame.display.set_mode(self.rect.size, self.flags)

**def** toggle_frame(self):
		self.flags ^= NOFRAME
    pygame.display.set_mode(self.rect.size, self.flags)
```

### **Create a graphical user interface (GUI)**

- The graphical user interface (GUI) consists of all the elements the user can interact with (read, click, drag, resize, select, input):
    - text
    - button
    - checkbutton
    - radiobutton
    - menu (pop-up, pull-down)
    - listboxes
    - slider

### **Text attributes**

- We store all pygame text attributes as class variables:

```python
**class** **Text**(Node):
		fontname = **None**
		fontsize = 36
    fontcolor = Color('black')
    background = **None**
    italic = **False**
    bold = **False**
    underline = **False**
```

- After initializing the Node, we update the instance variables from the Text class variables:

```python
super().__init__(**options)
self.__dict__.update(Text.options)
```

- The font size and the three styles (bold, italic, underline) are set at font creation:

```python
**def** set_font(self):
			self.font = pygame.font.Font(self.fontname, self.fontsize)
	   self.font.set_bold(self.bold)
     self.font.set_italic(self.italic)
     self.font.set_underline(self.underline)
```

- The font color and the background color are set when rendering the text:

```python
**def** render(self):
		self.img = self.font.render(self.text, **True**, self.fontcolor, self.background)
    self.rect.size = self.img.get_size()
```

- Here is a code example:

```python
**from** **app** **import** *

**class** **Demo**(App):
    **def** __init__(self):
        super().__init__()
        Scene(caption='Text')
        Text('Default text')
        Text('fontsize = 24', fontsize=24)
        Text('fontcolor = RED', fontcolor=Color('red'))
        Text('48 pts, blue', fontsize=48, fontcolor=Color('blue'))
        Text('fontbg = yellow', fontbg=Color('yellow'))

        Text('italic', pos=(400, 20), italic=**True**)
        Text('bold', bold=**True**)
        Text('underline', underline=**True**, font_bg=**None**)

**if** __name__ == '__main__':
    Demo().run()
```

### **Horizontal and vertical alignment**

- For a given box size, text can be aligned horizontally to the left, center, or right. The following code aligns the text image with these three positions:

```python
w, h = self.rect.size
w0, h0 = self.text_img.get_size()

**if** self.h_align == 0:
    x = 0
**elif** self.h_align == 1:
    x = (w-w0)//2
**else**:
    x = w-w0
```

- In the vertical direction the text image can be aligned at the top, middle or bottom:

```python
**if** self.v_align == 0:
    y = 0
**elif** self.v_align == 1:
    y = (h-h0)//2
**else**:
    y = h-h0

self.img0.blit(self.text_img, (x, y))
self.img = self.img0.copy()
```

- The image img0 is the orignal, used for scaling. The img is the one used for drawing.
- Here is a code example:

```python
**from** **app** **import** *

**class** **Demo**(App):
    **def** __init__(self):
        super().__init__()

        Scene(caption='Text Alignment', bg=Color('pink'))
        Text('left', size=(200, 40), fontsize=24)
        Text('center', h_align=1)
        Text('right', h_align=2)
        Text(bg=Color('blue'), fontcolor=Color('white'))
        
        Text('top', pos=(250, 20), h_align=1)
        Text('middle', v_align=1)
        Text('bottom', v_align=2)
        
**if** __name__ == '__main__':
    Demo().run()
```

### **Text attributes**

- A Text object has various attributes which are remembered.
- Here is a code example:

```python
**from** **app** **import** *

**class** **Demo**(App):
    **def** __init__(self):
        super().__init__()

        Scene(caption='Text', bg=Color('pink'))
        Text(size=(100, 40))
        Text(bg=Color('yellow'), h_align=1)
        Text(fontcolor=Color('red'))
        Text(fontbg=Color('green'), cmd='print(self.text)')

        Text(pos=(200, 20))
        Text(italic=**True**, v_align=1)
        Text(underline=**True**, fontsize=24)
        Text(bold=**True**)
        
**if** __name__ == '__main__':
    Demo().run()
```

### **Editable text**

- The class **`TextEdit`** provides editable text with a movable cursor. The cursor is represented as a small rectangle which is rendered under the text. A selection is represented as a large rectangle under the selected letters.

### **Create the cursor**

- The class attribute `TextEdit.cursor` defines the cursor color and width:

```python
cursor = Color('red'), 2  *# cursor color and width*
```

- Inside the constructor, the cursor is placed at the end of the text. A cursor image is created and filled with the cursor color. The cursor rectangle is initally placed at the end of the text:

```python
col, d = TextEdit.cursor
self.cursor = len(self.text)
self.cursor_img = pygame.Surface((d, self.rect.height))
self.cursor_img.fill(col)
self.cursor_rect = self.cursor_img.get_rect()
self.cursor_rect.topleft = self.rect.topright
```

### **Get the character index**

- The cursor is represented as an integer index in the range [0 .. n] where n is the lenght of the text. Each letter has a different width. The list `self.char_positions` remembers the x position of each letter:

```python
**def** set_char_positions(self):
		self.char_positions = [0]
    **for** i **in** range(len(self.text)):
        w, h = self.font.size(self.text[:i+1])
        self.char_positions.append(w)
```

- When we click with the mouse anywhere in the text, we need to know the character index:

```python
**def** get_char_index(self, position):
		**for** i, pos **in** enumerate(self.char_positions):
        **if** position <= pos:
            **return** i
    *# if not found return the highest index*
    **return** i
```

### **Move the cursor**

- The arrow keys allow to move the cursor to the left or to the right. The argument `d` is 1 or -1 and indicates the direction of movement. The cursor movement is limit to the interval [0 .. n]:

```python
**def** move_cursor(self, d):
		mod = pygame.key.get_mods()
    n = len(self.text)
    i = min(max(0, self.cursor+d), n)
```

- Pressing the CMD key, the cursor goes all the way to the beginning or the end of the line:

```python
**if** mod & KMOD_META:
    **if** d == 1:
        i = n
    **else**:
        i = 0
```

- Pressing the ALT key, the cursor goes to the end of the word:

```python
**if** mod & KMOD_ALT:
    **while** (0 < i < n) **and** self.text[i] != ' ':
        i += d
```

- Pressing the SHIFT key prevents cursor2 from moving, thus setting a selection:

```python
**if** **not** mod & KMOD_SHIFT:
    self.cursor2 = i

self.cursor = i
```

### **Copy, cut and insert text**

- The two cursors can be inverted. The following method returns the two cursors (selection indices) in the right order:

```python
**def** get_selection_indices(self):
		i = self.cursor
    i2 = self.cursor2

    **if** i < i2:
        **return** i, i2
    **else**:
        **return** i2, i
```

- To copy text we save the selection in a Scene variable `text`:

```python
**def** copy_text(self):
		i, i2 = self.get_selection_indices()
    text = self.text[i:i2]
    App.scene.text = text
```

- To cut text we copy the text and replace the selection with an empty string:

```python
**def** cut_text(self):
		self.copy_text()
    self.insert_text('')
```

- To insert text we replace the current selection with the new text:

```python
**def** insert_text(self, text):
		i, i2 = self.get_selection_indices()
    text1 = self.text[:i]
    text2 = self.text[i2:]
    self.text = text1 + text + text2
    self.cursor = i + len(text)
    self.cursor2 = self.cursor
```

### **Buttons**

- The button class displays a text and executes a command upon a mouse-click

### **ListBox**

- The ListBox class displays a list of items. One item can be selected with a mouse-click or with the UP/DOWN arrow keys. Pressing the RETURN key executes the command.

### **Detecting double-clicks**

- In order to detect double-clicks or multiple clicks we need to use a timer event. The reason for using a timer is that we cannot know at the time of a mouse click if there are more clicks to follow. We only know for sure after a short timeout period. So we define a new event as the first USEREVENT:

```python
DBL_CLICK_TIMER = pygame.USEREVENT
DBL_CLICK_TIMEOUT = 250
```

- Inside the `Scene.do_event()` we look for a MOUSEBUTTONDOWN event and we set a timer and increment the clicks:

```python
**if** event.type == MOUSEBUTTONDOWN:
    pygame.time.set_timer(DBL_CLICK_TIMER, DBL_CLICK_TIMEOUT)
    self.clicks += 1
```

### **Playing sound**

- The `pygame.mixer` module allows to play compressed OGG files or uncompressed WAV files.
- This checks the initialization parameters and prints the number of channels available. It opens a sound object and prays it:

```python
print('init =', pygame.mixer.get_init())
print('channels =', pygame.mixer.get_num_channels())
App.snd = pygame.mixer.Sound('5_app/rpgaudio.ogg')
App.snd.play()
print('length =', App.snd.get_length())
```

- Writes this to the console:

```python
init = (22050, -16, 2)
channels = 8
length = 28.437868118286133
```

- Here is a code example:

```python
*"""Play a sound."""***from** **app** **import** *

**class** **Demo**(App):
    **def** __init__(self):
        super().__init__()
        
        print('init =', pygame.mixer.get_init())
        print('channels =', pygame.mixer.get_num_channels())
        App.snd = pygame.mixer.Sound('5_app/rpgaudio.ogg')
        App.snd.play()
        print('length =', App.snd.get_length())

        Scene(caption='Sound mixer')
        Button('Stop', cmd='pygame.mixer.stop()')
        Button('Pause', cmd='pygame.mixer.pause()')
        Button('Unpause', cmd='pygame.mixer.unpause()')
        Button('Fadeout', cmd='pygame.mixer.fadeout(5000)')
        Button('Play', cmd='App.snd.play()')
        Button('Volume 0.1', cmd='App.snd.set_volume(0.1)', pos=(200, 20))
        Button('Volume 0.3', cmd='App.snd.set_volume(0.3)')
        Button('Volume 1.0', cmd='App.snd.set_volume(1.0)')

**if** __name__ == '__main__':
    Demo().run()
