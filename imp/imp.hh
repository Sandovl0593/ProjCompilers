#ifndef IMP_AST
#define IMP_AST

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>

#include <list>

#include "imp_value.hh"

using namespace std;

class ImpVisitor;
class ImpValueVisitor;
class TypeVisitor;

enum BinaryOp { PLUS, MINUS, MULT, DIV, EXP, LT, LTEQ, GT, GTEQ, EQ};

  
class Exp {
public:
  virtual int accept(ImpVisitor* v) = 0;
  virtual ImpValue accept(ImpValueVisitor* v) = 0;
  virtual ImpType accept(TypeVisitor* v) = 0;
  static string binopToString(BinaryOp op);
  virtual ~Exp() = 0;
};

class BinaryExp : public Exp {
public:
  Exp *left, *right;
  BinaryOp op;
  BinaryExp(Exp* l, Exp* r, BinaryOp op);
  int accept(ImpVisitor* v);
  ImpValue accept(ImpValueVisitor* v);
  ImpType accept(TypeVisitor* v);
  ~BinaryExp();
};

class NumberExp : public Exp {
public:
  int value;
  NumberExp(int v);
  int accept(ImpVisitor* v);
  ImpValue accept(ImpValueVisitor* v);
  ImpType accept(TypeVisitor* v);
  ~NumberExp();
};

class IdExp : public Exp {
public:
  string id;
  IdExp(string id);
  int accept(ImpVisitor* v);
  ImpValue accept(ImpValueVisitor* v);
  ImpType accept(TypeVisitor* v);
  ~IdExp();
};

class ParenthExp : public Exp {
public:
  Exp *e;
  ParenthExp(Exp *e);
  int accept(ImpVisitor* v);
  ImpValue accept(ImpValueVisitor* v);
  ImpType accept(TypeVisitor* v);
  ~ParenthExp();
};

class CondExp : public Exp {
public:
  Exp *cond, *etrue, *efalse;
  CondExp(Exp* c, Exp* et, Exp* ef);
  int accept(ImpVisitor* v);
  ImpValue accept(ImpValueVisitor* v);
  ImpType accept(TypeVisitor* v);
  ~CondExp();
};



class Stm {
public:
  virtual void accept(ImpVisitor* v) = 0;
  virtual void accept(ImpValueVisitor* v)=0;
  virtual void accept(TypeVisitor* v)=0;
  virtual ~Stm() = 0;
};

class StatementList;
class Body;

class AssignStatement : public Stm {
public:
  string id;
  Exp* rhs;  
  AssignStatement(string id, Exp* e);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~AssignStatement();
};

class PrintStatement : public Stm {
public:
  Exp* e;  
  PrintStatement(Exp* e);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~PrintStatement();
};

class IfStatement : public Stm {
public:
  Exp* cond;
  Body *tbody, *fbody;
  IfStatement(Exp* c, Body* tbody, Body *fbody);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~IfStatement();
};

class WhileStatement : public Stm {
public:
  Exp* cond;
  Body *body;
  WhileStatement(Exp* c, Body* b);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~WhileStatement();
};

class DoWhileStatement : public Stm {
public:
  Exp* cond;
  Body *body;
  DoWhileStatement(Exp* c, Body* b);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~DoWhileStatement();
};


// class ForStatement : public Stm {
// public:
//   string id;
//   Exp* begin, *end;
//   Body *body;
//   ForStatement(string id, Exp* begin, Exp* end, Body* body);
//   void accept(ImpVisitor* v);
//   void accept(ImpValueVisitor* v);
//   void accept(ImpVisitor* v);
//   ~ForStatement();
// };

// class BreakStatement : public Stm {
// public:
//     void accept(ImpVisitor* v);
// };

// class ContinueStatement : public Stm {
// public:
//     void accept(ImpVisitor* v);
// };


class StatementList {
public:
  list<Stm*> slist;
  StatementList();
  void add(Stm* s);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~StatementList();
};

class VarDec {
public:
  string type;
  list<string> vars;
  VarDec(string type, list<string> vars);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~VarDec();
};


class VarDecList {
public:
  list<VarDec*> vdlist;
  VarDecList();
  void add(VarDec* s);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~VarDecList();
};


class Body {
public:
  VarDecList* var_decs;
  StatementList* slist;
  Body(VarDecList* vdl, StatementList* sl);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~Body();
};

class Program {
public:
  Body* body;
  Program(Body* body);
  void accept(ImpVisitor* v);
  void accept(ImpValueVisitor* v);
  void accept(TypeVisitor* v);
  ~Program();
};



#endif

