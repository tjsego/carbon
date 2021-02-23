#include <CLogger.hpp>
#include <CConvert.hpp>
#include <c_object.h>
#include <c_error.h>
#include <iostream>
#include <algorithm>

class Message {
public:
    enum Priority
    {
        PRIO_FATAL       = 1,
        PRIO_CRITICAL,
        PRIO_ERROR,
        PRIO_WARNING,
        PRIO_NOTICE,
        PRIO_INFORMATION,
        PRIO_DEBUG,
        PRIO_TRACE,
    };
};

static int logLevel = Message::PRIO_NOTICE;

class FakeLogger {
public:
    void fatal(const std::string& fmt, const char* func, const char* file, const int line);
    void critical(const std::string& fmt, const char* func, const char* file, const int line);
    void error(const std::string& fmt, const char* func, const char* file, const int line);
    void warning(const std::string& fmt, const char* func, const char* file, const int line);
    void notice(const std::string& fmt, const char* func, const char* file, const int line);
    void information(const std::string& fmt, const char* func, const char* file, const int line);
    void debug(const std::string& fmt, const char* func, const char* file, const int line);
    void trace(const std::string& fmt, const char* func, const char* file, const int line);
};

static FakeLogger& getLogger() {
    static FakeLogger logger;
    return logger;
}

CLoggingBuffer::CLoggingBuffer(int level, const char* func, const char *file, int line):
                func(func), file(file), line(line)
{
    if (level >= Message::PRIO_FATAL && level <= Message::PRIO_TRACE)
    {
        this->level = level;
    }
    else
    {
        // wrong level, so just set to error?
        this->level = Message::PRIO_ERROR;
    }
}

CLoggingBuffer::~CLoggingBuffer()
{
    FakeLogger &logger = getLogger();
    switch (level)
    {
    case Message::PRIO_FATAL:
        logger.fatal(buffer.str(), func, file, line);
        break;
    case Message::PRIO_CRITICAL:
        logger.critical(buffer.str(), func, file, line);
        break;
    case Message::PRIO_ERROR:
        logger.error(buffer.str(), func, file, line);
        break;
    case Message::PRIO_WARNING:
        logger.warning(buffer.str(), func, file, line);
        break;
    case Message::PRIO_NOTICE:
        logger.notice(buffer.str(), func, file, line);
        break;
    case Message::PRIO_INFORMATION:
        logger.information(buffer.str(), func, file, line);
        break;
    case Message::PRIO_DEBUG:
        logger.debug(buffer.str(), func, file, line);
        break;
    case Message::PRIO_TRACE:
        logger.trace(buffer.str(), func, file, line);
        break;
    default:
        logger.error(buffer.str(), func, file, line);
        break;
    }
}

std::ostream& CLoggingBuffer::stream()
{
    return buffer;
}

void CLogger::setLevel(int level)
{
    logLevel = level;
}

int CLogger::getLevel()
{
    return logLevel;
}

void CLogger::disableLogging()
{
}

void CLogger::disableConsoleLogging()
{
}

void CLogger::enableConsoleLogging(int level)
{
}

void CLogger::enableFileLogging(const std::string &fileName, int level)
{
}

void CLogger::disableFileLogging()
{
}

std::string CLogger::getCurrentLevelAsString()
{
    return levelToString(logLevel);
}

std::string CLogger::getFileName()
{
    return "";
}

void CLogger::setFormattingPattern(const std::string &format)
{
}

std::string CLogger::getFormattingPattern()
{
    return "";
}

std::string CLogger::levelToString(int level)
{
    switch (level)
    {
    case Message::PRIO_FATAL:
        return "LOG_FATAL";
        break;
    case Message::PRIO_CRITICAL:
        return "LOG_CRITICAL";
        break;
    case Message::PRIO_ERROR:
        return "LOG_ERROR";
        break;
    case Message::PRIO_WARNING:
        return "LOG_WARNING";
        break;
    case Message::PRIO_NOTICE:
        return "LOG_NOTICE";
        break;
    case Message::PRIO_INFORMATION:
        return "LOG_INFORMATION";
        break;
    case Message::PRIO_DEBUG:
        return "LOG_DEBUG";
        break;
    case Message::PRIO_TRACE:
        return "LOG_TRACE";
        break;
    default:
        return "LOG_CURRENT";
    }
    return "LOG_CURRENT";
}

