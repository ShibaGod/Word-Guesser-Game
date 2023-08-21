#include <iostream>
#include <vector>
#include <cctype>
#include <array>



class WordGuesser
{
private:
    std::string word;
    std::string blank;
    int tries;
    
public:

    std::string getWord()
    {
        return word;
    }

    void setWord(std::string w)
    {
        word = w;
    }

    void setBlank()
    {
        for (int i{}; i < word.length(); ++i)
        {
            WordGuesser::blank.append("_");
        }
    }

    void setBlank(std::string w)
    {
        blank = w;
    }

    std::string getBlank()
    {
        return WordGuesser::blank;
    }

    void setTries(int x)
    {
        tries = x;
    }

    int getTries()
    {
        return tries;
    }
};

void runGameRound(WordGuesser& w)
{
    std::cout << "You have " << w.getTries() << " chances. " << '\n';
    std::cout << "This is what you have currently." << '\n';
    std::cout << w.getBlank() << '\n';

    std::cout << "Put in your guess: " << '\n';
    char guess{};
    std::cin >> guess;
    guess = static_cast<char>(std::toupper(guess));
    std::string newStr;
    for (size_t i{}; i < w.getWord().length(); ++i)
    {

        if (guess == w.getWord()[i])
        {
            newStr += guess;
        }
        else
        {
            if (w.getWord()[i] != '_')
            {
                newStr += w.getBlank()[i];
            }
            else
            {
                newStr += "_";
            }
        }
    }
    w.setBlank(newStr);
    
}

void playGame(WordGuesser& w)
{
    std::cout << "Let's start. " << '\n';
    std::cout << w.getBlank() << '\n';
    std::cout << "The word is " << w.getBlank().size() << " characters long. " << '\n';
    std::cout << "You start with " << w.getTries() << " chances. " << '\n' <<'\n';

    while (w.getTries() > 0)
    {
        if (w.getBlank() == w.getWord())
        {
            break;
        }
        runGameRound(w);
        w.setTries(w.getTries() - 1);
    }

    std::cout << "You're final answer is: " << w.getBlank() << '\n';

    if (w.getBlank() == w.getWord())
    {
        std::cout << "You win!" << '\n';
    }
    else
    {
        std::cout << "You lose!" << '\n';
    }
}

void startToPlayGame(std::string word, WordGuesser& w)
{
    w.setWord(word);
    w.setBlank();
    w.setTries(static_cast<int>(w.getBlank().size()));
}

void enterWord(WordGuesser& w)
{
    std::cout << "Enter a word: ";
    std::string word{};
    std::cin >> word;

    for (auto& ch : word)
    {
        ch = static_cast<char>(std::toupper(ch));
    }

    startToPlayGame(word, w);
}

void startGame(WordGuesser& w)
{
    std::cout << "Enter a word that you would like to try solving: " << '\n';
    enterWord(w);
  
}








int main()
{
    WordGuesser w;
    startGame(w);
    playGame(w);








    return 0;
}