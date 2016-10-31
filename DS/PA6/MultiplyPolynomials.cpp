#include <iostream>
using namespace std;

#ifndef LIST_NODE_H
#define LIST_NODE_H

template< typename T > class LinkedList;   // forward declare
template< typename T > class ListIterator; // forward declare
// ListNode class template definition
template< typename T >
class ListNode
{
        template< typename U > friend class LinkedList;
        template< typename U > friend class ListIterator;
private:
        T data;
        ListNode< T > *next;
}; // end class template ListNode

#endif

// ListIterator class template definition
#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

// ListIterator class template definition
template< typename T >
class ListIterator
{
        template< typename U > friend class LinkedList;
public:
        ListIterator(ListNode< T > *p = 0); // default constructor
        ~ListIterator(); // destructor
        T& operator*() const; // dereferencing operator
        T* operator->() const; // class member access operator
        ListIterator< T >& operator++(); // prefix increment operator
        //   ListIterator< T > operator++( int ); // postfix increment operator
        bool operator==(const ListIterator< T > &right) const; // equal to
        bool operator!=(const ListIterator< T > &right) const; // not equal to
private:
        ListNode< T > *ptr; // keep a pointer to LinkedList
}; // end class template ListIterator

#endif

// default constructor
template< typename T >
ListIterator< T >::ListIterator(ListNode< T > *p)
: ptr(p)
{
}

// destructor
template< typename T >
ListIterator< T >::~ListIterator()
{
}

// overloaded dereference operator
template< typename T >
T& ListIterator< T >::operator*() const
{
        return ptr->data;
}

// overloaded class member access operator
template< typename T >
T* ListIterator< T >::operator->() const
{
        return &(ptr->data);
}

// overloaded prefix increment operator
template< typename T >
ListIterator< T >& ListIterator< T >::operator++()
{
        ptr = ptr->next;
        return *this;
}

// overloaded equality operator
template< typename T >
bool ListIterator< T >::operator==(const ListIterator< T > &right) const
{
        return ptr == right.ptr;
}

// overloaded inequality operator
template< typename T >
bool ListIterator< T >::operator!=(const ListIterator< T > &right) const
{
        return ptr != right.ptr;
}

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// LinkedList class template definition
template< typename T >
class LinkedList
{
public:
        typedef ListIterator< T > iterator;
        LinkedList(); // Constructs an empty linked list, with no elements.
        
        // Constructs a linked list with a copy of each of the elements in listToCopy, in the same order.
        LinkedList(const LinkedList< T > &listToCopy);
        
        // Destroys all linked list elements, and deallocates all the storage allocated by the linked list.
        ~LinkedList();
        
        // Copies all the elements from "right" into the linked list
        const LinkedList< T > &operator=(const LinkedList< T > &right);
        
        const ListIterator< T > begin() const; // Returns head
        
        const ListIterator< T > end() const; // Returns NULL
        
        // The linked list is extended by inserting a new element before the head of the linked list.
        iterator insertHead(const T val);
        
        // The linked list is extended by inserting a new element before the element at the specified position.
        // This effectively increases the list size by one.
        iterator insert(iterator position, const T val);
        
        // Removes from the linked list the element at the specified position.
        // This effectively reduces the list size by one.
        iterator erase(iterator position);
        
        //Returns a bool value indicating whether the linked list is empty, i.e. whether head == NULL.
        bool empty() const;
        
        // Removes all elements from the linked list (which are destroyed),
        void clear(); // and resets head and tail to null pointer
private:
        ListNode< T > *head; // pointer to the first element of linked list
        ListNode< T > *tail; // pointer to the last element of linked list
}; // end class template LinkedList

#endif

// Constructs an empty linked list, with no elements.
template< typename T >
LinkedList< T >::LinkedList()
: head(NULL),
tail(NULL)
{
}

template< typename T >
LinkedList< T >::LinkedList(const LinkedList< T > &listToCopy)
{
        if (listToCopy.head == NULL) /* if the listtocopy is empty */
                head = tail = NULL;
        else {
                head = new ListNode<T>;
                head->data = listToCopy.head->data; /* set head */
                head->next = NULL;
                ListNode<T> *trail = head; /* to access element */
                ListNode<T> *newNode =NULL;
                ListNode<T> *ltcnode = listToCopy.head->next;
                if(ltcnode == NULL) /* if only has one element */
                        tail = head;
                else {
                        for(; ltcnode!=NULL; ltcnode= ltcnode->next) {
                                newNode = new ListNode<T>;
                                newNode->data = ltcnode->data;
                                trail->next = newNode;
                                trail = trail->next;
                        }
                        tail = newNode;
                }
        }
}