CLogLevel CLogger::stringToLevel(const std::string &str)
{
    std::string upstr = str;
    std::transform(upstr.begin(), upstr.end(), upstr.begin(), ::toupper);

    if (upstr == "LOG_FATAL")
    {
        return LOG_FATAL;
    }
    else if(upstr == "LOG_CRITICAL")
    {
        return LOG_CRITICAL;
    }
    else if(upstr == "LOG_ERROR" || upstr == "ERROR")
    {
        return LOG_ERROR;
    }
    else if(upstr == "LOG_WARNING" || upstr == "WARNING")
    {
        return LOG_WARNING;
    }
    else if(upstr == "LOG_NOTICE")
    {
        return LOG_NOTICE;
    }
    else if(upstr == "LOG_INFORMATION" || upstr == "INFO")
    {
        return LOG_INFORMATION;
    }
    else if(upstr == "LOG_DEBUG" || upstr == "DEBUG")
    {
        return LOG_DEBUG;
    }
    else if(upstr == "LOG_TRACE" || upstr == "TRACE")
    {
        return LOG_TRACE;
    }
    else
    {
        return LOG_CURRENT;
    }
}

bool CLogger::getColoredOutput()
{
    return false;
}

void CLogger::setColoredOutput(bool bool1)
{
}

void CLogger::setProperty(const std::string &name, const std::string &value)
{
}

void CLogger::log(CLogLevel l, const std::string &msg)
{
    FakeLogger &logger = getLogger();
    
    Message::Priority level = (Message::Priority)(l);
    
    switch (level)
    {
    case Message::PRIO_FATAL:
            logger.fatal(msg, "", "", 0);
        break;
    case Message::PRIO_CRITICAL:
            logger.critical(msg, "", "", 0);
        break;
    case Message::PRIO_ERROR:
            logger.error(msg, "", "", 0);
        break;
    case Message::PRIO_WARNING:
            logger.warning(msg, "", "", 0);
        break;
    case Message::PRIO_NOTICE:
            logger.notice(msg, "", "", 0);
        break;
    case Message::PRIO_INFORMATION:
            logger.information(msg, "", "", 0);
        break;
    case Message::PRIO_DEBUG:
            logger.debug(msg, "", "", 0);
        break;
    case Message::PRIO_TRACE:
            logger.trace(msg, "", "", 0);
        break;
    default:
            logger.error(msg, "", "", 0);
        break;
    }
}

void CLogger::setConsoleStream(std::ostream *os)
{
}

static PyObject *logger_log(PyObject *self, PyObject *args, PyObject *kwargs) {
    try {
        int level = carbon::arg<int>("level", 0, args, kwargs);
        
        if(level <= logLevel) {
            std::stringstream buffer;
            
            int size = PyTuple_Size(args);
            for(int i = 1; i < size; ++i) {
                buffer << carbon::str(PyTuple_GetItem(args, i));
            }
            
            CLogger::log((CLogLevel)level, buffer.str());
        }
        
        Py_RETURN_NONE;
    }
    catch(const std::exception &e) {
        C_RETURN_EXP(e);
    }
}

static PyMethodDef logger_methods[] = {
    { "log", (PyCFunction)logger_log, METH_STATIC| METH_VARARGS | METH_KEYWORDS, NULL },
    { NULL, NULL, 0, NULL }
};

PyGetSetDef logger_getsets[] = {
    {NULL}
};


