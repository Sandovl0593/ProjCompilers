#ifndef IMP_AST
#define IMP_AST

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>

#include <list>

using namespace std;

class ImpVisitor;

enum BinaryOp { PLUS, MINUS, MULT, DIV, EXP, LT, LTEQ, GT, GTEQ, EQ };

  
class Exp {
public:
  virtual int accept(ImpVisitor* v) = 0;
  static string binopToString(BinaryOp op);
  virtual ~Exp() = 0;
};

class BinaryExp : public Exp {
public:
  Exp *left, *right;
  BinaryOp op;
  BinaryExp(Exp* l, Exp* r, BinaryOp op);
  int accept(ImpVisitor* v);
  ~BinaryExp();
};

class NumberExp : public Exp {
public:
  int value;
  NumberExp(int v);
  int accept(ImpVisitor* v);
  ~NumberExp();
};

class IdExp : public Exp {
public:
  string id;
  IdExp(string id);
  int accept(ImpVisitor* v);
  ~IdExp();
};

class CondExp : public Exp {
public:
  Exp *cond, *tbody, *fbody;
  CondExp(Exp *cond, Exp* tbody, Exp* fbody);
  int accept(ImpVisitor* v);
  ~CondExp();
};

class ParenthExp : public Exp {
public:
  Exp *e;
  ParenthExp(Exp *e);
  int accept(ImpVisitor* v);
  ~ParenthExp();
};



class Stm {
public:
  virtual void accept(ImpVisitor* v) = 0;
  virtual ~Stm() = 0;
};

class StatementList;

class AssignStatement : public Stm {
public:
  string id;
  Exp* rhs;  
  AssignStatement(string id, Exp* e);
  void accept(ImpVisitor* v);
  ~AssignStatement();
};

class PrintStatement : public Stm {
public:
  Exp* e;  
  PrintStatement(Exp* e);
  void accept(ImpVisitor* v);
  ~PrintStatement();
};

class IfStatement : public Stm {
public:
  Exp* cond;
  StatementList *body, *elsebody;
  IfStatement(Exp* cond, StatementList* body, StatementList* elsebody);
  void accept(ImpVisitor* v);
  ~IfStatement();
};

class WhileStatement : public Stm {
public:
  Exp* cond;
  StatementList *body;
  WhileStatement(Exp* cond, StatementList* body);
  void accept(ImpVisitor* v);
  ~WhileStatement();
};

class DoWhileStatement : public Stm {
public:
  Exp* cond;
  StatementList *body;
  DoWhileStatement(StatementList* body, Exp* cond);
  void accept(ImpVisitor* v);
  ~DoWhileStatement();
};

class ForStatement : public Stm {
public:
  string id;
  Exp* begin, *end;
  StatementList *body;
  ForStatement(string id, Exp* begin, Exp* end, StatementList* body);
  void accept(ImpVisitor* v);
  ~ForStatement();
};

class BreakStatement : public Stm {
public:
    void accept(ImpVisitor* v);
};

class ContinueStatement : public Stm {
public:
    void accept(ImpVisitor* v);
};



class StatementList {
public:
  list<Stm*> slist;
  StatementList();
  void add(Stm* s);
  void accept(ImpVisitor* v);
  ~StatementList();
};

class Program {
public:
  StatementList* slist;
  Program(StatementList* sl);
  void accept(ImpVisitor* v);
  ~Program();
};


#endif

