#This makefile makes the examples from the first few chapters with Unity test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = pilot

#--- Inputs ----#
UNITY_HOME = unity.framework
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = ..
PROJECT_TEST_DIR = .
CPP_PLATFORM = Gcc
UNITY_BUILD_HOME = unity.framework/extras/fixture/build

UNITY_CFLAGS += -DUNITY_OUTPUT_CHAR=UnityOutputCharSpy_OutputChar
UNITY_WARNINGFLAGS = -Wall -Werror -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow 

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src \

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR)\
	$(PROJECT_TEST_DIR)/group1\
	$(PROJECT_TEST_DIR)/group2\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\

INCLUDE_DIRS =\
  .\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  
include $(UNITY_BUILD_HOME)/MakefileWorker.mk

