# Sat_Detection_Gen_dataset
Add other members and make this private repo
This project will create dataset to train ML model for tracking of satellite

I have created a program to rotate and zoom a cube using OpenGL and PyGame. You have to
1. Create a button to take screenshots of current sceen
  a. make sure the button's position is static wrt the screen
  b. the screenshot crops the button
2. Create a function to randomly rotate and zoom the cube after each screenshot
  a. I have already implemented the rotation part, except currently it rotates after giving actual input, you just have to give the keyboard signal by software or edit few variables which are rotating the cube.
  b. If possible, add noise to the screenshots to augument stars. We can always make another program for this, it's be easier. Just remember to invoke the other program after saving the screenshots.

3. Add skin to the cube. Currently the cube is just a wireframe and there are ways to add a surface by choosing 3 points in OpenGL
  a. Preferable use the skins as PNG, all kept in a folder so that we can just change the images and re-run the program to get new data.

UPDATE


@priyam314
priyam314 Add files via upload

Update to Sat_Detection_Gen_Dataset
A workspace for rotating cube has been built. Three buttons, one for screenshot which is working absolutely fine, second to close the particular workspace and third for the random function(this has no functionality yet), an image has also been added in place of rotating cube. 
The project thereof is programmed in Python using pygame and os modules.
The very next step is to link the rotating cube code to sat_detection_obc.py and complete the functionality of the "random" button, such that our cube will rotate in any direction specified or unspecified.

UPDATE



@GeNeRaL-ShAdOw
GeNeRaL-ShAdOw Add files via upload

@GeNeRaL-ShAdOw
Update to Sat_Detection_Gen_Dataset
Another code has been uploaded, with help from tutorials for the rotating cube.The screenshot function, however is still to be fulfilled.

UPDATE

A bug has been fixed.

UPDATE

The colour cube has been uploaded, although its not user modifiable.
