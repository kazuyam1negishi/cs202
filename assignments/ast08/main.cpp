/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 8
    Description: Handling branches (or arrays) in linked lists
    Input: none
    Output: branches and prunes (node array alloc and frees)
*/

#include<iostream>
using namespace std;

class node{
  public:
    //Your Code Here
    //Default Constructor
    //Constructor with year as arg
    //3 vars: integers for year and branches, and next pointer of node type
    int year;
    int branches;
    node * next;
    node(){
      year = 0;
      branches = 0;
      next = nullptr;
    };
    node(int y){
      year = y;
      branches = 0;
      next = nullptr;
    }
};

class Timeline{
  /*
  Moving the private here to not scroll too much
  private:
    int size;
    node * head;
  */
  public:
    // Finished!!!
    Timeline(int start, int size){
      // Make first node
      node * temp = new node;
      this->size = size;
      temp->year = start;
      temp->next = nullptr;
      head = temp;
      // Make the rest, but not at head
      // like I was doing at the beginning.
      for(int i = 1; i < size; i++){
        node * tmp = new node;
        tmp->year = start + i;
        tmp->next = nullptr;
        node * curr = head;
        while(curr->next != nullptr){
          curr = curr->next;
        }
        curr->next = tmp;
      }
    }

    // Finished!!!
    int createNexusEvent(int amount = 1){
      if(!head) return 0; //Can't create nexus event if timeline is empty!
      for(int i=0; i< amount; i++){
        int year = (rand() % size) + head->year;
        //branchsize is MaxSize minus years left give us how big branch can be before end of time 
        int branchSize = rand() % (head->year+size-year)/4; //divide by 4 to keep them smaller for visual reasons

        //Rest of function here. Don't change above so the rands match codegrade.
        //Your code Here for createNexusEvent
        //branch the timeline here.
        //dont forget to delete the year after nexus since we replaced with non pointer type in next[0]

        // start here
        // pointer to iterate through linked list
        node * ptr = head;
        // if ptr->next is nullptr,
        // that means the list is now empty.
        while(ptr->next != nullptr){
          // ptr now points to next node.
          ptr = ptr->next;
          if(ptr->year == year){
            // timeline split is done here, with one node
            // for the timeline and another for the branches.
            node * nexSplit = new node[2];
            // This is for the sacred timeline...
            nexSplit[0].year = (ptr->next)->year;
            nexSplit[0].next = (ptr->next)->next;
            nexSplit[0].branches = (ptr->next)->branches;
            // ...and the branch is to come later.
            // First, another new node for the branch.
            node * branch = &nexSplit[1];
            branch->year = ptr->year;
            branch->next = nullptr;
            for(int i = 1; i <= branchSize; i++){
              node * tmp = new node;
              tmp->year = ptr->year + i;
              tmp->next = nullptr;
              node * curr = branch;
              while(curr->next != nullptr){
                curr = curr->next;
              }
              curr->next = tmp;
            }
            // Pointing...
            ptr->next = nexSplit;
            ptr->branches = 1;
          }
        }
        cout << "Created Nexus at " << year << ", Size: " << branchSize+1 << endl;
      }
      return amount;
    }
    
