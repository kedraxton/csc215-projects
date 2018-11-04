// Kenna Draxton
// Code breaker training simulation for CIA recruits

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    //the flag to give the loop clearance
    bool playAgain = false;
    
    do
   {
    //saying that we will loop through 3 times
    for (int i= 0; i < 3; i++)
    {
        //letting the player know they will have three words to guess
        cout << "This is simulation " << i+1 << " of 3."<< endl;
        
        //giving the array categories
        enum fields {WORD, HINT, NUM_FIELDS};
        //telling us there are 10 words to guess from
        const int NUM_WORDS = 10;
        const string WORDS[NUM_WORDS][NUM_FIELDS] =
        //words to guess with their accompanying hints
        
        {
            {"apple","fruit"},
            {"carrot","vegetable"},
            {"dog","animal"},
            {"blue","color"},
            {"square","shape"},
            {"three","number"},
            {"feather","soft"},
            {"cement","hard"},
            {"cactus","Arizona"},
            {"van","car"}

        };
        //seeds the random word from our given array
        srand(static_cast<unsigned int>(time(0)));
        
        int choice = (rand() % NUM_WORDS);
        //word to guess
        string theWord = WORDS[choice][WORD];
         // hint for word
        string theHint = WORDS[choice][HINT];
    
        //word mixed up
        string jumble = theWord;
        int length = jumble.size();
        for (int i=0; i<length; ++i)
        {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }
    
        //intro to player
        cout << "\t\t\tWelcome to CIA code breaker training!\n\n";
        cout << "Decode the three words.\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n\n";
        //showing the word that needs to be decoded
        cout << "The code is: " << jumble;
    
        //users guess
        string guess;
        cout << "\n\nYour guess: ";
        cin >> guess;
    
        
        while ((guess != theWord) && (guess != "quit"))
        {
            if (guess == "hint")
            {
                cout << theHint;
            }
            else
            {
                cout << "Sorry, that's not it.";
            }
            
            cout <<"\n\nYour guess: ";
            cin >> guess;
        }
    
        if (guess == theWord)
        {
            cout << "\nThat's it!  You guessed it!\n";
        }
    
        cout << "\nThanks for playing.\n";
        
    }
       //asking the user if they want to play again
       cout << "would you like to play again: y/n: ";
       char userChoice;
       cin >> userChoice;
        if(userChoice == 'y' || userChoice == 'Y')
        {
            playAgain = true;
        }
       else
       {
           playAgain = false;
       }
         cout << "\nThanks for playing.\n";
   
   
   }while (playAgain);
    return 0;
}
