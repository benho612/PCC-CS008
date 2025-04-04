//
// Created by Ben Ho on 1/10/23.
//
#include "functions.h"
#include <iostream>
std::string getDefaultBoard()
{
    std::string board = "+---+\n"
                        " |    |\n"
                        "      |\n"
                        "      |\n"
                        "      |\n"
                        "      |\n"
                        "=========\n";
    return board;
}
void getInput(char &letter)
{
    std::cin >> letter;
}

char getInput()
{
    char letter;
    getInput(letter);
    return letter;
}

void updateDrawBoard(std::string& board, int misses)
{
    switch(misses) {
        case 1:
            board[15] = '0';
            break;
        case 2:
            board[23] = '|';
            break;
        case 3:
            board[22] = '/';
            break;
        case 4:
            board[24] = '\\';
            break;
        case 5:
            board[30] = '/';
            break;
        case 6:
            board[32] = '\\';
            break;


    }
}

bool inWord(const std::string &word, char letter)
{
    return (word.find(letter) != std::string::npos);

}

void prompt(const std::string &message)
{
    std::cout <<message;

}

std::string getWord(const std::vector<std::string> &words)
{
    return words.at(rand() % words.size());
}

void loadFromFile(const std::string &filename, std::vector<std::string> &words)
{
    std::ifstream fin;
    std::string next;
    if(openFile(fin, filename))
    {
        while(getline(fin,next))
            words.push_back(next);
    }
    closeFile(fin);
}

bool openFile(std::ofstream &out, const std::string &filename)
{
    out.open(filename);
    return !out.fail();
}

bool openFile(std::ifstream &in, const std::string &filename)
{
    in.open(filename);
    return !in.fail();
}

void addWord(const std::string &word, const std::string &filename, std::vector<std::string> &words)
{
    std::ofstream fout;
    if(openFile(fout,filename))
    {
        if(!checkInVec(words,word))
        {
            fout<<word<<std::endl;
            words.push_back(word);
        }
    }
    closeFile(fout);
}
bool checkInVec(const std::vector<std::string>& words, const std::string& word)
{
    
    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i] == word)
            return true;
    }
    return false;
}


void closeFile(std::ofstream &out)
{
    out.close();
}

void closeFile(std::ifstream &in)
{
    in.close();
}

void outputLetterbank(const std::vector<char> &letterbank){
    for(char i : letterbank)
    {
        std::cout<<i << " ";
    }
    std::cout <<std::endl;
}

void updateLetterbank(std::vector<char> &letterbank, char guess){
    letterbank.push_back(guess);
}

void run() {
    std::cout<<"Number of players: \n Enter-1 \n Enter-2 \n";
    int misses = 0, misses1 = 0, numOfPlayer = 0;
    std::cin>>numOfPlayer;
    bool players = switchPlayer(numOfPlayer);
    srand(time(0));
    std::vector<std::string> wordBank;
    std::vector<std::string> wordBank1;
    std::vector<char> letterBank;
    std::vector<char> letterBank1;
    std::string board, realWord, displayWord, board1, realWord1, displayWord1;
    char input;
    board = getDefaultBoard();
    board1 = getDefaultBoard();
    loadFromFile("words.txt", wordBank);
    loadFromFile("words.txt", wordBank1);
    realWord = getWord(wordBank);
    realWord1 = getWord(wordBank1);
    displayWord = getDisplayWord(realWord);
    displayWord1 = getDisplayWord(realWord1);
    bool player1Turn = true;
    while ( !(gameOver(displayWord, misses)) || !(gameOver(displayWord1, misses1))) {
        while (player1Turn && !gameOver(displayWord,misses)) {
            std::cout << "Player 1 Turn!" << std::endl;
            drawBoard(board);
            prompt(displayWord);
            std::cout << std::endl;
            outputLetterbank(letterBank);
            prompt("Player 1: Enter a letter: ");
            getInput(input);
            if (!inWord(realWord, input)) {
                misses++;
                prompt("wrong\n");
                player1Turn = false;
                if(gameOver(displayWord1,misses1))
                {
                    player1Turn = true;
                }
                updateDrawBoard(board, misses);
                updateLetterbank(letterBank, input);
            } else {
                prompt("correct\n");
                updateWord(realWord, displayWord, input);
            }
            std::cout << "______________" << std::endl;
            if (gameOver(displayWord, misses) )
            {
                player1Turn = false;
            }
            if(!players)
            {
                player1Turn = true;
            }
            final(displayWord,misses,board,letterBank);

        }
        while (!player1Turn && !gameOver(displayWord1,misses1)) {
            std::cout << "Player 2 turn!" << std::endl;
            drawBoard(board1);
            prompt(displayWord1);
            std::cout << std::endl;
            outputLetterbank(letterBank1);
            prompt("Player 2: Enter a letter: ");
            getInput(input);
            if (!inWord(realWord1, input)) {
                misses1++;
                prompt("wrong\n");
                player1Turn = true;
                if (gameOver(displayWord, misses)) {
                    player1Turn = false;
                }
                updateDrawBoard(board1, misses1);
                updateLetterbank(letterBank1, input);
            } else {
                prompt("correct\n");
                updateWord(realWord1, displayWord1, input);
            }
            std::cout << "______________" << std::endl;
            if (gameOver(displayWord1, misses1))
            {
                player1Turn = true;

            }
            final(displayWord1,misses1,board1,letterBank1);
        }
        if(!players)
        {
            break;
        }
    }
}

void printWord(const std::string &word) {
    std::cout << word << std::endl;
}

void updateWord(const std::string &word, std::string &displayWord, char guess) {
    if(inWord(word,guess))
    {
        for(int i=0; i<word.size();i++)
        {
            if(word[i] == guess)
            {
                displayWord[i] = guess;
            }
        }
    }
}

std::string getDisplayWord(const std::string &word) {
    std::string dashes;
    for (int i = 0; i < word.length(); ++i) {
        if(word[i] == ' ')
        {
            dashes += ' ';
        }
        else
        {
            dashes += '_';
        }
    }
    return dashes;
}

void drawBoard(std::string &board) {
    std::cout<<board;
}

bool gameOver(std::string displayWord, int misses) {

    return (displayWord.find('_') == std::string::npos || misses >= 6);
}

void final(std::string displayWord, int misses, std::string board, const std::vector<char>& letterBank){
    if (misses >= 6 ) {
        std::cout << "You lose!" << std::endl;
        drawBoard(board);
        prompt(displayWord);
        std::cout << std::endl;
        outputLetterbank(letterBank);
    }
    else if(misses <= 6 && gameOver(displayWord,misses))
    {
        std::cout << "You win!" << std::endl;
        drawBoard(board);
        prompt(displayWord);
        std::cout << std::endl;
        outputLetterbank(letterBank);
    }
}

bool switchPlayer(const int& numOfPlayer)
{
    switch(numOfPlayer)
    {
        case 1:
            return false;
            break;
        case 2:
            return true;
            break;
        default:
            std::cout<<"None of the above\n" << std::endl;
    }
}



