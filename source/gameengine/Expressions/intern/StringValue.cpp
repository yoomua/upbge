/** \file gameengine/Expressions/StringValue.cpp
 *  \ingroup expressions
 */
// StringValue.cpp: implementation of the EXP_StringValue class.
/*
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

#include "EXP_StringValue.h"

EXP_StringValue::EXP_StringValue(const std::string& txt)
	:m_value(txt)
{
}

std::string EXP_StringValue::GetName() const
{
	return m_value;
}

int EXP_StringValue::GetValueType() const
{
	return VALUE_STRING_TYPE;
}

std::string EXP_StringValue::GetText() const
{
	return m_value;
}

bool EXP_StringValue::Equal(EXP_Value *other) const
{
	if (other->GetValueType() != VALUE_STRING_TYPE) {
		return false;
	}

	return (m_value == static_cast<EXP_StringValue *>(other)->GetValue());
}

const std::string &EXP_StringValue::GetValue() const
{
	return m_value;
}

void EXP_StringValue::SetValue(const std::string& value)
{
	m_value = value;
}

EXP_Value *EXP_StringValue::GetReplica()
{
	EXP_StringValue *replica = new EXP_StringValue(*this);
	replica->ProcessReplica();
	return replica;
}
