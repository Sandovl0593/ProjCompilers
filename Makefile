CC=g++

SRC_IMP=imp_test.cpp imp\imp.cpp imp\imp_parser.cpp imp\imp_type.cpp imp\imp_printer.cpp imp\imp_interpreter.cpp

SRC_COMP=imp_compiler.cpp imp\imp.cpp imp\imp_parser.cpp imp\imp_printer.cpp imp\imp_typechecker.cpp imp\imp_type.cpp imp\imp_interpreter.cpp imp\imp_codegen.cpp

SRC_SVM=svm\svm_run.cpp svm\svm_parser.cpp svm\svm.cpp

imp: $(SRC_IMP)
	$(CC) -o imp  $(SRC_IMP)

compiler: $(SRC_IgMP)
	$(CC) -o compile  $(SRC_COMP)

svm: $(SRC_SVM)
	$(CC) -o svm  $(SRC_SVM)