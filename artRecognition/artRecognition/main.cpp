//
//  main.cpp
//  artRecognition
//
//  Created by Brandon Widow on 12/4/13.
//  Copyright (c) 2013 Brandon Widow. All rights reserved.
//

/*
 Program requires you to place the licenseplate.txt file onto your Desktop <- *IMPORTANT*
 The file should always be 100 characters in width and 15 characters in height
 
 When changing the licenseplate.txt with characters from the character.txt be sure to copy each line accurately
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <ctype.h>

using namespace std;

int checkString(string N) // This function checks the string and matches it with a premade string, then returns a character to the previous function, giving us our missing license plate value
{
    if(N=="111000000001111100000000001110000111100001100001111000011000000000000110000000000001100001111000011000011110000110000111100001") return 'A';
    if(N=="100000000001111000000000000110000111100001100001111000111000000000001110000111100011100001111000011000000000000110000000000111") return 'B';
    if(N=="111100000011111100000000001110000111100001100001111111111000011111111110000111111111100001111000011100000000001111110000001111") return 'C';
    if(N=="100000000001111000000000000110000111100001100001111000011000011110000110000111100001100001111000011000000000000110000000000111") return 'D';
    if(N=="110000000000111100000000001111000011111111110000111111111100000000111111000011111111110000111111111100000000001111000000000011") return 'E';
    if(N=="100000000000111000000000001110000111111111100001111111111000000011111110000000111111100001111111111000011111111110000111111111") return 'F';
    if(N=="111100000011111100000000001110000111100001100001111111111000011111111110000110000001100001111000011100000000000111110000001101") return 'G';
    if(N=="100001111000011000011110000110000111100001100000000000011000000000000110000111100001100001111000011000011110000110000111100001") return 'H';
    if(N=="110000000000111100000000001111111000011111111110000111111111100001111111111000011111111110000111111100000000001111000000000011") return 'I';
    if(N=="111100000000111111000000001111111111000011111111110000111111111100001111111111000011110000110000111110000000011111110000001111") return 'J';
    if(N=="100001111000011000011100001110000110000111100001000011111000000001111110000100001111100001100001111000011100001110000111100001") return 'K';
    if(N=="100001111111111000011111111110000111111111100001111111111000011111111110000111111111100001111111111000000000000110000000000001") return 'L';
    if(N=="100011111100011000111111000110000111100001100000000000011000100001000110001100110001100011111100011000111111000110001111110001") return 'M';
    if(N=="100011111100011000011111000110000011110001100010011100011000110011000110001110010001100011110000011000111110000110001111110001") return 'N';
    if(N=="111100000011111100000000001110000111100001100001111000011000011110000110000111100001100001111000011100000000001111110000001111") return 'O';
    if(N=="100000000011111000000000001110000111100001100001111000011000000000001110000000001111100001111111111000011111111110000111111111") return 'P';
    if(N=="111100000011111100000000001110000111100001100001111000011000011110000110000110100001100001110000011100000000001111110000001001") return 'Q';
    if(N=="100000000011111000000000001110000111100001100001111000011000000000001110000000001111100001100001111000011100001110000111100001") return 'R';
    if(N=="111100000011111100000000001111000011000011111000011111111111100001111111111110000111110000110000111100000000001111110000001111") return 'S';
    if(N=="100000000000011000000000000111111000011111111110000111111111100001111111111000011111111110000111111111100001111111111000011111") return 'T';
    if(N=="100001111000011000011110000110000111100001100001111000011000011110000110000111100001100001111000011100000000001111110000001111") return 'U';
    if(N=="000111111110000001111111100000011111111000100011111100011000111111000111000111100011111000110001111111000000111111111100111111") return 'V';
    if(N=="100011111100011000111111000110001111110001100011001100011000100001000110000000000001100001111000011000111111000110001111110001") return 'W';
    if(N=="000111111110001000111111000111000111100011111000110001111111000000111111100000000111110001111000111000111111000100011111111000") return 'X';
    if(N=="000111111110001000111111000111000111100011111000110001111111000000111111111000011111111110000111111111100001111111111000011111") return 'Y';
    if(N=="110000000000111100000000001111111110000111111111000011111111100001111111110000111111111000011111111100000000001111000000000011") return 'Z';
    
    if(N=="111100000011111100000000001110000111100001100001110000011000010010000110000011100001100001111000011100000000001111110000001111") return '0';
    if(N=="111110000111111110000001111111111000011111111110000111111111100001111111111000011111111110000111111111100001111111100000000111") return '1';
    if(N=="111000000001111000000000000110000111100001111111110000111111110000111111110000111111110000111111111000000000000110000000000001") return '2';
    if(N=="111000000001111000000000000110000111100001111111110000111111110000011111111111000011100001111000011000000000000111100000000111") return '3';
    if(N=="111111000001111111100000011111100011000111110001110001111000000000000110000000000001111111110001111111111100011111111111000111") return '4';
    if(N=="100000000000011000000000000110000111111111100001111111111000000000001111111111100001100001111000011100000000001111110000001111") return '5';
    if(N=="111100000011111100000000001110000111111111100001111111111000000000011110000111100001100001111000011100000000001111110000001111") return '6';
    if(N=="100000000000011000000000000111111111000011111111100001111111110000111111111000011111111100001111111110000111111111000011111111") return '7';
    if(N=="111100000011111100000000001110000111100001100001111000011110000000011110000111100001100001111000011100000000001111110000001111") return '8';
    if(N=="111000000011111100000000001110000111100001100001111000011100000000000111111111100001100001111000011100000000001111110000001111") return '9';
    
    return '0';
}

int checkSingleNumber(int N[100][15], int X, int Y) // This function will take each character from a 14x9 block of text and add them to an array, then convert the array into a string and sends the string into the checkString function to find out which character the 14x9 block represents
{
    int N_tmp[126]; // Our array, total of 126 spots
    for(int i=0; i<126; i++)
        N_tmp[i]=0; // Clear the array
    int count=0; // Count for each integer added into our array
    
    for(int j=Y; j<(Y+9); j++) // Our Y value, in our 14x9 block we must check 9 rows for integers
    {
        for(int i=X; i<(X+14); i++) // Our X value, in our 14x9 block we must check 14 columns for integers
        {
            N_tmp[count] = N[i][j]; // Adds each individual integer into the array
            count++; // Increases the count for each integer added, should result in 126; 14 x 9 = 126
        }
    }
    
    int size = sizeof(N_tmp) / sizeof(N_tmp[0]);
    char *intstr = new char[size+1];
    intstr[size] = 0;
    for(int i = 0; i < size; i++)
    {
        intstr[i] = '0' + N_tmp[i]; // Adds the contents of our array into a string
    }
    char outcome; // Char that we will be sending back to checkAllNumbers function
    outcome = checkString(intstr); // Sets the output to the result of our checkString function; whatever the string matches with is our character
    return outcome; // Returns the character of the outcome to checkAllNumbers to be displayed with the other license plate values
}

int checkAllNumbers(int N[100][15]) // This function checks each 14x9 block by sending the coordinates to the checkSingleNumber function and displaying the returned outcomes as a lincence plate number
{
    string firstChar, secondChar, thirdChar, fourthChar, fifthChar, sixthChar; // Our 6 license plate values; yet to be determined
    
    firstChar = checkSingleNumber(N, 3, 3); // The first character starts at (3,3) of our 100x15 wall of text
    secondChar = checkSingleNumber(N, 19, 3); // The second character starts at (19,3)
    thirdChar = checkSingleNumber(N, 35, 3); // The third character starts at (35,3)
    fourthChar = checkSingleNumber(N, 51, 3); // The fourth character starts at (51,3)
    fifthChar = checkSingleNumber(N, 67, 3); // The fifth character starts at (67,3)
    sixthChar = checkSingleNumber(N, 83, 3); // And the final character starts at (83,3)

    cout << "license Plate Number: " << firstChar << secondChar << thirdChar << fourthChar << fifthChar << sixthChar << endl; // Displays all the license plate values together
    return 0;
}

int main() // Our main function; displays the license plate and loads the file into an array to be decoded
{
    int N[100][15]; // Our array; the license plate should be 100 x 15 characters
    
    ifstream fp; // File that we are opening
    
    string display; // String we will use to display our license plate
    fp.open("/Users/brandonwidow/Desktop/licenseplate.txt"); // Opens our txt file location; *** rename to /Users/*yourname*/Desktop/licenseplate.txt ***
    for(;;) // While the file is opened...
    {
        fp>>display; // Loads the content of the file into a string
        cout << display << endl; // The string is then displayed in our output window to compare with how the program decodes our license plate
        if( fp.eof()) break; // Stops when reaching the end of the file
    }
    fp.close(); // Closes the file
    
    char character; // The char value we will use to determine our 0's and 1's when loading the file
    fp.open("/Users/brandonwidow/Desktop/licenseplate.txt"); // Our txt file location again; remember to rename
    if( fp.fail() )// If the file fails to open...
    {
        cout << "Unable to open input file." << endl; // Tell the user it cannot open
        return 0; // Stop
    }
    
    for(int i=0; i<15; i++) // Loops through the file for all 15 rows
    {
        for(int j=0; j<100; j++) // Loops through the file for all 100 columns
        {
            fp>>character; // Loads each individual character in the file as a char in our program, places each character into an array as a 0 or 1
            if(character==48) N[j][i] = 0; // If the ASCII code is 48, make the array integer for that spot a 0
            if(character==49) N[j][i] = 1; // If the ASCII code is 49, make the array integer for that spot a 1
            if( fp.eof()) break; // Stops when reaching the end of the file
        }
    }
    fp.close(); // Closes the file
    checkAllNumbers(N); //Sends our array to our checkAllNumbers function to be decoded and will display the 6 license plate values
    return 0;
}

