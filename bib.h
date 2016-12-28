#ifndef _BIB_H_
 #define _BIB_H_
 using namespace std;
 #include <iostream> 
 #include <cctype>
 #include <string.h>
 class Book{
  public:
	Book(char*, char*, int, bool);
        Book(const Book&);
	~Book();

        void setAuthor(char*);
	void setCat(char*);
	void setNumber(int);
	void setStatus(bool);

        friend ostream& operator <<(ostream&, const Book&);
  private:
	char* author;
	char* cathegory;
	int number;
	bool status;
 };
#endif