template<typename T>
const LinkedList< T > &LinkedList<T>::operator=(const LinkedList< T > &right)
{
        if (this != &right) {
                clear(); /* clean up */
                if (right.empty()) /* if right is empty */
                        return *this;
                head = new ListNode<T>;
                head->next = NULL;
                tail = head;
                ListNode<T> *tnode = head;
                ListNode<T> *rnode = right.head;
                ListNode<T> *newNode;
                for(; rnode != right.tail; rnode = rnode->next) { /* assign element */
                        tnode->data = rnode->data;
                        newNode = new ListNode<T>;
                        tnode->next = newNode;
                        tnode = tnode->next;
                }
                tnode->data = rnode->data;
                tnode->next = NULL;
                tail = tnode;
        }
        return *this;
}

// Destroys all linked list elements, and deallocates all the storage allocated by the linked list.
template< typename T >
LinkedList< T >::~LinkedList()
{
        clear();
}

template< typename T >
const ListIterator< T > LinkedList< T >::begin() const
{
        return ListIterator< T >(head);
}

template< typename T >
const ListIterator< T > LinkedList< T >::end() const
{
        return ListIterator< T >(NULL);
}

//Returns a bool value indicating whether the linked list is empty.
template< typename T >
bool LinkedList< T >::empty() const
{
        return (head == NULL);
}

// The linked list is extended by inserting a new element before the head of the linked list.
template< typename T >
ListIterator< T > LinkedList< T >::insertHead(const T val)
{
        ListNode< T > *newNode = new ListNode< T >;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) // empty list
                tail = newNode;
        else
                newNode->next = head;
        head = newNode;
        
        return iterator(newNode);
}

template <typename T>
ListIterator<T> LinkedList<T>::insert(iterator position, const T val)
{
        if(position.ptr == head) /* if position is head */
                insertHead(val);
        else if(position.ptr == NULL) { /* if position is NULL, which also means push_back */
                ListNode<T> *newNode = new ListNode<T>;
                newNode->data = val;
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
        }
        else {
                ListNode<T> *trail = head;
                for(; trail->next != position.ptr; trail = trail->next);
                ListNode<T> *newNode = new ListNode<T>;
                newNode->data = val;
                newNode->next = position.ptr;
                trail->next = newNode;
        }
        return position;
}

template<typename T>
ListIterator<T> LinkedList<T>::erase(iterator position)
{
        if(head != NULL) {
                ListNode<T> *trail = head;
                if(position.ptr == head) {
                        head = head->next;
                        if(head ==NULL)
                                tail = NULL;
                        delete trail;
                }
                else {
                        for(;trail->next != position.ptr; trail = trail->next);
                        if(position.ptr == tail) /* erase the last element */
                                tail = trail;
                        trail->next = position.ptr->next;
                        delete position.ptr;
                        position.ptr = trail;
                }
        }
        return position;
}

// Removes all elements from the linked list (which are destroyed),
// and resets head and tail to null pointer
template< typename T >
void LinkedList< T >::clear()
{
        if (head != NULL) // the list is not empty
        {
                ListNode< T > *trail;
                ListNode< T > *ptr = head;
                
                while (ptr != NULL)
                {
                        trail = ptr;
                        ptr = ptr->next;
                        delete trail;
                }
                
                head = NULL;
                tail = NULL;
        }
}

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

// Represents a term of a polynomial
struct Term
{
        int coef;
        int expon;
};

// Polynomial class template definition
template< typename T >
class Polynomial
{
        // Overloaded stream insertion operator
        template< typename U >
        friend ostream &operator<<(ostream &output, const Polynomial< U > &a);
public:
        Polynomial(); // Constructs an empty polynomial, with no terms.
        
        // Constructs a polynomial with a copy of each of the terms in polynomialToCopy.
        Polynomial(const Polynomial< T > &polynomialToCopy);
        
        ~Polynomial(); // Destructor with empty body
        
        // Copies all the terms from "right" into the polynomial
        const Polynomial< T > operator=(const Polynomial< T > &right);
        
