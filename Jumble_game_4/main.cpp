#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void theGame(){
    enum fields{Word,Hint,Num_fields};
    const int No_of_words = 5;
    int point = 0;
    int round = 1;
    int lifes = 3;
    const string Words[No_of_words][Num_fields] = 
    {
        {"Jonathan","Main character of the part 1 of JoJo"},
        {"Keyboard","You are using it right now"},
        {"Gravity","Do you believe in _____?"},
        {"Corona","Disease popular right now"},
        {"HelloWorld","First thing you learn while programming"}
    };
    int gamelength = sizeof(Words) / sizeof(Words[0]);
    string theWord,theHint;
    
    while (round <= gamelength && lifes != 0)
    {
        int chosen[gamelength];
        int chosen_1 = 0;
        int i =0;
        srand(static_cast<unsigned int>(time(0)));
        int choice = (rand()% No_of_words);
        while (i< gamelength)
        {
            for (int j=0; j< gamelength; ++j)
            {
                if (chosen[j] == choice)
                {
                    srand(static_cast<unsigned int>(time(0)));
                    choice = (rand()%No_of_words);
                }
                else 
                {
                    theWord = Words[choice][Word];
                    theHint = Words[choice][Hint];
                }
            }
        
            
            
            
            ++i;
        }
        
        cout<<"\t\t\t\t\tRound "<<round;
        cout<<"\n\t\t\t\t\tLifes "<<lifes;
        cout<<"\n\t\t\t\t\tPoints "<<point;
        string jumble = theWord;
        int length = jumble.size();
        for (int i =0; i < length; ++i)
        {
            int index1 = rand()%jumble.size();
            int index2 = rand()%jumble.size();
            char letter = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = letter;
        }
        cout<<"\nEnter 'hint' for hint\n";
        cout<<"\nEnter 'quit' to quit the game\n";
        cout<<"\nThe word is "<<jumble;
        
        string guess;
        cout<<"\nYour guess is ";
        cin>>guess;
        
        while (guess != "quit" && guess != theWord)
        {
            if (guess == "hint")
            {
                cout<<theHint;
            }
            else
            {
                cout<<"You are wrong\n";
                lifes -= 1;
                break;
            }
            cout<<"\nYour guess is ";
            cin>>guess;
        }
        if (guess == "quit")
        {
            break;
        }
        if (guess == theWord)
        {
            cout<<"\nYou guessed the correct word. Congrats\n";
            point += 1;
        }
        round += 1;
        chosen[chosen_1] = choice;
        chosen_1 +=1;
        
    }
    if (lifes == 0)
    {
        cout<<"\nYour life is "<<lifes;
    }
    cout<<"\nThank you for playing this game";
    cout<<"\nYour total score is "<<point<<endl;
} 

int main(){
    
    cout<<"\t\t\t\t Welcome to the Word Jumble Game\n\n";
    cout<<"Unscrabble the letters to make a meaningful word.\n";
    
    cout<<"Enter \n";
    cout<<"\n\t\t\t\t\t1. Start Game\n";
    cout<<"\n\t\t\t\t\t2. Help\n";
    cout<<"\n\t\t\t\t\t3. Quit\n";
    
    int choice;
    cout<<"Enter :";
    cin>>choice;
    switch (choice) {
        case 1 : theGame();
                 break;
        case 2 : cout<<"Help chako ho?";
                 break;
        case 3 : cout<<"La quit handeko";
                 break;
        default : cout<<"Wrong input";
    }
    
    
}


