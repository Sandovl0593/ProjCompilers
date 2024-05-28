#include "imp_printer.hh"

void ImpPrinter::print(Program* p) {
  cout << "Program : ";
  p->accept(this);
  return;
}

void ImpPrinter::visit(Program* p) {
  p->slist->accept(this);
  return;
}



void ImpPrinter::visit(StatementList* s) {
  cout << "{" << endl;
  list<Stm*>::iterator it;
  for (it = s->slist.begin(); it != s->slist.end(); ++it) {
    (*it)->accept(this);
    cout << ";" << endl;
  }
  cout << "}" << endl;
  return;
}

void ImpPrinter::visit(AssignStatement* s) {
  cout << s->id << " = ";
  s->rhs->accept(this);
  return;
}

void ImpPrinter::visit(PrintStatement* s) {
  cout << "print(";
  s->e->accept(this);
  cout << ")";
  return;
}

void ImpPrinter::visit(IfStatement* s) {
  cout << "if ";
  s->cond->accept(this);
  cout << " then ";
  s->body->accept(this);
  if (s->elsebody != NULL) {
    cout << "else ";
    s->elsebody->accept(this);
  }
  cout << "endif";
}

void ImpPrinter::visit(WhileStatement* s) {
  cout << "while ";
  s->cond->accept(this);
  cout << " do ";
  s->body->accept(this);
  cout << "endwhile";
}

void ImpPrinter::visit(DoWhileStatement* s) {
  cout << "do ";
  s->body->accept(this);
  cout << "while ";
  s->cond->accept(this);
  // cout << "endwhile";
}

void ImpPrinter::visit(ForStatement* s) {
  cout << "for " << s->id << ": ";
  s->begin->accept(this);
  cout << " to ";
  s->end->accept(this);
  cout << " do";
  s->body->accept(this);
  cout << "endfor";
 return;
}

void ImpPrinter::visit(BreakStatement *s) { cout << "break"; }

void ImpPrinter::visit(ContinueStatement *s) { cout << "continue"; }



int ImpPrinter::visit(BinaryExp* e) {
  e->left->accept(this);
  cout << ' ' << Exp::binopToString(e->op) << ' ';
  e->right->accept(this);
  return 0;
}

int ImpPrinter::visit(NumberExp* e) {
  cout << e->value;
  return 0;
}

int ImpPrinter::visit(IdExp* e) {
  cout << e->id;
  return 0;
}

int ImpPrinter::visit(CondExp* e) {
  cout << "ifexp(" ;
  e->cond->accept(this);
  cout << ", ";
  e->tbody->accept(this);
  cout << ", ";
  e->fbody->accept(this);
  cout << ')';
  return 0;
}

int ImpPrinter::visit(ParenthExp* ep) {
  cout << '(';
  ep->e->accept(this);
  cout << ')';
  return 0;
}