    // Finished!!!
    void print(){
      cout << "The Sacred Timeline" << endl;
      cout << "s->";
      //Your Code Here for print. It should match the output in wtf function exactly.
      node * ptr = head;
      while(ptr != nullptr){
          cout << ptr->year << "->";
          if(ptr->branches > 0){
            cout << "(";
            node * nexPtr = &ptr->next[1];
            while(nexPtr->next != nullptr){
              cout << "*" << nexPtr->year << ".1";
              nexPtr = nexPtr->next;
              cout << "->";
            }
            cout << "*" << nexPtr->year << ".1";
            cout << ")";
            cout << "~>";
          }
          ptr = ptr->next;
      }
      cout << "x\n" << endl;
    }
    //Visual Print Mode
    // Finished!!!
    void vprint(){
      //Your Code Here for visual print.
      //Best thing to do is to create a 2D array of chars. generate the proper drawing,
      //and then print out the array in a loop at the end. do 11 by 70.
      //branches alternate, first up, then down, then up, then down, and so on.
      //they always have two slashes in appropriate direction and then ~ where each ~ represents a branched node.
      //in the sacred timeline each - represents 1 year. If 2 branches happen to overap it's ok don't worry about it.
      //same thing if the map is too wide (bigger than 70) don't worry about it just stop printing and cut it off so
      //it does not segfault

      // Array declaration
      char graphic[11][70];
      // Array initialization
      // Printing top and bottom borders,
      // and whitespace where branches will be.
      for(int i = 0; i < 11; i++){
        for(int j = 0; j < 70; j++){
          // Print borders
          if(i == 0 || i == 10){
            graphic[i][j] = '#';
          // Initialize the rest of the arr
          } else if(i == 5 && j < size){
            graphic[i][j] = '-';
          } else {
            graphic[i][j] = ' ';
          }
        }
      }
      // resume here: print branches
      int yearCount = 0;
      node * timePtr = head;
      bool top = true;
      while(timePtr->next != nullptr){
        timePtr = timePtr->next;
        yearCount++;
        if(yearCount >= 70 || timePtr == nullptr){
          continue;
        }
        if(timePtr->branches > 0 && top == true){
          graphic[4][yearCount] = '/';
          graphic[3][yearCount + 1] = '/';
          node * branchPtr = &timePtr->next[1];
          int branchCount = 0;
          while(branchPtr != nullptr){
            branchPtr = branchPtr->next;
            branchCount++;
          }
          for(int i = 0; i < branchCount; i++){
            if((yearCount + 2 + i) < 70){
              graphic[2][yearCount + 2 + i] = '~';
            }
          }
          top = false;
          continue;
        }
        if(timePtr->branches > 0 && top == false){
          graphic[6][yearCount] = '\\';
          graphic[7][yearCount + 1] = '\\';
          node * branchPtr = &timePtr->next[1];
          int branchCount = 0;
          while(branchPtr != nullptr){
            branchPtr = branchPtr->next;
            branchCount++;
          }
          for(int i = 0; i < branchCount; i++){
            if((yearCount + 2 + i) < 70){
              graphic[8][yearCount + 2 + i] = '~';
            }
          }
          top = true;
          continue;
        }
      }
      for(int i = 0; i < 11; i++){
        for(int j = 0; j < 70; j++){
          cout << graphic[i][j];
        }
        cout << endl;
      }
    }

    // Nah...
    int prune(){ //prunes a branch and returns location it pruned. For all time. always.
      int yearWithBranch = -1;
      int branchSize = 1;
      //Your Code Here
      node * ptr = head;
      while(ptr->next != nullptr){
        ptr = ptr->next;
        if(ptr->branches != 0){
          // branch found
          yearWithBranch = ptr->year;
          branchSize = ptr->branches;
          // ptrs to traverse and remove nodes
          node * branch = ptr->next[1].next;
          node * delPtr = ptr->next[1].next;
          // delete nodes
          while(branch != nullptr){
            delPtr = branch;
            branch = branch->next;
            delete delPtr;
            branchSize++;
          }
          // new node to hold next node and connect timeline
          node * sacredTime = new node(ptr->next[0].year);
          // deep copy
          sacredTime->branches = ptr->next[0].branches;
          sacredTime->next = ptr->next[0].next;
          // remove and dealloc branch
          ptr->branches = 0;
          delete [] ptr->next;
          // timeline connected!
          ptr->next = sacredTime;
          break;
        }
      }

      if(yearWithBranch != -1)
        cout << "Pruned Brach at: " << yearWithBranch << " of size " << branchSize << endl;
      return yearWithBranch;
    }

