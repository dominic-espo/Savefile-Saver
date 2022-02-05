// Created by Dominic Esposito on 01/02/2022

#include <cstdio>       // For text output. The fmt library may be a viable alternative for faster output and colors, but will introduce pretty unnecessary bloat.
#include <filesystem>   // For creating folders.
#include <string>       // For string variables.
#include <windows.h>    // For getting the USERPROFILE, setting up unicode, and changing the terminal name.

struct Variables
{
    std::string sourceFolder;   // The savefile's source folder.
    char userInputC[64] = {};   // Allows for user input.
    int userInputI[64] = {};    // userInput after being converted to an integer.
    bool quit = false;          // Boolean for checking when to stop the program.
};

void startupCheck()
{
    Variables variables;

    if (!std::filesystem::exists("./Saved/"))
    {
        std::filesystem::create_directory("./Saved/");
    }

    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: Unable to create 'Saved' folder.");
    }
}

void destinationCheck()
{
    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: The '/Saved' folder was modified or removed during program operation.");
    }
}

void saveFunction(const std::string& sourceEndInput, const std::string& destFolderInput)
{
    Variables variables;

    printf("\n  Your files are now being copied. This may take some time depending on your drive type and source folder size...");

    variables.sourceFolder = ""; // Makes sure the string is cleared.
    variables.sourceFolder += std::getenv("USERPROFILE");
    variables.sourceFolder += sourceEndInput;

    if (!std::filesystem::exists(variables.sourceFolder))
    {
        throw std::runtime_error("Error: The requested game does not have existing savefiles on your system.");
    }

    std::filesystem::copy(variables.sourceFolder, destFolderInput, std::filesystem::copy_options::recursive);

    printf("\n\n  Your files have been successfully copied to the 'Saved' folder. It is highly recommended that you copy\n"
           "  the 'Saved' folder to a USB or external drive.\n\n"
           " Press 'Enter' to continue...");

    getchar();
}

int userInputFunction()
{
    Variables variables;

    fgets(variables.userInputC, sizeof(variables.userInputC), stdin);
    *variables.userInputI = std::stoi(variables.userInputC);

    return *variables.userInputI;
}

