#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

// PriorityQueue class template definition
template< typename T >
class PriorityQueue
{
   template< typename U >
   friend ostream &operator<<( ostream &output, const PriorityQueue< U > &priorityQueue );
public:
   PriorityQueue(); // default constructor
   bool empty() const;
   size_t size() const;
   const T& top() const;
   void push( const T& val );
   void pop();
private:
   vector< T > heap;
}; // end class template PriorityQueue

#endif

// default constructor
template< typename T >
PriorityQueue< T >::PriorityQueue()
{
   heap.push_back( T() );
}

template< typename T >
bool PriorityQueue< T >::empty() const
{
   return ( heap.size() == 1 );
}

template< typename T >
size_t PriorityQueue< T >::size() const
{
   return heap.size() - 1;
}

template< typename T >
const T& PriorityQueue< T >::top() const
{
   return heap[ 1 ];
}

template <typename T>
void PriorityQueue< T >::push( const T& val )
{
    //int tempPosition = heap.size();
    heap.push_back( T());
    int tempPosition = size();
  //  cout << (val < heap[tempPosition/2]) << endl;
    while((tempPosition != 1) && (heap[tempPosition/2] < val)) {
        heap[tempPosition] = heap[tempPosition/2];
        tempPosition /= 2;
    }
    heap[tempPosition] = val;
  //  cout << "temp:" << heap[tempPosition].id << " " << heap[tempPosition].time << endl;
//    cout << "temp-1:" << heap[tempPosition - 1].id << " " << heap[tempPosition - 1].time << endl;
   /* for(int i = 1; i < size(); ++i) {
        if(heap[i].time == heap[i + 1].time && heap[i].id > heap[i + 1].id) {
            T temp = heap[i];
            heap[i] = heap[i + 1];
            heap[i + 1] = temp;
        }
        else if(heap[i].time > heap[i + 1].time) {
            T temp = heap[i];
            heap[i] = heap[i + 1];
            heap[i + 1] = temp;
        }
    }*/    
   /* for(int i = 1; i <= size(); ++i)
        cout << heap[i].id << " ";
    cout << endl;
    for(int i  = 1; i <= size(); ++i)
        cout << heap[i].time << " ";
    cout << endl;*/
}

template <typename T>
void PriorityQueue<T>::pop()
{
    if(!empty()) {
        int parent, child;
        T temp = heap[size()];
        heap.resize(size());
        parent = 1; child = 2;
        while(child <= size()) {
            if((child < size() && (heap[child] < heap[child + 1])))
                child++;
            if(heap[child] < temp) break;
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = temp;
        if(heap[parent] < heap[parent + 1]) {
            T temp = heap[parent];
            heap[parent] = heap[parent + 1];
            heap[parent + 1] = temp;
        }
      /*  cout << "popped: ";
    for(int i = 1; i <= size(); ++i)
        cout << heap[i].id << " ";
    cout << endl;
    for(int i  = 1; i <= size(); ++i)
        cout << heap[i].time << " ";
    cout << endl;*/
    }
}

template< typename T >
ostream &operator<<( ostream &output, const PriorityQueue< T > &priorityQueue )
{
   typename vector< T >::const_iterator it;
   for( it = priorityQueue.heap.begin() + 1; it < priorityQueue.heap.end(); ++it )
      output << *it << endl;

   return output; // enables cout << x << y;
}

struct Node
{
   int id;
   int time;
   int period;

   bool operator<( const Node &rhs ) const
   {
      return time > rhs.time || ( time == rhs.time && id > rhs.id );
   }
};

int main()
{
   string command;
   PriorityQueue< Node > priorityQueue;

   while( cin >> command )
   {
      if( command == "#" )
         break;

      Node node;
      cin >> node.id >> node.period;
      node.time = node.period;

      priorityQueue.push( node );
   }

   int k;
   cin >> k;

   for( int i = 0; i < k; i++ )
   {
      Node node = priorityQueue.top();
      priorityQueue.pop();
      cout << node.id << endl;

      node.time += node.period;
      priorityQueue.push( node );
   }
   cout << endl;
}
