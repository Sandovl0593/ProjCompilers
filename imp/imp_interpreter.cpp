#include "imp_interpreter.hh"


int ImpInterpreter::interpret(Program* p) {
  p->accept(this);
  return 0;
}

void ImpInterpreter::visit(Program* p) {
  p->slist->accept(this);
  return;
}



void ImpInterpreter::visit(StatementList* s) {
  list<Stm*>::iterator it;
  for (it = s->slist.begin(); it != s->slist.end(); ++it) {
    (*it)->accept(this);
  }
  return;
}

void ImpInterpreter::visit(AssignStatement* s) {
  int v = s->rhs->accept(this);
  env.update(s->id, v);  
  return;
}

void ImpInterpreter::visit(PrintStatement* s) {
  int v = s->e->accept(this);
  cout << v << endl;
  return;
}

void ImpInterpreter::visit(IfStatement* s) {
  int v = s->cond->accept(this);
  if (!v) {
    if (s->elsebody != NULL) 
      s->elsebody->accept(this);
  } else 
    s->body->accept(this);
  return;
}

void ImpInterpreter::visit(WhileStatement* s) {
  while (s->cond->accept(this))
    s->body->accept(this);
  return;
}

void ImpInterpreter::visit(DoWhileStatement* s) {
  do {
    s->body->accept(this);
  }
  while (s->cond->accept(this)); return;
}

void ImpInterpreter::visit(ForStatement* s) {
  int n1 = s->begin->accept(this);
  int n2 = s->end->accept(this);
  for (int i = n1; i <= n2; ++i) {
    env.update(s->id, i); // update iterator i -> variable decl id
    s->body->accept(this);
  }
 return;
}

void ImpInterpreter::visit(BreakStatement *s) {}

void ImpInterpreter::visit(ContinueStatement *s) {}



int ImpInterpreter::visit(BinaryExp* e) {
  int v1 = e->left->accept(this);
  int v2 = e->right->accept(this);
  int result = 0;
  switch(e->op) {
    case PLUS: result = v1+v2; break;
    case MINUS: result = v1-v2; break;
    case MULT: result = v1 * v2; break;
    case DIV: result = v1 / v2; break;
    case EXP:
      result = 1;
      while (v2 > 0) { result *= v1; v2--; }
      break;
    case LT: result = v1 < v2; break;
    case LTEQ: result = v1 <= v2; break;
    case GT: result = v1 > v2; break;
    case GTEQ: result = v1 >= v2; break;
    case EQ: result = v1 == v2; break;
  }
  return result;
}

int ImpInterpreter::visit(NumberExp* e) {
  return e->value;
}

int ImpInterpreter::visit(IdExp* e) {
  if (env.check(e->id))
    return env.lookup(e->id);
  else {
    cout << "Variable indefinida: " << e->id << endl;
    exit(0);
  }
  return 0;
}

int ImpInterpreter::visit(CondExp* e) {
  int cond = e->cond->accept(this);
  if (cond) return e->tbody->accept(this);
  else return e->fbody->accept(this);
}

int ImpInterpreter::visit(ParenthExp* ep) {
  return ep->e->accept(this);
}
