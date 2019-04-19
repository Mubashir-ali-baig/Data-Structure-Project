#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;
#include "game.h"
#include "UserAccount.h"
#include "ControlTowerCrew.h"
#include "Avl.h"
#include "AircraftCrew.h"
#include "quiz.h"
#include "pessenger.h"


int main()
{
char ch;
cout<<"\t\t\t\t***WELCOME TO AIRPORT SIMULATOR PROGRAM***\t\t\t\t"<<endl; 
cout<<endl;
A3:cout<<"\t\t\t\t***CHOOSE YOUR OPTIONS TO PROCEED***\t\t\t\t"<<endl;
cout<<endl;
cout<<"\t\t\t\t***Press a to Signup***\t\t\t\t"<<endl;
cout<<"\t\t\t\t***Press b to Login***\t\t\t\t"<<endl;
cout<<"\t\t\t\t***Press c to Exit***\t\t\t\t"<<endl;
cout<<"\t\t\t\t";
ch=getch();
switch(ch)
{
case 'a':
	{
	 useraccount un;
	 un.signup();
	 goto A3;
	 break;
	}
case 'b':
	{
	 int a;
		useraccount un;
	 a=un.login();
	 if(a==0)
	 {
	  goto A3;
	  break;
	 }
	 else
	 {
a2: 
	  cout<<endl;
	  cout<<"\t\t\t\t***Press a to play as a Pessenger***\t\t\t\t"<<endl;
      cout<<"\t\t\t\t***Press b to play as a Control Tower Crew***\t\t\t\t"<<endl;
      cout<<"\t\t\t\t***Press c to play as an Aircraft Crew***\t\t\t\t"<<endl;
	  cout<<"\t\t\t\t***Press d to Logout***\t\t\t\t"<<endl;
	  cout<<"\t\t\t\t";
	  ch=getch();
	  cout<<endl;
      switch(ch)
	  {
	  case 'a':
		  {
a1:         cout<<endl;
			cout<<"\t\t\t\t***Press a to View Flights***\t\t\t\t"<<endl;
            cout<<"\t\t\t\t***Press b to Book a Flight***\t\t\t\t"<<endl;
            cout<<"\t\t\t\t***Press c to Play the Puzzle***\t\t\t\t"<<endl;
			cout<<"\t\t\t\t***Press d to exit Pessenger mode***\t\t\t\t"<<endl;
			cout<<"\t\t\t\t";
			ch=getch();
			switch(ch)
			{
			case 'a':
				{
				 ControlTowerCrew ct;
				 ct.ViewFlights();
				 goto a1;
				 break;
				}
			case 'b':
				{
				 pessenger ps;
				 ps.BookFlight();
                 goto a1;
				 break;
				}
			case 'c':
				{
				 pessenger ps;
				 ps.PLayToEarn();
				 goto a1;
				 break;
				}
			case 'd':
				{
				 goto a2;
				 break;
				}
			default:
				{
				 cout<<"\t\t\t\t***Wrong choice Choose Again***\t\t\t\t"<<endl;
				 goto a1;
				}
			}
		  break;
		  }
	  case 'b':
		  {
a3:         cout<<endl;
			cout<<"\t\t\t\t***Press a to View Flights***\t\t\t\t"<<endl;
            cout<<"\t\t\t\t***Press b to Add Flight***\t\t\t\t"<<endl;
            cout<<"\t\t\t\t***Press c to Delete a Flight***\t\t\t\t"<<endl;
			cout<<"\t\t\t\t***Press d to exit Control Tower Crew mode***\t\t\t\t"<<endl;
		    cout<<"\t\t\t\t";
			ch=getch();
			switch(ch)
			{
			case 'a':
				{
				 ControlTowerCrew ct;
				 ct.ViewFlights();
				 goto a3;
				 break;
				}
			case 'b':
				{
				 ControlTowerCrew ct;
				 ct.addFlights();
				 goto a3;
				 break;
				}
			case 'c':
				{
				 ControlTowerCrew ct;
				 ct.DequeueFlight();
				 goto a3;
				 break;
				}
			case 'd':
				{
				 goto a2;
				 break;
				}
			default:
				{
				 cout<<"\t\t\t\t***Wrong Choice Choose Again***\t\t\t\t"<<endl;
				 goto a3;
				}
			}
			break;
		  }
	  case 'c':
		  {
		   a4:cout<<"\t\t\t\t***Press a to Play the AVL Puzzle***\t\t\t\t"<<endl;
		   cout<<"\t\t\t\t***Press b to Exit the Air Craft Crew Mode***\t\t\t\t"<<endl;
		   cout<<"\t\t\t\t";
		   ch=getch();
		   switch(ch)
		   {
		   case 'a':
			   {
			    AircraftCrew ac;
				ac.BalanceTheAircraft();
				goto a4;
				break;
			   }
		   case 'b':
			   {
			    goto a2;
				break;
			   }
		   default:
			   {
			    cout<<"\t\t\t\t***Wrong Choice Choose Again***\t\t\t\t"<<endl;
				goto a4;
			   }
		   }
		  break;
		  }
	  case 'd':
		  {
		   goto A3;
		   break;
		  }
	  }
	 }
	 break;
    }
case 'c':
	{
	 exit(0);
	}
default:
	{
	 cout<<"\t\t\t\t***No such Choice Available***\t\t\t\t"<<endl;
	 goto A3;
	}
}
//useraccount un;
 //un.login();
 //un.signup();
//ControlTowerCrew ct;
 //ct.DequeueFlight(); 
 //ct.addFlights();
 // ct.ViewFlights();
//pessenger ps;
 //ps.PLayToEarn();
 //ps.BookFlight();
 //ps.CheckFlights();
	
}