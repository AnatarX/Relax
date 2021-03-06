#include "StdMethod.h"

StdMethod::StdMethod(const MethodSignature& signature, std::function<Object*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), function(function), accessModifier(accessModifier), isStatic(isStatic)
{
}

StdMethod::StdMethod(const QString& name, const QString& dataType, const QString& nameClass, const QList<Parameter>& parameters, std::function<Object*(Stack&)> function, const AccessModifier& accessModifier, bool isStatic)
	:MethodSignature(name, dataType, nameClass, parameters), function(function), accessModifier(accessModifier), isStatic(isStatic)
{
}

bool StdMethod::IsStatic() const
{
	return isStatic;
}

AccessModifier StdMethod::GetAccessModifier() const
{
	return accessModifier;
}

std::function<Object*(Stack&)> StdMethod::GetFunction() const
{
	return function;
}

void StdMethod::SetIsStatic(bool isStatic)
{
	this->isStatic = isStatic;
}

void StdMethod::SetAccessModifier(const AccessModifier& accessModifier)
{
	this->accessModifier = accessModifier;
}

void StdMethod::SetFunction(std::function<Object*(Stack&)> function)
{
	this->function = function;
}

Object* StdMethod::CallFunction(Stack& stack)
{
	return function(stack);
}

bool StdMethod::operator==(const StdMethod& other) const
{
	bool signatureIsEqual = MethodSignature::operator==(dynamic_cast<const MethodSignature&>(other));
	bool isStaticIsEqual = isStatic == other.IsStatic();
	bool accessModifierIsEqual = accessModifier == other.GetAccessModifier();
	return signatureIsEqual && isStaticIsEqual && accessModifierIsEqual;
}
