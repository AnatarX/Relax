#include "Frame.h"

Frame::Frame(Method* method, const VariableList& variableList) : method(method), variables(variableList)
{
}

Variable* Frame::FindVariableById(int id)
{
    return variables.FindVariableById(id);
}

Method* Frame::GetMethod() const
{
    return method;
}

VariableList Frame::GetVariableList() const
{
    return variables;
}

void Frame::SetMethod(Method* method)
{
    this->method = method;
}

void Frame::SetVariableList(const VariableList& variables)
{
    this->variables = variables;
}

void Frame::CreateVariable(int id)
{
    variables.push_back(Variable(id));
}
