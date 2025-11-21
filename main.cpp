#include <iostream>
#include <string>

using namespace std;

enum objectType{ROCK, PAPER, SCISSORS};

void displayRules()
{
    cout << "Welcome to the game of Rock, Paper, "
         << "and Scissors." << endl;
    cout << "This is a game for two players. For each "
         << "game, each" << endl;
    cout << "player selects one of the objects, Rock, "
         << "Paper or Scissors." << endl;
    cout << "The rules for winning the game are: " << endl;
    cout << "1. If both players select the same object, it "
         << "is a tie." << endl;
    cout << "2. Rock breaks Scissors: So player who selects "
         << "Rock wins." << endl;
    cout << "3. Paper covers Rock: So player who selects "
         << "Paper wins." << endl;
    cout << "4. Scissors cut Paper: So player who selects "
         << "Scissors wins." << endl;
    cout << "Enter R or r to select Rock, P or p to select "
         << "Paper, and S or s to select Scissors." << endl;
}

bool validselection(char selection)
{
    switch(selection)
    {
        case 'r':
        case 'R':
        case 'p':
        case 'P':
        case 's':
        case 'S':
            return true;
        default:
            return false;
    }
}

objectType retreivePlay(char selection)
{
    objectType object;
    switch(selection)
    {
        case 'r':
        case 'R':
            object=ROCK;
            break;
        case 'p':
        case 'P':
            object=PAPER;
            break;
        case 's':
        case 'S':
            object=SCISSORS;
            break;
    }
    return object;
}

void convertenum(objectType object)
{
    switch(object)
    {
        case ROCK:
            cout << "Rock";
            break;
        case PAPER:
            cout << "Paper";
            break;
        case SCISSORS:
            cout << "Scissors";
            break;
    }
}

objectType winningObject(objectType play1, objectType play2)
{
    if((play1 == ROCK && play2 == SCISSORS) || (play2 == ROCK && play1 == SCISSORS))
        return ROCK;
    else if((play1 == ROCK && play2 == PAPER) || (play2 == ROCK && play1 == PAPER))
        return PAPER;
    else
        return SCISSORS;
}

void gameresult(objectType play1, objectType play2, int &winner)
{
    objectType winnerobject;
    if(play1 == play2)
    {
        winner = 0;
        cout << "Both Players selected ";
        convertenum(play1);
        cout << endl;
        cout << "It is a Tie" << endl;
    }
    else
    {
        winnerobject = winningObject(play1, play2);
        cout << "Player 1 selected ";
        convertenum(play1);
        cout << endl;
        cout << "Player 2 selected ";
        convertenum(play2);
        cout << endl;
        if(play1 == winnerobject)
            winner = 1;
        else if(play2 == winnerobject)
            winner = 2;
        cout << "Player " << winner << " wins this game" << endl;
    }
}

void displayresult(int gcount, int wcount1, int wcount2)
{
    cout << "The total number of plays: " << gcount << endl;
    cout << "The number of plays won by player 1: " << wcount1 << endl;
    cout << "The number of plays won by player 2: " << wcount2 << endl;
}

bool isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
            return true;
            break;
        default:
            return false;
    }
}

string rotate(string pstr)
{
    string::size_type len = pstr.length();
    string rstr;
    rstr = pstr.substr(1, len-1) + pstr[0];
    return rstr;
}

string pigLatinstring(string pstr)
{
    string::size_type len;
    bool foundVowel;
    string::size_type counter;
    if(isVowel(pstr[0]))
        pstr += "-way";
    else
    {
        pstr += '-';
        pstr = rotate(pstr);
        len = pstr.length();
        foundVowel = false;
        for(counter = 1; counter < len-1; counter++)
            if(isVowel(pstr[0]))
            {
                foundVowel = true;
                break;
            }
            else
                pstr = rotate(pstr);
        if(!foundVowel)
            pstr = pstr.substr(1,len) + "-way";
        else
            pstr = pstr + "ay";
    }
    return pstr;
}



int main()
{
    int gcount=0,wcount1=0,wcount2=0,winner;
    char selection1,selection2,response;
    objectType play1,play2;
    displayRules();
    cout << "Enter (Y/y) if you want to play: ";
    cin  >> response;
    while(response == 'y' || response == 'Y')
    {
        cout << "Player 1 Enter selection: ";
        cin  >> selection1;
        cout << "Player 2 Enter selection: ";
        cin  >> selection2;
        if(validselection(selection1) && validselection(selection2))
        {
            play1=retreivePlay(selection1);
            play2=retreivePlay(selection2);
            gcount++;
            gameresult(play1, play2, winner);
         if(winner == 1)
            wcount1++;
         else if(winner == 2)
            wcount2++;
        }
        cout << "Enter (Y/y) if you want to play: ";
        cin  >> response;
    }
    displayresult(gcount,wcount1,wcount2);


    string str;
    cout << "\n\nEnter a string: ";
    cin  >> str;
    cout << "The pig Latin form of " << str << " is " << pigLatinstring(str) << endl;
    return 0;
}
