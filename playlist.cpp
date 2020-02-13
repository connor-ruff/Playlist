/**********************************************
* File: playlist.cpp
* Author: Matthew Morrison, edited by Connor Ruff
* Email: cruff@nd.edu
*  
* This is the main driver for the Music class which creates a playlist of song
**********************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../classes/Song.h"

void getFileStream(int argc, char** argv, std::ifstream& ifs){
	
	// Must be exactly two characters
	if(argc != 2){
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	// Attempt to open the file
	ifs.open (argv[1], std::ifstream::in);
	
	if(!ifs.is_open()){
		std::cout << "Input File Name " << argv[1] << " does not exist\n";
		exit(-1);
	}
	
}

int main(int argc, char** argv){
	
	// Check the input 
	std::ifstream playListIn;
	getFileStream(argc, argv, playListIn);
	
	/***************************************
	 * Initialize an empty song playlist 
	 * using your selected Data Structure
	 * between here and the while loop 
	 ***************************************/
	std::vector<Music> playlist;
	
	// Read in the playlist information 
	while( !playListIn.eof() ){
		
		// Boolean if all checks pass 
		bool checks = true;
		
		// Get the unsigned int from the file 
		std::string readStr;
		
		// First, get the songID 
		std::getline(playListIn, readStr);
		std::stringstream convert(readStr);
		
		// Get all the information for a song 
		unsigned int songID;
		if( !(convert >> songID) ){
			checks = false;
		}
		
		// Use getline for the entire artist's Name 
		std::string artistName;
		std::getline(playListIn, artistName);
		
		// Use getline for the entire song title 
		std::string songTitle;
		std::getline(playListIn, songTitle);
		
		// Use getline for the entire Album Name 
		std::string albumName;
		std::getline(playListIn, albumName);
		
		// First, get the Year 
		std::getline(playListIn, readStr);
		std::stringstream convert2(readStr);
		unsigned int year;
		if( !(convert2 >> year) ){
			checks = false;
		}
		
		// If all checks pass 
		if(checks == true){
			
			/***********************
			* You have everything you need to insert 
			* into a Song class object. You just need 
			* to create the object and insert into the 
			* Data Structure of your choice
			***********************/
		// Create an object of Music class
		Music theEntry(songID, artistName, songTitle, albumName, year);
		// Add it to the playlist vector
		playlist.push_back(theEntry) ;
		}
		
	}
	
	/***********************
	* Now that the playlist is created 
	* print all the objects in the Data Structure
	***********************/
	
	// Print the Playlist
	std::cout << playlist << std::endl;	
}
