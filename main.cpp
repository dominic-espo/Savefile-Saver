// Created by Dominic Esposito on 01/02/2022

#include <iostream>     // For text output. The fmt library may be a viable alternative for faster output and colors, but will introduce unnecessary bloat.
#include <filesystem>   // For creating folders.
#include <string>       // For string variables.
#include <algorithm>    // For std::find.
#include <windows.h>    // For getting the USERPROFILE and setting up unicode.

struct Variables
{
    std::string sourceFolder;   // The savefile's source folder.
    std::string userInput;      // For user input.
};

static void saveFunction(const std::string& sourceFolderEnd, const std::string& destFolder)
{
    Variables variables;

    printf("\n  Your files are now being copied. This may take some time depending on your drive type and data size...");

    variables.sourceFolder = ""; // Makes sure the string is cleared.
    variables.sourceFolder += std::getenv("USERPROFILE"); // Appends the current account username to the directory.
    variables.sourceFolder += sourceFolderEnd; // Appends the second half of the directory after the account username.

    if (!std::filesystem::exists(variables.sourceFolder))
    {
        throw std::runtime_error("Error: The requested game does not have any existing savefiles on your system...");
    }

    std::filesystem::copy(variables.sourceFolder, destFolder, std::filesystem::copy_options::recursive);

    printf("\n\n  Your files have been successfully copied to the 'Saved' folder. It is highly recommended that you copy\n"
           "  the 'Saved' folder to a USB or external drive.\n\n"
           " Press 'Enter' to exit...");

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void startupCheck()
{
    Variables variables;

    if (!std::filesystem::exists("./Saved/"))
    {
        std::filesystem::create_directory("./Saved/");
    }

    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: Unable to create '/Saved/' folder...");
    }
}

static void destinationCheck()
{
    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: The '/Saved' folder was modified or removed during program operation...");
    }
}

