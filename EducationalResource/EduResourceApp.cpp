#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include <sstream> //look into this library

using namespace std;

void mainMenu()
{
 cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl; 
 cout << "| Financial Resources (Type 1)  |" << endl; 
 cout << "| Course Resources    (Type 2)  |" << endl; 
 cout << "| Technical Support   (Type 3)  |" << endl; 
 cout << "| Other               (Type 4)  |" << endl;
 cout << "| Main Menu           (Type 5)  |" << endl; 
 cout << "| Nothing             (Type 0)  |" << endl;
 cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

void menu1() //TODO:: Will convert to a string function once files are in place.
{
    cout << "|*_*|*_*|*_*|*_*|*_*|" << endl; 
    cout << "|     DEVELOPING    |" << endl; 
    cout << "|*_*|*_*|*_*|*_*|*_*|" << endl; 
}

string menu2() 
{
    string select;
    cout << "\nResource(s).\n"; 

    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|Top Coding Books (Type 1)|" << endl;
    cout << "|Nothing          (Type 0)|" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Enter values (0 - 1): "; 
    cin >> select; 

    while(select != "0")
    {
        if(select == "1")
        {
            cout << "Successfully obtained data on popular coding books." << endl;

            return "DataFiles/TopCodingBooks/RankBooks.txt"; 
        } 
        else
        {
             cout << "Please type the correct number!\n"; 
        }
        cout << "Type values (0 - 1): "; 
        cin >> select;
    }

    cout <<  "No file selected." << endl;

    return " "; 
} 


void menu3() // TODO:: Will convert to a string function once files are in place. 
{
    cout << "|^_-|^_-|^_-|^_-|^_-|" << endl; 
    cout << "|     DEVELOPING    |" << endl; 
    cout << "|^_-|^_-|^_-|^_-|^_-|" << endl;
}

string menu4() //Will implement linked list for this portion. 
{
    string select;
    cout << "\nHere are some other resources you might find helpful.\n"; 

    cout << "*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "|TedTalks (Type 1)|" << endl;
    cout << "|Nothing  (Type 0)|" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Enter values (0 - 1): "; 
    cin >> select; 

    while(select != "0")
    {
        if(select == "1")
        {
            cout << "Successfully obtained data on TedTalks." << endl;

            return "DataFiles/TedTalks/data.txt"; 
        } 
        else
        {
             cout << "Please type the correct number!\n"; 
        }
        cout << "Type values (0 - 1): "; 
        cin >> select;
    }

    cout <<  "No file selected." << endl;

    return " "; 
}

void seeFileContent(string fileName) // See information. Print out the first getline ask if they want to see all or some character number
{
   
   fstream myfile;
   myfile.open(fileName, ios::in);
   if(myfile.is_open())
   {
      string line;
      string answer;
      bool stop = false; 

      cout << "We will print out the first 4 lines for you" << endl; 

    while (stop != true)
    {
      for(int i = 0; i < 5; i++)
      {
          getline(myfile, line); 
          cout << line << endl << endl; 
      }

      cout << "Do you want to continue? [Y]es or [N]o : ";
      cin >> answer; 
      while (answer != "y" && answer != "n" && answer != "Y" && answer != "N")
       {
                 cout << "Please type 'y' or 'n'!\n";
                 cin >> answer;
       }

       if (answer == "N" || answer == "n")
       {
           stop = true;
           cout << "\nMoving to the search portion of the program." << endl;
       } 
       else if (myfile.eof()) 
       {
           stop = true;
           cout << "We are at the end of the file!\n" << endl; 
       }
       else
       {
           cout << "Printing the next 5 lines\n" << endl; 
       }

    }

      myfile.close(); 
   }
}


/* Rony */

// structure for the node in a linked list
struct nodeType
{
     string info;
     nodeType *link;
};

// print linked list as output

void print_Linked_List(nodeType *head)

{
     nodeType *current_data = head;
     cout << "The list is in this order (title, author, date, views, likes, link):" << endl;
// Linked list is traversed and data is print as output
//<cstddef> 
     
     while (current_data != 0)
     {
          cout << current_data->info << endl;
          current_data = current_data->link;
     }
}

// Function to check the linked list is empty or not

bool isLinkedListEmpty(nodeType *head)
{
    if (head == 0) 
// if linked list is empty them return true
    
        return true;

    else    
// If the linked list is not empty then return false
    
        return false;
}


// function to insert info in the linked list:

void insertInfo_in_linkedList(nodeType* &head, string givenInfo)
{
    nodeType *current = head;
    nodeType *newNode = new nodeType();
    newNode->info = givenInfo;
    newNode->link = 0;
    if (current == 0)
    {
    	
        head = newNode;
        return;
    }
    while (current->link != 0)
    {
        current = current->link;
    }
    current->link = newNode;
}


// Function to add items in the linked list:

void add_items_in_list(nodeType* &head, vector<string> data)
{
    string data_enter; 
    // variable that stores data
    // vector<string>::iterator it;

    for(int i = 0; i < 6; i++)
    {
        data_enter = data[i]; 
        insertInfo_in_linkedList(head, data_enter);
    }
}

// function to find length of the linked list:

int length_of_list(nodeType *head)
{
    int len = 0;
    nodeType *current = head;
    while (current != 0)
    {
        len++;
        current = current->link;
    }
    
    return len;
}


// function to destroy the linked list:
void destroy_Linked_List(nodeType *head)
{
    nodeType *prev = 0, *current = head;
    while (current != 0)
    {
        prev = current;
        current = current->link;
        delete prev;
    }

delete prev;
delete current;
head = 0;

}

// Function to print info of first node in a list:

string First_node_Info(nodeType *head)
{
    if (isLinkedListEmpty(head) == true)
    {
        cout << "List is empty.\n";
        return "-1";
    }

    else
        return head->info;

}


// function to print info of last node in a List:

string Last_node_info(nodeType *head)
{
    nodeType *current = head;
    while (current->link != 0)
    {
        current = current->link;
    }

return current->info;
}


// function to search item in the list:

bool search_Item_In_List(nodeType *head, string targetItem)
{

    nodeType *current = head;
    while (current != 0)
    {
        if (current->info == targetItem)
            return true;

    current = current->link;
    }

return true;
}



// function to delete the item from the linked list:

void delete_item_from_list(nodeType *head, string targetItem)
{
    nodeType *prev = 0, *current = head;
    if (isLinkedListEmpty(head) == true)
    {
        cout << "List is empty.\n";
        return;
    }
        
        else if (head->info == targetItem)
        {   
            head = head->link;
            delete current;
            return;
        }

        while (current != 0 && current->info != targetItem)
        {
            prev = current;
            current = current->link;
        }
        
        if (current->info != targetItem)
        {
            cout << "Search Item is not present in Linked List.\n";
            return;
        }
        else
        {
            prev->link = current->link;
            delete current;
        }
}


// function to copy the linked List:
nodeType *copyLinkedList(nodeType *head)
{
    nodeType *newHead = 0, *current = head;
    while (current != 0)
    {
        insertInfo_in_linkedList(newHead, current->info);
        current = current->link;
    }
    return newHead;
}

/* D'Marco */
// TODO: bubbleSort & Queue

//print list of sorted values
void printArray(double rank[], int n)
{
    int i;
   
   cout << "rankings are.." << endl; 
    for (i = 0; i < 270; i++)
        cout << rank[i] << " ";
    cout << endl;

}

//sorting algorithm
template <class elemType>
void bubbleSort(elemType list[], int length)

{
    int operation=0;
    for (int iteration = 1; iteration < length; iteration++){
       
        for (int index= 0; index < length - iteration; index++){
           
            if (list[index] > list[index + 1]){ // swap numbers if a greater number comes before a smaller number
               
                elemType temp = list[index];                
               
                list[index] = list[index + 1];                
               
                list[index + 1] = temp;          
               
                operation++;
            }      
        }  

        // return list;
       
    }
  cout<<"number of operations: ";// print out operations
  cout<< operation<< endl;  
}

/* Clarence */
//TODO: Merge Sort 

vector<string> readRecordFromFile(string fileName) // see information for Ted Talks. Lead linked list implementation
{
    vector<string> record;
    string searchTerm;
    string answer; 

    cout << "What are you looking for?: ";  
    getline(cin >> ws, searchTerm); // cin >> searchTerm; 
    cout << "Looking for information containing " << searchTerm << ".\n"; 

   ifstream myFile; 
   myFile.open(fileName, ios::in | ios::binary); 
   string  title,  author,  date,  views, likes, link;
   bool found = false; 
   while(!found)
   {
      getline(myFile, title, ',');
      getline(myFile, author,',');
      getline(myFile, date, ',');
      getline(myFile, views, ',');
      getline(myFile, likes, ',');
      getline(myFile, link, '\n');
      if (title == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\nMatch a Tedtalk presentation named '" << record[0]  << "' by  " << record[1] <<".\n";
         cout << "Holding all related information..." << endl;

      } 
      else if (author == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\nFound " << record[1] << " in our database." << endl;
         cout << "Holding all related information..." << endl;
      }
      else if (date == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\n" << record[1] << " TedTalk was released " << record[2] << ".\n";
         cout << "Holding all related information..." << endl;
      }
      else if (views == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\n" << record[1] << " has " << record[3] << " views on their TedTalk video.\n";
         cout << "Holding all related information..." << endl;
      }
      else if (likes == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\n" << record[1] << " has " << record[4] << " likes on their TedTalk video.\n";
         cout << "Holding all related information..." << endl; 
      }
      else if (link == searchTerm)
      {
         found = true; 
         record.push_back(title);
         record.push_back(author);
         record.push_back(date);
         record.push_back(views);
         record.push_back(likes);
         record.push_back(link);

         cout << "\nThe link to " << record[1] <<"'s video is " << record[5] << endl;
         cout << "Holding all related information..." << endl; 
      }
      else if (myFile.eof())
      {
        //  found = true; 
         cout << "We were not able to find  search results for: " << searchTerm << ".\n";
         cout << "Would you like to search for another term. [Y]es or [N]o: "; 
         cin >> answer; 
         while (answer != "y" && answer != "n" && answer != "Y" && answer != "N")
             {
                 cout << "Please type 'y' or 'n'!\n";
                 cin >> answer;
             }
         if (answer == "N" || answer == "n")
         {
             found = true;
            //  cout << record; 
             cout << "Returning to Main Menu."; 
         } else if (answer == "Y" || answer == "y") {

             cout << "What are you looking for?: ";  
             getline(cin >> ws, searchTerm);
             //myFile.seekp(); //seek put - sets writing (putting) pointer at a specified place in the file. flag -> file::beg
             myFile.clear();
             myFile.seekg(0);
         }
      }
   }
   myFile.close(); 
   return record;
}

void SortAndSee(string fileName) // For Top coding books, check the rankings
{
    // Rating,Reviews,Book_title,,Number_Of_Pages,Type,Price
    string answer; 

    double rank[270] =  {4.17,4.01,3.33,3.97,4.06,3.84,4.09,4.15,3.87,4.62,4.03,3.78,
                        3.73,3.87,3.87,3.95,3.85,3.94,3.75,4.1,4.22,3.71,4.21,
                        4.28,3.2,3.67,3.97,3.98,3.96,4.37,4.25,4.32,4.01,4.13,
                        4.15,3.91,3.86,4.03,4.23,4.04,4.09,4.33,4.09,3.93,4,
                        4.27,3.84,4.2,4.06,3.65,4.08,4.15,4.01,4.06,5,4.12,
                        4.35,4.11,4.35,4.11,3.32,4,3.97,4.28,3.91,3.68,3.78,
                        4.4,4.04,4.15,4.02,3.76,4.15,3.6,4.16,4.27,4.05,3.68,
                        4.16,4.34,4.11,4.39,3.88,3.7,3.83,4.11,3.22,4.31,4.31,
                        4.27,4.05,4.28,4.43,4.5,3.38,3.87,4.29,3.97,4.25,3.89,
                        4.29,4.2,3.78,4.54,4.34,4.49,4.11,4.15,3.82,4.4,3.97,
                        4.02,3.58,3.75,4.67,4.33,4.2,4.3,3.73,4.29,3.86,3.82,
                        4.04,4.28,4.2,4.5,3.98,3.83,4.18,3.96,3.67,4.72,3.37,
                        4.25,4.03,4.13,3.93,4.62,4.4,4.17,4.08,4.08,3.79,4.22,
                        4.23,4.14,4.54,3.58,4,4.4,4.21,3.93,4.11,4.34,4.08,3.83,
                        4.18,4.23,4.23,4.12,4.28,4.18,4.15,3.93,4.33,4.22,3.91,
                        4.18,4.21,4.25,4.35,4.25,4.19,4.24,4.46,4.46,4,3,3.83,
                        4.16,4.14,4.1,3,4.18,3.52,4.13,4.12,3,4.22,4.37,4.21,
                        4.37,3.88,3.7,4.67,4.21,3.87,4.05,4.58,3.92,4.2,4,4.32,
                        3.96,3.95,4.42,4.08,4,3.96,4.31,4.15,4.23,4.13,3.56,4.3,
                        3.78,4.41,3.86,4.24,4.23,4.33,4.25,4.05,4.34,4.15,3.94,
                        3.59,3.48,4.45,4.02,4.03,3.92,3.77,3.91,4.25,4.14,4.23,
                        44.01,4.03,4.33,4.06,3.97,4.37,4.1,4.35,4.37,3.9,4.02,
                        4.03,4.1,4.42,4.11,4.11,3.96,3.67,4.13,3.87,4.16,4.18,
                        3.45,3.82,4.08,3.77,3.82,4.26,3.76,3.94,4.49,4.77,3.84};
                        int n = sizeof(rank)/sizeof(rank[0]);              
            cout << "Would you like to see the the most or least popluar coding books?. [M]ost or [L]east: "; 
            cin >> answer; 
         
         while (answer != "m" && answer != "l" && answer != "M" && answer != "L")
         {
        
            cout << "Please type 'm' or 'l'!\n";
            cin >> answer;
            
         }

        if (answer == "L" || answer == "l")
        {
            cout << "Bubble Sorting...\n"; 
            bubbleSort(rank,n);
            printArray(rank, n); 
                
                //Queue
        } 
        else 
        {
            bubbleSort(rank,n);
            //Stack
            cout << "Bubble Sorting...\n";
            printArray(rank, n); 
        } 

            cout << "Returning to main menu\n";
        
         
}


int main()
{
    string exit = "0"; // used character type because you will not get an error based on things such as int or str.
    string fileName = " ";
    nodeType *head = 0; 

    cout << "Welcome to the terminal version of the the Education Resource App!\n";
    cout << "What would you like assistance with?\n";
    mainMenu();
    cout << "Enter values (0 - 5): "; 
    cin >> exit;

    while(exit != "0")
    {
        if(exit == "1")
        {
            menu1();
        }
        else if(exit == "2"){
            fileName =  menu2();
            if(fileName != " ")
            {
                seeFileContent(fileName);
                SortAndSee(fileName);
            }
        }
        else if(exit == "3")
        {
            menu3(); 
        }
        else if(exit == "4")
        {
           fileName =  menu4();
           if(fileName != " ")
           {
               seeFileContent(fileName); 
               vector<string> data4 = readRecordFromFile(fileName);
               add_items_in_list(head, data4);
               print_Linked_List(head);
           }
        }
        else if(exit == "5")
        {
            mainMenu(); 
        }
        else
        {
            cout << "Please type the correct number!\n";
        }
        cout << "Enter values (0 - 5): "; 
        cin >> exit;   
    }

    cout << "Goodbye" << endl;
    return 0; 
}
