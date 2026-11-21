#include <iostream>
#include <vector>
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
            while(p){
                SLLNode* n=p->next;
                delete p;
                p=n;
            }
    }

    int size(){
        int counter=0;
        SLLNode* p=start;
        while(p){
            p=p->next;
            counter++;
        }
        return counter;
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
    void MoveBy(int d){
        d=d%this->size();
        if(d){
            d=this->size()-d;
            SLLNode* newstart=start;
            for(int i=0; i<d; i++){
                newstart=newstart->next;
            }
            SLLNode* p=start;
            while(p->next){
                if(p->next==newstart){
                    SLLNode* t=p;
                    p=p->next;
                    t->next=nullptr;
                }
                else
                    p=p->next;
            }
            p->next=start;
            start=newstart;
        }
    }
};

struct DLLNode{
    int value;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int value=0, DLLNode* next=nullptr, DLLNode* prev=nullptr): value(value), next(next), prev(prev) {}
};
struct DLL{
    DLLNode* start;
    DLL(): start(nullptr) {}
    ~DLL(){
        DLLNode* p=start;
        while(p){
            DLLNode* n=p->next;
            delete p;
            p=n;
        }
    }

    int size(){
        int counter=0;
        DLLNode* p=start;
        while(p){
            p=p->next;
            counter++;
        } 
        return counter;
    }
    void print(){
        std::cout << "NULL<->";
        DLLNode* p=start;
        while(p){
            std::cout << p->value << "<->";
            p=p->next;
        }
        std::cout << "NULL\n";
    }
    void AddNode(int value, int ind=INT_MAX){
        DLLNode* n=new DLLNode(value);
        if(!start){
            start=n;
            return;
        }
        if(ind==-1){
            n->next=start;
            start->prev=n;
            start=n;
            return;
        }
        int counter=0;
        DLLNode* p=start;
        while(p->next && counter<ind){
            p=p->next;
            counter++;
        }
        n->next=p->next;
        n->prev=p;
        if(p->next)
            p->next->prev=n;
        p->next=n;
    }
    void MoveBy(int d){
        d=d%this->size();
        if(d){
            d=this->size()-d;
            DLLNode* newstart=start;
            for(int i=0; i<d; i++)
                newstart=newstart->next;
            DLLNode* p=start;
            while(p->next){
                if(p->next==newstart){
                    DLLNode* t=p;
                    p=p->next;
                    t->next=nullptr;
                    newstart->prev=nullptr;
                }
                else
                    p=p->next;
            }
            p=p->next=start;
            start->prev=p;
            start=newstart;
        }
    }
};

struct CLL{
    SLLNode* start;
    CLL(): start(nullptr) {}
    ~CLL(){
        SLLNode* p=start;
        while(p->next!=start){
            SLLNode* n=p->next;
            delete p;
            p=n;
        }
        delete p;
    }

    int size(){
        if(!start)
            return 0;
        SLLNode* p=start;
        int counter=1;
        while(p->next!=start){
            p=p->next;
            counter++;
        }
        return counter;
    }
    void print(){
        SLLNode* p=start;
        while(p->next!=start){
            std::cout << p->value << "->";
            p=p->next;
        }
        std::cout << p->value << '\n';
    }
    void AddNode(int value, int ind=INT_MAX){
        SLLNode* n=new SLLNode(value);
        if(!start){
            start=n;
            start->next=start;
            return;
        }
        if(ind==-1){
            SLLNode* p=start;
            while(p->next!=start)
                p=p->next;
            n->next=start;
            p->next=n;
            start=n;
            return;
        }
        if(ind>=size()){
            SLLNode* p=start;
            while(p->next!=start)
                p=p->next;
            n->next=start;
            p->next=n;
        }
        else{
            SLLNode* p=start;
            int counter=0;
            while(counter<ind){
                p=p->next;
                counter++;
            }
            n->next=p->next;
            p->next=n;
        }
    }
    void MoveBy(int d){
        d=d%this->size();
        if(d){
            d=this->size()-d;
            SLLNode* newstart=start;
            for(int i=0; i<d; i++)
                newstart=newstart->next;
            start=newstart;
        }
    }
};

int main(){
    int d;
    std::cin >> d;
    std::vector<int> v={1, 2, 3, 4, 5};
    for (int i=0; i<d; i++){
        int tmp=v[v.size()-1];
        for (int j=v.size()-1; j>0; j--){
            v[j]=v[j-1];
        }
        v[0]=tmp;
    }
    for (int i=0; i<v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << '\n';
    SLL list;
    list.AddNode(3);
    list.AddNode(2);
    list.AddNode(1);
    list.AddNode(4);
    list.print();
    list.MoveBy(5);
    list.print();
    DLL dlist;
    dlist.AddNode(3);
    dlist.AddNode(2);
    dlist.AddNode(1);
    dlist.AddNode(4);
    dlist.print();
    dlist.MoveBy(3);
    dlist.print();
    CLL clist;
    clist.AddNode(3);
    clist.AddNode(2);
    clist.AddNode(1);
    clist.AddNode(4);
    clist.print();
    clist.MoveBy(6);
    clist.print();

    return 0;
}