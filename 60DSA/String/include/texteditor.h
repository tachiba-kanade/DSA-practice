#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string>

class TextEditor
{
public:
    void run();

private:
    std::string filename;
    std::string content;

    void openFile();
    void saveFile();
    void appendText();
    void displayContent();
    void clearContent();
};

#endif // TEXTEDITOR_H
