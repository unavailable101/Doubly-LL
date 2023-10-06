#include"list.h"
#include <iostream>
using namespace std;

struct node {
    int elem;
    node* next;
    node* prev;
};

class DoublyLL : public List{
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;
    
    public:
    void addHead(int num) {
        node* n = (node*)calloc(1, sizeof(node));
        n->elem = num;
        n->next = head;
        if (!head){
            head = n;
            tail = n;
        } else {
            head->prev = n;
            head = n;
        }
        size++;
    }

    void addTail(int num) {
        node* n = (node*)calloc(1, sizeof(node));
        n->elem = num;
        n->next = nullptr;
        if (!tail){
            head = n;
            tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        size++;
    }

    void addAt(int num, int pos) {
        node* n = (node*)calloc(1,sizeof(node));
        n->elem = num;
        int ctr;//declare counter
        
        if (pos == 1){ //if pos is 1 then add head
             addHead(num);
             return;
        }
        if (pos == size+1){ //if pos is size+1 then add tail
            addTail(num);
            return;
        }

        node* curr; //declare curr
        if (size/2 >= pos){ //if half the size is greater than pos, start head
            curr = head;
            ctr = 1; //initialize ctr to one since mag start ka sa head
            while (curr)
            {
                if (ctr == pos){
                    n->prev = curr->prev;
                    n->next = curr;
                    curr->prev->next = n; //update ang next sa curr->prev to n
                    curr->prev = n; //update ang curr->prev to n
                    break;//curr->prev->next and curr->prev kay lahi, ok?
                }
                curr = curr->next;
                ctr++;
            }
            
        } else { //if half the size is lesser than pos, start tail
            curr = tail;
            ctr = size; //inititalize ctr to size since mag sugod ka sa tail
            while (curr)
            {
                if (ctr == pos){
                    n->prev = curr->prev;
                    n->next = curr;
                    curr->prev->next = n; //update ang next sa curr->prev to n
                    curr->prev = n; //update ang curr->prev to n
                    break;//curr->prev->next and curr->prev kay lahi, ok?
                }
                curr = curr->prev;
                ctr--;
            }
        }
        size++;
    }

    int remove(int num){
        if (head->elem == num){
            node* temp = head;
            //head->next->next->prev = head;
            head = head->next;
            free(temp);
            size--;
            return 1;
        }

        if (tail->elem == num){
            node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            free(temp);
            size--;
            return size+1;
        }
        
        node* curr=head;
        int ctr = 1;
        while (curr){
            if (curr->elem == num) {
                node* temp = curr;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = curr->next;
                free(temp);
                size--;
                return ctr;
            } 
            curr = curr->next;
            ctr++;
        }
        return -1;
    }

    int removeAt(int pos) {
        if (pos == 1){
            node* temp = head;
            int t = temp->elem;
            head = head->next;
            if (head) head->prev = nullptr; //pwede ramn wala nang if statement
            free(temp);
            size--;
            return t;
        }
        if (pos == size) {
            node* temp = tail;
            int t = temp->elem;
            tail = tail->prev;
            if (tail) tail->next = nullptr; //pwede ramn wala nang if statement
            free(temp);
            size--;
            return t;
        }
        
        //declare curr and ctr
        node* curr;
        int ctr;

        if (size/2 >= pos){ //start head and set ctr to 1
            curr = head;
            ctr = 1;
            while (curr){
                if (ctr == pos) {
                    int t = curr->elem;
                    node* temp = curr;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    curr->prev = curr->next;
                    free(temp);
                    size--;
                    return t;
                } 
            curr = curr->next;
            ctr++;  
            }
        } else { //start tail and set ctr to size
            curr = tail;
            ctr = size;
            while (curr){
                if (ctr == pos) {
                    int t = curr->elem;
                    node* temp = curr;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    curr->prev = curr->next;
                    free(temp);
                    size--;
                    return t;
                } 
            curr = curr->prev;
            ctr--;  
            }
        }
        return -1;
    }

    
    int removeAll(int num) {
        node* curr = head;
        int ctr = 0;

        while (curr)
        {
            if (curr->elem == num) {
                if (curr == head){
                    //what's wrong with you TTOTT nganu binlan mn gyud nimog usa TTOTT
                    //mu work napd ni, basta naa lang ang else statement (curr = curr->next)
                    head = head->next;
                    head->prev = nullptr;
                    free(curr);
                    size--;
                    curr = head; //i balik si curr sa head
                    ctr++;
                
                } else if (curr == tail){        
                    //ikaw pd! nganu mu crash mn ka TTOTT
                    //nevermind, ok na ni, basta naa lang ang else statement (curr = curr->next)
                    tail = tail->prev;
                    tail->next = nullptr;
                    free(curr);
                    size--;
                    curr = nullptr; //set curr to nullptr to end this loop ug para di sha ma dangling pointer(?)
                    ctr++;
                
                } else {
                    node* temp = curr;
                    curr->prev->next = curr->next; //connect next of curr->prev to curr->next
                    curr->next->prev = curr->prev; //connect prev of curr->next to curr->prev
                    curr = curr->prev; //update curr to prev
                    free(temp);
                    size--;
                    ctr++;
                }
            } else curr = curr->next; //dapat i else kay every if statement above kay naay update mn
        }//if dili i else ni na statement:
        //for HEAD: ang curr, which is na set sa head, kay mo mve dayun sa curr->next
        //for TAIL: ang curr, which is na set to nullptr, kay mo move dayun sa next, which is wa shay gi point, that's why mu crash
        //for middle: ang curr, which is na set to curr->prev, kay mu move dayun sa next, which is nahug rag ni balik ra sha sa curr
        if (ctr > 0) return ctr;
        else return -1;
    }

    int getNum(int pos) {
        if (pos == 1) return head->elem;
        if (pos == size) return tail->elem;
        
        //declare curr and ctr
        node* curr;
        int ctr;

        if (size/2 >= pos){ //start head and set ctr to 1
            curr = head;
            ctr = 1;
            while (curr){
                if (ctr == pos) return curr->elem;
                curr = curr->next;
                ctr++;
            }
        } else { //start tail and set ctr to size
            curr = tail;
            ctr = size;
            while (curr){
                if (ctr == pos) return curr->elem;
                curr = curr->prev;
                ctr--;
            }
        }
        return -1;
    }

    int getPos(int num) {
        node* curr = head;
        int ctr = 1;
        while (curr)
        {
            if (curr->elem == num) return ctr; 
            curr = curr->next;
            ctr++;
        }
        return -1;
    }
    
    void printHead() {
        node* curr = head;
        cout<<"Size: "<<size<<endl;
        cout<<"From Head to Tail: "<<endl;
        while (curr)
        {
            cout<<curr->elem;
            if (curr->next) cout<<" -> ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void printTail() {
        node* curr = tail;
        cout<<"Size: "<<size<<endl;
        cout<<"From Tail to Head: "<<endl;
        while (curr)
        {
            cout<<curr->elem;
            if (curr->prev) cout<<" <- ";
            curr = curr->prev;
        }
        cout<<endl;
    }
};