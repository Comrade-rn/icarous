/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif


/* -----------------------------------------------------------------------------
 * clabels.swg
 *
 * Definitions of C specific preprocessor symbols.
 * ----------------------------------------------------------------------------- */

// this is used instead of default SWIGEXPORT symbol

#ifndef SWIGEXPORTC
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) || defined(__APPLE__)
#   define SWIGEXPORTC
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORTC __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORTC
#   endif
# endif
#endif

#ifndef SWIGPROTECT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) || defined(__APPLE__)
#   define SWIGPROTECT(x)
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGPROTECT(x) __attribute__ ((visibility("protected"))) x
#   else
#     define SWIGPROTECT(x)
#   endif
# endif
#endif



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define SWIG_STR(x) #x
#define SWIG_contract_assert(expr, msg) if(!(expr)) { printf("%s\n", msg); SWIG_exit(0); } else


typedef struct {
  void *obj;
  const char **typenames;
} SwigObj;


#define SWIG_MAX_RT_STACK 256
#define SWIG_REGISTRY_INIT 256

SWIGINTERN SwigObj **SWIG_registry_base = 0;
SWIGINTERN SwigObj **SWIG_registry = 0;
SWIGINTERN int SWIG_registry_size = SWIG_REGISTRY_INIT;

SWIGINTERN SwigObj *SWIG_create_object(const char *classname);
SWIGINTERN void SWIG_destroy_object(SwigObj *object);
SWIGINTERN void SWIG_free_SwigObj(SwigObj *object);

SWIGEXPORTC struct SWIG_exc_struct {
  int code;
  char *msg;
  SwigObj *klass;
  int handled;
} SWIG_exc = { 0, 0, 0, 0 };

SWIGEXPORTC jmp_buf SWIG_rt_env;
SWIGEXPORTC int SWIG_rt_init = 0;
SWIGINTERN jmp_buf SWIG_cpp_back_env;
SWIGINTERN jmp_buf *SWIG_rt_stack_base = 0;
SWIGINTERN jmp_buf *SWIG_rt_stack_ptr = 0;

SWIGINTERN void SWIG_rt_stack_push() {
  // TODO: check for stack overflow
  memcpy(SWIG_rt_stack_ptr, SWIG_rt_env, sizeof(SWIG_rt_env));
  SWIG_rt_stack_ptr++;
}

SWIGINTERN void SWIG_rt_stack_pop() {
  if (SWIG_rt_stack_ptr == SWIG_rt_stack_base)
    return;
  SWIG_rt_stack_ptr--;
  memcpy(SWIG_rt_env, SWIG_rt_stack_ptr, sizeof(SWIG_rt_env));
}

SWIGINTERN void SWIG_add_registry_entry(SwigObj *entry) {
  if (SWIG_registry_base == 0) {
    SWIG_registry_base = SWIG_registry = (SwigObj **) malloc(SWIG_registry_size * sizeof(SwigObj *));
    memset(SWIG_registry_base, 0, SWIG_registry_size * sizeof(SwigObj *));
  }
  *SWIG_registry = entry;
  SWIG_registry++;
  if ((SWIG_registry - SWIG_registry_base) == SWIG_registry_size) {
    SWIG_registry = SWIG_registry_base;
    SWIG_registry_size += SWIG_REGISTRY_INIT;
    int new_size = SWIG_registry_size * sizeof(SwigObj *);
    SWIG_registry_base = (SwigObj **) malloc(new_size);
    memset(SWIG_registry_base, 0, new_size);
    memcpy(SWIG_registry_base, SWIG_registry, (SWIG_registry_size - SWIG_REGISTRY_INIT) * sizeof(SwigObj *));
    free(SWIG_registry);
    SWIG_registry = SWIG_registry_base + (SWIG_registry_size - SWIG_REGISTRY_INIT);
  }
}

SWIGINTERN void SWIG_remove_registry_entry(SwigObj *entry) {
  int i;
  for (i = 0; i < SWIG_registry_size; ++i) {
    if (*(SWIG_registry_base + i) == entry) {
      *(SWIG_registry_base + i) = 0;
      break;
    }
  }
}

