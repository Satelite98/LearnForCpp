#ifndef __BOOK_H
#define __BOOK_H


class libMat {
public:

// constructor can not be virtual ,but destruct can be !.
 libMat(){cout<<"the construct of libmat \n"<<endl; }
 virtual ~libMat(){cout<< "the destructor of libmat \n"<<endl;}
 virtual void print() const { cout<<"libmat:: print \n"<<endl; }

 private:

};


// father reference
void print(const libMat& mat )
{
 cout << "in non-member print \n"<<endl;
 mat.print();
}

#endif/*__BOOK_H*/