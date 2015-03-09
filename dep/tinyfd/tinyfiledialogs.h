/*
tinyfiledialogs.h
unique header file of the tiny file dialogs library - tinyfd
created [November 9, 2014]
Copyright (c) 2014 - 2015 Guillaume Vareille http://ysengrin.com
http://tinyfiledialogs.sourceforge.net

tiny file dialogs library version 1.10.1 [March 8, 2015] zlib licence.
Cross-platform dialogs in C/C++ WINDOWS OSX GNOME KDE SOLARIS CONSOLE
tinyfd is tested with C & C++ compilers
on Visual Studio 2013 OSX Linux Freebsd Illumos Solaris
using Gnome Kde Enlightenment Mate Cinnamon Unity
Lxde Lxqt Xfce WindowMaker IceWm Cde Jds

A single C file (add it to your project) with
6 modal function calls for all platforms:
- open file dialog (& multiple files)
- save file dialog
- select folder dialog
- message box (& question box)
- input box (& password box)
- color picker.

Independent complement to GLUT, GLUI, VTK, SDL, UNITY3D or any CONSOLE program,
there is NO INIT & NO MAIN LOOP. The dialogs can be forced into console mode.

On Windows:
- native code creates the graphic dialogs (mostly)
- improved console mode can use dialog.exe from
  http://andrear.altervista.org/home/cdialog.php
- basic console inputs.

On Unix we try command line calls:
- zenity
- kdialog
- applescript
- python2/tkinter
- Xdialog
- dialog
- basic console inputs.
The same executable can run across desktops & distributions.
 
- License -

This software is provided 'as-is', without any express or implied
warranty.  In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.  If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef TINYFILEDIALOGS_H
#define TINYFILEDIALOGS_H

/*
if tinydialogs.c is compiled with a C++ compiler
rather than with a C compiler, you need to comment out:
extern "C" {
and the corresponding closing bracket:
}
*/

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */


int tinyfd_messageBox (
    char const * const aTitle , /* "" */
    char const * const aMessage , /* "" may contain \n and \t */
    char const * const aDialogType , /* "ok" "okcancel" "yesno" */
    char const * const aIconType , /* "info" "warning" "error" "question" */
    int const aDefaultButton ) ; /* 0 for cancel/no , 1 for ok/yes */
	/* returns 0 for cancel/no , 1 for ok/yes */

char const * tinyfd_saveFileDialog (
    char const * const aTitle , /* "" */
    char const * const aDefaultPathAndFile , /* "" */
    int const aNumOfFileFilters , /* 0 */
    char const * const * const aFileFilters ) ; /* NULL or {"*.txt"} */

char const * tinyfd_openFileDialog (
    char const * const aTitle , /* "" */
    char const * const aDefaultPathAndFile , /* "" */
    int const aNumOfFileFilters , /* 0 */
    char const * const * const aFileFilters , /* NULL or {"*.jpg","*.png"} */
    int aAllowMultipleSelects ) ; /* 0 or 1 */
	/* in case of multiple files, the separator is | */

char const * tinyfd_selectFolderDialog (
	char const * const aTitle , /* "" */
    char const * const aDefaultPath ) ; /* "" */

char const * tinyfd_inputBox(
	char const * const aTitle , /* "" */
	char const * const aMessage , /* "" may NOT contain \n nor \t */
	char const * const aDefaultInput ) ;  /* "" , if NULL it's a passwordBox */
/* returns NULL on cancel */

char const * tinyfd_colorChooser(
	char const * const aTitle , /* "" */
	char const * const aDefaultHexRGB , /* NULL or "#FF0000" */
	unsigned char aDefaultRGB[3] , /* { 0 , 255 , 255 } */
	unsigned char aoResultRGB[3] ) ; /* { 0 , 0 , 0 } */
	/* returns the hexcolor as a string "#FF0000" */
	/* aoResultRGB also contains the result */
	/* aDefaultRGB is used only if aDefaultHexRGB is NULL */
	/* aDefaultRGB and aoResultRGB can be the same array */

extern int tinyfd_forceConsole ;  /* 0 (default) or 1
can be modified at run time.
for unix & windows: 0 (graphic mode) or 1 (console mode).
0: try to use a graphic solution, if it fails then it uses console mode.
1: forces all dialogs into console mode even when the X server is present,
   if the package dialog (and a console is present) or dialog.exe is installed.
on windows it only make sense for console applications */

/* #define TINYFD_WIN_CONSOLE_ONLY //*/
/* Define this on windows, if you don't want to include the windows code
creating the GUI dialogs.
Then you don't need link to the windows GUI libraries */


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* TINYFILEDIALOGS_H */


/*
- On windows: link against Comdlg32.lib User32.lib and Shell32.lib
  This linking is not compulsary for console mode (see above).
- On unix: it tries command line calls, so no such need.
- On unix you need zenity, kdialog, applescript, python2/tkinter
  Xdialog or dialog.
  One of those is already included on most (if not all) desktops.
- Use windows separators on windows and unix separators on unix.
- char const * fileFilters[3] = { "*.obj" , "*.stl" , "*.dxf" } ;
- String memory is preallocated statically for all the returned values.
- File and path names are tested before return, they are valid.
- If you pass only a path instead of path + filename,
  make sure it ends with a separator.
- tinyfd_forceConsole=1; forces, at run time, all dialogs into console mode.
- On windows, console mode only make sense for console applications.
- Mutiple selects are not allowed in console mode.
- The package dialog must be installed to run in enhanced console mode.
  It is already installed on most unix systems.
- On osx, the package dialog can be installed via http://macports.org
- On windows, for a better console mode,
  dialog.exe should be copied somewhere on your executable path.
  It can be found at the bottom of the following page:
  http://andrear.altervista.org/home/cdialog.php
- If dialog is missing, it will switch to basic console input.

- Here is the Hello World (and a bit more):
    if a console is missing, it will use graphic dialogs
    if a graphical display is absent, it will use console dialogs

#include <stddef.h>
#include "tinyfiledialogs.h"
int main()
{
  tinyfd_forceConsole = tinyfd_messageBox("Hello World",
    "\tIf dialog is installed:\nforce dialogs into console mode?",
    "yesno", "question", 0);
	
  char const * lThePassword =  tinyfd_inputBox(
    "a password box","your password will be revealed",NULL);
	
  if ( lThePassword )
    tinyfd_messageBox("your password is", lThePassword, "ok", "info", 1);
}

on OSX :
$ gcc -o main.app main.c tinyfiledialogs.c
 
on UNIX :
$ gcc -o main main.c tinyfiledialogs.c
 
on WINDOWS just create a console application project with visual studio.
*/