SWIGINTERN void SWIG_free_SwigObj(SwigObj *object) {
  if (object) {
    if (object->typenames)
      free(object->typenames);
    free(object);
    object = (SwigObj *) 0;
  }
}

SWIGINTERN void SWIG_cleanup() {
  if (SWIG_rt_stack_base)
    free(SWIG_rt_stack_base);
  if (SWIG_exc.msg)
   free(SWIG_exc.msg);
  if (SWIG_exc.klass) {
    if (SWIG_exc.klass->typenames)
      free(SWIG_exc.klass->typenames);
    free(SWIG_exc.klass);
  }
  int i;
  if (SWIG_registry_base) {
    for (i = 0; i < SWIG_registry_size; ++i) {
      if (*(SWIG_registry_base + i)) {
        SWIG_free_SwigObj(*(SWIG_registry_base + i));
        *(SWIG_registry_base + i)  = 0;
      }
    }
  }
  free(SWIG_registry_base);
  SWIG_registry_base = 0;
}

#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORTC void SWIG_rt_try() {
  SWIG_rt_stack_push();
}

SWIGEXPORTC int SWIG_rt_catch(const char *type) {
  int result = 0;
  if (!type || (strcmp("SWIG_AnyException", type) == 0)) {
    result = 1;
  }
  else if (SWIG_exc.klass) {
    int i = 0;
    while (SWIG_exc.klass->typenames[i]) {
      if (strcmp(SWIG_exc.klass->typenames[i++], type) == 0) {
        result = 1;
        break;
      }
    }
  }
  if (result) {
    SWIG_rt_stack_pop();
    SWIG_exc.handled = 1;
  }
  return result;
}

SWIGEXPORTC void SWIG_rt_throw(SwigObj *klass, const char *msg) {
  if (SWIG_exc.msg) {
    free(SWIG_exc.msg);
    SWIG_exc.msg = (char *) 0;
  }
  if (msg) {
    SWIG_exc.msg = (char *) malloc(strlen(msg) + 1);
    strcpy(SWIG_exc.msg, msg);
  }
  SWIG_exc.klass = klass;
  SWIG_exc.handled = 0;
  longjmp(SWIG_rt_env, 1);
}

SWIGEXPORTC void SWIG_rt_unhandled() {
  if (SWIG_exc.msg) { 
    free(SWIG_exc.msg);
    SWIG_exc.msg = 0;
  }
  SWIG_rt_stack_pop();
  longjmp(SWIG_rt_env, SWIG_exc.code);
}

SWIGEXPORTC void SWIG_rt_endtry() {
  if (SWIG_exc.handled) {
    if (setjmp(SWIG_rt_env) == 0) {
      SWIG_rt_stack_push();
      longjmp(SWIG_cpp_back_env, 1);
    }
  }
  else {
    SWIG_rt_stack_pop();  // pop the SWIG_try context
  }
}

SWIGEXPORTC int SWIG_exit(int code) {
  SWIG_cleanup();
  exit(code);
}

#ifdef __cplusplus
}
#endif

SWIGINTERN void SWIG_terminate() {
  fprintf(stderr, "Unhandled exception: %s\n%s\nExitting...\n", 
    SWIG_exc.klass->typenames[0],
    SWIG_exc.msg ? SWIG_exc.msg : "");
  SWIG_exit(SWIG_exc.code);
}

SWIGINTERN void SWIG_runtime_init() {
  int i, code;
  if (!SWIG_rt_init) {
    SWIG_rt_init = 1;
    SWIG_rt_stack_base = SWIG_rt_stack_ptr = (jmp_buf *) malloc(sizeof(jmp_buf) * SWIG_MAX_RT_STACK);
    if (SWIG_exc.code = setjmp(SWIG_rt_env)) {
      // deallocate C++ exception
      if (setjmp(SWIG_rt_env) == 0) {
        SWIG_rt_stack_push();
        SWIG_exc.handled = 1;
        longjmp(SWIG_cpp_back_env, 1);
      }
      SWIG_terminate();
    }
  }
}

