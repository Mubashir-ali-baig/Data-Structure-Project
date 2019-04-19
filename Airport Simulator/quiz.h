#include<fstream>
class quiz:public game
{
public:
	quiz()
	{
	
	}
	void insert(string Name)
	{
	 
		cout<<Name<<endl;
		int Money;
	 int i=0;
	 int index;
	 ifstream iff;
	 iff.open("players.txt");
	 int flag=0;
	 struct idds *start=NULL;
	 struct idds *curr=start;
	 while(!iff.eof())
	 {
		idds *ptr=new idds;
		iff>>ptr->Username;
		iff>>ptr->password;
		iff>>ptr->level;
		iff>>ptr->money;
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
		 if(curr->Username==Name)
		 {
			 index=curr->level;
			 Money=curr->money;
		     flag++;
			 break;
		 }
		 curr=curr->next;
	 }
	 if(flag==0)
	 {
	  cout<<"No such User"<<endl;
	  return ;
	 }
	 index=index+2;
	 
	 int n;
	
	btree *root=NULL;
	int j=0;
	int list[10];
	int m=0;
	ifstream q;
	q.open("quiz1.txt");
	string query;
	string answer;
	while(m<index)
	{
	btree *Curr=root;
	srand(time(0));
	int num;
	for(int i=0;i<10;i++)
	{
	 
		list[i]=rand();
	    
		
	}
	
	//cout<<list[0]<<endl;
	struct btree *ptr=new btree;
	ptr->left=NULL;
	ptr->right=NULL;
	for(i=0;i<=index;i++)
	{
	 if(i==j)
	 {
		 getline(q,query);
		 getline(q,answer);
		 ptr->level=list[i];
		 ptr->question=query;
		 ptr->answer=answer;
		 j++;
		 break;
	 }
	}
	cout<<"beforeInorder "<<ptr->level<<endl;
	if(root==NULL)
	{
	
		root=ptr;
	}
	
	else
	{
	 btree *Curr=root;
	 decide(Curr,ptr);
	}
	m++;
	}
	
	flag=0;
	//ifstream q;
	//q.open("quiz1.txt");
	//LoadQuestions(root,query,answer,flag,q);
	InOrder(root);
	int Mon=0;
	int b;
	b=Validate(root,Name,Mon);
	cout<<"MONEY"<<b<<endl;
	q.close();
}
	
	void decide(btree *curr,btree *ptr)
	{
		if(ptr->level<curr->level)
		{
			if(curr->left==NULL)
			{
				curr->left=ptr;
			}
			else
			{
				curr=curr->left;
				decide(curr,ptr);
			}
		}
		else if(ptr->level>curr->level)
		{
			if(curr->right==NULL)
			{
				curr->right=ptr;
			}
			else
			{
				curr=curr->right;
				decide(curr,ptr);
			}
		}
	}
void InOrder(struct btree *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
        {
            InOrder(root->left);

        }
		//cout<<root->level<<endl;
		cout<<root->question<<endl;
		//cout<<root->answer<<endl;
		InOrder(root->right);
    }
}
int Validate(struct btree *root,string name,int money)
{
	string response;
	if(root!=NULL)
    {
        if(root->left!=NULL)
        {
            Validate(root->left,name,money);

        }
		//cout<<"Level"<<root->level<<endl;
		cout<<"Question: "<<root->question<<endl;
		cin>>response;
		if(response==root->answer)
		{
		 cout<<"CORRECT"<<endl;
		 
		 money=money+1000;
		 
		}
		
		Validate(root->right,name,money);
	}
	update(money,name);
	return money;
}
	void update(int money,string name)
	{
	ifstream p;
	p.open("players.txt");
	struct idds *start=NULL;
	 struct idds *curr=start;
	 while(!p.eof())
	 {
		 struct idds *ptr=new idds;
		 p>>ptr->Username;
		 p>>ptr->password;
		 p>>ptr->level;
		 p>>ptr->money;
		 ptr->next=NULL;
		 /*ip>>arr[index].Username;
		 ip>>arr[index].password;
		 ip>>arr[index].level;
		 ip>>arr[index].money;
		 */
		 if(ptr->Username==name)
		 {
			 ptr->money=ptr->money+money;
			 if(money>=1000)
			 {
				 ptr->level=ptr->level+1;
			 }
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
	 p.close();
	 
	 curr=start;
	 ofstream op;
	 op.open("players.txt");
	
	 while(curr->next!=NULL)
	 {
		 //cout<<curr->Username<<curr->money<<endl;
		
		 op<<curr->Username<<" "<<curr->password<<" "<<curr->level<<" "<<curr->money<<endl;
		 
		 curr=curr->next;
	 }
	op.close();
}


/*void LoadQuestions(struct btree *root,string query,string answer,int flag,ifstream& q)
	{

	if(root!=NULL)
    {
        if(flag==0)
		{
		 
		 
		  getline(q,query);
	     // cout<<query<<endl;
	      getline(q,answer);
		  flag++;
		 
		}
		if(root->left!=NULL)
        {
			LoadQuestions(root->left,query,answer,flag,q);
        }
		
		root->question=query;
		root->answer=answer;
		query="";
		answer="";
		flag=0;
		  getline(q,query);
	      getline(q,answer);
		LoadQuestions(root->right,query,answer,flag,q);
    }
  }
 */
private:
	
}; 