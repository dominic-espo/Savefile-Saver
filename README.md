# Savefile Saver

I created this project as a solution to a simple, but annoying problem: Backing up my game savefiles. I wanted to be able to copy all of my
saved data from a game, into a folder, where I could then put it onto a USB as a backup. It's certainly possible to do manually, but it becomes
tedious after a while. So, Savefile Saver was born.

### Requirements

* Windows 7 =<

*It may be possible to use Windows versions lower than this, but versions lower than 7 have not been tested*

### Installation

You can download a binary release from the [release](https://github.com/DrakoDom/Savefile-Saver/releases/ "Releases") page, or compile from source.

To compile from source, you can use any compiler that supports the Windows API. Now, it is possible to modify this source for use on Linux. The only
reason this program uses the Windows API, is so that the %USER% environment variable can be fetched. So, to get this program running on a Linux
machine, you would need to modify the use of `std::getenv("USERPROFILE")` somehow. I have no explored this route yet. But feel free to do so yourself.