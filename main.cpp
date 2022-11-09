#include "header.hpp"

int test_msgpack()
{

    // std::stringstream ss;
    
    // A aaa(25);
    // msgpack::pack(ss, aaa);
    // // serialize_msgpack(&aaa, FIRST_FILE);

    // // deserialize the buffer into msgpack::object instance.
    // msgpack::unpacked unp;
    // msgpack::unpack(unp, ss.str().data(), ss.str().size());
    // msgpack::object deserialized = unp.get();

    // // msgpack::object supports ostream.
    // std::cout << deserialized << std::endl;

    // // convert msgpack::object instance into the original type.
    // // if the type is mismatched, it throws msgpack::type_error exception.
    // A aParse;
    // deserialized.convert(aParse);

    // or create the new instance
    // A aParse2 =
    //     deserialized.as<A>();

    //B bbb{&aParse};
    // serialize_msgpack(&bbb, SECOND_FILE);

    // B bParse;
    // deserialize_msgpack(&bParse, SECOND_FILE);

    A aaa(25);
    serialize_msgpack(aaa, FIRST_FILE);
    
    A aParse;
    deserialize_msgpack(aParse, FIRST_FILE);

    B bbb{&aParse};
    serialize_msgpack(bbb, SECOND_FILE);

    B bParse;
    deserialize_msgpack(bParse, SECOND_FILE);



    return 0;
}

int test_json()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    A aaa(25);
    serealize_json(aaa, FIRST_FILE);
    
    A aParse;
    deserealize_json(aParse, FIRST_FILE);

    B bbb{&aParse};
    serealize_json(bbb, SECOND_FILE);

    B bParse;
    deserealize_json(bParse, SECOND_FILE);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << endl << endl;
    std::cout << "Time of working: "<< duration << endl;

    return 0;
}

int main(int argc, char* argv[]) {

    test_msgpack();
    //test_json();
}
