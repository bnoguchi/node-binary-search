#include <v8.h>

using namespace v8;

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
