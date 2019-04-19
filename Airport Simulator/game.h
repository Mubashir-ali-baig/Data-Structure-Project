class game
{
public:
 game()
 {
	 this->username="";
	 this->password="";
	 this->key="";
	 this->name="";
	 this->PlayerName="";
	 this->score=0;
	 this->airline="";
	 this->destination="";
	 this->money=0;
	 this->score=0;
	 this->cost=0;
 }
 string getName()
 {
	 return this->PlayerName;
 }
 void setName(string name)
 {
	 this->PlayerName=name;
 }
 int getScore()
 {
	 return this->score;
 }
 void setScore(int score)
 {
	 this->score=score;
 }
protected:
  struct idds
  {
   string Username;
   string password;
   string destination;
   string airline;
   string aircraft;
   int cost;
   int money;
   int level;
   struct idds *next;
  };
  struct btree
	{
	 struct btree *left;
	 struct btree *right;
	 string question;
	 string answer;
	 int level;
	 int height;
	 int num;
	};
  string PlayerName;
  idds arr[20];
  idds arr1[20];
  string username;
  string password;
  string name;
  string key;
  int money;
  int score;
  string airline;
  string destination;
  int cost;
  string aircraft;
  int level;
};