#include "imp.hh"
#include "imp_visitor.hh"

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
CondExp::CondExp(Exp *cond, Exp* tbody, Exp* fbody): cond(cond), tbody(tbody), fbody(fbody) {}
ParenthExp::ParenthExp(Exp *e):e(e){}

Exp::~Exp() {}
BinaryExp::~BinaryExp() { delete left; delete right; }
NumberExp::~NumberExp() { }
IdExp::~IdExp() { }
CondExp::~CondExp() { }
ParenthExp::~ParenthExp(){ delete e; }

int BinaryExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

int NumberExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

int IdExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

int CondExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

int ParenthExp::accept(ImpVisitor* v) {
  return v->visit(this);
}

AssignStatement::AssignStatement(string id, Exp* e):id(id), rhs(e) { }
PrintStatement::PrintStatement(Exp* e):e(e) { }

StatementList::StatementList():slist() {}
Program::Program(StatementList* sl):slist(sl) {}

Stm::~Stm() {}
AssignStatement::~AssignStatement() { delete rhs; }
PrintStatement::~PrintStatement() { delete e; }
StatementList::~StatementList() { }
Program::~Program() {
  // loop 
}
IfStatement::IfStatement(Exp* cond, StatementList* body, StatementList* elsebody): cond(cond), body(body), elsebody(elsebody) { }
IfStatement::~IfStatement() { delete cond; delete body; delete elsebody; }

WhileStatement::WhileStatement(Exp* cond, StatementList* body): cond(cond), body(body) { }
WhileStatement::~WhileStatement() { delete cond; delete body; }

DoWhileStatement::DoWhileStatement(StatementList* body, Exp* cond): cond(cond), body(body) { }
DoWhileStatement::~DoWhileStatement() { delete cond; delete body; }

ForStatement::ForStatement(string id, Exp* begin, Exp* end, StatementList* body): id(id), begin(begin), end(end), body(body) { }
ForStatement::~ForStatement() { delete begin; delete end; delete body; }

void AssignStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void PrintStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void StatementList::add(Stm* s) { slist.push_back(s);  }

void StatementList::accept(ImpVisitor* v) {
  return v->visit(this);
}

void IfStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void WhileStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void DoWhileStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void ForStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void BreakStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void ContinueStatement::accept(ImpVisitor* v) {
  return v->visit(this);
}

void Program::accept(ImpVisitor* v) {
  return v->visit(this);
}