        void create(); // Creates a polynomial
        
        Polynomial< T > operator*(const Polynomial< T > &b); // Returns the product of two polynomials
private:
        T polynomial; // a polynomial
        
        void insert(Term termToInsert); // Inserts a new term into the polynomial
        
        bool zero() const; // Returns true if and only if polynomial is a zero polynomial
}; // end class template Polynomial

#endif


// Constructs an empty polynomial, with no terms.
template< typename T >
Polynomial< T >::Polynomial()
: polynomial()
{
}

// Constructs a polynomial with a copy of each of the terms in polynomialToCopy.
template< typename T >
Polynomial< T >::Polynomial(const Polynomial &polynomialToCopy)
: polynomial(polynomialToCopy.polynomial)
{
}

// Destructor with empty body
template< typename T >
Polynomial< T >::~Polynomial()
{
}

// Copies all the terms from "right" into the polynomial
template< typename T >
const Polynomial< T > Polynomial< T >::operator=(const Polynomial< T > &right)
{
        if (&right != this) // avoid self-assignment
                polynomial = right.polynomial;
        
        return *this; // enables x = y = z, for example
}

// Randomly generates a polynomial with "numTerms" terms
template< typename T >
void Polynomial< T >::create()
{
        int numTerms;
        cin >> numTerms;
        Term newTerm;
        for (int i = 0; i < numTerms; i++)
        {
                cin >> newTerm.coef >> newTerm.expon;
                insert(newTerm);
        }
}

// Multiplies two polynomials
template< typename T >
Polynomial< T > Polynomial< T >::operator*(const Polynomial< T > &b)
{
        Polynomial< T > product;
        Term newTerm;
        if (!zero() && !b.zero())
                for (LinkedList< Term >::iterator itA = polynomial.begin(); itA != polynomial.end(); ++itA)
                        for (LinkedList< Term >::iterator itB = b.polynomial.begin(); itB != b.polynomial.end(); ++itB)
                        {
                                newTerm.coef = itA->coef * itB->coef;
                                newTerm.expon = itA->expon + itB->expon;
                                product.insert(newTerm);
                        }
        
        return product;
}

// Returns true if and only if polynomial is a zero polynomial
template< typename T >
bool Polynomial< T >::zero() const
{
        return polynomial.empty();
}

// Overloaded stream insertion operator
template< typename T >
ostream &operator<<(ostream &output, const Polynomial< T > &a)
{
        if (a.zero())
        {
                output << 0 << endl;
                return output;
        }
        
        LinkedList< Term >::iterator it = a.polynomial.begin();
        
        output << it->coef;
        if (it->expon != 0)
                output << "x^" << it->expon;
        
        for (++it; it != a.polynomial.end(); ++it)
        {
                if (it->coef > 0)
                        output << " + " << it->coef;
                else
                        output << " - " << -it->coef;
                
                if (it->expon != 0)
                        output << "x^" << it->expon;
        }
        
        output << endl;
        
        return output; // enables cout << x << y;
} // end function operator<<

template <typename T>
void Polynomial<T>::insert(Term termToInsert)
{
        if (termToInsert.coef != 0) {
                if(zero()) /* if it's empty */
                        polynomial.insertHead(termToInsert);
                else {
                        LinkedList<Term>::iterator it = polynomial.begin();
                        while(it != polynomial.end()) {
                                if(it->expon == termToInsert.expon) {
                                        it->coef += termToInsert.coef;
                                        if(it->coef == 0)
                                                polynomial.erase(it);
                                                return;
                                }
                        
                                if(it->expon < termToInsert.expon) { /* tTI expon > it expon */
                                        polynomial.insert(it, termToInsert);
                                        return;
                                }
                                ++it; /* jump to next one */
                                if (it == polynomial.end())
                                        polynomial.insert(it, termToInsert);
                        }
                        
                }
        }
}

int main()
{
        Polynomial< LinkedList< Term > > multiplicand; // create an empty polynomial
        Polynomial< LinkedList< Term > > multiplier; // create an empty polynomial
        Polynomial< LinkedList< Term > > product; // create an empty polynomial
        multiplicand.create(); // create a polynomial with 3 terms
        multiplier.create(); // create a polynomial with 4 terms
        product = multiplicand * multiplier;
        cout << product;
}
