#include <iostream>
using namespace std;

class Node {
public:
    Node* linkfild_f;
    Node* linkfild_b;
    int index;
};
class Linkedlist {
private:
    Node* start;
    int size_of_list;
public:
    Linkedlist() {
        start = nullptr;
        size_of_list = -1;
    }
    void Insert(int n, int index);
    void Push_back(int index);
    void Remove(int n);
    void Printlist();
    void Pop_back();
    int Size();
    int get_num(int n);
    int get_last();
    bool Empty();
    Node* get_lastnode();

    friend Linkedlist& operator+(Linkedlist& L1, Linkedlist& L2);
    Node operator[](int n)
    {
        Node* Tempnode = start;
        for (int i=0; i<n; i++) Tempnode = Tempnode->linkfild_f;
        return *Tempnode;
    }
    Linkedlist& operator=(Linkedlist& List)
    {
        while(!Empty())
            Pop_back();
        Node* tempNode = List.start;
        while (tempNode != nullptr){
            Push_back(tempNode->index);
            tempNode = tempNode->linkfild_f;
        } delete tempNode;
        return *this;
    }
    Linkedlist& operator+=(Linkedlist& List)
    {
        Linkedlist Templist;
        Templist=List;
        Node* Tempnode_=Templist.start;
        for(int i=0; i<=Templist.size_of_list; i++){
            Push_back(Tempnode_->index);
            Tempnode_ = Tempnode_->linkfild_f;
        } delete Tempnode_;
        return *this;
    }
};

int main()
{
    Linkedlist li;
    li.Push_back(35592);
    li.Push_back(1111);
    li.Insert(1, 22);
    li.Printlist();

    Linkedlist li2;
    li2.Push_back(939);
    li2.Insert(0, 333);
    li2.Push_back(3885);
    li2.Printlist();

    li+=li2;
    li2=li;
    li.Printlist();
    li.Insert(4, 3030);
    li.Printlist();
    li+=li;
    li.Printlist();
    Linkedlist li3,li4;
    li3=li4=li;
    li.Insert(3, 5);
    li.Printlist(); li3.Printlist(); li4.Printlist();
}

Linkedlist& operator+(Linkedlist& L1, Linkedlist& L2){
    Linkedlist Templist;
    Node* Tempnode = L1.start;
    for(int i=0; i<L1.size_of_list; i++){
        Templist.Push_back(Tempnode->index);
        Tempnode = Tempnode->linkfild_f;
    }
    Tempnode = L2.start;
    for(int i=0; i<L2.size_of_list; i++){
        Templist.Push_back(Tempnode->index);
        Tempnode = Tempnode->linkfild_f;
    }delete Tempnode;
    return Templist;
}
void Linkedlist::Insert(int n, int idx) {
    if (n < 0) {
        cout << "You can't input a negative number." << endl;
        return;
    }
    Node* Newnode = new Node;
    Newnode->index = idx;
    if (size_of_list == -1) {
        Newnode->linkfild_b = nullptr;
        Newnode->linkfild_f = nullptr;
        start = Newnode;
        size_of_list++;
    }
    else if (n == 0) {
        start->linkfild_b = Newnode;
        Newnode->linkfild_f = start;
        start = Newnode;
        size_of_list++;
    }
    else if (n <= size_of_list) {
        Node* Tempnode = start;
        for (int i = 0; i < n - 1; i++) {
            if (Tempnode == nullptr) {
                cout << "Invalid index." << endl;
                return;
            }
            Tempnode = Tempnode->linkfild_f;
        }
        Newnode->linkfild_f = Tempnode->linkfild_f;
        Tempnode->linkfild_f->linkfild_b = Newnode;
        Newnode->linkfild_b = Tempnode;
        Tempnode->linkfild_f = Newnode;
        size_of_list++;
    }
    else {
        Node* Tempnode = start;
        while (Tempnode->linkfild_f != nullptr) {
            Tempnode = Tempnode->linkfild_f;
        }
        Tempnode->linkfild_f = Newnode;
        Newnode->linkfild_b = Tempnode;
        Newnode->linkfild_f = nullptr;
        size_of_list++;
    }
}
void Linkedlist::Push_back(int index) {
    Insert(size_of_list + 1, index);
}
void Linkedlist::Remove(int n) {
    if(n < 0){
        cout << "You can't input a negative number." << endl;
        return;
    }
    if(n > size_of_list){
        cout << "n is bigger than size of list." << endl;
        return;
    }
    if(n == 0){
        Node* temp = start;
        start = start->linkfild_f;
        delete temp;
        size_of_list--;
        return;
    }
    Node* Tempnode = start;
    for(int i=0; i<n-1; i++) Tempnode = Tempnode->linkfild_f;
    Node* Removenode = Tempnode->linkfild_f;
    if(Removenode->linkfild_f!=nullptr)
        Removenode->linkfild_f->linkfild_b = Tempnode;
    Tempnode->linkfild_f = Removenode->linkfild_f;
    delete Removenode;
    size_of_list--;

    return;
}
void Linkedlist::Pop_back(){
    Remove(size_of_list);
}
void Linkedlist::Printlist(){
    Node* Tempnode = start;
    for(int i=0; i<=size_of_list; i++){
        cout<<Tempnode->index<<" ";
        Tempnode = Tempnode->linkfild_f;
    }
    cout<<endl;
}
int Linkedlist::Size() {
    return size_of_list + 1;
}
int Linkedlist::get_num(int n){
    if(n<0){
        cout << "You can't input a negative number." << endl;
    }
    if(n>size_of_list){
        cout << "n is bigger than size of list." << endl;
    }
    else{
        Node* Tempnode = start;
        for (int i=0; i<n; i++) Tempnode = Tempnode->linkfild_f;
        return Tempnode->index;
    }
}
int Linkedlist::get_last()
{
    if (size_of_list == -1){
        cout << "List is empty." << endl;
        return -1;
    }
    Node* Tempnode = start;
    while (Tempnode->linkfild_f != nullptr) {
        Tempnode = Tempnode->linkfild_f;
    }
    return Tempnode->index;
}
Node* Linkedlist::get_lastnode()
{
    Node* Tempnode = start;
    while (Tempnode->linkfild_f != nullptr) {
        Tempnode = Tempnode->linkfild_f;
    }
    return Tempnode;
}
bool Linkedlist::Empty(){
    return size_of_list==-1?1:0;
}
