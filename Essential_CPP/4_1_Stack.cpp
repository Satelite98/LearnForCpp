#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MStack
{
    public:
    MStack(){ };
    bool push (const string&elem);
    bool pop (string &elem);
    bool peek(string &elem);

    bool empty();
    bool full();
    int size(){return _stack.size(); }
    
   ~MStack(){ };
    private:
    
    vector<string> _stack; //用vector模拟stack;
};

bool MStack::empty()
{
return _stack.empty();
}

bool MStack::full()
{
  return (_stack.size() == _stack.max_size());
}
bool MStack::pop(string &elem)
{
  if(this->empty()) { return false;}
  elem = _stack.back();//先取值 再弹出 FILO
  _stack.pop_back();
  return true;
}
bool MStack::push (const string&elem)
{
   if (full())
   {
    return false;
   }
   _stack.push_back(elem);
}

int main(void )
{
 MStack stackfortext;
 string forwrite;

 stackfortext.push("first");
 stackfortext.push("scend");
 stackfortext.pop(forwrite);
 cout<<forwrite<<"  ";
 stackfortext.pop(forwrite);
 cout<<forwrite;
return  0;
}

