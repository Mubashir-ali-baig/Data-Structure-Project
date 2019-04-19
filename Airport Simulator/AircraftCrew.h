class AircraftCrew:public game
{
public:
void BalanceTheAircraft()
{
 string name;
 char ch;
 cout<<"To Fly an Aircraft You must rearrange the numbers in Pre-order AVL traversal"<<endl;
 cout<<"\t\t\t\t***Enter your username***"<<endl;
 cout<<"\t\t\t\t";
 cin>>name;
P1: cout<<"\t\t\t\t***Select your difficulty***\t\t\t\t"<<endl;
 cout<<"\t\t\t\t***Press a for Easy difficulty with 5 numbers***\t\t\t\t"<<endl;
 cout<<"\t\t\t\t***Press b for Medium difficulty with 9 numbers***\t\t\t\t"<<endl;
 cout<<"\t\t\t\t***Press c for Expert difficulty with 13 numbers***\t\t\t\t"<<endl;
 cout<<"\t\t\t\t***Press d to exit***\t\t\t\t"<<endl;
 cout<<"\t\t\t\t";
 ch=getch();
 struct btree *root=NULL;
 switch(ch)
 {
 case 'a':
	 {
	  srand(time(0));
	  int size=4;
	  int list[5];
	  for(int i=0;i<=size;i++)
	  {
	   list[i]=rand();
	  }
	  
	  BuildPuzzle(root,list,size);
	  break;
	 }
 case 'b':
	 {
	  srand(time(0));
	  int size=8;
	  int list[9];
	  for(int i=0;i<=size;i++)
	  {
	   list[i]=rand();
	  }
	  
	  BuildPuzzle(root,list,size);
	  break;
	 }
 case 'c':
	 {
	  srand(time(0));
	  int size=12;
	  int list[14];
	  for(int i=0;i<=size;i++)
	  {
	   list[i]=rand();
	  }
	  
	  BuildPuzzle(root,list,size);
	  break;
	 }
 case 'd':
	 {
	  return ;
	 }
 default:
	 {
	  cout<<"Wrong choice"<<endl;
	  goto P1;
	 }
 }
}
void BuildPuzzle(struct btree *start,int *list,int size)
{
	int num;
	int i=0;
	for(i=0;i<=size;i++)
	{
	 cout<<"Before Balancing "<<list[i]<<endl;
	}
	i=0;
	while(i<=size)
	{
	 num=list[i];
	 avl av;
	 start=av.insert(start,num);
	 i++;
	}
	avl av;
	i=0;
	//int *List=NULL;
	av.preOrder(start,list,size,i);
	i=0;
	//cout<<"The Numbers are"<<endl;
	/*while(i<=size)
	{
	 cout<<list[i]<<endl;
	 cout<<endl;
	 i++;
	}
	*/
	i=0;
	
	
	ofstream o;
    o.open("avlanswer.txt");
	av.match(start,o);
    o.close();
	cout<<"\t\t\t\t***Balance the numbers and place them in preorder fashion***\t\t\t\t"<<endl;
	ifstream in;
	in.open("avlanswer.txt");
	int real;
	int flag=0;
	while(i<=size)
	{
	 cout<<"\t\t\t\t***Enter the Number***\t\t\t\t"<<endl;
	 cin>>list[i];
	 in>>real;
	 if(list[i]!=real)
	 {
	  cout<<"\t\t\t\t***Wrong answer mate you crashed the plane***\t\t\t\t"<<endl;
	  flag++;
	  break;
	 }
	 i++;
	}
	if(flag==0)
	{
	 cout<<"\t\t\t\t***Correct Answer Congratulations you seccessfully flew an aircraft!***\t\t\t\t"<<endl;
	}
}
private:
};