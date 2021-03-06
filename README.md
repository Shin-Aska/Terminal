# Terminal

A **Terminal Library** that aims to unify command line shell commands for manipulating display in a simple class library.

![alt tag](http://i.imgur.com/Uj5ko4L.png?1)

Each terminal emulator has different functions on how they implement text display. Windows and DOS has different semantics
on how you use their Windows Console API compare to the Unix's one. Creating a multi-platform console application that is
capable of displaying colored text puts a burden on the programmer's part and thus this library aims to allevate that burden
by developing a class library that contains functions that works the same on all platforms.


Documentation
===========
Coming soon...


How to use
===========

Programs using the library must first activate the library with the command cnTerm_Activate. This is to indicate that the
library will now be overriding the normal i/o commands of the program. Functions such as *printf* and *cout* might still
work but it is **recommended** that those functions will be unused while this is activated as it might generate an error
on the output of the program.

Once activated, you can now call functions such as *cnPrint()* which will print the text on the screen. Other functions
for manipulation  of input/output exists such as *cnStartPoint()* which specifies which space it will the text display.

For example, compiling this code (Demo - 1.cpp)

```C++

#include "../headers/Terminal"
#include <cstdlib>

int main (void)
{
	cnTerm_Activate;

	cnPrint(RED, "Roses Are Red\n");
	cnStartPoint(1);
	cnPrint(BLUE, "Violets Are Blue\n");
	cnPrint(CYAN, "Sugar is sweet\n");
	cnPrint(PURPLE, "And so are you.");
    getch();
	cnTerm_Deactivate;
}
```

will result in to this.

![alt tag](http://i.imgur.com/1qLDgCT.png)

It is recommended that after the end of the program, you call in cnTerm_Deactivate which removes the override of the normal
i/o commands and returns everything back to normal. Of course more information is provided in the documentation.

Examples
===========

windows/File List - Sample.cpp

A quick demo demonstrating how the library is used to mimic Unix's ls utility program
![alt tag](http://i.imgur.com/gKAPExj.png?1)

windows/GladOS + Multi Media - Sample.cpp

A quick demo how the library is used to copy the ending credits of portal.
![alt tag](http://i.imgur.com/qSo19ZP.png?1)

