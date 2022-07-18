#ifndef __TRIANGULAR_H
#define __TRIANGULAR_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;
class triangular{

public:
        triangular();//default;

        triangular(int length){
        _length =length;
        _newport = new string(" begain");
        cout<< "_newport has been built.\r\n"<<endl;}

        triangular(int length,int beg_pos);
        triangular(const triangular& rhs);
        triangular* copy(triangular& rhs);
        ~triangular(){delete _newport; cout<< "_newport has been deleted.\r\n"<<endl;};// default distruct
        //删除一个对象用delete 就可 删除数组指针等需要掉用多个析构函数的用 delete[]

        int length() const { return _length;}
        int beg_pos() const{ return _beg_pos;}
        void next_reset() const;
private:
        int _length;//总长度
        int _beg_pos;//起始位置
        mutable int _next;//下一个元素 multable变量被修改不影响const函数的const属性
        string _name;
        string* _newport;
        static vector<int> _elems;
friend class tri_interator;
};

vector<int> triangular::  _elems; //这个使用静态成员的时候必须要有

// default constructer
triangular::triangular(){
_length = 0;
_beg_pos = 0;
_next = -1;
_newport = new string(" begain");

cout<< "_newport has been built.\r\n"<<endl;
}
//Member initialization list 。why the private port can be used?
triangular::triangular(const triangular& rhs):_length(rhs._length),_beg_pos(rhs._beg_pos),_next(rhs._next){
    _newport = new string(" begain");
cout<< "_newport has been built.\r\n"<<endl;
}

//用初始化列表初始化string
triangular::triangular(int length,int beg_pos):_name("Ttiangulr")
{
 _length = length>0?length:1;
 _beg_pos = beg_pos>0?beg_pos:1;
 _next = _beg_pos-1;
 _newport = new string(" begain");
cout<< "_newport has been built.\r\n"<<endl;
}

void triangular::next_reset() const{
    _next = 10;//multable变量被修改不影响const函数的const属性
}

triangular* triangular::copy(triangular& rhs){
    if(this != &rhs)//对象不呢比较 没用重载运算符，只能用这种比较
    {
        this->_length = rhs._length;
        this->_name = rhs._name;
        this->_next = rhs._next;
    }
    return this;
}


/*-----------------------------------------------class tri_interator--------------------------------------------------------*/
class tri_interator{
public:
        tri_interator(int index):_index(index-1){}
        bool operator==(const tri_interator&) const; //声明时可以不给定义
        bool operator!=(const tri_interator&) const;
        int operator*() const;//*是没有参数的运算符
        tri_interator& operator++();
        tri_interator operator++(int);
         
private:
        bool check_integrity() const ;
        int _index;

friend class triangular;
};

bool tri_interator::operator==(const tri_interator&rhs)const{

return (_index == rhs._index);
}

bool tri_interator::operator!=(const tri_interator&rhs)const{

return !(_index == rhs._index);
}
bool tri_interator::check_integrity() const{
 if (_index > triangular::_elems.size())
 {return false;}
 return true;
}
int tri_interator::operator*() const
{
 if (check_integrity()){
  return triangular::_elems[_index];//返回对应地址的值
 }
 else return 0xFF;
}
#endif