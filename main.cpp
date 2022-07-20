// Created by Dominic Esposito on 01/02/2022

#include <filesystem>   // For creating folders.
#include <string>       // For string variables.
#include <getopt.h>     // For getopt_long.
#include <windows.h>    // For getting the USERPROFILE and setting up unicode.

static void saveFunction(const std::string& source_folder_end, const std::string& destination_folder)
{
    std::string source_folder; // The savefile's source folder.

    printf("\n  Your files are now being copied. This may take some time depending on your drive type and data size...");

    source_folder = ""; // Makes sure the string is cleared.
    source_folder += std::getenv("USERPROFILE"); // Appends the current account username to the directory.
    source_folder += source_folder_end; // Appends the second half of the directory after the account username.

    if (!std::filesystem::exists(source_folder))
    {
        throw std::runtime_error("Error: The requested game does not have any existing savefiles on your system... Press 'Enter' to exit");
    }

    std::filesystem::copy(source_folder, destination_folder, std::filesystem::copy_options::recursive);

    printf("\n\n  Your files have been successfully copied to the 'Saved' folder. It is highly recommended that you copy\n"
           "  the 'Saved' folder to a USB or external drive.\n\n");
}

static void startupCheck()
{
    opterr = 0;

    if (!std::filesystem::exists("./Saved/"))
    {
        std::filesystem::create_directory("./Saved/");
    }

    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: Unable to create '/Saved/' folder... Press 'Enter' to exit");
    }
}

static void destinationCheck()
{
    if (!std::filesystem::exists("./Saved/"))
    {
        throw std::runtime_error("Error: The '/Saved' folder was modified or removed during program operation... Press 'Enter' to exit");
    }
}

// This is definitely terrible
static void gameCheck(const std::string& games_arg)
{
    if (games_arg == "Crusader Kings III")
    {
        if (std::filesystem::exists("./Saved/Crusader Kings III"))
        {
            printf("\n  Error: The folder '/Saved/Crusader Kings III' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Documents/Paradox Interactive/Crusader Kings III/save games", "./Saved/Crusader Kings III");
        }
    }
    else if (games_arg == "Cyberpunk 2077")
    {
        if (std::filesystem::exists("./Saved/Cyberpunk 2077"))
        {
            printf("\n  Error: The folder '/Saved/Cyberpunk 2077' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/CD Projekt Red", "./Saved/CD Projekt Red");
        }
    }
    else if (games_arg == "DARK SOULS III")
    {
        if (std::filesystem::exists("./Saved/DarkSoulsIII"))
        {
            printf("\n  Error: The folder '/Saved/DarkSoulsIII' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/DarkSoulsIII", "./Saved/DarkSoulsIII");
        }
    }
    else if (games_arg == "DARK SOULS: REMASTERED")
    {
        if (std::filesystem::exists("./Saved/NBGI"))
        {
            printf("\n  Error: The folder '/Saved/NBGI/DARK SOULS REMASTERED' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Documents/NBGI/DARK SOULS REMASTERED", "./Saved/NBGI");
        }
    }
    else if (games_arg == "DOOM (2016)")
    {
        if (std::filesystem::exists("./Saved/DOOM"))
        {
            printf("\n  Error: The folder '/Saved/DOOM' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/id Software/DOOM/", "./Saved/DOOM");
        }
    }
    else if (games_arg == "DOOM Eternal")
    {
        if (std::filesystem::exists("./Saved/DOOMEternal"))
        {
            printf("\n  Error: The folder '/Saved/DOOMEternal' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Saved Games/id Software/DOOMEternal/", "./Saved/DOOMEternal");
        }
    }
    else if (games_arg == "Hearts of Iron IV")
    {
        if (std::filesystem::exists("./Saved/Hearts of Iron IV"))
        {
            printf("\n  Error: The folder '/Saved/Hearts of Iron IV' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Documents/Paradox Interactive/Hearts of Iron IV/save games", "./Saved/Hearts of Iron IV");
        }
    }
    else if (games_arg == "Minecraft")
    {
        if (std::filesystem::exists("./Saved/Minecraft"))
        {
            printf("\n  Error: The folder '/Saved/Minecraft' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/.minecraft/saves", "./Saved/Minecraft");
        }
    }
    else if (games_arg == "Sekiro: Shadows Die Twice")
    {
        if (std::filesystem::exists("./Saved/Sekiro"))
        {
            printf("\n  Error: The folder '/Saved/Sekiro' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/AppData/Roaming/Sekiro", "./Saved/Sekiro");
        }
    }
    else if (games_arg == "The Witcher 3")
    {
        if (std::filesystem::exists("./Saved/The Witcher 3"))
        {
            printf("\n  Error: The folder '/Saved/The Witcher 3' already exists. To prevent data loss, you will be unable to write to the folder until it is removed from '/Saved'...\n\n");
        } else
        {
            destinationCheck();
            saveFunction("/Documents/The Witcher 3/gamesaves", "./Saved/The Witcher 3");
        }
    }
    else
    {
        printf("\n  Error: You have entered an invalid game as an argument. Consider checking the '--games' command...\n\n");
    }
}

static void showAscii()
{
    printf(R"(
   ██████  ▄▄▄    ██▒   █▓▓█████   █████▒██▓ ██▓    ▓█████      ██████  ▄▄▄    ██▒   █▓▓█████  ██▀███
 ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██   ▒▓██▒▓██▒    ▓█   ▀    ▒██    ▒ ▒████▄ ▓██░   █▒▓█   ▀ ▓██ ▒ ██▒
 ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▒████ ░▒██▒▒██░    ▒███      ░ ▓██▄   ▒██  ▀█▄▓██  █▒░▒███   ▓██ ░▄█ ▒
   ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ░▓█▒  ░░██░▒██░    ▒▓█  ▄      ▒   ██▒░██▄▄▄▄██▒██ █░░▒▓█  ▄ ▒██▀▀█▄
 ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░▒█░   ░██░░██████▒░▒████▒   ▒██████▒▒ ▓█   ▓██▒▒▀█░  ░▒████▒░██▓ ▒██▒ v0.3.0

)");
}

static void showHelp()
{
    showAscii();

    printf(" -h, --help     Lists all commands and their functions.\n\n"
           " -s, --save     Select a game to save.\n"
           " -g, --games    Lists all supported games.\n\n");
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
    const char* short_opts = "hs:g";
    const option long_opts[] = {
            {"help",    no_argument,    nullptr, 'h'},
            {"save",    no_argument,    nullptr, 's'},
            {"games",   no_argument,    nullptr, 'g'}
    };
    const auto getopt_init = getopt_long(argc, argv, short_opts, long_opts, nullptr);

    startupCheck();
    SetConsoleOutputCP(CP_UTF8); // Fixes ASCII art not being displayed properly.

    // If no argument has been passed, show help.
    if (argc == 1)
    {
        showHelp();

        return 0;
    }

    while (getopt_init != -1)
    {
        switch (getopt_init)
        {
            default:
                printf("\n  Error: You have entered an invalid argument. Consider checking the '--help' command...\n\n");

                return 0;
            case 'h':
                showHelp();

                return 0;
            case 's':
                gameCheck(optarg);

                return 0;
            case 'g':
                showGames();

                return 0;
        }
    }
}