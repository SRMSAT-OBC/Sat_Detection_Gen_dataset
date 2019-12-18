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
