/**********************************************
* File: Song.cpp
* Author: Connor Ruff
* Email: cruff@nd.edu
* 
* The methods for the Music class are contained here 
**********************************************/
#include "Song.h"

/********************************************
* Function Name  : Default Constructor 
* Pre-conditions : N/A
* Post-conditions: N/A
* 
* Set the private members to empty value if object is created without arguments
********************************************/

Music::Music() : ID(), artist(), title(), album(), year() {}

/********************************************
* Function Name  : Constructor 
* Pre-conditions : unsigned int, std:string (x3), unsigned int
* Post-conditions: N/A
*
* Set the private members equal to the appropriate values as called when
* object was decalred 
********************************************/

Music::Music( unsigned int IDIn, std::string artistIn, std::string titleIn, 
				std::string albumIn, unsigned int yearIn) :
				ID(IDIn), artist(artistIn), title(titleIn),album(albumIn),year(yearIn) {}


/********************************************
* Function Name  : Overloaded Output Operator 
* Pre-conditions : ostream, std::vector<Music>
* Post-conditions: ostream
*
* Prints out the full playlist in a nice format 
********************************************/

 std::ostream& operator<<(std::ostream& os,  const std::vector<Music>& playlist) {
	
	// The Header for each column of data
	os << std::left << std::setw(9) << "Song ID" ;
	os << std::left << std::setw(20) << "Artist" ;
	os << std::left << std::setw(20) << "Title" ;
	os << std::left << std::setw(22) << "Album" ;
	os << std::left << std::setw(4) << "Year" ;
	os << std::endl;
	
	
	// Cycle Through Each Entry In the Playlist
	// and print the data for each
	for(unsigned int i=0; i<playlist.size(); ++i) {
		
		os  << std::left << std::setw(9) << playlist.at(i).ID ; 
		os  << std::left << std::setw(20) << playlist.at(i).artist ;
		os  << std::left << std::setw(20) << playlist.at(i).title ;
		os  << std::left << std::setw(22) << playlist.at(i).album ;
		os  << std::left << std::setw(4) << playlist.at(i).year ;
		os << std::endl;
	} 
	

	
	return os;

}
