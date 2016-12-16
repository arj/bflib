#ifndef BFLIB_STRINGS_STRING_H
#define BFLIB_STRINGS_STRING_H

#include <string>

namespace bflib {

    // TODO Fully compatible std::string implementation. Works everywhere where a string is needed by implicit conversion
//    template <
//            class CharT,
//            class Traits = std::char_traits<CharT>,
//            class Allocator = std::allocator<CharT>>
//    class basic_string {
//    public:
//        basic_string() : basic_string(Allocator()) {}
//        explicit basic_string(const Allocator& alloc);
//        basic_string(size_type count, CharT ch, const Allocator& alloc = Allocator());
//        basic_string(const basic_string& other,
//                      size_type pos,
//                      size_type count = bflib::basic_string::npos,
//                      const Allocator& alloc = Allocator());
//        basic_string( const basic_string& other,
//                      size_type pos,
//                      const Allocator& a = Allocator());
//        basic_string( const basic_string& other,
//                      size_type pos,
//                      size_type count,
//                      const Allocator& alloc = Allocator() );
//        basic_string( const CharT* s,
//                      size_type count,
//                      const Allocator& alloc = Allocator() );
//        (4)
//        basic_string( const CharT* s,
//                      const Allocator& alloc = Allocator() );
//        (5)
//        template< class InputIt >
//
//        basic_string( InputIt first, InputIt last,
//        const Allocator& alloc = Allocator() );
//        (6)
//        basic_string( const basic_string& other );
//        (7)
//        basic_string( const basic_string& other, const Allocator& alloc );
//        (7) 	(since C++11)
//        basic_string( basic_string&& other );
//        (8) 	(since C++11)
//        basic_string( basic_string&& other, const Allocator& alloc );
//        (8) 	(since C++11)
//        basic_string( std::initializer_list<CharT> init,
//        const Allocator& alloc = Allocator() );
//        (9) 	(since C++11)
//        explicit basic_string( std::basic_string_view<charT, traits> sv,
//        const Allocator& alloc = Allocator() );
//        (10) 	(since C++17)
//
//    private:
//        std::string string_;
//    };

}

#endif //BFLIB_STRINGS_STRING_H
