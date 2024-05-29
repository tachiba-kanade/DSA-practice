#include "TextEditor.h"
#include <iostream>
#include <fstream>

void TextEditor::run()
{
    char choice;
    do
    {
        std::cout << "\nSimple Text Editor\n";
        std::cout << "1. Open File\n";
        std::cout << "2. Save File\n";
        std::cout << "3. Append Text\n";
        std::cout << "4. Display Content\n";
        std::cout << "5. Clear Content\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            openFile();
            break;
        case '2':
            saveFile();
            break;
        case '3':
            appendText();
            break;
        case '4':
            displayContent();
            break;
        case '5':
            clearContent();
            break;
        case '6':
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != '6');
}

void TextEditor::openFile()
{
    std::cout << "Enter filename to open: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (file.is_open())
    {
        content.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        std::cout << "File opened successfully.\n";
    }
    else
    {
        std::cout << "Failed to open file.\n";
    }
}

void TextEditor::saveFile()
{
    std::cout << "Enter filename to save: ";
    std::cin >> filename;
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << content;
        file.close();
        std::cout << "File saved successfully.\n";
    }
    else
    {
        std::cout << "Failed to save file.\n";
    }
}

void TextEditor::appendText()
{
    std::cout << "Enter text to append (end with ~ on a new line):\n";
    std::cin.ignore();
    std::string line;
    while (std::getline(std::cin, line) && line != "~")
    {
        content += line + "\n";
    }
}

void TextEditor::displayContent()
{
    std::cout << "\n--- File Content ---\n";
    std::cout << content;
    std::cout << "\n--- End of Content ---\n";
}

void TextEditor::clearContent()
{
    content.clear();
    std::cout << "Content cleared.\n";
}
