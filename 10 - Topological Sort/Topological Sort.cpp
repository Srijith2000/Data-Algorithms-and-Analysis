//Topological Sort
#include<iostream>
using namespace std;

enum vcolor {WHITE, GRAY, BLACK};
struct node{
	int ver;
	node * next;
};
struct vnode{
	string name;
	int d,f,pi;
	vcolor color;
	node * adjptr;
};

class graph{
	int n;
	vnode vertex[10];
	node * list;
	int time;
public:
	void createGraph(){
    	cout <<"Enter the number of vertices: ";
    	cin >> n;
    	int m;
    	for(int i = 1; i <= n; i++){
       		cout << "\nEnter the name of vertex "<<i<<": ";
        	cin >> vertex[i].name;
        	vertex[i].adjptr = NULL;
        	cout <<"Enter the number of adjacent vertices of "<<vertex[i].name <<": ";
        	cin >> m;

        	node* cur = NULL;
        	for(int j = 1; j <= m; j++){
            	node* t = new node;
            	cout <<"Enter the index of adjacent vertex "<<j<<" of "<<vertex[i].name<<": ";
            	cin >> t->ver;
            	if(cur==NULL)
					vertex[i].adjptr = t;
            	else
            		cur->next=t;
				t->next=NULL;
            	cur=t;
        	}
    	}
	}
	void DFS(){
		for(int i = 1; i <= n; i++){
    		vertex[i].color = WHITE;
        	vertex[i].pi = -1;
    	}
    	time = 0;
    	list = NULL;
    	for(int u = 1; u <= n; u++){  
            if(vertex[u].color == WHITE)
                DFS_VISIT(u);
        }
	}
	void DFS_VISIT(int u){
		time++;
    	vertex[u].d = time;
    	vertex[u].color = GRAY;

    	node* temp = vertex[u].adjptr;
    	while(temp != NULL){
        	int v = temp->ver;
        	if(vertex[v].color == WHITE){
            	vertex[v].pi = u;
            	DFS_VISIT(v);
        	}
        	temp = temp->next;
    	}
    	time++;
    	vertex[u].f = time;
    	vertex[u].color = BLACK;
    	node* T = new node;
    	T->ver = u;
    	T->next = list;
    	list = T;
	}
	void TOPSORT(){
    	DFS();
    	node* temp = new node;
    	temp=list;
    	cout <<"Topological Sort: ";
    	while(temp != NULL){
        	cout << vertex[temp->ver].name << " ";
        	temp = temp->next;
    	}
    	cout << endl;
    	return;
	}
	void disp(){
		cout<<"\nAdjacency List:\n";
		for(int u=1; u<=n; u++){  
            cout<<vertex[u].name;
            node* t=vertex[u].adjptr;
            while(t != NULL){
            	cout<<"-->"<<t->ver;
            	t=t->next;
			}
			cout<<"\n";
		}
		cout<<endl;
	}
};

int main(){
	graph g;
    g.createGraph();
    g.disp();
    g.TOPSORT();
    g.disp();
    return 0;
}
