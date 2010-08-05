#include <v8.h>

using namespace v8;

// Finds the closest index where value <= the given value
int floor_binary_search(Local<Array> ary, unsigned int r) {
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
    return -1;
}

Handle<Value> GenerateFloorBinarySearch( const Arguments &args ) {
    HandleScope scope;
    Local<Object> o = args[0]->ToObject();
    Local<Array> a = Local<Array>::Cast(o);
    return Integer::New(floor_binary_search(a, args[1]->Uint32Value()));
}

Handle<Value> GenerateBinarySearch( const Arguments &args ) {
    HandleScope scope;
    Local<Object> o = args[0]->ToObject();
    Local<Array> a = Local<Array>::Cast(o);
    return Integer::New(binary_search(a, args[1]->Uint32Value()));
}

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;
    Local<FunctionTemplate> t1 = FunctionTemplate::New(GenerateFloorBinarySearch);
    target->Set(String::NewSymbol("floorBinarySearch"), t1->GetFunction());
    Local<FunctionTemplate> t2 = FunctionTemplate::New(GenerateBinarySearch);
    target->Set(String::NewSymbol("binarySearch"), t2->GetFunction());
}