// This is definitely terrible
static void gameCheck()
{
    Variables variables;

    printf("  If you're not sure what games are supported, exit, and run the --games command"
           "\n\n > ");

    // Gets the entire line of user input (including spaces).
    std::getline(std::cin, variables.userInput);

    if (variables.userInput == "Crusader Kings III")
    {
        if (std::filesystem::exists("./Saved/Crusader Kings III"))
        {
            printf("\n  Error: The folder '/Saved/Crusader Kings III' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Documents/Paradox Interactive/Crusader Kings III/save games", "./Saved/Crusader Kings III");
        }
    }
    else if (variables.userInput == "Cyberpunk 2077")
    {
        if (std::filesystem::exists("./Saved/Cyberpunk 2077"))
        {
            printf("\n  Error: The folder '/Saved/Cyberpunk 2077' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/CD Projekt Red", "./Saved/CD Projekt Red");
        }
    }
    else if (variables.userInput == "DARK SOULS III")
    {
        if (std::filesystem::exists("./Saved/DarkSoulsIII"))
        {
            printf("\n  Error: The folder '/Saved/DarkSoulsIII' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/DarkSoulsIII", "./Saved/DarkSoulsIII");
        }
    }
    else if (variables.userInput == "DARK SOULS: REMASTERED")
    {
        if (std::filesystem::exists("./Saved/NBGI"))
        {
            printf("\n  Error: The folder '/Saved/NBGI/DARK SOULS REMASTERED' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Documents/NBGI/DARK SOULS REMASTERED", "./Saved/NBGI");
        }
    }
    else if (variables.userInput == "DOOM (2016)")
    {
        if (std::filesystem::exists("./Saved/DOOM"))
        {
            printf("\n  Error: The folder '/Saved/DOOM' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/id Software/DOOM/", "./Saved/DOOM");
        }
    }
    else if (variables.userInput == "DOOM Eternal")
    {
        if (std::filesystem::exists("./Saved/DOOMEternal"))
        {
            printf("\n  Error: The folder '/Saved/DOOMEternal' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/id Software/DOOMEternal/", "./Saved/DOOMEternal");
        }
    }
    else if (variables.userInput == "Hearts of Iron IV")
    {
        if (std::filesystem::exists("./Saved/Hearts of Iron IV"))
        {
            printf("\n  Error: The folder '/Saved/Hearts of Iron IV' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Documents/Paradox Interactive/Hearts of Iron IV/save games", "./Saved/Hearts of Iron IV");
        }
    }
    else if (variables.userInput == "Minecraft")
    {
        if (std::filesystem::exists("./Saved/Minecraft"))
        {
            printf("\n  Error: The folder '/Saved/Minecraft' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/.minecraft/saves", "./Saved/Minecraft");
        }
    }
    else if (variables.userInput == "Sekiro: Shadows Die Twice")
    {
        if (std::filesystem::exists("./Saved/Sekiro"))
        {
            printf("\n  Error: The folder '/Saved/Sekiro' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/Sekiro", "./Saved/Sekiro");
        }
    }
    else if (variables.userInput == "The Witcher 3")
    {
        if (std::filesystem::exists("./Saved/The Witcher 3"))
        {
            printf("\n  Error: The folder '/Saved/The Witcher 3' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else
        {
            destinationCheck();
            saveFunction("/Documents/The Witcher 3/gamesaves", "./Saved/The Witcher 3");
        }
    }
}

static void showAscii()
{
    printf(R"(
   ██████  ▄▄▄    ██▒   █▓▓█████   █████▒██▓ ██▓    ▓█████      ██████  ▄▄▄    ██▒   █▓▓█████  ██▀███
 ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██   ▒▓██▒▓██▒    ▓█   ▀    ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
 ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▒████ ░▒██▒▒██░    ▒███      ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▓██ ░▄█ ▒
   ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ░▓█▒  ░░██░▒██░    ▒▓█  ▄      ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ▒██▀▀█▄
 ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░▒█░   ░██░░██████▒░▒████▒   ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░██▓ ▒██▒ v0.3.0-alpha.1

)");
}

static void showHelp()
{
    showAscii();

    printf(" --help     Lists all commands and their functions.\n\n"
           " --save     Select a game to save.\n"
           " --games    Lists all supported games.\n\n");
}

static void showGames()
{
    showAscii();

    printf("  Crusader Kings III         | C:/Users/USER/Documents/Paradox Interactive/Crusader Kings III/save games\n"
           "  Cyberpunk 2077             | C:/Users/USER/Saved Games/CD Projekt Red\n"
           "  DARK SOULS III             | C:/Users/USER/AppData/Roaming/DarkSoulsIII\n"
           "  DARK SOULS: REMASTERED     | C:/Users/USER/Documents/NBGI/DARK SOULS REMASTERED\n"
           "  DOOM (2016)                | C:/Users/USER/Saved Games/id Software/DOOM\n"
           "  DOOM Eternal               | C:/Users/USER/Saved Games/id Software/DOOMEternal\n"
           "  Hearts of Iron IV          | C:/Users/USER/Documents/Paradox Interactive/Hearts of Iron IV/save games\n"
           "  Minecraft                  | C:/Users/USER/AppData/Roaming/.minecraft/saves\n"
           "  Sekiro: Shadows Die Twice  | C:/Users/USER/AppData/Roaming/Sekiro\n"
           "  The Witcher 3              | C:/Users/USER/Documents/The Witcher 3/gamesaves\n\n");
}

int main(int argc, char* argv[])
{
    Variables variables;

    int i = 0;

    SetConsoleOutputCP(CP_UTF8); // Fixes unicode ASCII art not being displayed properly.
    startupCheck();

    // If no argument has been passed, show help.
    if (argc == 1)
    {
        showHelp();

        return 0;
    }

    // Checks if the help argument has been passed.
    for (i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            showHelp();

            return 0;
        }
    }

    // Checks for all other arguments.
    for (i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--games") == 0)
        {
            showGames();

            return 0;
        }

        if (strcmp(argv[i], "--save") == 0)
        {
            showAscii();

            // This is definitely terrible
            gameCheck();

            return 0;
        }
    }
}