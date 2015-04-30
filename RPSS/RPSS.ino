/*
Justien J. Young Esq.

Program: Responsible Patrons Storage System ~> RPSS
Decription: This program handle the comunication between the componits of the RPSS

Program started: January  14, 2015 3:34 PM ~> started building RPSS program (Arduino)
																		~> worked on structer 
																~>  3:37 PM ~> end
Program edited: February 19, 2015 9:55 PM ~> Adding class's to arduino libraries
																	~> constucting RPSS in arduino IDE
																	~> added class: 
																		~> FingerScanner
																		~> Cabnet
																		~> Breath
																	~> Learned how header files are writtin in the arduino IDE
																		~> Example
																				~> #include "Cabnet.h"
																						~> can be used in its class, but not in others
																				~> #include <Cabnet\Cabnet.h>
																						~> must be used in other classes
																	~> All code for class's in arduino library
																	~> Errors still showing
																			~> Example:
																					~> 	1	IntelliSense: expected a '{'	c:\program files (x86)\arduino\hardware\tools\avr\avr\include\stdlib.h	106
																			~> header files
																					~> #include <stdarg.h> // add to see it will fix error
																					~> #include <stdlib.h> // add to see it will fix error
																					~> not shere how to fix
																	~> February 20, 2015 12:15 AM ~> end
Program edited: February 20, 2015 9:30 PM ~> Checking code in arduino
																		 ~> setting out pins 
																		 ~> converting  cout to Serial.println()
																		 ~> converting cin to () = = analogRead()
																 ~>  10:30 PM ~> end
Program edited: February 20, 2015 11:30 PM ~> Changing library folder
																			~> Moving library files
																					~> Moved Breath & Cabnet in to FingerScanner
																	~> 11:35 PM ~> end
Program edited: February 21, 2015 12:00 PM ~> Changing library folder
																			~> Moving library files
																					~> Created new library folder
																							~> RPSS
																					~> Moved all .h &  . cpp files from FingerScanner in to RPSS
																			~> Cabnet
																	~> 12:05 PM> end
Program edited: February 22, 2015 11:30 AM ~> Checking code in arduino
																		~> Checked Arduino site 
																				~> http://playground.arduino.cc/Code/Library
																		~> Fixed header file calls
																		~> Error: Output
																				~> Compiling 'RPSS' for 'Arduino Uno'
																				~> core.a(main.cpp.o)*:In function `main'
																				~> main.cpp:undefined reference to `loop'
																				~> Error creating .elf
																		~> Found posoble fix for error:
																				~> http://erasesoftware.com/arduino-error-compiling-core-amain-cpp-o-in-function-main/
																		~> 12:57 PM ~> end
Program edited: February 22, 2015 9:32 PM ~> Cleaning up code in the class's:
																		~> FingerScanner
																		~> Cabnet
																		~> Breath
																~> Error: Output still unresolved
																		~> Compiling 'RPSS' for 'Arduino Uno'
																		~> core.a(main.cpp.o)*:In function `main'
																		~> main.cpp:undefined reference to `loop'
																		~> Error creating .elf
																~> Error may be on my end
																~> Once code in class's is corrected it will be sent to team members
																~> Checked main.cpp file: 
																		~> C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino
																~> After carfuly revewing the code I found the sourcce of the error
																		~> argumint's placed in the void loop()
																				~> int &scan, int &breath
																				~> previnded the code from properly compiling
																		~> Error fixed
																~> Will test Wind class in RPSS (C++) before inpliminting in RPSS
																~> 10:50 PM ~> end
Program edited: February 23, 2015 4:20 AM ~> Adding class
																		~> Wind
																		~> Test sucsessful.
																				~> in C++
																 ~> Changing in/out put
																		~> converting  cout to Serial.println()
																		~> converting cin to () = analogRead()
																 ~> Removing
																		~> #include "StdAfx.h"
																		~> #include <iostream>
																		~> using namespace std;
																 ~> Addding
																		~> #include <Arduino.h>
																~> Test sucsessful.
																		~> in Arduino
																				~> Compiling 'RPSS' for 'Arduino Uno'
																				~> Binary sketch size: 3,668 bytes (used 11% of a 32,256 byte maximum) (0.51 secs)
																 ~> 4:34 PM ~> end
*/

#include "Boards.h"
#include <Arduino.h>
#include  "FingerScanner.h"

//Class's created in numericall order.
	FingerScanner
		scanner;
				
	/*Breath
           dyb;
           
        Cabnet
          cab;*/

int
  scan = 2,
  breath = 3,
  lock = 4, 
  unlock = 5;

void setup()
{

	//Serial .begin(9600);

	pinMode(scan,OUTPUT);

	pinMode(breath,OUTPUT);

	pinMode(lock,OUTPUT);

	pinMode(unlock,OUTPUT);

}

void loop(/*int &scan, int &breath*/)
{

	//scan = analogRead(A0);
  //Serial.println(scan);
	//breath = analogRead(A1);
  //Serial.println(breath);
	//lock = analogRead(A2);
  //Serial.println(lock);
	//unlock = analogRead(A3);
  //Serial.println(unlock);
	//windSpeed = analogRead(A4);
  //Serial.println(windSpeed);
	
	//Serial.println(" For testing: \n \t\t1 > in data base/pass \n \t\t0 > not in data base/faile \n");
	/*
	Serial.println(" Hello, Patron \n\n";
	Serial.println(" Welcome to The Responsible Patrons Storage System \n\n"); 
	*/
	
	scanner.Scan(scan,breath);
	
	//system("pause"); 

}
