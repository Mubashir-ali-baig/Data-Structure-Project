class pessenger:public game
{
public:
	pessenger()
	{
		
	}
	string getPlayerName()
	{
		return this->PlayerName;
	}
	void setPlayerName()
	{
	 cout<<"Enter your username"<<endl;
	 cin>>this->username;
	 //this->PlayerName=this->name;
	}
	void setDestination()
	{
	 cout<<"Choose your Destination from the above given list"<<endl;
	 cin>>this->destination;
	}
	void setAirline()
	{
	 cout<<"Choose your Airline from the above given list"<<endl;
	 cin>>this->airline;
	}
	void setTravelClass()
	{
	 char ch;
	 A2:cout<<"Choose Your Traveling class from the above given list"<<endl;
	 cout<<"Press a to select Economical Class"<<endl;
	 cout<<"Press b to select Business Class"<<endl;
	 cout<<"Press c to select Private Class"<<endl;
	 ch=getch();
	 switch(ch)
	 {
	 case 'a':
		 {
			 this->aircraft="Economical-Class";
			 break;
		 }
	 case 'b':
		 {
			 this->aircraft="Business-Class";
			 break;
		 }
	 case 'c':
		 {
			 this->aircraft="Private-Class";
			 break;
		 }
	 default:
		 {
		  cout<<"Wrong choice Choose Again"<<endl;
		  goto A2;
		 }
	 }
	}
	void CheckFlights()
	{
	 ControlTowerCrew ct;
	 ct.ViewFlights();
	}
	void CheckMoney()
	{
	 
	 ifstream iff;
	 iff.open("players.txt");
 	 int i=0;
     
	 while(!iff.eof())
	 {
		 iff>>arr1[i].Username;
		 iff>>arr1[i].password;
		 iff>>arr1[i].level;
		 iff>>arr1[i].money;
		 if(this->username==arr1[i].Username)
		 {
			 this->money=arr1[i].money;
			 break;
		 }
		 i++;
	 }

	}
	void BookFlight()
	{
	 int money;
	 setPlayerName();
	 CheckMoney();
	 ControlTowerCrew CT;
	 CT.ViewFlights();
	 setDestination();
	 setAirline();
	 setTravelClass();
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
	 ip.close();
		int flag=0;
	 curr=start;
	 
	 while(curr!=NULL)
	 {
		 if(curr->destination==this->destination)
		 {
			 if(curr->airline==this->airline)
			 {
				 if(curr->aircraft==this->aircraft)
				 {
					 if(curr->cost<=this->money)
					 {
					  string line;
					  flag++;
					  ifstream iff;
					  iff.open("records.txt");
					  int i=0;
					  flag=0;
					  while(!iff.eof())
					  {
						    iff>>arr[i].Username;
							iff>>arr[i].destination;
							iff>>arr[i].airline;
							iff>>arr[i].aircraft;
							if(this->username==arr[i].Username)
							{
							 cout<<"You already have a flight"<<endl;
							 flag++;
							 break;
						   }
							i++;
					  }
						iff.close();  
					  if(flag==0)
						{
							ofstream op;
							op.open("records.txt",ios::app);
							op<<this->username<<" "<<this->destination<<" "<<this->airline<<" "<<this->aircraft<<endl;
							cout<<"You have successfully booked your flight"<<endl;
							op.close();
							//string name;
							//string Class;
							//int money;
							//name=this->username;
							//Class=this->aircraft;
							//money=this->money;
							//DeductMoney(name,Class,money);
							if(this->aircraft=="Economical-Class")
	 {
		 this->money=this->money-500;
	 }
	 else if(this->aircraft=="Business-Class")
	 {
		 this->money=this->money-10000;
	 }
	 else if(this->aircraft=="Private-Class")
	 {
		 this->money=this->money-100000;
	 }
	 ifstream ip;
	 ip.open("players.txt");
	 int index=0;
	 struct idds *start=NULL;
	 struct idds *curr=start;
	 while(!ip.eof())
	 {
		 struct idds *ptr=new idds;
		 ip>>ptr->Username;
		 ip>>ptr->password;
		 ip>>ptr->level;
		 ip>>ptr->money;
		 ptr->next=NULL;
		 /*ip>>arr[index].Username;
		 ip>>arr[index].password;
		 ip>>arr[index].level;
		 ip>>arr[index].money;
		 */
		 if(ptr->Username==username)
		 {
			 ptr->money=this->money;
		 }
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
	 
	 ip.close();
	 curr=start;
	 ofstream of;
	 of.open("players.txt");
	 index=0; 
	 while(curr->next!=NULL)
	 {
		// cout<<curr->Username<<curr->money<<endl;
		 of<<curr->Username<<" "<<curr->password<<" "<<curr->level<<" "<<curr->money<<endl;
		 
		 curr=curr->next;
	 }
	of.close();
	break;

	}
	else
		break;
	}
	 else if(curr->cost>this->money)
	{
	 cout<<"Not enough money"<<endl;
	}   
	}
					  
	}
					 
	}
			 
	curr=curr->next;	 
	 }
		 
	 }
	/*void DeductMoney(string name,string Class,int money)
	{
		if(this->aircraft=="Economical-Class")
	 {
		 this->money=this->money-500;
	 }
	 else if(this->aircraft=="Business-Class")
	 {
		 this->money=this->money-10000;
	 }
	 else if(this->aircraft=="Private-Class")
	 {
		 this->money=this->money-100000;
	 }
	 ifstream ip;
	 ip.open("players.txt");
	 int index=0;
	 struct idds *start=NULL;
	 struct idds *curr=start;
	 while(!ip.eof())
	 {
		 struct idds *ptr=new idds;
		 ip>>ptr->Username;
		 ip>>ptr->password;
		 ip>>ptr->level;
		 ip>>ptr->money;
		 ip>>arr[index].Username;
		 ip>>arr[index].password;
		 ip>>arr[index].level;
		 ip>>arr[index].money;
		 
		 if(ptr->Username==username)
		 {
			 ptr->money=this->money;
		 }
		 if(start==NULL)
		 {
		  start=ptr;
		 }
		 else
		 {
		  struct idds *curr=start;
		  while(curr!=NULL)
		  {
			  curr=curr->next;
		  }
		  curr->next=ptr;
		 }
		 
	 }
	 ip.close();
	 curr=start;
	 ofstream op;
	 op.open("players.txt");
	 index=0; 
	 while(!op.eof())
	 {
		 cout<<curr->Username<<endl;
		 op<<curr->Username<<" "<<curr->password<<" "<<curr->level<<" "<<curr->money<<endl;
		 
		 curr=curr->next;
	 }
	
	}
*/	
	void PLayToEarn()
	{
	cout<<"Earn money by winning a quiz"<<endl;
	cout<<"Enter your username"<<endl;
	cin>>this->username;
	quiz q;
	struct btree *start=NULL;
	//cout<<this->username<<endl;
	q.insert(this->username);
	
	}
	void Leadeboard()
	{
	 
	}
	

private:

};