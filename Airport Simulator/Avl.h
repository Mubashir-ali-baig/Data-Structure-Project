class avl:public game
{
public:
struct btree* newNode(int num) 
{ 
    struct btree* node = new btree; 
    node->num=num; 
    node->left=NULL; 
    node->right=NULL; 
    node->height=1;   
    return(node); 
}  
	struct btree* insert(struct btree *node,int num)
	{
	 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(num)); 
  
    if (num < node->num) 
        node->left  = insert(node->left,num); 
    else if (num > node->num) 
        node->right = insert(node->right,num); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
	if (balance > 1 && num < node->left->num) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && num > node->right->num) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && num > node->left->num) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && num < node->right->num) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    
    return node; 
	}
int height(struct btree *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
}
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}
struct btree *rightRotate(struct btree *y) 
{ 
    struct btree *x = y->left; 
    struct btree *T2 = x->right; 
    x->right = y; 
    y->left = T2; 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1;  
    return x; 
}
struct btree *leftRotate(struct btree *x) 
{ 
    struct btree *y = x->right; 
    struct btree *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
}
int getBalance(struct btree *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
}
void preOrder(struct btree *root,int *list,int size,int i) 
{ 
    if(root != NULL) 
    { 
		//cout<<"After Balancing"<<root->num<<endl;
		//list[i]=root->num;
        preOrder(root->left,list,size,i); 
        preOrder(root->right,list,size,i); 
    }
	
}
void match(struct btree *root,ofstream &o)
{
	
	
		
		
		
		if(root != NULL) 
    { 
		o<<root->num<<endl;
		
		match(root->left,o); 
        match(root->right,o); 

		}
		
		
}
private:
};