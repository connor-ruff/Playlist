/**********************************************
* File: Song.h
* Author: Connor Ruff
* Email: cruff@nd.edu
* 
* The header file for the Music class 
**********************************************/

#ifndef SONG_H
#define SONG_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

class Music{
	
	private:
		unsigned int ID;
		std::string artist;
		std::string title;
		std::string album;
		unsigned int year;

	public:
	

	Music() ;
	Music( unsigned int, std::string, std::string, std::string, unsigned int);
	
	friend std::ostream& operator<<(std::ostream&, const std::vector<Music>&);			

	
};

#endif
