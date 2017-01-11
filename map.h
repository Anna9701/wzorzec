#ifndef _MAP_H_
 #define _MAP_H_
 #include <iostream>
 #include <cstdlib>
 #include <string.h>
 #include <string>
 #include <cctype>
 #include <typeinfo>
 using namespace std;
 template <class klucz, class typ> 

   class Map{
    public:
		Map();
		Map(const Map &);
	        ~Map();

		Map& operator= (const Map&);
		int& operator[](klucz);
		void Add (klucz, typ&);
 		typ* find (klucz) const;
		friend ostream& operator<< (ostream& os, const Map &tab){
			node* temp = tab.head;	
			while(temp != NULL){
		         cout << "\"" << temp->key << "\"\t"; 
			 cout << *temp->val << endl;
			 temp = temp->next; 
			}
			
			return os;
		} 
	    
    private:
		struct node;
                node *head;

	   	void clear();
		void swap(Map &);
                virtual bool porownaj(klucz, klucz)const;
                
               

	        struct node{
	          node *next;
	          klucz key;
	          typ *val;
		  
	          node(const klucz k): next(NULL){		    
		  	        key = k;
		
	          }
	          node(const klucz k, const typ &v): next(NULL){
		    key = k;
	            val = new typ(v);
		   // val = v;
	          }
	          node (node &x): next(NULL){
		//  if(x.key == NULL)
		// 	key = NULL;
		//  else{
			key = x.key;
		   
		   val = new typ(*x.val);
		  // val = x.val;
	          }  
	          ~node(){
		    delete val;
		   }
	          
                private:
		node &operator=(const node &);
	       };
  };

	template<class klucz, class typ> 
	Map<klucz, typ>::Map (){
		head = NULL;
	}

	template<class klucz, class typ>
	Map<klucz, typ>::Map(const Map &x){
		node *src, **dst;
		head = NULL;
		src = x.head;
		dst = &head;
		while(src){
			*dst = new node(*src);
			src = src->next;
			dst = &((*dst)->next);
		}
	}
	template <class klucz, class typ>
	 Map<klucz, typ>::~Map(){
		clear();
	}
	template<class klucz, class typ>
	void Map<klucz, typ>::clear(){
		while(head){
			node *temp = head->next;
			delete head;
			head = temp; 
		}
	}
	template <class klucz, class typ>
	 void Map<klucz, typ>::Add(klucz k, typ &v){
		node *n = new node(k, v);
		n->next = head; 
		head = n;
	}
	template<class klucz, class typ>
	void Map<klucz, typ>::swap (Map &x){
		node *temp = head;
		head = x.head;
		x.head = temp;
	}
	template<class klucz, class typ>
	Map<klucz, typ>& Map<klucz, typ>::operator= (const Map &x){
		if(&x == this)
			return *this;
	
		Map temp (x);
		swap (temp);
	
		return *this;
	}
	template<class klucz, class typ>
	int& Map<klucz, typ>::operator[] (klucz key){
		node *x = find (key);
		if(!x){
			Add(key, 0);
			x = head;
		}
	
		return x->val;
	}
	template <class klucz, class typ>
	//typename Map<klucz, typ>::typ* Map<klucz, typ>::find(klucz key) const{
	typ* Map<klucz, typ>::find(klucz key) const{

		node *x = head;
		while(x){
		if(porownaj(x->key, key))
				return x->val;
			x = x->next;
		};
	
		return NULL;
	}
	template <class klucz, class typ>
	bool Map<klucz, typ>::porownaj(klucz key1, klucz key2)const{
	    if(key1 == key2)
		return true;
	    else
		return false;
	}

	
			
#endif

