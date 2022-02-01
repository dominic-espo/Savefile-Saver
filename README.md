# Savefile Saver

I created this project as a solution to a simple, but annoying problem: Backing up my game savefiles. I wanted to be able to copy all of my
saved data from a game, into a folder, where I could then put it onto a USB as a backup. It's certainly possible to do manually, but all of
that becomes tedious after a while. So, Savefile Saver was born.

### Requirements

* Compiler that supports the Windows API, and C++20
* CMake 3.21.1 =<
* Windows 7 =<

*It may be possible to use Windows versions lower than this, but versions lower than 7 have not been tested, and may have critical bugs that
cause data loss.*

### Installation

You can download a binary release from the [release](https://github.com/DrakoDom/Savefile-Saver/releases/ "Releases") page, or compile from source.

To compile from source, you can use any compiler that supports the Windows API. All you need is the `main.cpp` file. You can also use the included
`CMakeLists.txt` file if needed.

Now, it is possible to modify this source for use on Linux. The reason this program uses the Windows API, is so that the %USER% environment
variable can be fetched, unicode can be displayed properly, and the terminal can have a custom name. So, to get this program running on a Linux
machine, you would need to remove `SetConsoleTitle(TEXT("Savefile Saver"))` and `SetConsoleOutputCP(CP_UTF8)` then modify the use of
`std::getenv("USERPROFILE")` somehow.

This would require a lot of work for a very small amount of users. I use Linux myself, but not for gaming. That's why I have Windows. So, I have
not explored this route yet. But feel free to do so yourself in a fork of this project.