# Old-School Game Project

# Where is the code?
Inside the "Src" folder. "assets" is also required for, well, the assets of the game. The rest of the files are from Visual Studio (including the solution), (may be) required to run the program on your own machine, so I uploaded them as well just in case.

# What's new?
A lot - but basically in the latest ver. (2/16/2019 3:00AM) we have animated sprites for both player, enemies and map tiles. We can also control the player entity using keyboard controls (WASD), and there's a collision system using 2d vectors implemented as well. There's also an Entity Component System which manages all entities. Oh, and we can load our maps straight out of a text file using a map tile generator in the program, which is pretty cool too.

# Requirements 
For the making of the game we are using [**SDL Library (download link)**](https://www.libsdl.org/download-2.0.php). (**You need to download it from the Development Libraries.**), which has many tutorials you can find on YouTube:
[Tutorial video explaining how to link the library to the project (Visual Studio 2017)](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx) 

It is very important to understand how we install SDL into our IDE.
http://lazyfoo.net/tutorials/SDL/index.php - this website provides the most crucial information about SDL, how to install it and use it. If you prefer a video tutorial you can use the YouTube link above.

It is **strongly recommended** to use Visual Studio 2017 IDE, as most resources we can find online regarding this project will be presented in VS, and it is also highly customizable and allows the use of extensions such as GitHub, Azure, MySQL (Data storage and processing), Gaming Development etc.



# Important Notes

When including your library it has to have a certain location set which later on cannot be changed, so if you reallocate the IDE will give you an error which states that your files are missing. In order to tackle this problem we will have to reallocate the file's location through properties by edit those settings.

We are learning modern C++ 2011 and further so it would be the best we could stick to that and use modern C++ methods rather than traditional coding, for easier code comperhension.

# Tutorials
http://lazyfoo.net/tutorials/SDL/index.php

http://www.sdltutorials.com/sdl-tutorial-basics

https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx

http://www.sdltutorials.com/
