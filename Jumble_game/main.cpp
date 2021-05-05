#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    enum fields{Word,Hint,Num_fields};
    const int No_of_words = 5;
    const string Words[No_of_words][Num_fields] = 
    {
        {"Jonathan","Main character of the part 1 of JoJo"},
        {"Keyboard","You are using it right now"},
        {"Gravity","Do you believe in _____?"},
        {"Corona","Disease popular right now"},
        {"HelloWorld","First thing you learn while programming"}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand()% No_of_words);
    string theWord = Words[choice][Word];
    string theHint = Words[choice][Hint];

    string jumble = theWord;
    int length = jumble.size();
    for (int i = 0; i<length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char letter = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = letter;
    }

    cout<<"\t\t\t\t Welcome to the Word Jumble Game\n\n";
    cout<<"Unscrabble the letters to make a meaningful word.\n";
    cout<<"Enter 'hint' for a hint.\n";
    cout<<"Enter 'quit' to quit the game.\n";
    cout<<"The word is "<<jumble;

    string guess;
    cout<<"\nYour guess is ";
    cin>>guess;

    while (guess != theWord && guess != "quit")
    {
        if (guess == "hint")
        {
            cout<< theHint;
        }
        else
        {
            cout<<"Sorry that's not it.";
        }
        cout<<"\nYour guess is ";
        cin>>guess;
    }
    if (guess == theWord)
    {
        cout<<"\nYou guessed the correct word. Congrats";
    }
    cout<<"\nThanks for playing this game.\n";

    return 0;
}
