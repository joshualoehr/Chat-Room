/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_prog3_observer.h"

static const char* CMockString_argc = "argc";
static const char* CMockString_argv = "argv";
static const char* CMockString_main_observer = "main_observer";

typedef struct _CMOCK_main_observer_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;
  int Expected_argc;
  char** Expected_argv;

} CMOCK_main_observer_CALL_INSTANCE;

static struct mock_prog3_observerInstance
{
  int main_observer_IgnoreBool;
  int main_observer_FinalReturn;
  CMOCK_main_observer_CALLBACK main_observer_CallbackFunctionPointer;
  int main_observer_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE main_observer_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_prog3_observer_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.main_observer_IgnoreBool)
    Mock.main_observer_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_main_observer);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.main_observer_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.main_observer_CallbackFunctionPointer != NULL)
    Mock.main_observer_CallInstance = CMOCK_GUTS_NONE;
}

void mock_prog3_observer_Init(void)
{
  mock_prog3_observer_Destroy();
}

void mock_prog3_observer_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.main_observer_CallbackFunctionPointer = NULL;
  Mock.main_observer_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int main_observer(int argc, char** argv)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_main_observer_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_main_observer);
  cmock_call_instance = (CMOCK_main_observer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.main_observer_CallInstance);
  Mock.main_observer_CallInstance = CMock_Guts_MemNext(Mock.main_observer_CallInstance);
  if (Mock.main_observer_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.main_observer_FinalReturn;
    Mock.main_observer_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.main_observer_CallbackFunctionPointer != NULL)
  {
    return Mock.main_observer_CallbackFunctionPointer(argc, argv, Mock.main_observer_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_main_observer,CMockString_argc);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_argc, argc, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_main_observer,CMockString_argv);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_argv, argv, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_main_observer(CMOCK_main_observer_CALL_INSTANCE* cmock_call_instance, int argc, char** argv)
{
  cmock_call_instance->Expected_argc = argc;
  cmock_call_instance->Expected_argv = argv;
}

void main_observer_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_main_observer_CALL_INSTANCE));
  CMOCK_main_observer_CALL_INSTANCE* cmock_call_instance = (CMOCK_main_observer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.main_observer_CallInstance = CMock_Guts_MemChain(Mock.main_observer_CallInstance, cmock_guts_index);
  Mock.main_observer_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.main_observer_IgnoreBool = (int)1;
}

void main_observer_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int argc, char** argv, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_main_observer_CALL_INSTANCE));
  CMOCK_main_observer_CALL_INSTANCE* cmock_call_instance = (CMOCK_main_observer_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.main_observer_CallInstance = CMock_Guts_MemChain(Mock.main_observer_CallInstance, cmock_guts_index);
  Mock.main_observer_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_main_observer(cmock_call_instance, argc, argv);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void main_observer_StubWithCallback(CMOCK_main_observer_CALLBACK Callback)
{
  Mock.main_observer_CallbackFunctionPointer = Callback;
}
