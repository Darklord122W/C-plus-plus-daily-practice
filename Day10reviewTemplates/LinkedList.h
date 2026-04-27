// Header file for linked list class

class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	LinkedList(); //default construtor
	LinkedList(const LinkedList& lst); //copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList();//destructor
	
	// A new node containing the given data is inserted at the front of the list
	// data is the data to be stored
	void add(int data);

	// A new node containing the given data is inserted at the given position in the list
	// pos specifies the (index) position to insert the new node
	// data is the data to be stored
	void insertAt(int pos, int data);
	
	// The first incidence of the given data found from the list.
	// Returns true if data is found, false otherwise
	// data specifies the data to be found from the list
	bool findVal(int data);
	
	// Empties the list, freeing up dynaically allocated memory
	void removeAll();

	// Prints the contents of the list to the screen, in order
	void printList();

private:
	/* A struct contains data variable (which are accessed using dot
	 * notation in the same way that object methods or attributes are
	 * accessed).  Structs cannot have methods.*/
	// List node
	struct Node {
		int data; 	//list data
		Node *next; //pointer to next item in the list
	};

	Node *head; //Pointer to the first node in the list
	int size; 	//Records the number of nodes in the list
};


