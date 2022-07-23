#include  <iostream>
#include <string>
#include <vector>
 using namespace std;

class lessthan {
public:
    lessthan(){}
    lessthan (int val):_val(val),name("test"){}
    int  comp_val_out() const{return _val; }
    void comp_val_in(int val){_val == val;}

    bool operator()(int _value) const;//function object 重载括号
    friend  ostream& operator<<(ostream &os,lessthan& rhs); //这里本来两个参数会体术参数过多，但是改成友元没问题了。
    ~lessthan(){}


    //point to member function 
    typedef void (lessthan::*PtrType)(); //这一条语句将成员函数指针重命名为 PtrType
    
    //模式相同  成员指针可以指向以下任意一个函数
    void fibonacci(){name = "fibonacci";}
    void pell(){name = "pell";}
    void lucas(){name = "lucas";}
    void triangular(){name = "triangular";}
    void sequare(){name = "sequare";}
    void pentagonal(){name = "pentagonal";}

    PtrType pm = 0;//定义了函数指针为0.
    string name;
private:
    int _val;
    // static  shouled  be defiened out of the class ;
    static const int num_seq = 6;
    static PtrType func_tbl[num_seq]; //函数指针名称列表
    static vector< vector<int> > seq;
};

//the defien of static class;
const int lessthan::num_seq;
vector< vector<int> > lessthan::seq(num_seq);

//这里表明 用类里面的定义 定义了一个类里面的类型数组
lessthan::PtrType lessthan::func_tbl[num_seq]
 = {
  &lessthan::fibonacci,
  &lessthan::pell,
  &lessthan::lucas,
  &lessthan::triangular,
  &lessthan::sequare,
  &lessthan::pentagonal
 };
// 判断大小
bool lessthan::operator()(int _value)const{
    return _value <_val;
}
//friend 函数 类外直接定义
  ostream& operator<<(ostream &os , lessthan& rhs){
   os<<"("<<rhs.name<<")";
   return os;
}


int main (void)
{

    int a=10;
    lessthan MyProject(5);
    // if(MyProject(a)){ //这里调用重载的符号 不需要打“ . ”
    // cout <<"true"<<endl;
    // }else { cout << "false"<< endl;}
    MyProject(a)?cout<<"true"<<endl:cout<<"false"<<endl;
    cout << MyProject<<endl;

    lessthan::PtrType func_pos = 0; //这里要局部定义 为什么用类内部的定义就不行？
    func_pos= &lessthan::fibonacci;
    // MyProject.pm = &lessthan::fibonacci;
    (MyProject.*func_pos)();
    cout<<MyProject.name;
    return 0;
}
 