#define SWIG_CThrowException(klass, msg) \
  if (setjmp(SWIG_cpp_back_env) == 0) \
    SWIG_rt_throw((SwigObj *) klass, msg);

    
  SwigObj *SWIG_temporary = (SwigObj *) malloc(sizeof(SwigObj));


/* Includes the header in the wrapper code */
#include "GeofenceMonitor.h"

const char* Swig_typename_GeofenceConflict = "GeofenceConflict";

const char* Swig_typename_GeofenceMonitor = "GeofenceMonitor";


SWIGINTERN SwigObj *SWIG_create_object(const char *classname) {
SWIG_runtime_init();
SwigObj *result;
result = (SwigObj *) malloc(sizeof(SwigObj));
result->obj = 0;
if (strcmp(classname, "GeofenceConflict") == 0) {
result->typenames = (const char **) malloc(2*sizeof(const char*));
result->typenames[0] = Swig_typename_GeofenceConflict;
result->typenames[1] = 0;
}
if (strcmp(classname, "GeofenceMonitor") == 0) {
result->typenames = (const char **) malloc(2*sizeof(const char*));
result->typenames[0] = Swig_typename_GeofenceMonitor;
result->typenames[1] = 0;
}
SWIG_add_registry_entry(result);
return result;
}


SWIGINTERN void SWIG_destroy_object(SwigObj *object) {
if (object) {
if (object->typenames) {
if (strcmp(object->typenames[0], "GeofenceConflict") == 0) {
if (object->obj)
delete (GeofenceConflict *) (object->obj);
}
if (strcmp(object->typenames[0], "GeofenceMonitor") == 0) {
if (object->obj)
delete (GeofenceMonitor *) (object->obj);
}
SWIG_free_SwigObj(object);
}
}
}
#ifdef __cplusplus
extern "C" {
#endif
  
  SWIGEXPORTC void _wrap_GeofenceConflict_fenceId_set(SwigObj * carg1, int carg2) {
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    int arg2 ;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    arg2 = (int) carg2;
    if (arg1) (arg1)->fenceId = arg2;
  }
  
  
  SWIGEXPORTC int _wrap_GeofenceConflict_fenceId_get(SwigObj * carg1) {
    int cppresult;
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    int result;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    cppresult =  (int) ((arg1)->fenceId);
    result = cppresult;
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_GeofenceConflict_violationStatus_set(SwigObj * carg1, bool carg2) {
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    bool arg2 ;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    arg2 = (bool) carg2;
    if (arg1) (arg1)->violationStatus = arg2;
  }
  
  
  SWIGEXPORTC bool _wrap_GeofenceConflict_violationStatus_get(SwigObj * carg1) {
    bool cppresult;
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    bool result;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    cppresult =  (bool) ((arg1)->violationStatus);
    result = (bool) cppresult;
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_GeofenceConflict_conflictstatus_set(SwigObj * carg1, bool carg2) {
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    bool arg2 ;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    arg2 = (bool) carg2;
    if (arg1) (arg1)->conflictstatus = arg2;
  }
  
  
  SWIGEXPORTC bool _wrap_GeofenceConflict_conflictstatus_get(SwigObj * carg1) {
    bool cppresult;
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    bool result;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    cppresult =  (bool) ((arg1)->conflictstatus);
    result = (bool) cppresult;
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_GeofenceConflict_recoveryPoint_set(SwigObj * carg1, /*aaa*/ double * carg2) {
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    double *arg2 ;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    arg2 = (double *) carg2;
    {
      size_t ii;
      double *b = (double *) arg1->recoveryPoint;
      for (ii = 0; ii < (size_t)3; ii++) b[ii] = *((double *) arg2 + ii);
    }
  }
  
  
  SWIGEXPORTC double * _wrap_GeofenceConflict_recoveryPoint_get(SwigObj * carg1) {
    double * cppresult;
    GeofenceConflict *arg1 = (GeofenceConflict *) 0 ;
    double * result;
    
    {
      if (carg1)
      arg1 = (GeofenceConflict *) carg1->obj;
    }
    cppresult =  (double *)(double *) ((arg1)->recoveryPoint);
    result = cppresult;
    return result;
  }
  
  
  SWIGEXPORTC SwigObj * _wrap_new_GeofenceConflict() {
    SwigObj * result;
    
    result = SWIG_create_object("GeofenceConflict");
    result->obj = (void*) new GeofenceConflict();
    
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_delete_GeofenceConflict(SwigObj * carg1) {
    SWIG_remove_registry_entry(carg1);
    SWIG_destroy_object(carg1);
  }
  
  
  SWIGEXPORTC SwigObj * _wrap_new_GeofenceMonitor(SwigObj * carg1) {
    FlightData *arg1 = (FlightData *) 0 ;
    SwigObj * result;
    
    {
      if (carg1)
      arg1 = (FlightData *) carg1->obj;
    }
    result = SWIG_create_object("GeofenceMonitor");
    result->obj = (void*) new GeofenceMonitor(arg1);
    
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_GeofenceMonitor_CheckViolation(SwigObj * carg1, /*aaa*/ double * carg2, double carg3, double carg4, double carg5) {
    GeofenceMonitor *arg1 = (GeofenceMonitor *) 0 ;
    double *arg2 ;
    double arg3 ;
    double arg4 ;
    double arg5 ;
    
    {
      if (carg1)
      arg1 = (GeofenceMonitor *) carg1->obj;
    }
    arg2 = (double *) carg2;
    arg3 = (double) carg3;
    arg4 = (double) carg4;
    arg5 = (double) carg5;
    (arg1)->CheckViolation(arg2,arg3,arg4,arg5);
  }
  
  
  SWIGEXPORTC bool _wrap_GeofenceMonitor_CheckWPFeasibility(SwigObj * carg1, /*aaa*/ double * carg2, /*aaa*/ double * carg3) {
    bool cppresult;
    GeofenceMonitor *arg1 = (GeofenceMonitor *) 0 ;
    double *arg2 ;
    double *arg3 ;
    bool result;
    
    {
      if (carg1)
      arg1 = (GeofenceMonitor *) carg1->obj;
    }
    arg2 = (double *) carg2;
    arg3 = (double *) carg3;
    cppresult =  (bool)(arg1)->CheckWPFeasibility(arg2,arg3);
    result = (bool) cppresult;
    return result;
  }
  
  
  SWIGEXPORTC int _wrap_GeofenceMonitor_GetNumConflicts(SwigObj * carg1) {
    int cppresult;
    GeofenceMonitor *arg1 = (GeofenceMonitor *) 0 ;
    int result;
    
    {
      if (carg1)
      arg1 = (GeofenceMonitor *) carg1->obj;
    }
    cppresult =  (int)(arg1)->GetNumConflicts();
    result = cppresult;
    return result;
  }
  
  
  SWIGEXPORTC void _wrap_GeofenceMonitor_GetConflict(SwigObj * carg1, int carg2, int * carg3, bool * carg4, bool * carg5, /*aaa*/ double * carg6) {
    GeofenceMonitor *arg1 = (GeofenceMonitor *) 0 ;
    int arg2 ;
    int *arg3 = 0 ;
    bool *arg4 = 0 ;
    bool *arg5 = 0 ;
    double *arg6 ;
    
    {
      if (carg1)
      arg1 = (GeofenceMonitor *) carg1->obj;
    }
    arg2 = (int) carg2;
    arg3 = (int *) carg3;
    arg4 = (bool *) carg4;
    arg5 = (bool *) carg5;
    arg6 = (double *) carg6;
    (arg1)->GetConflict(arg2,*arg3,*arg4,*arg5,arg6);
  }
  
  
  SWIGEXPORTC void _wrap_delete_GeofenceMonitor(SwigObj * carg1) {
    SWIG_remove_registry_entry(carg1);
    SWIG_destroy_object(carg1);
  }
  
  
#ifdef __cplusplus
}
#endif