    // Finished!!!
    ~Timeline(){
      //Your Code Here for de-allocating. if you find a branch that was not pruned just cout that it was not pruned.
      //cout << "Branch was not pruned!" << endl;
      node * ptr = head;
      while(ptr->next != nullptr){
        ptr = ptr->next;
        delete head;
        head = ptr;
      }
      delete head;
    }
  //Don't modify any code beneath this line or the TVA will prune you!!!
  private:
    int size;
    node *head;
  public:
    void wtf(){ //This code should print your sacred timeline identical to your print function//
      {int o_384d4468adeab2d9aed6871 = 121934831;};typedef node o_384d4468adeab2d9aed6871e0fa;
      cout<<"\x54""h\145 \x53""a\143r\x65""d\040T\x69""m\145l\x69""n\145"<<endl;
      o_384d4468adeab2d9aed6871e0fa* o_384d4468adeab2d9aed6871e0fa887d6=head;cout<<"\x73""-\076";
      while (o_384d4468adeab2d9aed6871e0fa887d6){cout<<o_384d4468adeab2d9aed6871e0fa887d6->year
      <<"\x2D"">";if ((o_384d4468adeab2d9aed6871e0fa887d6->branches > (0x0000000000000000 + 
      0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(o_384d4468adeab2d9aed6871e0fa887d6->
      branches > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)))
      {cout<<"\x28""";for (int o_8aec06cef502177edb2e9beb8e48618e=(0x0000000000000000 + 0x0000000000000200 + 
      0x0000000000000800 - 0x0000000000000A00);(o_8aec06cef502177edb2e9beb8e48618e < o_384d4468adeab2d9aed6871e0fa887d6->
      branches) & !!(o_8aec06cef502177edb2e9beb8e48618e < o_384d4468adeab2d9aed6871e0fa887d6->branches);
      o_8aec06cef502177edb2e9beb8e48618e++){cout<<"\x2A"""<<o_384d4468adeab2d9aed6871e0fa887d6->
      next[o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 
      0x0000000000000A03)].year<<"\x2E"""<<o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 
      0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);o_384d4468adeab2d9aed6871e0fa* 
      o_c4e691df50ffe930c3969e01258ea6a1=o_384d4468adeab2d9aed6871e0fa887d6->next[o_8aec06cef502177edb2e9beb8e48618e + 
      (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03)].next;
      while (o_c4e691df50ffe930c3969e01258ea6a1){cout<<"\x2D"">\052"<<o_c4e691df50ffe930c3969e01258ea6a1->
      year<<"\x2E"""<<o_8aec06cef502177edb2e9beb8e48618e + (0x0000000000000002 + 0x0000000000000201 + 
      0x0000000000000801 - 0x0000000000000A03);o_c4e691df50ffe930c3969e01258ea6a1 = o_c4e691df50ffe930c3969e01258ea6a1->
      next;};};cout<<"\x29""~\076";};o_384d4468adeab2d9aed6871e0fa887d6 = o_384d4468adeab2d9aed6871e0fa887d6->next;};
      cout<<"\x78""\x0A"<<endl;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    }
};

//FOR ALL TIME. ALWAYS
int main(int argc, char *argv[]) { // ./a.out 40 4 1970 50 (40 is seed, 4 is number of nexus events to 
  //create 1970 is starting year of the sacred timeline, and 50 is the length of the sacred timeline).
  int seed = 40;                //for testing with no cmd args
  int nexusEventsToCreate = 4;  //for testing with no cmd args
  int startYear = 1970;         //for testing with no cmd args
  int timelineLength = 50;      //for testing with no cmd args
  if(argc == 5){ //for codegrading
    seed = atoi(argv[1]);
    nexusEventsToCreate = atoi(argv[2]);
    startYear = atoi(argv[3]);
    timelineLength = atoi(argv[4]);
  }
  srand(seed);
  Timeline sacredTimeline(startYear, timelineLength);
  sacredTimeline.print();
  sacredTimeline.createNexusEvent(nexusEventsToCreate);
  // remember to uncomment before submitting!
  // sacredTimeline.print();
  sacredTimeline.wtf();
  sacredTimeline.vprint();
  cout << "Nexus Event Detected! Sending Minute Men to Prune the Branches!\n" << endl;
  //on behalf of the time variance authority, I hereby arrest you for crimes against the sacred timeline
  while(sacredTimeline.prune()!=-1){
    sacredTimeline.print();
  }
  cout << "\nSacred Timeline Restored :)" << endl;
  sacredTimeline.print();
  sacredTimeline.vprint();

  cout << "___________   ____\n| /|    \\  \\ /  / \\\n|/ |    |\\  Y \\/   \\\n   "
       <<   "|    | \\   /\\    \\\n   |____|  \\_/_/\\____\\\n FOR ALL TIME.  ALWAYS.\n"<< endl;
  return 0;
}
