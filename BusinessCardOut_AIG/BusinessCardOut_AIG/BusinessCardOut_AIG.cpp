// Ariel Guerrero
// 2/19/2019
//  program that creates a VCard in version 4.0 

// remember fstream for reading files and 
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
		 Class: Main
	Parameters:
   Description: 2/19/2019 Program thats creates a VCARD v4.0 and saves it so the user doesnt have to type it all up
				2/20/2020 Did reading on VCARD
				2/21/2021 Finished cleaning up the code and took some stuff out that wasnt doing anything.

*/
int main()
{

	// file that writes user data  for a vCard to a file.
	ofstream fileVC;

	// always open and close files, name the file something good!
	fileVC.open("AIG_UpgradedBusinessCard.vcf");

	// All VCARDS have a BEGIN: and an END:
	fileVC << "BEGIN:VCARD" << endl;

	// this is a 4.0 version of vcard
	fileVC << "VERSION:4.0" << endl;

	// very basic vcard info
	fileVC << "N:Guerrero;Ariel" << endl;
	fileVC << "ORG:Mobile Mechanic Co." << endl;
	fileVC << "TITLE:Mechanic" << endl;
	fileVC << "TEL;TYPE=work,voice;VALUE=uri:tel: 210-999-9999" << endl;
	fileVC << "TEL;TYPE=home,voice;VALUE=uri:tel: 210-989-8989" << endl;
	fileVC << "EMAIL:aguerrero232@example.com" << endl;
	fileVC << "REV:20080424T195243Z" << endl; // i think this is a time stamp 
	fileVC << "x-qq:21588891" << endl; // 

	//every vcard uses END: 
	fileVC << "END:VCARD " << endl;

	// always close files!
	fileVC.close();

	return 0;
}