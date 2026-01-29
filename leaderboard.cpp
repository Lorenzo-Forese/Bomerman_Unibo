#include "include/finestre.h"
#include "include/leaderboard.h"
#include <fstream>
#include <iostream>
using namespace std;

//########################################################################
//### SE NON VEDI I VECCHI PUNTEGGI TOGLI IL COMMENTO DA UNA DELLE DUE ###
//########################################################################

 string filename = "leaderboard.txt" ;   // SE IL FILE ESEGUIBILE e' NELLO STESSO FOLDER DI leaderboard.txt
//string filename = "../leaderboard.txt" ;  // SE IL FILE ESEGUIBILE e' IN UN SUBFOLDER COME /build




void leaderboard::ScriviSuLeaderboard( string newName , int newScore){

	const int MAX = 50;        // maximum number of records
	char names[MAX][50];        // array of C-strings
	int scores[MAX];            // array of integers
	int count = 0;
	
	ifstream infile( filename );
	    if (infile) {
	        while (count < MAX && infile >> names[count] >> scores[count]) {
	            count++;
	        }
	        infile.close();
	    }
	
	    // You cannot use std::cin without <iostream>,
	    // so we simulate the input here ÔÇö replace with real values.
	    // Example:
	    // strcpy(newName, "Alice");
	    // newScore = 42;
	
	    // *** Replace these with your actual input method ***
	    // (If allowed, add #include <iostream> and use cin.)  // TEMP EXIT until input method defined
	
	    // Add new record
	    if (count < MAX) {
	        // Copy name manually
	        int i = 0;
	        while (newName[i] != '\0') {
	            names[count][i] = newName[i];
	            i++;
	        }
	        names[count][i] = '\0';
	        scores[count] = newScore;
	        count++;
	    }
	
	    // ----- Sort by score (descending) -----
	    for (int i = 0; i < count - 1; i++) {
	        for (int j = i + 1; j < count; j++) {
	            if (scores[j] > scores[i]) {
	                // swap score
	                int tempS = scores[i];
	                scores[i] = scores[j];
	                scores[j] = tempS;
	
	                // swap name (C-string copy)
	                char tempN[50];
	                int k = 0;
	                while ((tempN[k] = names[i][k])) k++;
	                k = 0;
	                while ((names[i][k] = names[j][k])) k++;
	                k = 0;
	                while ((names[j][k] = tempN[k])) k++;
	            }
	        }
	    }
	
	    // ----- Rewrite entire file -----
	    std::ofstream outfile( filename );
	    for (int i = 0; i < count; i++) {
	        outfile << names[i] << " " << scores[i] << "\n";
	    }
	    outfile.close();
	
	    return ;
	
}

void leaderboard::print_file_in_window(WINDOW *win) {
    ifstream infile(filename);
    if (!infile) {
        // If the file could not be opened, display an error message in the window
        wprintw(win, "Error opening file: %s\n", filename.c_str());
        wrefresh(win);
        return;
    }

    string line;
    int y = 9;  // Row position in the window
    int max_y, max_x;

    // Get the size of the window
    getmaxyx(win, max_y, max_x);
	wclear(win);
    // Loop through the file, line by line
    while (std::getline(infile, line)) {
        if (y >= max_y - 1) {
            break;  // Stop if we've reached the bottom of the window
        }

        // Ensure we don't print more than the width of the window
        if (line.length() > static_cast<size_t>(max_x - 1)) {
            line = line.substr(0, max_x - 1);  // Truncate line to fit within window
        }
        // Print each line in the window
        mvwprintw(win, y++, (max_x /2) - line.length(), "%s" , line.c_str());
        
        wrefresh(win);
    }

    infile.close();
}
