/*
   Copyright 2016 Dejan D. M. Milosavljevic

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
/*
 Project Name: PNM
 Description: One-time usage logging
 Source: http://github.com/dmilos/TopLog
*/
#ifndef TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8
#define TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>
#include <cstring>
#include <mutex>


// {{{ Begin of Configuration.
#if !defined( TOPLOG__OUTPUT_FILE )
#define TOPLOG__OUTPUT_FILE     true
#endif

#if !defined( TOPLOG__OUTPUT_CONSOLE )
#define TOPLOG__OUTPUT_CONSOLE  false
#endif

#define TOPLOG__LOG_PREFIX__DATETIME     "[" << TopLogNamespace::getCurrentTime() << "] "
#define TOPLOG__LOG_PREFIX__THREADID      TopLogNamespace::getCurrentThreadID()
#define TOPLOG__LOG_PREFIX__FILE_LONG          __FILE__
#define TOPLOG__LOG_PREFIX__FILE_SHORT      (strrchr(__FILE__, TOPLOG__FOLDER_SEPARATOR) ? strrchr(__FILE__, TOPLOG__FOLDER_SEPARATOR) + 1 : __FILE__)
#define TOPLOG__LOG_PREFIX__FUNCTION      __FUNCTION__
#define TOPLOG__LOG_PREFIX__LINE          __LINE__

#define TOPLOG__LOG_PREFIX_COMPLETE         TOPLOG__LOG_PREFIX__DATETIME          \
                                        <<  TOPLOG__LOG_PREFIX__THREADID << " "\
                                        <<  TOPLOG__LOG_PREFIX__FILE_SHORT << "(" << TOPLOG__LOG_PREFIX__LINE << "):" \
                                        <<  TOPLOG__LOG_PREFIX__FUNCTION << " - "


#if defined( _MSC_BUILD )
// Must include trailing backslash
#define TOPLOG__FILE_FOLDER     ".\\"

#pragma warning ( push )
#pragma warning ( disable: 4244 )
#endif

#if defined(__GNUC__) || defined(__GNUG__)
// Must include trailing slash
#define TOPLOG__FILE_FOLDER     "./"
#endif


#define TOPLOG__FILE_PREFIX     "TopLog_"

// End of configuration }}}

// Everything in this namespace are considered as private
#if defined( _MSC_BUILD )
#define TOPLOG__FOLDER_SEPARATOR     '\\'
#endif

#if defined(__GNUC__) || defined(__GNUG__)
#define TOPLOG__FOLDER_SEPARATOR     '/'
#endif
namespace TopLogNamespace
 {

  inline std::thread::id getCurrentThreadID()
   {
    return std::this_thread::get_id();
   }


  inline std::string getCurrentTime()
   {
    time_t t = time(0);

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4996 )
#endif
    tm   n = *localtime( &t );
#ifdef _MSC_VER
#pragma warning( pop )
#endif

    std::stringstream ss;

    ss <<                                      n.tm_year + 1900 << "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_mon  + 1    <<  "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_mday        <<  "_";
    ss << std::setw(2) << std::setfill('0') << n.tm_hour        <<  "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_min         <<  "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_sec             ;

    return ss.str();
   }

  inline void function( std::string const& message )
   {
    static std::string dn = TOPLOG__FILE_FOLDER;
    static std::string fn = TOPLOG__FILE_PREFIX + TopLogNamespace::getCurrentTime();
    static mutex  s_lock;

    std::lock_guard locker( s_lock );

    if( true == TOPLOG__OUTPUT_FILE )
     {
      std::string name = dn + fn + ".txt";

      std::ofstream ofs( name, std::ios_base::app );

      ofs << message;
      ofs.flush();
     }

    if( true == TOPLOG__OUTPUT_CONSOLE )
     {
      std::cout  << message;
      std::cout.flush();
     }
   }

  class Sink{};

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::thread::id const& id )
   {
    std::stringstream ss;

    ss <<  id;

    TopLogNamespace::function( ss.str() );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::string const& message )
   {
    TopLogNamespace::function( message );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::wstring const& message )
   {
#pragma warning( push )
#pragma warning( disable: 4244 )
    TopLogNamespace::function( std::string( message.begin(), message.end() ) );
#pragma warning( pop )
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::int8_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::int16_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }
  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::int32_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }
  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::int64_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }


  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::uint8_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }
  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::uint16_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::uint32_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, std::uint64_t const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, float const& d )
   {
    TopLogNamespace::function( std::to_string( d ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, double const& d )
   {
    TopLogNamespace::function( std::to_string( d ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, long double const& dd )
   {
    TopLogNamespace::function( std::to_string( dd ) );
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, char const* s )
   {
    if( nullptr != s )
     {
      TopLogNamespace::function( std::string( s ) );
     }
     else
     {
      TopLogNamespace::function( std::string( "TopLog: Supplied char pointer is nullptr!" ) );
     }
    return TopLogNamespace::Sink{};
   }

  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, void const* p )
   {
    std::stringstream ss;

    ss <<  p;

    TopLogNamespace::function( ss.str() );
    return TopLogNamespace::Sink{};
   }

  struct Scope
  {
   public:
     Scope( std::string const& file, std::string const& function, int line, std::thread::id tid )
      :m_file( file )
      ,m_function( function )
      ,m_line( line )
      ,m_tid( tid )
      {
       TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX__DATETIME << m_tid << " " << m_file << " - " << m_function << " - " << m_line << " - " << "ENTER" << "\n";
      }

     ~Scope()
      {
       TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX__DATETIME << m_tid << " " << m_file << " - " << m_function << " - " << m_line << " - " << "EXIT" << "\n";
      }

     std::string     m_file;
     std::string     m_function;
     int             m_line;
     std::thread::id m_tid;
  };

 }

#if defined( _MSC_BUILD )
#pragma warning ( pop )
#endif


// API

#if 1

#define TOPLOG_SCOPE          TopLogNamespace::Scope scope_logger_instance( TOPLOG__LOG_PREFIX__FILE_SHORT, __FUNCTION__, __LINE__, TopLogNamespace::getCurrentThreadID() )
#define TOPLOG_POINT          TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << "POINT" << "\n"
#define TOPLOG_VALUE(value)   TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << #value << " == " << value << "\n"
#define TOPLOG_COMMENT(value) TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << value << "\n"

#endif
#endif
