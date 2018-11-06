// Kenna Draxton
// KEYWORDS 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
    {
    bool playAgain = false;
    //where do you start; where to stop; how do we get there
    for(int i = 0; i<3; i++)
    //i++, i = i+1 same thing
    {
    
    
    
    // Display Title of program to user
    cout<< "\tKeywords 2\n"<<endl;
    // set-up
    const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed
    
    
    //create a collection of 10 words
    vector<string> words;
    words.push_back("ZOOM");
    words.push_back("DOUBLE");
    words.push_back("AGENT");
    words.push_back("EUROPE");
    words.push_back("COVERT");
    words.push_back("BOND");
    words.push_back("PASSPORT");
    words.push_back("UNDERCOVER");
    words.push_back("POLICE");
    words.push_back("INVESTIGATE");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            // word to guess
    int wrong = 0;                               // number of incorrect guesses
    string soFar(THE_WORD.size(), '-');          // word guessed so far
    string used = "";                            // letters already guessed
    //hold the recruit's name in a variable, and address them by it throughout the simulation
    string userName;
    
    
    //ask the recruit to login using their name
    cout<< "Please enter your name:"<<endl;
    cin>> userName;
    cout<< "Hello " << userName << "!\n"<< endl;
    
    //display an overview of Keywords 2 to the user
    cout<< "In this simulation you have to guess what the words are by guessing letters, you will be told along the way if those letters are in your word or not.....\n" << endl;
    
    //display directions on how to play
    cout << "Select letters that you think are part of the coded words, we will place them in the word if they belong and give you another chance!\n" << endl;
    
    
    cout << "Welcome to Keywords 2.  Good luck!\n";
        
        
    
    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
     
        //letting the recruit know they will have three words to guess
        //and what simulation number they are on
        cout << "This is simulation " << i+1 << " of 3."<< endl;
        
        
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;
        
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        //make uppercase since secret word in uppercase
        guess = toupper(guess);
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        
        used += guess;
        
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";
            
            // update soFar to include newly guessed letter
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    
    // shut down
    if (wrong == MAX_WRONG)
        cout << "\nRECRUIT!!! :( !";
    else
        cout << "\nYou guessed it!";
    
    cout << "\nThe word was " << THE_WORD << endl;
    }
    
        //asking the recruit if they want to play again
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
        
        
    
    while (playAgain);
    
    return 0;

}
}