int main()
{
    Variables variables;

    SetConsoleTitle(TEXT("Savefile Saver")); // Sets the terminal name.
    SetConsoleOutputCP(CP_UTF8); // Fixes unicode ASCII art not being displayed properly.

    startupCheck();

    while (!variables.quit)
    {
        if (!std::filesystem::exists("./Saved/"))
        {
            throw std::runtime_error("Error: The '/Saved' folder was modified or removed during program lifetime.");
        }

        printf("\033c"); // ANSI escape code to clear the terminal.
        printf(R"(
    ██████  ▄▄▄    ██▒   █▓▓█████   █████▒██▓ ██▓    ▓█████      ██████  ▄▄▄    ██▒   █▓▓█████  ██▀███
  ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██   ▒▓██▒▓██▒    ▓█   ▀    ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
  ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▒████ ░▒██▒▒██░    ▒███      ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▓██ ░▄█ ▒
    ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ░▓█▒  ░░██░▒██░    ▒▓█  ▄      ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ▒██▀▀█▄
  ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░▒█░   ░██░░██████▒░▒████▒   ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░██▓ ▒██▒ Development Build v0.1.0-alpha.2

)");

        printf(" All currently supported games:\n\n"
               "  1 > Crusader Kings III         | C:/Users/USER/Documents/Paradox Interactive/Crusader Kings III/save games\n"
               "  2 > Cyberpunk 2077             | C:/Users/USER/Saved Games/CD Projekt Red\n"
               "  3 > DARK SOULS III             | C:/Users/USER/AppData/Roaming/DarkSoulsIII\n"
               "  4 > DARK SOULS: REMASTERED     | C:/Users/USER/Documents/NBGI/DARK SOULS REMASTERED\n"
               "  5 > DOOM (2016)                | C:/Users/USER/Saved Games/id Software/DOOM\n"
               "  6 > DOOM Eternal               | C:/Users/USER/Saved Games/id Software/DOOMEternal\n"
               "  7 > Hearts of Iron IV          | C:/Users/USER/Documents/Paradox Interactive/Hearts of Iron IV/save games\n"
               "  8 > Minecraft                  | C:/Users/USER/AppData/Roaming/.minecraft/saves\n"
               "  9 > Sekiro: Shadows Die Twice  | C:/Users/USER/AppData/Roaming/Sekiro\n"
               "  10 > The Witcher 3              | C:/Users/USER/Documents/The Witcher 3/gamesaves\n\n"
               "  0 > Exit\n\n"
               " > ");

        switch (userInputFunction())
        {
            default:
                printf("\n  You have entered an out-of-bounds integer, or a non-integer...");

                getchar();

                break;
            case 0:
                variables.quit = true;

                printf("\n  Thank you for using my program!\n\n"
                       " Press 'Enter' to exit...");

                getchar();

                break;
            case 1: // Crusader Kings III
                if (std::filesystem::exists("./Saved/Crusader Kings III"))
                {
                    printf("\n  Error: The folder '/Saved/Crusader Kings III' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Documents/Paradox Interactive/Crusader Kings III/save games", "./Saved/Crusader Kings III");
                }

                break;
            case 2: // Cyberpunk 2077
                if (std::filesystem::exists("./Saved/Cyberpunk 2077"))
                {
                    printf("\n  Error: The folder '/Saved/Cyberpunk 2077' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Saved Games/CD Projekt Red", "./Saved/CD Projekt Red");
                }

                break;
            case 3: // DARK SOULS III
                if (std::filesystem::exists("./Saved/DarkSoulsIII"))
                {
                    printf("\n  Error: The folder '/Saved/DarkSoulsIII' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/AppData/Roaming/DarkSoulsIII", "./Saved/DarkSoulsIII");
                }

                break;
            case 4: // DARK SOULS: REMASTERED
                if (std::filesystem::exists("./Saved/NBGI"))
                {
                    printf("\n  Error: The folder '/Saved/NBGI/DARK SOULS REMASTERED' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Documents/NBGI/DARK SOULS REMASTERED", "./Saved/NBGI");
                }

                break;
            case 5: // DOOM (2016)
                if (std::filesystem::exists("./Saved/DOOM"))
                {
                    printf("\n  Error: The folder '/Saved/DOOM' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Saved Games/id Software/DOOM/", "./Saved/DOOM");
                }

                break;
            case 6: // DOOM Eternal
                if (std::filesystem::exists("./Saved/DOOMEternal"))
                {
                    printf("\n  Error: The folder '/Saved/DOOMEternal' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Saved Games/id Software/DOOMEternal/", "./Saved/DOOMEternal");
                }

                break;
            case 7: // Hearts of Iron IV
                if (std::filesystem::exists("./Saved/Hearts of Iron IV"))
                {
                    printf("\n  Error: The folder '/Saved/Hearts of Iron IV' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Documents/Paradox Interactive/Hearts of Iron IV/save games", "./Saved/Hearts of Iron IV");
                }

                break;
            case 8: // Minecraft
                if (std::filesystem::exists("./Saved/Minecraft"))
                {
                    printf("\n  Error: The folder '/Saved/Minecraft' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/AppData/Roaming/.minecraft/saves", "./Saved/Minecraft");
                }

                break;
            case 9: // Sekiro: Shadows Die Twice
                if (std::filesystem::exists("./Saved/Sekiro"))
                {
                    printf("\n  Error: The folder '/Saved/Sekiro' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/AppData/Roaming/Sekiro", "./Saved/Sekiro");
                }

                break;
            case 10: // The Witcher 3
                if (std::filesystem::exists("./Saved/The Witcher 3"))
                {
                    printf("\n  Error: The folder '/Saved/The Witcher 3' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...");

                    getchar();
                } else
                {
                    destinationCheck();
                    saveFunction("/Documents/The Witcher 3/gamesaves", "./Saved/The Witcher 3");
                }

                break;
        }
    }

    return EXIT_SUCCESS;
}
