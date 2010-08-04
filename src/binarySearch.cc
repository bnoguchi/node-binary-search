#include <v8.h>

using namespace v8;

// Copy/pasted from http://www.fredosaurus.com/notes-cpp/algorithms/searching/binarysearch.html
int binarySearch(int sortedArray[], int first, int last, int key) {
   // function:
   //   Searches sortedArray[first]..sortedArray[last] for key.  
   // returns: index of the matching element if it finds key, 
   //         otherwise  -(index where it could be inserted)-1.
   // parameters:
   //   sortedArray in  array of sorted (ascending) values.
   //   first, last in  lower and upper subscript bounds
   //   key         in  value to search for.
   // returns:
   //   index of key, or -insertion_position -1 if key is not 
   //                 in the array. This value can easily be
   //                 transformed into the position to insert it.
   
   while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key > sortedArray[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (key < sortedArray[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return mid;     // found it. return position /////
   }
   return -(first + 1);    // failed to find key
}


int binary_search(Local<Array> ary, unsigned int r) {
    int upper = ary->Length() - 1;
    int lower = 0;
    int idx = 0;

    while (lower <= upper) {
        idx = (lower + upper) / 2;

        unsigned int l = ary->Get(idx)->Uint32Value();
        if (l == r) {
          return idx;
        }
        else if (l > r) {
          upper = idx - 1;
        }
        else {
          lower = idx + 1;
        }
    }
    if (upper < 0) {
        upper = ary->Length() - 1;
    }
    return upper;
}

Handle<Value> Generate( const Arguments &args ) {
    HandleScope scope;
    Local<Object> o = args[0]->ToObject();
    Local<Array> a = Local<Array>::Cast(o);
    return Integer::New(binary_search(a, args[1]->Uint32Value()));
}

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;
    Local<FunctionTemplate> t = FunctionTemplate::New(Generate);
    target->Set(String::NewSymbol("binarySearch"), t->GetFunction());
}
