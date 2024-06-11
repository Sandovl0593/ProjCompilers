#include "imp.hh"
#include "imp_visitor.hh"
#include "type_visitor.hh"

string Exp::binopToString(BinaryOp op) {
  switch(op) {
    case PLUS: return "+";
    case MINUS: return "-";
    case MULT: return "*";
    case DIV: return "/";
    case EXP: return "**";
    case LT: return "<";
    case LTEQ: return "<=";
    case GT: return ">";
    case GTEQ: return ">=";
    case EQ: return "==";
  }
  return "";
}


// Constructors
BinaryExp::BinaryExp(Exp* l, Exp* r, BinaryOp op):left(l),right(r),op(op) {}
NumberExp::NumberExp(int v):value(v) {}
IdExp::IdExp(string id):id(id) {}
ParenthExp::ParenthExp(Exp *e):e(e){}
CondExp::CondExp(Exp *c, Exp* et, Exp* ef):cond(c), etrue(et), efalse(ef){}
BoolExp::BoolExp(bool b):value(b){}
UnaryExp::UnaryExp(Exp* e, UnaryOp op):op(op), e(e){}

Exp::~Exp() {}
BinaryExp::~BinaryExp() { delete left; delete right; }
NumberExp::~NumberExp() { }
IdExp::~IdExp() { }
ParenthExp::~ParenthExp(){ delete e; }
CondExp::~CondExp(){ delete cond; delete etrue; delete efalse; }
BoolExp::~BoolExp() { }
UnaryExp::~UnaryExp() { delete e; }


// ImpVisitor
int BinaryExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int NumberExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int IdExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int ParenthExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int CondExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int BoolExp::accept(ImpVisitor* v) {
  return v->visit(this);
}
int UnaryExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

// TypeVisitor
ImpType BinaryExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType NumberExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType IdExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType ParenthExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType CondExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType BoolExp::accept(TypeVisitor* v) {
  return v->visit(this);
}
ImpType UnaryExp::accept(TypeVisitor* v) {
  return v->visit(this);
}

AssignStatement::AssignStatement(string id, Exp* e):id(id), rhs(e) { }
PrintStatement::PrintStatement(Exp* e):e(e) { }
IfStatement::IfStatement(Exp* c,Body *tb, Body* fb):cond(c),tbody(tb), fbody(fb) { }
WhileStatement::WhileStatement(Exp* c,Body *b):cond(c),body(b) { }
DoWhileStatement::DoWhileStatement(Exp* c,Body *b):cond(c),body(b) { }

StatementList::StatementList():slist() {}
VarDec::VarDec(string type, list<string> vars):type(type), vars(vars) {}
VarDecList::VarDecList():vdlist() {}
Body::Body(VarDecList* vdl, StatementList* sl):var_decs(vdl), slist(sl) {}
Program::Program(Body* b):body(b) {}

Stm::~Stm() {}
AssignStatement::~AssignStatement() { delete rhs; }
PrintStatement::~PrintStatement() { delete e; }
IfStatement::~IfStatement() { delete fbody; delete tbody; delete cond; }
WhileStatement::~WhileStatement() { delete body; delete cond; }
DoWhileStatement::~DoWhileStatement() { delete body; delete cond; }

StatementList::~StatementList() { }
VarDec::~VarDec() { }
VarDecList::~VarDecList() { }
Body::~Body() { delete slist; delete var_decs; }
Program::~Program() { delete body; }

// ForStatement::ForStatement(string id, Exp* begin, Exp* end, StatementList* body): id(id), begin(begin), end(end), body(body) { }
// ForStatement::~ForStatement() { delete begin; delete end; delete body; }

// ImpVisitor
void AssignStatement::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void PrintStatement::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void IfStatement::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void WhileStatement::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void DoWhileStatement::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void StatementList::add(Stm* s) { slist.push_back(s);  }
void StatementList::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void VarDec::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void VarDecList::add(VarDec* vd) { vdlist.push_back(vd);  }
void VarDecList::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void Body::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}
void Program::accept(ImpVisitor* v) {
  v->visit(this);
  return; 
}

// TypeVisitor
void AssignStatement::accept(TypeVisitor* v) {
  return v->visit(this);
}
void PrintStatement::accept(TypeVisitor* v) {
  return v->visit(this);
}
void IfStatement::accept(TypeVisitor* v) {
  return v->visit(this);
}
void WhileStatement::accept(TypeVisitor* v) {
  return v->visit(this);
}
void DoWhileStatement::accept(TypeVisitor* v) {
  return v->visit(this);
}
void StatementList::accept(TypeVisitor* v) {
  return v->visit(this);
}
void VarDec::accept(TypeVisitor* v) {
  return v->visit(this);
}
void VarDecList::accept(TypeVisitor* v) {
  return v->visit(this);
}
void Body::accept(TypeVisitor* v) {
  return v->visit(this);
}
void Program::accept(TypeVisitor* v) {
  return v->visit(this);
}