PyTypeObject CLogger_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "Logger"                              , // .tp_name
  sizeof(CLogger)                       , // .tp_basicsize
  0                                     , // .tp_itemsize
  0                                     , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  0                                     , // .tp_repr
  0                                     , // .tp_as_number
  0                                     , // .tp_as_sequence
  0                                     , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  0                                     , // .tp_str
  0                                     , // .tp_getattro
  0                                     , // .tp_setattro
  0                                     , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                                     , // .tp_doc
  0                                     , // .tp_traverse
  0                                     , // .tp_clear
  0                                     , // .tp_richcompare
  0                                     , // .tp_weaklistoffset
  0                                     , // .tp_iter
  0                                     , // .tp_iternext
  logger_methods                        , // .tp_methods
  0                                     , // .tp_members
  logger_getsets                        , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  0                                     , // .tp_init
  0                                     , // .tp_alloc
  PyType_GenericNew                     , // .tp_new
  0                                     , // .tp_free
  0                                     , // .tp_is_gc
  0                                     , // .tp_bases
  0                                     , // .tp_mro
  0                                     , // .tp_cache
  0                                     , // .tp_subclasses
  0                                     , // .tp_weaklist
  0                                     , // .tp_del
  0                                     , // .tp_version_tag
  0                                     , // .tp_finalize
  #ifdef COUNT_ALLOCS
  0                                     , // .tp_allocs
  0                                     , // .tp_frees
  0                                     , // .tp_maxalloc
  0                                     , // .tp_prev
  0                                     , // .tp_next
  #endif
};


HRESULT _CLogger_Init(PyObject* m) {
    if (PyType_Ready((PyTypeObject*)&CLogger_Type) < 0) {
        return c_error(E_FAIL, "could not initialize Logger type");
    }

    Py_INCREF(&CLogger_Type);
    if (PyModule_AddObject(m, "Logger", (PyObject *)&CLogger_Type) < 0) {
        Py_DECREF(&CLogger_Type);
        return c_error(E_FAIL, "could not add Logger to module");
    }

    PyObject *dict = CLogger_Type.tp_dict;
    
    if(!dict) {
        return c_error(E_FAIL, "CLogger_Type.dict is null");
    }
    
    PyDict_SetItemString(dict, "LOG_CURRENT", PyLong_FromLong(LOG_CURRENT));
    PyDict_SetItemString(dict, "LOG_FATAL", PyLong_FromLong(LOG_FATAL));
    PyDict_SetItemString(dict, "LOG_CRITICAL", PyLong_FromLong(LOG_CRITICAL));
    PyDict_SetItemString(dict, "LOG_ERROR", PyLong_FromLong(LOG_ERROR));
    PyDict_SetItemString(dict, "LOG_WARNING", PyLong_FromLong(LOG_WARNING));
    PyDict_SetItemString(dict, "LOG_NOTICE", PyLong_FromLong(LOG_NOTICE));
    PyDict_SetItemString(dict, "LOG_INFORMATION", PyLong_FromLong(LOG_INFORMATION));
    PyDict_SetItemString(dict, "LOG_DEBUG", PyLong_FromLong(LOG_DEBUG));
    PyDict_SetItemString(dict, "LOG_TRACE", PyLong_FromLong(LOG_TRACE));

    return S_OK;
}

void FakeLogger::fatal(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "FATAL: " << fmt << ", func: " << func << ", file:" << file << ",lineno:" << line << std::endl;
}

void FakeLogger::critical(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "CRITICAL: " << fmt << ", func: " << func << ",file:" << file << ",lineno:" << line << std::endl;
}

void FakeLogger::error(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "ERROR: " << fmt << ", func: " << func  << ",file:" << file << ",lineno:" << line << std::endl;
}

void FakeLogger::warning(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "WARNING: " << fmt << ", func: " << func << ",file:" << file << ",lineno:" << line << std::endl;
}

void FakeLogger::notice(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "NOTICE: " << fmt << ", func: " << func << std::endl;
}

void FakeLogger::information(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "INFO: " << fmt << ", func: " << func << std::endl;
}

void FakeLogger::debug(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "DEBUG: " << fmt << ", func: " << func << std::endl;
}

void FakeLogger::trace(const std::string &fmt, const char* func, const char *file,
        const int line)
{
    std::cout << "TRACE: " << fmt << ", func: " << func << std::endl;
}
