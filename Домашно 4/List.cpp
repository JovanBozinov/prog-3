#include <iostream>
#include <climits>

struct SLLNode{
    int value;
    SLLNode* next;
    SLLNode(int value=0, SLLNode* next=nullptr): value(value), next(next) {}
};
struct SLL{
    SLLNode* start;
    SLL(): start(nullptr) {}
    ~SLL(){
        SLLNode* p=start;
        if(p){
            while(p){
                SLLNode* n=p->next;
                delete p;
                p=n;
            }
        }
    }

    void print(){
        SLLNode* p=start;
        while(p){
            std::cout << p->value << "->";
            p=p->next;
        }
        std::cout << "NULL\n";
    }

    void AddNode(int value, int ind=INT_MAX){
        SLLNode* n=new SLLNode(value);
        if(!start){
            start=n;
            return;
        }
        if(ind==-1){
            n->next=start;
            start=n;
            return;
        }
        int counter=0;
        SLLNode* p=start;
        while(p->next && counter<ind){
            p=p->next;
            counter++;
        }
        n->next=p->next;
        p->next=n;    
    }
    void RemoveByind(int ind){
        SLLNode* p=start;
        if(ind==0){
            p=start->next;
            delete start;
            start=p;
            return;
        }
        int counter=0;
        while(p->next && counter+1<ind){
            p=p->next;
            counter++;
        }
        if(counter+1==ind && p->next){
            SLLNode* t=p->next;
            p->next=t->next;
            delete t;
        }
    }
    void RemoveByVal(int value, bool All=false){
        if(All){
            SLLNode* p=start;
            while(p->next){
                if(p->next->value==value){
                    SLLNode* t=p->next;
                    p->next=t->next;
                    delete t;
                }
                if(!p->next)
                    break;
                p=p->next;
            }
            if(start->value==value){
                p=start;
                start=p->next;
                delete p;
            }
        }
        else{
            SLLNode* p=start;
            if(start->value==value){
                start=p->next;
                delete p;
            }
            else{
                while(p->next){
                    if(p->next->value==value){
                        SLLNode* t=p->next;
                        p->next=t->next;
                        delete t;
                        break;
                    }
                    p=p->next;
                }
            }
        }
    }
};

int main(){
    SLL list;
    list.AddNode(1);
    list.AddNode(2, -1);
    list.print();
    list.AddNode(3, -1);
    list.print();
    list.AddNode(4);
    list.RemoveByind(4);
    list.print();
    list.RemoveByVal(4, false);
    list.print();
    list.AddNode(2);
    list.print();
    list.RemoveByVal(2, true);
    list.print();
    
    return 0;
}