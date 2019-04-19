class useraccount:public game
{
private:

public:
	useraccount():game()
	{}
	string getUsername()
	{
		return this->username;
	}
	string getpassword()
	{
		return this->password;
	}
	void setUsername()
	{
	  cout<<"\t\t***Enter Username***\t\t"<<endl;
	  cout<<"\t\t\t\t";
	  cin>>this->name;
	  this->username=this->name;
	}
	void setPassword()
	{
	  cout<<"\t\t\t\t***Enter password***\t\t\t\t"<<endl;
	  cout<<"\t\t\t\t";
	  cin>>this->key;
	  this->password=this->key;
	}
	void signup()
	{
	 setUsername();
	 setPassword();
	 this->level=1;
	 this->money=1000;
	 ofstream of;
	 of.open("players.txt",ios::app);
	 of<<this->username<<" "<<this->password<<" "<<this->level<<" "<<this->money<<endl;
	 of.close();
	 cout<<"\t\t\t\t***Signup Successfull***\t\t\t\t"<<endl;
	}
	int login()
	{
	 struct idds *start=NULL;
	 setUsername();
	 setPassword();
     
	 ifstream ifo;
	 ifo.open("players.txt");
	 int index=0;
	 int flag=0;
	 struct idds *curr=start;
	 while(!ifo.eof())
	 {
		 
		 struct idds *ptr=new idds;
		 ifo>>ptr->Username;
		 ifo>>ptr->password;
		 ifo>>ptr->level;
		 ifo>>ptr->money;
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
	 while(curr!=NULL)
	 {
		 if(curr->Username==this->username&&curr->password==this->password)
		 {
		  cout<<"\t\t\t\t***login Successfull***\t\t\t\t"<<endl;
		  flag++;
		  break;
		 }
		 curr=curr->next;
	 }
	 if(flag==0)
	 {
	  cout<<"\t\t\t\t***Wrong Credentials***\t\t\t\t"<<endl;
	  return 0;
	 }
	 if(flag>0)
	 {
	  return 1;
	 }
	ifo.close();
	}
};