#ifndef TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8
#define TopLog_3f086ec6_c405_4a5b_b6c0_2edbc9f0a6b8
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <thread>


// Q: Load configuration from file?
// A: NO. This is not Big Fancy Logger!

// Configuration.
#define TOPLOG__LOG_PREFIX__DATETIME     "[" << TopLogNamespace::getCurrentTime() << "] "
#define TOPLOG__LOG_PREFIX__THREADID      TopLogNamespace::getCurrentThreadID()
#define TOPLOG__LOG_PREFIX__FILE          __FILE__
#define TOPLOG__LOG_PREFIX__FUNCTION      __FUNCTION__
#define TOPLOG__LOG_PREFIX__LINE          __LINE__

#define TOPLOG__LOG_PREFIX_COMPLETE         TOPLOG__LOG_PREFIX__DATETIME          \
                                        <<  TOPLOG__LOG_PREFIX__THREADID << " "\
                                        <<  TOPLOG__LOG_PREFIX__FUNCTION << " - " << TOPLOG__LOG_PREFIX__LINE

#define TOPLOG__FILE_FOLDER     ".\\"
#define TOPLOG__FILE_PREFIX     "TopLog_"


// Everything in this namespace are considered private
namespace TopLogNamespace
 {

  inline std::thread::id getCurrentThreadID()
   {
    return std::this_thread::get_id();
   }


  inline std::string getCurrentTime()
   {
    time_t t = time(0);
    tm   n = *localtime( &t );

    std::stringstream ss;

    ss <<                                      n.tm_year + 1900 << "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_mon  + 1    <<  "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_mday        <<  "_";
    ss << std::setw(2) << std::setfill('0') << n.tm_hour        <<  "-";
    ss << std::setw(2) << std::setfill('0') << n.tm_min             ;

    return ss.str();
   }

  inline void function( std::string const& message )
   {
    static std::string dn = TOPLOG__FILE_FOLDER;
    static std::string fn = TOPLOG__FILE_PREFIX + TopLogNamespace::getCurrentTime();

    std::ofstream ofs( dn + "\\" + fn + ".txt", std::ios_base::app );

    ofs << message;
    ofs.flush();
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
    TopLogNamespace::function( std::string( message.begin(), message.end() ) );
    return TopLogNamespace::Sink{};
   }


  inline TopLogNamespace::Sink operator<<( TopLogNamespace::Sink, int const& i )
   {
    TopLogNamespace::function( std::to_string( i ) );
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

     std::string m_file;
     std::string m_function;
     int         m_line;
     std::thread::id m_tid;
  };

 }

// API
#define TOPLOG_SCOPE          TopLogNamespace::Scope scope_logger_instance( "", __FUNCTION__,  __LINE__, TopLogNamespace::getCurrentThreadID() )
#define TOPLOG_POINT          TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << "POINT" << "\n"
#define TOPLOG_VALUE(value)   TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << #value << " == " << value << "\n"
#define TOPLOG_COMMENT(value) TopLogNamespace::Sink{} << TOPLOG__LOG_PREFIX_COMPLETE << " - " << value << "\n"

#endif
