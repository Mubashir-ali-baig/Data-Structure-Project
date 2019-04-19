class ControlTowerCrew:public game
{
public:
	ControlTowerCrew():game()
	{};
	string getFlights()
	{
		return this->destination;
	}
	void setFlights()
	{
	 cout<<"Enter the destination name"<<endl;
	 cin>>this->destination;
	}
	string getAirline()
	{
		return this->airline;
	}
	int getAirlineCost()
	{
		return this->cost;
	}
	void setAirlineCost()
	{
		cout<<"Enter the cost of this "<<this->airline<<endl;
		cin>>this->airline;
	}
	void setAirline()
	{
	 cout<<"Choose the name of Airline"<<endl;
	A1: cout<<"Press a for PIA"<<endl;
	 cout<<"Press b for Shaheen"<<endl;
	 cout<<"Press c for Airblue"<<endl;
	 cout<<"Press d for Qatar"<<endl;
	 cout<<"Press e for Lufthansa"<<endl;
	 char ch;
	 ch=getch();
	 switch(ch)
	 {
	 case 'a':
		 {
		 this->airline="PIA";
		 break;
		 }
		 case 'b':
		 {
		  this->airline="Shaheen";
		  break;
		 }
		 case 'c':
			 {
				 this->airline="Airblue";
				 break;
			 }
		 case 'd':
			 {
				 this->airline="Qatar";
				 break;
			 }
		 case 'e':
			 {
				 this->airline="Lufthansa";
				 break;
			 }
		 default:
			 {
				 cout<<"Wrong Choice Choose Again"<<endl;
			     cout<<endl;
				 goto A1;
			 }
	 }
	}
	string getdAircraftType()
	{
		return this->aircraft;
	}
	void setAircraftType()
	{
	 char ch; 
	L1: cout<<"Enter the type of aircraft"<<endl;
	 cout<<"Enter a for Economical class"<<endl;
	 cout<<"Enter b for Business class"<<endl;
	 cout<<"Enter c for Private class"<<endl;
	 cout<<"Enter d to go back"<<endl;
	 ch=getch();
	 switch(ch)
	 {
	 case 'a':
		 {
			 this->aircraft="Economical-Class";
			 this->cost=500;
			 break;
		 }
	 case 'b':
		 {
			 this->aircraft="Business-Class";
			 this->cost=10000;
			 break;
		 }
	 case 'c':
		 {
			 this->aircraft="Private-Class";
			 this->cost=100000;
			 break;
		 }

	 case 'd':
		 return ;
	 default:
		 {
		  cout<<"Wrong Choice Choose Again"<<endl;
		  cout<<endl;
		  goto L1;
		 }
	 }
	}
	void addFlights()
	{
L1:
	 setFlights();
	 setAirline();
	 setAircraftType();
	// setAirlineCost();
	 ofstream op;
	 op.open("flights.txt",ios::app);
	 op<<this->destination<<" "<<this->airline<<" "<<this->aircraft<<" "<<this->cost<<endl;
	 cout<<"Flight Added Successfully in the database"<<endl;
	 op.close();
	}
	void ViewFlights()
	{
	    struct idds *start=NULL;
		struct idds *curr=start;
		
		ifstream ip;
		ip.open("flights.txt");
		while(!ip.eof())
		{
			struct idds *ptr=new idds;
			ip>>ptr->destination;
			ip>>ptr->airline;
			ip>>ptr->aircraft;
			ip>>ptr->cost;
			ptr->next=NULL;
			if(start==NULL)
			{
			 start=ptr;
			}
			else
			{
			 struct idds *curr=start;
			 while(curr->next!=NULL)
			 {
				 curr=curr->next;
			 }
			 curr->next=ptr;
			}
		}
		curr=start;
		cout<<"***"<<"Destination"<<" "<<"Airline"<<" "<<"AirCraft-Type"<<" "<<"Cost"<<"***\t\t\t\t"<<endl;
		cout<<endl;
		while(curr->next!=NULL)
		{
			cout<<"\t\t\t\t";
			cout<<curr->destination<<" "<<curr->airline<<" "<<curr->aircraft<<" "<<curr->cost<<"$";
			cout<<endl;
			curr=curr->next;
		}
	 ip.close();
	}
	void DequeueFlight()
	{
	 
	 int flag=0;
	 string user;
	 cout<<"Enter your username"<<endl;
	 cin>>user;
	 ifstream is;
	 is.open("records.txt");
	 struct idds *start=NULL;
	 idds *curr=start;
	 while(!is.eof())
	 {
	  struct idds *ptr=new idds;
	  ptr->next=NULL;
	  is>>ptr->Username;
	  is>>ptr->destination;
	  is>>ptr->airline;
	  is>>ptr->aircraft;
	 if(ptr->Username==user)
	 {
	  flag++;
	  is>>ptr->Username;
	  is>>ptr->destination;
	  is>>ptr->airline;
	  is>>ptr->aircraft;
	 }
	 if(start==NULL)
	 {
	  start=ptr;
	 }
	 else
	 {
	  idds *curr=start;
	  while(curr->next!=NULL)
	  {
		  curr=curr->next;
	  }
	  curr->next=ptr;
	 }
	 }
	 if(flag==0)
	 {
	  cout<<"No such Flight"<<endl;
	  return ;
	 }
	 is.close();
	 curr=start;
	 ofstream of;
	 of.open("records.txt");
	 while(curr->next!=NULL)
	 {
		 of<<curr->Username<<" "<<curr->destination<<" "<<curr->airline<<" "<<curr->aircraft<<endl;
		 curr=curr->next;
	 }
	 cout<<"Flight Successfully Deleted"<<endl;
	}
	
	
private:
};