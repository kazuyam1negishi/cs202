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
    Node * head;
  */
  public:
    //Your Code Here
    //Constructor with start year and size. default param are 0 for both.
    Timeline(int start, int size){
      this->size = size;
      head->year = start;
      for(int i = 0; i < size-1; i++){
        head->next = 
      }
    }

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
        
        cout << "Created Nexus at " << year << ", Size: " << branchSize+1 << endl;
      }
      return amount;
    }
    void print(){
      cout << "The Sacred Timeline" << endl;
      //Your Code Here for print. It should match the output in wtf function exactly.
      cout << "x\n" << endl;
    }
    //Visual Print Mode
    void vprint(){
      //Your Code Here for visual print.
      //Best thing to do is to create a 2D array of chars. generate the proper drawing,
      //and then print out the array in a loop at the end. do 11 by 70.
      //branches alternate, first up, then down, then up, then down, and so on.
      //they always have two slashes in appropriate direction and then ~ where each ~ represents a branched node.
      //in the sacred timeline each - represents 1 year. If 2 branches happen to overap it's ok don't worry about it.
      //same thing if the map is too wide (bigger than 70) don't worry about it just stop printing and cut it off so
      //it does not segfault
    }
    int prune(){ //prunes a branch and returns location it pruned. For all time. always.
      int yearWithBranch = -1;
      int branchSize = 1;
      //Your Code Here
      if(yearWithBranch != -1)
        cout << "Pruned Brach at: " << yearWithBranch << " of size " << branchSize << endl;
      return yearWithBranch;
    }

    ~Timeline(){
      //Your Code Here for de-allocating. if you find a branch that was not pruned just cout that it was not pruned.
      //cout << "Branch was not pruned!" << endl;
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
  //sacredTimeline.print();
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
