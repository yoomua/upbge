/*
 * Parser.h: interface for the CParser class.
 * Eindhoven University of Technology 1997
 * OOPS team (Serge vd Boom, Erwin Coumans, Tom Geelen, Wynke Stuylemeier)
 * Copyright (c) 1996-2000 Erwin Coumans <coockie@acm.org>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Erwin Coumans makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 */

/** \file EXP_InputParser.h
 *  \ingroup expressions
 */

#ifndef __EXP_INPUTPARSER_H__
#define __EXP_INPUTPARSER_H__

class CParser;

#include "EXP_Expression.h"

class CParser {
 public:
  CParser();
  virtual ~CParser();

  CExpression *ProcessText(const std::string &intext);
  void SetContext(CValue *context);

 private:
  enum symbols {
    errorsym,
    lbracksym,
    rbracksym,
    cellsym,
    commasym,
    opsym,
    constsym,
    sumsym,
    ifsym,
    whocodedsym,
    eolsym,
    idsym
  };  // all kinds of symbols

  enum optype {
    OPmodulus,
    OPplus,
    OPminus,
    OPtimes,
    OPdivide,
    OPand,
    OPor,
    OPequal,
    OPunequal,
    OPgreater,
    OPless,
    OPgreaterequal,
    OPlessequal,
    OPnot
  };  // all kinds of operators

  enum consttype { booltype, inttype, floattype, stringtype };  // all kinds of constants

  int sym,        // current symbol
      opkind,     // kind of operator, if symbol is an operator
      constkind;  // kind of operator, if symbol is a constant

  char ch;              // current character
  int chcount;          // index to character in input string
  CExpression *errmsg;  // contains a errormessage, if scanner error

  std::string text,             // contains a copy of the original text
      const_as_string;          // string representation of the symbol, if symbol is a constant
  bool boolvalue;               // value of the boolean, if symbol is a constant of type boolean
  CValue *m_identifierContext;  // context in which identifiers are looked up

  void ScanError(const std::string &str);
  CExpression *Error(const std::string &str);
  void NextCh();
  void TermChar(char c);
  void DigRep();
  void CharRep();
  void GrabString(int start);
  void GrabRealString(int start);
  void NextSym();
  const std::string Symbol2Str(int s);
  void Term(int s);
  int Priority(int optor);
  CExpression *Ex(int i);
  CExpression *Expr();
};

#endif /* __EXP_INPUTPARSER_H__ */
